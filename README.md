# goNCommand

goNCommand is a set of Bash scripts to convert eight games (Ninja Commando, Ghost Pilots, Art of Fighting 3, Magician Lord, Ninja Master's, Crossed Swords, Sengoku, Super Sidekicks) to romsets for Final Burn Alpha, MAME or FBNeo.

## Installation

Put these files in a directory of your choice:

    goNCommand
    goGPilots
    goAoF3
    goML
    goNM
    goCS
    goSengoku
    goSuperS
    ss_unswizzle.c

Then compile ss_unswizzle.c:

    gcc -o ss_unswizzle ss_unswizzle.c

## Usage
1. Set the path MY_RAW_ROMS_DIR to point to the directory where Ninja Commando (or another supported game) is installed. In this directory, you will see files such as c1.bin and m1.bin. Example :

    MY_RAW_ROMS_DIR=/home/lionel2/provi/amazon/ninja_commando/rom

2. Set the path MY_OUT_ROM_DIR_1 to a temporary directory of your choice.
3. Run one of the eight scripts: 

```
./goNCommand
```
or
```
./goGPilots
```
or ./goAoF3 or ./goML or ./goNM or ./goCS or ./goSengoku or ./goSuperS

You should get a ncommand.zip file (or gpilots.zip, or aof3.zip, or maglord.zip, or ninjamas.zip, or crsword.zip, or sengoku.zip, or ssideki.zip) in the directory where the script is.

## Background and information
The C code ss_unswizzle.c was written by ark (the script goNCommand links to the original post where I found it).

The script goNCommand creates all but one file that match FBNeo CRC32. The file 050-p1.p1 does not match the CRC32 given by FBNeo, and I do not know how to fix this, as it is a simple copy of the original file. The game seems to run fine: feel free to investigate.

Update: a friend noticed that 050-p1.p1 differs from the "known" file only at one address. I updated all the scripts, as it seems to be the case for all of them.

Other useful scripts to extract and convert games are available from:
+ https://gitlab.com/vaiski/romextract
+ https://github.com/ValadAmoleo/sf30ac-extractor/tree/mame
+ https://github.com/farmerbb/RED-Project
+ https://github.com/shawngmc/game-extraction-toolbox


## Contributing

Feel free to fork this code (and solve the mystery of 050-p1.p1 wrong CRC32).

## License

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.




