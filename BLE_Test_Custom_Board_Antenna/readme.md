This project is a simple BLE Heartrate project that works with our custom
board; simply flash this project to the board (easiest to use ELF file and
CubeProgrammer). 

With this running, you can use a BLE Scanner application to check that the
antenna is hooked up and the secondary MCU is responding correctly.

Sometimes I get hung behavior where Windows/ST Tools stop communicating with
the board after a flash of BLE projects; restarting windows and the the device seem to work.
If that doesn't work, you need to use the DFU (hook it up, reset the board, and
use CubeProgrammer to load a new ELF).

