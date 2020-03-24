#pragma once
#include<iostream>

using namespace std;

class node {
	int info;
	node* next;
public:
	node();
	node(int, node*);
	void setInfo(int);
	void setNext(node*);
	int getInfo();
	node* getNext();
	friend class SET;
	// nu este nevoie de destructor
};
