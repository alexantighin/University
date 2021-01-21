# University

*Read this in other languages: [English](README.en.md), [Romanian](README.md).*

Proiectul are la bază limbajul de programare C++ și include câteva concepte de bază ale Programării Orientată pe Obiecte precum, abstractizarea, incapsularea, moștenirea și polimorfismul. Aplicația conține o clasă de bază [Persoana](#Persoana) și două derivate din ea, [Student](#Student) și [Profesor](#Profesor). Clasa [PersoaneUniversitate](#PersoaneUniversitate) conține instanțe ale celor două clase derivate, iar prin intermediul clasei [Meniu](#Meniu) se poate accesa interfața proiectului prin intermediul consolei. În cele două documente cu extensia .txt ([Studenti](Studenti.txt) și [Profesori](Profesori.txt)) se găsesc informațiile inițiale cu privire la cele două tipuri de persoane, ca mai apoi prin intermediul consolei să se poată folosi metode de Afișare, Adăugare și Ștergere.

## Interfața

<p align="center">
  <img src="https://i.ibb.co/HPCw9tm/Screenshot-3.png">
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
  - [PersoaneUniversitate](#PersoaneUniversitate)
  - [Meniu](#Meniu)
  
  #### Data
  Această clasă conține trei membri privați de tip integer în care se stochează ziua, luna și anul dintr-o dată. Se poate crea un obiect de tip [Data](Data.h) prin intermediul unuia dintre cei trei constructori (vid, cu parametri și de copiere). Conține metode de citire și afisare a informațiilor necesare, dar pentru o ușurință în plus, operatorul >> este supraîncărcat pentru citire și opearatorul << pentru afișare.
  #### Persoana
  Aceasta este clasa de baza care contine membri protected pentru a fi ulterior mosteniti de clasele derivate. Prin intermediul abstractizarii constructorii nu sunt de tip publici pentru a impiedica crearea unui obiect de tip Persoana fara ca acesta sa nu fie Student sau Profesor. In cazul datelor de tip char* s-au folosit operatorii new si delete pentru a aloca spatiu necesar in memorie si respectiv pentru a dealoca in momentul in care sunt apelat deconstructorul.
  #### Student
  Aceasta clasa foloste conceptul de mostenire, ea fiind derivata din clasa Persoana, preluand toate informatiile acesteia, dar avand si ea la randul ei 2 membri unici, numarMatricol si programStudiu. Cu ajutorul polimorfismului, unul dintre cele mai importante principii ale programarii de tip OOP, se pot folosi aceleasi denumiri pentru diferite scopuri. Aceasta clasa utilizeaza acelasi nume pentru constructori, chiar daca au argumente de tipuri diferite, dar si supraincarca operatorii =, >> si <<.
  #### Profesor
  Ca si celelalte clase si aceasta foloseste principiul incapsularii, ce consta in combinarea membrilor de tip data cu cei de tip functii sau metode intr-o singura unitate. Precum clasa Student si clasa Profesor mosteneste clasa de baza Persoana, avand si ea 2 membri unici, unul dintre ei fiind de tip Data.
  #### PersoaneUniversitate
  Aceasta clasa contine instante ale claselor Student si Profesor, dar si 2 membri ce contorizeaza numarul de persoane.
  #### Meniu
  Cu ajutorul aceste clase se poate accesa interfata aplicatiei.
  
  
  
