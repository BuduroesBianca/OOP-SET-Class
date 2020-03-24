#include "node.h"

using namespace std;

node::node() : info(0), next(NULL) {}

node::node(int i, node* n) : info(i), next(n) {}

void node::setInfo(int i)
{
	info = i;
}
void node::setNext(node* n)
{
	next = n;
}
int node::getInfo()
{
	return info;
}
node* node::getNext()
{
	return next;
}
