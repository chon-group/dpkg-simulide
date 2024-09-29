# SimulIDE Chon-Group Debian Package

|![](https://github.com/user-attachments/assets/0e3609bc-9483-4785-b925-5b707007f712)|
|-|
|This repository implements a APT Package of [SimulIDE 1.1.0 (Revision 1936)](https://simulide.com/p/testers/) for Debian, Ubuntu, and derivatives with [Cognitive Hardware on Network Basic Prototypes (ChonBots)](https://github.com/chon-group/ChonBots) examples.|

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

    FREITAS, Bruno Policarpo Toledo; LAZARIN, Nilson Mori; PANTOJA, Carlos Eduardo. Uma Proposta de Emulador de Portas Seriais para Sistemas Multiagentes Embarcados. _In_: Workshop-Escola de Sistemas de Agentes, seus Ambientes e Aplicações (WESAAC), 17. , 2023, Pelotas/RS. Anais [...]. Pelotas: UFPel, 2023 . p. 55-66. URL: [https://zenodo.org/record/8329081](https://www.researchgate.net/publication/373484449_Uma_Proposta_de_Emulador_de_Portas_Seriais_para_Sistemas_Multiagentes_Embarcados)

    <details>
    <summary> Cite using Bibtex </summary>

        ```
        @inproceedings{freitas2023,
        author = {Freitas, Bruno Policarpo Toledo and Lazarin, Nilson Mori and Pantoja, Carlos Eduardo},
        title = {Uma {Proposta} de {Emulador} de {Portas} {Seriais} para {Sistemas} {Multiagentes} {Embarcados}},
        booktitle = {Anais do XVII Workshop-Escola de Sistemas de Agentes, seus Ambientes e Aplicações (WESAAC 2023)},
        location = {Pelotas/RS},
        year = {2023},
        pages = {55--66},
        publisher = {UFPel},
        address = {Pelotas, RS, Brasil},
        url = {https://zenodo.org/record/8329081}
        }
        ```
    </details>
