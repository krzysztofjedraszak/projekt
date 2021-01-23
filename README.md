
# CANDY CRUSH SAGA

![chrome_NmBlf6qEnb](https://user-images.githubusercontent.com/65609128/105609970-12bc7c80-5dad-11eb-8612-c127becc305d.jpg)

Celem gracza jest zdobycie jak największej ilości punktów, gracz ma na to 120 s. Sterowanie będzie się odbywać za pomocą myszki. Kliknięcie zaznacza cukierek, następne kliknięcie usuwa zaznaczenia jeżeli jest to ten sam cukierek, natomiast jeśli inny następuje zamiana. Cukierki można przesuwać o dowolną liczbę pól. Dla 3 cukierków w linii będą się usuwać 3 cukierki, dla czterech 4, a dla pięciu 5. Punkty dodawane to odpowiednio 30pkt, 40 pkt, 50pkt. W grze na bieżąco wyświetlany jest aktualny wynik, pozostały czas oraz najlepszy wynik. Po upływie czasu gra się kończy.

### Filmik prezentujący grę
https://youtu.be/bnWJhQ5TPnI

## KLASY:


### Abstract
- zaznacz() - zwraca prawdę jeśli pozycja myszki zawiera sie w obszarze danego cukierka

### Aktualny Wynik

### Cukierek
- gettyp() - pobiera wartość typu cukierka
- get_jest_klikniety() - zwraca prawdę jeśli cukierek jest kliknięty
- set_jest_klikniety() - ustawienie kliknięcia cukierka

### Element Sceny

Klasa ta jest "mózgiem" gry, odpowiada za logikę i mechanizmy
- porownanie() - porównuje wynik aktualny i najlepszy
- match() - sprawdza czy cukierki są w linii
- usun() - usuwa cukierki w linii, nadaje punkty
- get_zmiana() - zwraca prawdę jeśli nastapiła zmiana wyniku
- set_zmiana() - ustawia wartość zmiany wyniku
- get_punkty() - zwraca ilość aktualnych punktów
- set_punkty() - ustawia ilość aktualnych punktów
- zrob() - zliczanie kliknięć myszką, pokazywanie oraz usuwanie znacznika, zamiana cukierków
- match_i_usun() - sprawdzenie dopasowania cukierków i usunięcie ich
- wyswietl_naj_wynik() - wyświetla najlepszy wynik
- wczytaj_naj_wynik() - wczytuje najlepszy wynik
- zapisz_naj_wynik() - zapisuje najlepszy wynik
- odliczanie() - realizuje odliczanie zegara i wyświetlanie na ekranie
- wyswietl_aktualny() - wyświetla aktualny wynik gry
- jesli_zmiana_wyniku() - jeżeli następuje zmiana wyniku wyświetla go na ekranie, jeżeli wynik aktualny jest większy od najlepszego zapisuje wynik aktualny do pliku .txt
- pokaz_wszystko() - wyświetlanie obiektów i okna gry

### Najlepszy Wynik
 
### Plansza

### Zegar

### Znacznik



### Makieta:

![makieta](https://user-images.githubusercontent.com/65609128/82364929-3ce4c000-9a10-11ea-842a-516c5de51f6f.png)
