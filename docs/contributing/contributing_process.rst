Contributing Process
====================

Contributions to the TF-M project need to follow the process below.

.. Note::

   Please contact TF-M mailing list
   `tf-m@lists.trustedfirmware.org <mailing_list_>`_ for any question.

- It is recommended to subscribe to TF-M mailing list
  via `this page <https://lists.trustedfirmware.org/mailman3/lists/tf-m.lists.trustedfirmware.org>`_.
- Refer to the :doc:`/roadmap` or send a mail to the TF-M mailing list `tf-m@lists.trustedfirmware.org <mailing_list_>`_
  to get the latest status and plan of TF-M.
- Follow :doc:`Design Proposal Guideline </contributing/tfm_design_proposal_guideline>`
  to propose your design.
- Follow guidelines below to prepare the patch:

  - Clone the TF-M code on your own machine from `TF-M git repository
    <https://git.trustedfirmware.org/TF-M/trusted-firmware-m.git>`_.
  - Follow the :doc:`TF-M getting started </getting_started/tfm_getting_started>`,
    :doc:`Build Instructions </building/tfm_build_instruction>` and
    :doc:`Coding Guide </contributing/coding_guide>` for the TF-M project.
  - Make your changes in logical chunks to help reviewers. Each commit should
    be a separate review and either work properly or be squashed after the
    review and before merging.
  - Follow :doc:`Documentation Contribution Guidelines </contributing/doc_guidelines>`
    to update documentation in ``docs`` folder if needed.
  - Test your changes and add details to the commit description.
  - The code is accepted under :doc:`Developer Certificate of Origin (DCO) </contributing/dco>`.
    Use ``git commit -s`` to add a ``Signed-off-by`` trailer at the end of the
    commit log message.
    See `git-commit <https://git-scm.com/docs/git-commit>`_ for details.
  - Ensure that each changed file has the correct copyright and license
    information. Files that entirely consist of contributions to this project
    should have a copyright notice and BSD-3-Clause SPDX license identifier of
    the form

    ::

        SPDX-License-Identifier: BSD-3-Clause
        SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors

    to reflect the community ownership of the project. Individual copyrights
    can be traced back through the corresponding commits. For more details please refer
    to `Linux Foundation guidelines on copyright notices`_ for OSS projects.
    Patches that contain changes to imported Third Party IP files should retain
    their original copyright and license notices. If changes are made to the imported
    files, then add an additional ``SPDX-FileCopyrightText`` tag line as shown above.

    The original form of the project copyright note as

        Copyright (c) XXXX[-YYYY], <OWNER>. All rights reserved.

    is still appropriate but shall be avoided in the new files.

  - Add a `Change-Id <https://review.trustedfirmware.org/Documentation/user-changeid.html>`_
    to the commit message, which can be generated any way you like (e.g. from
    the SHA of the commit).
    It is suggested to clone repositories with commit-msg hook. The commit-msg
    hook attaches Change-Id automatically.
    Take `trusted-firmware-m <https://review.trustedfirmware.org/admin/repos/TF-M/trusted-firmware-m>`_
    as an example.

- Submit your patch for review.
  Refer to `Uploading Changes <https://review.trustedfirmware.org/Documentation/user-upload.html>`_
  for details of uploading patch.
- Add relevant :doc:`code owner(s) </contributing/maintainers>` for reviewing
  the patch.
- You may be asked to provide further details or make additional changes.
- You can discuss further with code owner(s) and maintainer(s) directly via
  TF-M mailing list `tf-m@lists.trustedfirmware.org <mailing_list_>`_ if necessary.
- If multiple patches are linked in a chain then code owners and maintainers
  should review and merge individual patches when they are ready, rather than
  waiting for the entire chain to be reviewed. If multiple patches are intended
  to be merged together then authors shall use topics or explicitly mention
  that in the commit message.
- Click ``Allow-CI +1`` button on Gerrit page to run CI to validate your patch.
  Your patch shall pass CI successfully before being merged. Code owner(s) and
  maintainer(s) may ask for additional test.
- Once the change is approved by code owners, the patch will be merged by the
  maintainer.

--------------

.. _mailing_list: tf-m@lists.trustedfirmware.org
.. _Linux Foundation guidelines on copyright notices: https://www.linuxfoundation.org/blog/blog/copyright-notices-in-open-source-software-projects

*Copyright (c) 2017-2022, Arm Limited. All rights reserved.*
