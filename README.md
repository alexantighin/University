# University

*Read this in other languages: [English](README.en.md), [Romanian](README.md).*

Proiectul are la bază limbajul de programare C++ și include câteva concepte de bază ale Programării Orientată pe Obiecte precum, abstractizarea, incapsularea, moștenirea și polimorfismul. Aplicația conține o clasă de bază [Persoana](#Persoana) și două derivate din ea, [Student](#Student) și [Profesor](#Profesor). Clasa [PersoaneUniversitate](#PersoaneUniversitate) conține instanțe ale celor două clase derivate, iar prin intermediul clasei [Meniu](#Meniu) se poate accesa interfața proiectului prin intermediul consolei. În cele două documente cu extensia .txt (Studenti și Profesori) se găsesc informațiile inițiale cu privire la cele două tipuri de persoane, ca mai apoi prin intermediul consolei să se poată folosi metode de Afișare, Adăugare și Ștergere.

## Interfața

<p align="center">
  <img src="https://i.ibb.co/xDHrDV8/Screenshot-2.png">
</p>

<p align="center">
  <img src="https://i.ibb.co/LYnvDpW/Screenshot-3.png">
</p>

<p align="center">
  <img src="https://i.ibb.co/DQRnwqR/Screenshot-4.png">
</p>

## Clase
  - [Data](#Data)
  - [Persoana](#Persoana)
  - [Student](#Student)
  - [Profesor](#Profesor)
  - PersoaneUniversitate
  - Meniu
  
  #### Data
  Aceasta clasa contine 3 membri privati de tip integer in care se stocheaza ziua, luna si anul dintr-o data. Se poate crea un obiect de tip Data prin intermediul unuia dintre cei 3 constructori (vid, cu parametri, de copiere). Contine metode de citire si afisare a informatiilor necesare, dar pentru o usurinta in plus operatorul >> este supraincarcat pentru citire si opearatorul << pentru afisare.
  #### Persoana
  Aceasta este clasa de baza care contine membri protected pentru a fi ulterior mosteniti de clasele derivate. Constructorii nu sunt de tip publici pentru a impiedica crearea unui obiect de tip Persoana fara ca acesta sa nu fie Student sau Profesor. In cazul datelor de tip char* s-au folosit operatorii new si delete pentru a aloca spatiu necesar in memorie si respectiv pentru a dealoca in momentul in care sunt apelat deconstructorul.
  #### Student
  Aceasta clasa foloste conceptul de mostenire, ea fiind derivata din clasa Persoana, preluand toate informatiile acesteia, dar avand si ea la randul ei 2 membri unici, numarMatricol si programStudiu.
  
