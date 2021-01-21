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
  - [Data](Data.h)
  - [Persoana](Persoana.h)
  - [Student](Student.h)
  - [Profesor](Profesor.h)
  - [PersoaneUniversitate](PersoaneUniversitate.h)
  - [Meniu](Meniu.h)
  
  #### Data
  Această clasă conține trei membri privați de tip integer în care se stochează ziua, luna și anul dintr-o dată. Se poate crea un obiect de tip [Data](Data.h) prin intermediul unuia dintre cei trei constructori (vid, cu parametri și de copiere). Conține metode de citire și afisare a informațiilor necesare, dar pentru o ușurință în plus, operatorul >> este supraîncărcat pentru citire și opearatorul << pentru afișare.
  #### Persoana
  Aceasta este clasa de bază care conține membrii protected pentru a fi ulterior moșteniți de clasele derivate. Prin intermediul abstractizării constructorii nu sunt de tip publici pentru a împiedica crearea unui obiect de tip [Persoana](Persoana.h) fără ca acesta sa nu fie [Student](Student.h) sau [Profesor](Profesor.h). În cazul datelor de tip char* s-au folosit operatorii new si delete pentru a aloca spatiu necesar in memorie si respectiv pentru a dealoca în momentul în care este apelat deconstructorul.
  #### Student
  Această clasă folosește conceptul de moștenire, ea fiind derivată din clasa [Persoana](Persoana.h), preluând toate informațiile acesteia, dar având și ea la randul ei doi membri unici, numarMatricol și programStudiu. Cu ajutorul polimorfismului, unul dintre cele mai importante principii ale programarii de tip OOP, se pot folosi aceleași denumiri pentru diferite scopuri. Această clasă utilizează același nume pentru constructori, chiar dacă au argumente de tipuri diferite, dar și supraîncarcă operatorii =, >> și <<.
  #### Profesor
  Ca și celelalte clase și aceasta folosește principiul încapsulării, ce constă în combinarea membrilor de tip data cu cei de tip funcții sau metode într-o singură unitate. Precum clasa [Student](Student.h) si clasa [Profesor](Profesor.h) moștenește clasa de baza [Persoana](Persoana.h), având și ea doi membri unici, unul dintre ei fiind de tip [Data](Data.h).
  #### PersoaneUniversitate
  Această clasă conține instanțe ale claselor [Student](Student.h) si [Profesor](Profesor.h), dar și doi membri ce contorizează numărul de persoane.
  #### Meniu
  Cu ajutorul acestei clase se poate accesa interfața aplicatiei. 
  
