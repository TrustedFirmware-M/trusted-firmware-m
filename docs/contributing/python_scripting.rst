##########################
Python Scripts and Modules
##########################

Overview
--------

This document describes the guidelines for adding Python scripts and modules to TF-M. TF-M supports
multiple platforms, each potentially requiring platform-specific scripts or modules. Scripts and
modules are organized as `Namespace Packages <https://packaging.python.org/en/latest/guides/packaging-namespace-packages/>`_.

Adding Platform-Specific Modules
--------------------------------

Suppose a module is located at
``path/to/module/``
and its package name is ``foo``:

- Add the module path to ``pyproject.toml``:

  .. code-block:: toml

      [tool.setuptools.package-dir]
      foo = "path/to/module/"

- Register the package in ``pyproject.toml``:

  .. code-block:: toml

      [tool.setuptools]
      packages = ["foo"]

- Install the module:

  .. code-block:: bash

      pip install .

  Or, for editable installation:

  .. code-block:: bash

      source .venv/bin/activate
      pip install -e .

- Import the installed module in other Python scripts/modules:

  .. code-block:: python

      import foo.<MODULE_NAME> as <MODULE_SHORT_NAME>

Adding Platform-Specific Scripts
--------------------------------

- Every script should define a ``main()`` entry point.
- Add the script’s entry point to ``pyproject.toml``. The script executable name must be prefixed
  with the platform name.

For example, for a script ``bar`` in package ``foo``:

- Register the script in ``pyproject.toml``:

  .. code-block:: toml

      [project.scripts]
      foo_bar = "foo.bar:main"

- Install scripts in a virtual environment:

  .. code-block:: bash

      # Subsequent edits made to scripts after install **WONT** be reflected immediately and will need to be installed again
      source .venv/bin/activate
      pip install .

  Or, for editable installation:

  .. code-block:: bash

      # Edits made to the scripts will be reflected immediately
      source .venv/bin/activate
      pip install -e .

- Run the script by calling the executable:

  .. code-block:: bash

      (.venv) ± foo_bar
      foo_bar help text

--------------

*SPDX-License-Identifier: BSD-3-Clause*

*SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors*
