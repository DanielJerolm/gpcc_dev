# gpcc_dev
Development environment for GPCC.

# Before cloning...
This project contains submodules. The most important one is of course GPCC, since this project is the development
environment for GPCC. After cloning and initializing the submodules, all submodules incl. GPCC will be on a defined
commit, but will also be in detached head state.

To clone this project and to initialize the submodules, use one of the following commands:

HTTPS:

`git clone -b master --recurse-submodules https://github.com/DanielJerolm/gpcc_dev.git`

SSH:

`git clone -b master --recurse-submodules git@github.com:DanielJerolm/gpcc_dev.git`


If you cloned the project using a different command and missed to initialize the submodules, or if the submodules
folders are empty, then you can use the following commands to initialize the submodules:

```
git submodule init
git submodule update
```

# After cloning...
gpcc_dev contains a VSCODE workspace file (`gpcc_dev-Workspace.code-workspace`). Open it in VSCODE. gpcc_dev contains
all relevant settings for VSCODE to build GPCC (Terminal -> Run Task... -> ...) and to debug the unit tests.

Intellisense requires a file `compile_commands.json` from CMake to resolve includes and symbols properly. After opening
the workspace for the first time, you should take the following actions:

1. Run `Terminal->Run Task...->cmake_init_unittest_release` from the main menu.

2. Open any CPP/HPP-file.

3. Click on the drop-down-box in the bottom right of VSCODE that displays the current configuration.

4. Choose the configuration "Linux-unittests".
