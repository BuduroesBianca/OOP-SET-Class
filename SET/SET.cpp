#include "SET.h"
#include<iostream>
#include<fstream>
#include<exception>
using namespace std;

SET::SET() : length(0), start(NULL), end(NULL) {} //constructor fara parametri

SET::SET(node* n)  //constructor cu parametri
{
    this->start = n;
    this->end = n;
}

SET::SET(const SET& S) //constructor de copiere
{
    node* p = S.start;
    start = new node(p->getInfo(), NULL);
    length = 1;
    node* q = start;
    p = p->getNext();

    while (p->getNext() != NULL) {
        node* aux = new node(p->getInfo(), NULL);
        q->setNext(aux);
        q = q->getNext();
        length++;
        p = p->getNext();
    }
    end = new node(p->getInfo(), NULL);
    q->setNext(end);
    length++;
}

SET::~SET() //destructor
{
    node* p = start;
    while (p != NULL) {
        node* q = p;
        p = p->getNext();
        delete q;
    }
    start = end = NULL;
    length = 0;
}

node* SET::getStart() const
{
    return this->start;
}

int SET::getLength() const    //returnarea lungimii set-ului
{
    return this->length;
}

void SET::makeSET() // transforma lista intr-un set
{
    if (length >= 2) 
    {
        int i = 0;
        node* aux = this->start;
        while (this->nr_aparitii(aux->info) > 1) 
        {
            stergere(i);
            aux = this->start;
        }
        i++;
        while (i < length) {
            if (aux->next != NULL && this->nr_aparitii(aux->next->info) > 1)
                stergere(i);
            else 
            {
                aux = aux->next;
                i++;
            }
        }
    }
}


void SET::insertie(int x)
{
    if (length == 0) {
        start = end = new node(x, NULL);
        length = 1;
    }
    else {
        end->setNext(new node(x, NULL));
        end = end->getNext();
        length++;
    }
}


void SET::insertAt(int x, int i)  // metoda care insereaza elementul x pe pozitia i
{
    if (i > length) {
        insertie(x);
    }
    else if (i <= 0) {
        node* p = new node(x, start);
        start = p;
        length += 1;
    }
    else {
        node* p = start;
        for (int j = 0; j < i; j++) {
            p = p->getNext();
        }
        node* q = new node(x, p);
        node* aux = start;
        for (int j = 0; j < i - 1; ++j) aux = aux->getNext();
        aux->setNext(q);
        length += 1;
    }
}

void SET::stergere(int i) // metoda care sterge elementul de pe pozitia i
{
    if (i < 0 || i >= length) {
        return;
    }
    node* p = start;
    if (i == 0) {
        if (length == 1 || length == 0) {
            end = start = NULL;
        }
        else {
            start = start->getNext();
            delete p;
        }
    }
    else {
        for (int j = i; j > 1; j--) {
            p = p->getNext();
        }
        node* o = p->getNext();
        p->setNext(o->getNext());
        delete o;
    }
    length--;
}

bool SET::cautare(int x)   //cautarea unei valori in set
{
    node* aux = this->start;
    int gasit = 0;
    int i = 0;
    if (this->length == 0)
        return false;
    while (i < length && gasit == 0)
    {
        if (aux->info == x)
            gasit = 1;
        else
        {
            aux = aux->next;
            i++;
        }
    }
    if (gasit)
        return true;
    else return false;
}

int SET::Suma()   //suma elementelor din set
{
    node* aux = start; int suma = 0, i = 0;
    while (i < length)
    {
        suma += aux->info;
        aux = aux->next;
        i++;
    }
    return suma;
}

void SET::getEvenNumbers(SET& S)
{
    node* aux = start;
    int i = 0;
    while (i < length)
    {
        if (aux->info % 2 == 0)
        {
            S.insertAt(aux->info, length - 1);
        }
        aux = aux->next;
        i++;
    }
    S.makeSET();
}

void SET::getOddNumbers(SET& S)
{
    node* aux = start;
    int i = 0;
    while (i < length)
    {
        if (aux->info % 2 != 0)
        {
            S.insertAt(aux->info, length - 1);
        }
        aux = aux->next;
        i++;
    }
    S.makeSET();
}

int SET::nrElem()   //determinarea numarului de elemente din set
{
    return this->length;
}

ostream& operator << (ostream& cout, const SET& S)  //supraincarcare <<
{
    if (S.length > 0)
    {
        node* aux = S.start; int i = 1;
        while (i <= S.length)
        {
            cout << aux->getInfo() << ' ';
            aux = aux->getNext();
            i++;
        }
    }
    else cout << "SET vid";
    return cout;

}

istream& operator >> (istream& in, SET& S)    //supraincarcare operator >>
{
    int lungime, i, x;
    cout << "Numarul de elemente = ";
    in >> lungime;
    cout << "Elemente = ";
    for (i = 0; i < lungime; i++)
    {
        in >> x;
        S.insertAt(x, lungime - 1);
    }
    return in;

}

SET& SET::operator = (const SET& S) //supraincarcare operator =
{
    if (this->getLength() != 0)
    {
        this->~SET();
        node* aux = S.start;
        this->start = new node(aux->info, aux->next);
        node* p = this->start;
        aux = aux->next;
        while (aux->next) {
            p->next = new node(aux->info, aux->next);
            p = p->next;
            aux = aux->next;
        }
        this->end = new node(aux->info, NULL);
        this->length = S.length;
    }
    else
    {
        node* aux = S.start;
        this->start = new node(aux->info, aux->next);
        node* p = this->start;
        aux = aux->next;
        while (aux->next) {
            p->next = new node(aux->info, aux->next);
            p = p->next;
            aux = aux->next;
        }
        this->end = new node(aux->info, NULL);
        this->length = S.length;
    }
    return *this;
}

int SET::operator [] (int poz)  //supraincarcare operator []
{
    if (poz > this->length || poz < 0)
    {
        throw std::out_of_range("Index gresit");
    }
    else
    {
        node* aux = start;
        int i = 0;
        while (i != poz)
        {
            aux = aux->next;
            i++;
        }
        return aux->info;
    }

}

void SET::operator * (int scalar)  //supraincarcare operator *
{
    node* aux = new node;
    int i = 0;
    aux = start;
    while (i < length)
    {
        aux->info *= scalar;
        aux = aux->next;
        i++;
    }
    cout << *this;
}

int SET::operator < (SET& S)  //supraincarcare operator <
{
    int x, y;
    x = this->nrElem();
    y = S.nrElem();
    if (x < y)
        return 1;
    else
        return 0;
}

int SET::operator > (SET& S)  //supraincarcare operator >
{
    int x, y;
    x = this->nrElem();
    y = S.nrElem();
    if (x > y)
        return 1;
    else
        return 0;
}

SET SET::operator + (const SET& S)
{
    if ((S.length == 0 && length == 0) || (S.length > 0 && length == 0))
        return S;
    if (S.length == 0 && length > 0)
        return *this;

    SET sAux(*this);
    node* aux = this->start;
    for (int i = 0; i < length; i++)
    {
        sAux.insertie(aux->getInfo());
        aux = aux->next;
    }

    aux = S.start;
    for (int i = 0; i < S.length; i++)
    {
        sAux.insertie(aux->getInfo());
        aux = aux->next;
    }

    sAux.makeSET();
    return sAux;
}


