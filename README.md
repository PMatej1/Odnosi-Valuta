# Valutni Odnosi

Ovaj projekat implementira strukturu podataka za čuvanje i upravljanje valutnim odnosima. Podržava dodavanje novih tečajeva i dohvaćanje tečajeva između bilo koje dvije valute. Ako direktan tečaj nije dostupan, izračunava tečaj koristeći postojeće odnose. Struktura osigurava konzistentnost tečajeva i podržava dvosmjerne upite.

## Karakteristike

- **Dodavanje Tečaja**: Omogućava dodavanje novih valutnih odnosa.
- **Dohvaćanje Tečaja**: Dohvaća tečaj između dvije valute, čak i ako direktan tečaj nije dostupan, izračunavajući tečaj koristeći postojeće odnose.
- **Konzistentnost**: Osigurava konzistentnost tečajeva.
- **Dvosmjerni Upiti**: Podržava dohvaćanje tečajeva u oba smjera.

## Primjer

Dati odnosi:
- {EUR, BAM, 1.95}
- {USD, EUR, 0.9}

Upit za tečaj između USD i BAM će vratiti 1.755.

## Pregled Strukture

Rješenje se bazira na razbijanju valuta na disjunktne skupove. Prilikom dodavanja svakog odnosa, algoritam upravlja povezanim skupovima prema različitim scenarijima. Završni izračun se temelji na pronalaženju zajedničkog korijena i računanja tečaja koristeći puteve do korijena. Ako valute nemaju zajednički korijen, rezultat je nula.

## Korištenje

### Dodavanje Tečaja

Za dodavanje novog tečaja između dvije valute:

```cpp
Valuta valutni_odnosi;
valutni_odnosi.dodajOdnos('EUR', 'BAM', 1.95);
valutni_odnosi.dodajOdnos('USD', 'EUR', 0.9);
```
### Dohvaćanje Tečaja

Za dohvaćanje tečaja između dvije valute:

```cpp
double tecaj=valutni_odnosi.transfer2("BAM", "USD");
cout<<tecaj;
```
### Detalji Implementacije

## Struktura Podataka

Struktura podataka je graf gdje svaki čvor predstavlja valutu, a grane predstavljaju tečajeve. Osigurava da sve valute u istom povezanom komponentu mogu biti konvertirane jedna u drugu

### Konzistentnost

Algoritam održava konzistentnost osiguravajući da su svi izračunati tečajevi koherentni. Koristi strukturu union-find s kompresijom puta za efikasno upravljanje povezanim komponentama valuta.

### Dvosmjerni Odnosi

Budući da su tečajevi dvosmjerni, struktura podataka čuva i dohvaća tečajeve u oba smjera. Na primjer, ako je poznat tečaj iz EUR u BAM, tečaj iz BAM u EUR je također implicitno poznat.

### Rukovanje Nedostajućim Podacima
Ako nema dovoljno podataka za izračunavanje traženog tečaja, metoda vraća nulu.

### Autori
Matej Panić



