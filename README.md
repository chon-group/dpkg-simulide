# SimulIDE Chon-Group Debian Package
This repository implements a APT Package of
[SimulIDE 1.1.0 (Revision 1936)](https://simulide.com/p/testers/) for Debian, Ubuntu, and derivatives with [Cognitive Hardware on Network Basic Prototypes (ChonBots)](https://github.com/chon-group/ChonBots) examples.

## How to Install?
1) In a terminal run the commands below:

```console
echo "deb [trusted=yes] http://packages.chon.group/ chonos main" | sudo tee /etc/apt/sources.list.d/chonos.list
sudo apt update
sudo apt install chonos-simulide
```

## COPYRIGHT
[SimulIDE](https://simulide.com/) is a simple real time electronic circuit simulator, intended for hobbyist or students to learn and experiment with analog and digital electronic circuits and microcontrollers, supporting PIC, AVR and Arduino.