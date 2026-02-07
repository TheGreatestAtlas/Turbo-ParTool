# Turbo-ParTool
# PL:
Pakiet programów służących do edytowania pliku `.par` z gry **KnightShift**.

**UWAGA! TA WERSJA MA PEWNE NIEDORÓBKI I BARDZO STARY KOD ŹRÓDŁOWY PRZED REFAKTORYZACJĄ,**
**jednak skompilowane oprogramowanie działa dobrze i raczej nie będzie sprawiać problemów podczas modowania KnightShift.**


## PARex (DEKOMPILATOR)

**PARex** jest to program służący do eksportu pliku `.par` z **KnightShift** do postaci
folderu z plikami `.cpp`, które reprezentują każdą sekcję `.par`.

### Jak używać?
1. Włączamy program.
2. Wpisujemy nazwę pliku wejściowego wraz z formatem.
3. No i klikamy enter i czekamy (szybko schodzi).

Program działa również w trybie ARGC&ARGV, przykład:<br>
`PARex.exe <nazwa pliku.par> <nazwa folderu wyjściowego>`

PRZED EDYCJĄ NALEŻY UPEWNIĆ SIĘ, ŻE WYPAKOWANY PAR PO DEKOMPILACJI JEST TAKI SAM JAK PAR PO KOMPILACJI...

### Edycja plików:
- Pliki `cpp` fajnie jest edytować w programie `geany`, który ładnie przedstawia sekcję w postaci drzewka.
- Plik `section_order.txt` to plik, w którym jest kolejność odpowiednich sekcji. Przy dodawaniu nowej sekcji należy wpisać nowo dodaną sekcję do tego pliku w odpowiednim miejscu.
- Wpisy `count()` oznaczają, że podczas kompilacji, kompilator sam policzy ilość sekcji/obiektów w par (jest to bardzo wygodne). Jeżeli chcemy na stałę wpisać wartość to też możemy to zrobić i kompilator to przepuści.
- Aby dodać obiekt należy skopiować jakiś obiekt i wkleić do środka sekcji w odpowiednio wybrane miejsce i pozmieniać dane. W takiej kolejności w jakiej jest header i obiekty w danej sekcji to w takiej kolejności zostanie skompilowana sekcja.
- Nazwy zmiennych można dowolnie nazywać prócz nazw `number_of_objects` oraz `number_of_sections`!!!
- Program **PARim** czyli kompilator obsługuje komentarze także można coś tam bazgrać w plikach.

### Plik konfiguracyjny PARex.cfg:
- W tym pliku możemy wyłączyć/włączyć wypisywanie do plików `.cpp` danych masek w postaci pojedynczych bitów o określonych etykietach.
- Jeśli wyłączymy jakąś etykietę to **PARex** wypisze do pliku wartość w postaci standardowej czyli zapisze to w formie `uint32_t`.
- Jest to wygodne ponieważ możemy wybrać co dokładnie chcemy mieć wypakowane i nie musimy marnować czasu na wypakowywanie/kompilowaniezbędnych informacji (jeśli je za takowe uważamy) gdy ich nie potrzebujemy. Przyśpiesza to w znaczny sposób późniejszy czas kompilacji.
- Etykiety w pliku cfg przyjmują wartości:
	* YES/Yes/yes
	* TRUE/True/true
	* NO/No/no
	* FALSE/False/false

## PARim (KOMPILATOR)
**PARim** jest to program, a dokładnie kompilator służacy do kompilacji całego folderu z plikami obiektów `.cpp` do postaci `.par`.

### Jak używać?
1. Włączamy program.
2. Wpisujemy nazwe folderu.
3. Klikamy enter i za chwilkę powinno się zrobić.
4. Gotowe mamy par!

Program działa również w trybie ARGC&ARGV, przykład:<br>
`PARim.exe <nazwa folderu wejściowego> <nazwa pliku wyjściowego.par>`

### Szybki Export
Aby w szybki sposób dekompilować plik `.par` należy korzystać z `EXPORT.ps1` lub `EXPORT.bat`.
W celu modyfikacji argumentów/konfiguracji należy zedytować plik `.bat/.ps1` przez notatnik.

