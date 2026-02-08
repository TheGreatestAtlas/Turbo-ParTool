# Export pliku .par za pomocą PARex

**PARex** jest to program służący do eksportu pliku `.par` z
**KnightShift** do postaci katalogu z plikami `.cpp`, które reprezentują
każdą sekcję obiektów pliku `.par`.

## Jak używać?: {#jak-używać .unnumbered}

1.  Włączamy program.

2.  Wpisujemy nazwę pliku wejściowego wraz z formatem.

3.  Klikamy przycisk enter i czekamy.

4.  Po wyłączeniu okna konsoli wiemy, że program skończył pracę.

Program działa również w trybie ARGC&ARGV. Przykład użycia:

    PARex.exe <nazwa_pliku.par>

## Szybki Export: {#szybki-export .unnumbered}

Aby w szybki sposób dekompilować plik `.par` należy korzystać z
`EXPORT.ps1` lub `EXPORT.bat`. W celu modyfikacji
argumentów/konfiguracji należy zedytować plik `.bat/.ps1` przez
notatnik.\
**Przkład pliku .bat:**

    PARex.exe <nazwapliku.par>

**Przykład pliku .ps1:**

    .\PARex.exe .\<nazwapliku.par>

# Opcjonalna konfiguracja PARex

Plik **PARex.cfg** umożliwia konfigurację sposobu eksportu danych do
plików `.cpp`. Użytkownik może zdecydować, czy wybrane wartości będą
prezentowane jako pojedyncze bity (flagi) o określonych etykietach, czy
w formacie surowym. W przypadku wyłączenia mapowania na flagi, dane
zostaną zapisane jako typ `uint32_t`. Rezygnacja z flagowania pozwala na
znaczące przyspieszenie procesu eksportu oraz skrócenie czasu kompilacji
wygenerowanego kodu. W pliku konfiguracyjnym dostępne są następujące
parametry:

## Prawda: {#prawda .unnumbered}

- YES/Yes/yes

- TRUE/True/true

- 1

## Fałsz: {#fałsz .unnumbered}

- NO/No/no

- FALSE/False/false

- 0

# Ogólny pogląd na strukturę otrzymanych plików po eksporcie/dekompilacji

Po eksporcie pliku `.par`, otrzymamy katalog w którym znajdują się pliki
`.cpp` reprezentujące sekcje z obiektami. Składnia plików jest w języku
`C++`. Oprócz plików `.cpp` z sekcjami - otrzymujemy również plik
`section_order.txt`, w którym znajduje się kolejność kompilacji plików
sekcji.

<figure id="teoria::pliki" data-latex-placement="H">
<img src="poglad_na_pliki.png" style="width:70.0%" />
<figcaption>Lista plików .cpp po eksporcie.</figcaption>
</figure>

# Edycja plików:

- Pliki `.cpp` dobrze jest edytować w programie geany, który w
  estetyczny sposób przedstawia sekcję w postaci drzewka.

- Plik `section_order.txt` to plik, w którym jest kolejność odpowiednich
  sekcji. Przy dodawaniu nowej sekcji należy wpisać nowo dodaną sekcję
  do tego pliku w odpowiednim miejscu.

- Wpisy `count()` oznaczają, że podczas kompilacji, kompilator sam
  policzy ilość sekcji/obiektów w `.par` (jest to bardzo wygodne).
  Jeżeli chcemy na stałę wpisać wartość to możemy ją wpisać zamiast
  `count()` i kompilator to przepuści.

- Aby dodać obiekt - należy skopiować jakiś obiekt i wkleić do środka
  sekcji w odpowiednio wybrane miejsce i pozmieniać dane.

- W takiej kolejności w jakiej jest header i obiekty w danej sekcji, to
  w takiej kolejności zostanie skompilowana sekcja.

- Nazwy zmiennych mogą być dowolne, ale wyjątkami są nazwy
  `number_of_objects` oraz `number_of_sections` - te nazwy są
  zastrzeżone dla kompilatora.

- Program **PARim** czyli kompilator obsługuje komentarze także można je
  zostawiać w plikach.

# Kompilacja plików .cpp do postaci .par przez PARim

**PARim** jest to program, a dokładnie kompilator służacy do kompilacji
całego katalogu z plikami sekcji `.cpp` do postaci `.par`.

## Jak używać?: {#jak-używać-1 .unnumbered}

1.  Włączamy program.

2.  Wpisujemy nazwe katalogu.

3.  Klikamy enter i za chwilkę powinno się zrobić.

4.  Wyłączenie okna konsoli sygnalizuje zakończenie pracy programu.

Program działa również w trybie ARGC&ARGV. Przykład użycia:

    PARim.exe <nazwa katalogu wejściowego>

## Szybki Import: {#szybki-import .unnumbered}

Aby w szybki sposób kompilować katalog z plikami `.cpp`, należy
korzystać z `IMPORT.ps1` lub `IMPORT.bat`. W celu modyfikacji
argumentów/konfiguracji należy zedytować plik `.bat/.ps1` przez
notatnik.\
**Przykład pliku .bat:**

    PARim.exe <nazwa katalogu wejściowego>

**Przykład pliku .ps1:**

    .\PARim.exe .\<nazwa katalogu wejściowego>
