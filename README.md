# Typewriter
Turn your Linux keyboard into a typewriter.


## Install
```bash
git clone https://github.com/Zombant/Typewriter.git
cd Typewriter
sudo make install
```
Note: You must add the appropriate event number for your keyboard to __typewriter.c__ before installing.

Your device event number can be found with `cat /proc/bus/input/devices`.

## Run
The `-b` flag allows the program to run after the terminal is closed
```bash
sudo -b typewriter
```
To specify a device:
```bash
sudo -b typewriter /dev/input/event2
```
Note that this may not work if you don't have access to /dev/input. This is why it is run with `sudo`. However, the root user cannot produce sound with pulseaudio. See the below two workarounds.

## Stopping the program
Run the following at the command line:
```bash
sudo killall typewriter
```

## Set up PulseAudio system-wide


If the sound effects do not play with PulseAudio, try following the directions on the [PulseAudio page on the Arch Wiki](https://wiki.archlinux.org/title/PulseAudio#Starting_system-wide_on_boot) to start PulseAudio system-wide.

## Try giving the user permissions to the event file
__This is a bad idea so don't do it__
As root, run (replacing event3 with the event for your device)
```bash
chmod o+r /dev/input/event3
```

Now you do not have to run the typewriter as root

To undo this, run as root:
```bash
chmod o-r /dev/input/event3
```

## Uninstall
```bash
sudo make uninstall
```
