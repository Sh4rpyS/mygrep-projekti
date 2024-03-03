# Mygrep-projekti
5G00ET60 kurssin mygrep projektityö

Tarkoituksena oli ohjelmoida pienikokoinen ohjelma, joka pyrkii olemaan samanlainen kuin LINUX järjestelmän GREP ohjelma.

# Käyttöliittymä
Käynnistäessä ohjelman komentorivillä voit valita miten ohjelma toimii:
- Jos et laita mitään, ohjelma käynnistyy ns. "Standalone" tilassa, tähän tilaan ei tarvitse tiedostoa.
    * Tässä tilassa voi käyttää vapaaehtoisesti asetusta "i", joista kerrotaan enemmän alempana.
- Jos binäärin lisäksi ohjelmalle antaa avain sanan ja tekstitiedoston formaatissa "./mygrep {avainsana} {tiedoston nimi}", niin ohjelma etsii tiedodstosta rivejä, joista avainsana löytyy.
- Halutessaan voi lisätä binäärin ja avainsanan väliin erilaisia asetuksia formaatissa "./mygrep {asetukset} {avainsana} {tiedoston nimi}", asetuksista enemmän alempana.

# Erilaiset asetukset
- Asetukset annetaan tekstinä joka alkaa "-o", eli esimerkiksi "-olr", eri asetukset alla:
    * l = Line numbering, ohjelma antaa rivinumeron löytyneille riveille, joista avainsana löytyy.
    * o = Occurences, ohjelma ilmoittaa kuinka monta kertaa avainsana löytyi.
    * i = Ignore upper/lowercase letters, ohjelma etsii avainsanaa huolimatta siitä, onko sanoissa pieniä vai isoja alkukirjaimia.
    * r = Reverse search, ohjelma etsii millä rivillä ei ole kyseistä avainsanaa.

# Ohjelman kääntäminen
Ohjelma on käännetty staattieseti GCC g++ kääntäjällä (Versio: 13.1.0) ja se käyttää c++20 standardia. Ohjelman kääntökomento:
- g++ -o mygrep.exe src/*.cpp -Iinclude -static -static-libgcc -std=c++20