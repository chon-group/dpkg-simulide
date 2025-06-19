# SimulIDE Chon-Group Debian Package

|![](https://github.com/user-attachments/assets/f6201538-c842-4f57-8e7a-06f0dda94b42)|
|-|
|This repository implements a APT Package of [SimulIDE 1.1.0 (Revision 2069)](https://simulide.com/p/testers/) for Debian, Ubuntu, and derivatives with [Cognitive Hardware on Network Basic Prototypes (ChonBots)](https://github.com/chon-group/ChonBots) examples.|

## How to Install?
1) In a terminal run the commands below:

```console
echo "deb [trusted=yes] http://packages.chon.group/ chonos main" | sudo tee /etc/apt/sources.list.d/chonos.list
sudo apt update
sudo apt install linux-headers-`uname -r` chonos-simulide
```

## COPYRIGHT
+ [SimulIDE](https://simulide.com/) is a simple real time electronic circuit simulator, intended for hobbyist or students to learn and experiment with analog and digital electronic circuits and microcontrollers, supporting PIC, AVR and Arduino. Licensed by AGPLv3

---
+ ___SimulIDE Debian Package___ is licensed under a [Creative Commons Attribution 4.0 International License](http://creativecommons.org/licenses/by/4.0/). The licensor cannot revoke these freedoms as long as you follow the license terms:

    * __Attribution__ — You must give __appropriate credit__ like below:

    Bruno Freitas, Nilson Lazarin, and Carlos Pantoja. 2023. A Proposal for a Serial Port Emulator for Embedded Multi-Agent Systems. In _Proceedings of the 17th Workshop-School on Agents, Environments, and Applications_, August 30, 2023, Pelotas/RS, Brasil. SBC, Porto Alegre, Brasil, 55-66. DOI: https://doi.org/10.5753/wesaac.2023.33437.

    <details>
    <summary> Cite using Bibtex </summary>

        ```
        @inproceedings{freitas2023,
        author = {Bruno Freitas and Nilson Lazarin and Carlos Pantoja},
        title = {{A Proposal for a Serial Port Emulator for Embedded Multi-Agent Systems}},
        booktitle = {Proceedings of the 17th Workshop-School on Agents, Environments, and Applications},
        location = {Pelotas/RS},
        year = {2023},
        issn = {2326-5434},
        pages = {55--66},
        publisher = {SBC},
        address = {Porto Alegre, RS, Brasil},
        doi = {10.5753/wesaac.2023.33437},
        url = {https://sol.sbc.org.br/index.php/wesaac/article/view/33437}
        }
        ```
    </details>