PRZYKŁAD BAT:<br>
`PARex.exe <nazwapliku.par> <nazwa folderu wyjściowego>`

PRZYKŁAD .ps1:<br>
`.\PARex.exe .\<nazwapliku.par> .\<nazwa folderu wyjściowego>`

### Szybki Import
Aby w szybki sposób kompilować folder z `.cpp` należy korzystać z `IMPORT.ps1` lub `IMPORT.bat`.
W celu modyfikacji argumentów/konfiguracji należy zedytować plik `.bat/.ps1` przez notatnik.

PRZYKŁAD BAT:<br>
`PARim.exe <nazwa folderu wejściowego> <nazwa pliku wyjściowego.par>`

PRZYKŁAD .ps1:<br>
`.\PARim.exe .\<nazwa folderu wejściowego> .\<nazwa pliku wyjściowego.par>`


# ENG:
A package of programs for editing `.par` files from the game **KnightShift**.

**WARNING! THIS VERSION HAS SOME BUGS AND VERY OLD SOURCE CODE BEFORE REFACTORING.**
**However, the compiled software works well and is unlikely to cause problems when modding KnightShift.**


## PARex (DECOMPILATOR)
**PARex** is a program used to export a `.par` file from **KnightShift** into a
folder with `.cpp` files that represent each `.par` section.

### How to use.
1. Turn on the program.
2. We enter the name of the input file along with the format.
3. Well, we click enter and wait (it goes down quickly).

The program also works in ARGC&ARGV mode, example:<br>
`PARex.exe <input parameters filename.par> <output directory name>`

BEFORE EDITING, MAKE SURE THAT THE UNPACKED PAR AFTER DECOMPILATION IS THE SAME AS THE PAR AFTER COMPILATION....

### Edit files:
- It's nice to edit the cpp files in the geany program, which nicely presents the section in the form of a tree.
- The file `section_order.txt` is the file where the order of the relevant sections is. When adding a new section, enter the newly added section into this file in the appropriate place.
- `count()` entries mean that during compilation, the compiler will count the number of sections/objects in pairs by itself (this is very convenient). If we want to permanently enter a value then we can do that too and the compiler will let it through.
- To add an object, you need to copy some object and paste it into the middle of the section in the appropriate place and change the data. In the order in which the header and objects in the section is, then the section will be compiled in that order.
- Variable names can be named freely except `number_of_objects` and `number_of_sections`!!!
- **PARim** program or compiler supports comments also you can scribble something in there files.

### PARex.cfg configuration file:
- In this file we can disable/enable writing out mask data to `.cpp` files in the form of single bits with specific labels.
- If we disable any label then **PARex** will write out the value to the file in standard form i.e. write it in `uint32_t` form.
- This is convenient because we can choose what exactly we want to have extracted and we don't have to waste time extracting/compilingunnecessary information (if we consider it as such) when we don't need it. This speeds up the later compilation time considerably.
- Labels in the cfg file take values:
	* YES/Yes/yes
	* TRUE/True/true
	* NO/No/no
	* FALSE/False/false

## PARim (COMPILATOR)
**PARim** is a program, or more precisely a compiler used to compile an entire folder of `.cpp` object files into `.par`.

### How to use?
1. Turn on the program.
2. We type the name of the folder.
3. We click enter and in a moment it should be done.
4. Ready we have par!

The program also works in ARGC&ARGV mode, example:<br>
`PARim.exe <input directory name> <output parameters file.par>`

### Quick Export
To quickly decompile a `.par` file, use `EXPORT.ps1` or `EXPORT.bat`.
To modify the arguments/configuration, edit the `.bat/.ps1` file via notepad.

EXPORT BAT: <br>
`PARex.exe <filename.par> <name of output folder>`

EXAMPLE .ps1: <br>
`.\PARex.exe .\<filename.par> .\<name of output folder>`

### Quick Import
To quickly compile a folder with `.cpp`, use `IMPORT.ps1` or `IMPORT.bat`.
To modify the arguments/configuration, edit the `.bat/.ps1` file via notepad.

EXAMPLE BAT: <br>
`PARim.exe <name of input folder> <name of output parameters file.par>`

EXAMPLE .ps1: <br>
`.\PARim.exe .\<name of input folder> .\<name of output parameters file.par>`