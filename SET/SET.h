#pragma once
#include "node.h"
#include<iostream>
#include<fstream>
using namespace std;

class SET
{
    node* start;
    node* end;
    int length;

    int nr_aparitii(int x) // metoda care numara aparitiile unei valori in set
    {
        int i = 0, contor = 0;
        node* aux = start;
        while (i < length)
        {
            if (aux->info == x)
                contor++;
            aux = aux->next;
            i++;
        }
        return contor;
    }

public:

    SET();
    SET(node*);
    SET(const SET& s);
    ~SET();
    node* getStart() const;
    int getLength() const;

    void makeSET();
    void insertAt(int, int);
    void stergere(int);
    bool cautare(int);
    int Suma();
    void getEvenNumbers(SET&);
    void getOddNumbers(SET&);
    int nrElem();
    void insertie(int);

    friend ostream& operator << (ostream&, const SET&);
    friend istream& operator >> (istream&, SET&);
    SET operator + (const SET&);
    int operator > (SET&);
    int operator < (SET&);
    int operator [] (int);
    void operator * (int);
    SET& operator = (const SET&);

};