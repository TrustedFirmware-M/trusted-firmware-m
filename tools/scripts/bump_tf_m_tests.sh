#!/usr/bin/env bash
#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set -euo pipefail

REMOTE_URL="https://github.com/TrustedFirmware-M/tf-m-tests.git"
BRANCH="main"
VERSION_FILE="lib/ext/tf-m-tests/version.txt"
COMMIT_MSG="Build: Bump tf-m-tests"

# Sanity checks
[[ -f "$VERSION_FILE" ]] || {
    echo "ERROR: $VERSION_FILE not found" >&2
    exit 1
}

# Extract currently recorded version
current="$(sed -nE 's/^version=([0-9a-fA-F]+)$/\1/p' "$VERSION_FILE")"
[[ -n "$current" ]] || {
    echo "ERROR: Could not parse version from $VERSION_FILE" >&2
    exit 1
}

# Fetch latest SHA from remote without cloning
latest_full="$(git ls-remote "$REMOTE_URL" "refs/heads/$BRANCH" | awk '{print $1}')"
[[ -n "$latest_full" ]] || {
    echo "ERROR: Could not resolve latest SHA" >&2
    exit 1
}

latest_short="${latest_full:0:7}"

echo "Current version : $current"
echo "Latest  version : $latest_short"

# No-op if already up to date
if [[ "$current" == "$latest_short" || "$current" == "$latest_full" ]]; then
    echo "tf-m-tests already up to date"
    exit 0
fi

# Update version.txt (preserve file structure and comments)
sed -i -E "s/^version=.*/version=$latest_short/" "$VERSION_FILE"

# Ensure the change is exactly what we expect
git diff -- "$VERSION_FILE"

# Commit in a single commit
git add "$VERSION_FILE"
git commit -s -m "$COMMIT_MSG"

echo "Committed: $COMMIT_MSG"
