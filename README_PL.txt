PARex (DEKOMPILATOR)
--------------------
PARex jest to program służący do eksportu pliku .par z KnightShift do postaci
folderu z plikami .cpp, które reprezentują każdą sekcję .par.

Jak używać?
    1. Włączamy program.
    2. Wpisujemy nazwę pliku wejściowego wraz z formatem.
    3. No i klikamy enter i czekamy (szybko schodzi).

Program działa również w trybie ARGC&ARGV, przykład:
PARex.exe <nazwa pliku.par> <nazwa folderu wyjściowego>

PRZED EDYCJĄ NALEŻY UPEWNIĆ SIĘ, ŻE WYPAKOWANY PAR PO DEKOMPILACJI JEST TAKI SAM JAK PAR PO KOMPILACJI...

Edycja plików:
--------------
    -> Pliki cpp fajnie jest edytować w programie geany, który ładnie przedstawia sekcję w postaci drzewka.
    -> Plik section_order.txt to plik, w którym jest kolejność odpowiednich sekcji. Przy dodawaniu nowej
    sekcji należy wpisać nowo dodaną sekcję do tego pliku w odpowiednim miejscu.
    -> Wpisy count() oznaczają, że podczas kompilacji, kompilator sam policzy ilość sekcji/obiektów w par (jest to bardzo wygodne).
    Jeżeli chcemy na stałę wpisać wartość to też możemy to zrobić i kompilator to przepuści.
    -> Aby dodać obiekt należy skopiować jakiś obiekt i wkleić do środka sekcji w odpowiednio wybrane miejsce i pozmieniać dane.
    W takiej kolejności w jakiej jest header i obiekty w danej sekcji to w takiej kolejności zostanie skompilowana sekcja.
    -> Nazwy zmiennych można dowolnie nazywać prócz nazw number_of_objects oraz number_of_sections!!!
    -> Program PARim czyli kompilator obsługuje komentarze także można coś tam bazgrać w plikach.

Plik konfiguracyjny PARex.cfg:
------------------------------
    -> W tym pliku możemy wyłączyć/włączyć wypisywanie do plików .cpp danych masek w postaci pojedynczych bitów o określonych etykietach.
    -> Jeśli wyłączymy jakąś etykietę to PARex wypisze do pliku wartość w postaci standardowej czyli zapisze to w formie uint32_t.
    -> Jest to wygodne ponieważ możemy wybrać co dokładnie chcemy mieć wypakowane i nie musimy marnować czasu na wypakowywanie/kompilowanie
    zbędnych informacji (jeśli je za takowe uważamy) gdy ich nie potrzebujemy. Przyśpiesza to w znaczny sposób późniejszy czas kompilacji.
    -> Etykiety w pliku cfg przyjmują wartości:
        - YES/Yes/yes
        - TRUE/True/true
        - NO/No/no
        - FALSE/False/false

PARim (KOMPILATOR)
------------------
PARim jest to program, a dokładnie kompilator służacy do kompilacji całego folderu z plikami obiektów .cpp do postaci .par.

Jak używać?
    1. Włączamy program.
    2. Wpisujemy nazwe folderu.
    3. Klikamy enter i za chwilkę powinno się zrobić.
    4. Gotowe mamy par!

Program działa również w trybie ARGC&ARGV, przykład:
PARim.exe <nazwa folderu wejściowego> <nazwa pliku wyjściowego.par>

Szybki Export
-------------
Aby w szybki sposób dekompilować plik .par należy korzystać z EXPORT.ps1 lub EXPORT.bat.
W celu modyfikacji argumentów/konfiguracji należy zedytować plik .bat/.ps1 przez notatnik.

PRZYKŁAD BAT: 
PARex.exe <nazwapliku.par> <nazwa folderu wyjściowego>

PRZYKŁAD .ps1: 
.\PARex.exe .\<nazwapliku.par> .\<nazwa folderu wyjściowego>

Szybki Import
-------------
Aby w szybki sposób kompilować folder z .cpp należy korzystać z IMPORT.ps1 lub IMPORT.bat.
W celu modyfikacji argumentów/konfiguracji należy zedytować plik .bat/.ps1 przez notatnik.

PRZYKŁAD BAT: 
PARim.exe <nazwa folderu wejściowego> <nazwa pliku wyjściowego.par>

PRZYKŁAD .ps1: 
.\PARim.exe .\<nazwa folderu wejściowego> .\<nazwa pliku wyjściowego.par>