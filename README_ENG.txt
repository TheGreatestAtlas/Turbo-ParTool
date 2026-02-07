PARex (DECOMPILATOR)
--------------------
PARex is a program used to export a .par file from KnightShift into a
folder with .cpp files that represent each .par section.

How to use.
    1. Turn on the program.
    2. We enter the name of the input file along with the format.
    3. Well, we click enter and wait (it goes down quickly).

The program also works in ARGC&ARGV mode, example:
PARex.exe <input parameters filename.par> <output directory name>

BEFORE EDITING, MAKE SURE THAT THE UNPACKED PAR AFTER DECOMPILATION IS THE SAME AS THE PAR AFTER COMPILATION....

Edit files:
--------------
    -> It's nice to edit the cpp files in the geany program, which nicely presents the section in the form of a tree.
    -> The file section_order.txt is the file where the order of the relevant sections is. When adding a new
    section, enter the newly added section into this file in the appropriate place.
    -> count() entries mean that during compilation, the compiler will count the number of sections/objects in pairs by itself (this is very convenient).
    If we want to permanently enter a value then we can do that too and the compiler will let it through.
    -> To add an object, you need to copy some object and paste it into the middle of the section in the appropriate place and change the data.
    In the order in which the header and objects in the section is, then the section will be compiled in that order.
    -> Variable names can be named freely except number_of_objects and number_of_sections!!!
    -> PARim program or compiler supports comments also you can scribble something in there files.

PARex.cfg configuration file:
------------------------------
    -> In this file we can disable/enable writing out mask data to .cpp files in the form of single bits with specific labels.
    -> If we disable any label then PARex will write out the value to the file in standard form i.e. write it in uint32_t form.
    -> This is convenient because we can choose what exactly we want to have extracted and we don't have to waste time extracting/compiling
    unnecessary information (if we consider it as such) when we don't need it. This speeds up the later compilation time considerably.
    -> Labels in the cfg file take values:
        - YES/Yes/yes
        - TRUE/True/true
        - NO/No/no
        - FALSE/False/false

PARim (COMPILATOR)
------------------
PARim is a program, or more precisely a compiler used to compile an entire folder of .cpp object files into .par.

How to use?
    1. Turn on the program.
    2. We type the name of the folder.
    3. We click enter and in a moment it should be done.
    4. Ready we have par!

The program also works in ARGC&ARGV mode, example:
PARim.exe <input directory name> <output parameters file.par>

Quick Export
------------
To quickly decompile a .par file, use EXPORT.ps1 or EXPORT.bat.
To modify the arguments/configuration, edit the .bat/.ps1 file via notepad.

EXPORT BAT: 
PARex.exe <filename.par> <name of output folder>

EXAMPLE .ps1: 
.\PARex.exe .\<filename.par> .\<name of output folder>

Quick Import
------------
To quickly compile a folder with .cpp, use IMPORT.ps1 or IMPORT.bat.
To modify the arguments/configuration, edit the .bat/.ps1 file via notepad.

EXAMPLE BAT: 
PARim.exe <name of input folder> <name of output parameters file.par>

EXAMPLE .ps1: 
.\PARim.exe .\<name of input folder> .\<name of output parameters file.par>