
#include "SET.h"
#include <iostream>
#include<cassert>ss

using namespace std;

void SETTests()
{
    SET S;
    S.insertie(3);
    S.insertie(1);
    S.insertie(1);
    S.insertie(2);


    // verifica metoda nrElem() care returnează cardinalul mulțimii 

    assert(S.nrElem() == 4);

    // verifica metoda care transforma o lista intr-un set prin eliminarea duplicatelor

    S.makeSET();

    assert(S.nrElem() == 3);
    assert(S[0] == 3);
    assert(S[1] == 1);
    assert(S[2] == 2);

    // verifica metoda care inserează un element pe o anumită poziție 

    int len = S.nrElem();
    S.insertAt(0, len); // inseram 0 pe ultima pozitie
    assert(S[len] == 0);

    // verifica metoda care șterge elementul de pe o anumită poziție 

    S.stergere(2);
    assert(S[2] == 0);

    // verifica metoda care returnează suma tuturor elementelor din set

    assert(S.Suma() == 4);

    // verifica metodele care returnează un set cu numere pare și unul cu numere impare pe baza setului inițial 

    SET S_pare, S_impare;
    S.getEvenNumbers(S_pare);
    S.getOddNumbers(S_impare);

    assert(S_pare[0] == 0);
    assert(S_pare.nrElem() == 1);

    assert(S_impare[0] == 3);
    assert(S_impare[1] == 1);
    assert(S_impare.nrElem() == 2);

    // verificam supraincarcarea operatorului * pentru inmultirea cu un scalar 
    // reamintesc ca setul este : 3, 1, 0

    S * 3;

    assert(S[0] == 9);
    assert(S[1] == 3);
    assert(S[2] == 0);

    //verificam operatorii <,> care compara in functie de cardinalul fiecarui set

    SET S1, S2;

    S1.insertie(1);
    S1.insertie(2);


    S2.insertie(1);


    assert(S1 > S2);
    assert(S2 < S1);

    // verificam metoda de cautare a unei valori in set

    assert(S1.cautare(1) == true);
    assert(S1.cautare(50) == false);



}

int main()
{
    SETTests();
    cout << endl << "Testele au trecut" << endl;

    SET s;
    int val, poz, scalar;

    cout << "Introdu numarul de elemente al listei si lista pentru a fi afisat set-ul:" << endl << endl;

    cin >> s;

    s.makeSET();


    cout << "Setul s este : " << s << " iar acesta va fi folosit pe parcursul programului." << endl << endl;


    cout << "Introdu o valoare si verifica daca aceasta se afla in setul s" << endl;
    cout << "Valoarea de cautat = ";
    cin >> val;

    if (s.cautare(val))
        cout << "Valoarea " << val << " se afla in setul s" << endl;
    else
        cout << "Valoarea " << val << " nu se afla in setul s" << endl;

    cout << endl << "Acceseaza elementul de pe o pozitie data" << endl;
    cout << "Introdu pozitia : ";
    cin >> poz;
    cout << endl << "Elementul de pe pozitia " << poz << " este : " << s[poz] << endl << endl;

    cout << "Cardinalul setului ( numarul elementelor din multime ) este : " << s.nrElem() << endl << endl;

    cout << "Suma elementelor din set este : " << s.Suma() << endl << endl;

    SET s_pare;
    s.getEvenNumbers(s_pare);
    cout << "Elementele pare din set sunt : " << s_pare << endl;

    SET s_impare;
    s.getOddNumbers(s_impare);
    cout << "Elementele impare din set sunt : " << s_impare << endl << endl;

    cout << "Inmultirea setului cu un scalar" << endl;
    cout << "Introdu scalarul : ";
    cin >> scalar;
    cout << "Setul s a devenit acum: ";
    s* scalar;
    cout << endl << endl;

    SET s1, s2;
    cout << "Introduceti 2 seturi pentru a realiza urmatoarele operatii" << endl << "1. COMPARATIE" << endl << "2. REUNIUNE (fara duplicate)" << endl;
    cout << endl << "Set 1:" << endl;
    cin >> s1;
    cout << endl << "Set 2:" << endl;
    cin >> s2;

    cout << endl << "Comparatie: " << endl;

    if (s1 > s2)
        cout << "s1 are mai multe elemente ca s2 => s1 > s2" << endl;
    else if (s1 < s2)
    {
        cout << "s2 are mai multe elemente ca s1 => s2 > s1" << endl;
    }
    else
        cout << "s1 are acelasi cardinal cu s2 => s1 = s2" << endl;

    cout << endl << "Reuniunea dintre cele doua seturi este : " << s1 + s2 << endl;

    return 0;
}

