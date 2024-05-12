# My QMK repo with qmk_firmware as a submodule

The idea for this set up came from [Separate keymap repo for QMK](https://medium.com/@patrick.elmquist/separate-keymap-repo-for-qmk-136ff5a419bd)

## Building the firmware
- `make iris`
- `make romac`
- `make kyria-1`
- `make kyria-3`

They all build `*.hex` files except the *kyria-3* which builds a `*.uf2` file. The compile for *kyria-3* includes `-e CONVERT_TO=elite_pi` which can be added to `rules.mk` but I prefered to leave it explicitly defined as a reminder.

I have added `QMK` configuration so that I don't need to specify the `keymap` (with `-km`) which I've set to `greywidget`. You can view the config with `qmk config -a`

## Flashing the micro-controllers
- *kyria-3* double-press the reset button and then drag the firmware onto the drive. It doesn't matter what it is called
- *all the others* run `qmk_toolbox.exe`, click the reset button and select the appropriate file and click on *flash*

I've changed the Makefile to that each build includes a timestamp in its name and you shouldn't need to rename the firmware in order to use it.

## Managing the repo
The repo `qmk-keymaps` was set up normally with python package `qmk` installed, and then:
- `git submodule add https://github.com/qmk/qmk_firmware.git`
- `git submodule update --init --recursive`


## Pulling Upstream Changes from the Submodule Remote
- cd `qmk_firmware`
- `git fetch`
- `git merge origin/master`
- `cd ..` back to main repo
- `git diff --submodule` shows that the submodule has been updated and lists the commits
- `git add .`
- `git commit -m "latest submodule updates"`
- `git push origin main` Push my own code and also update submodule references. Until you do this, it will look like there are submodule
