#include <vector>
#include <string>
#include <iostream>
#include "Term.h"
class polynomial
{
public:
	Term* head;
	Term* tail;
    char var = 'x';

    polynomial();
    polynomial(Term* t);
    polynomial(polynomial* p);
    polynomial(const polynomial& p);
    Term* gethead();
    Term* gettail();
    void sethead(Term* t);
    void settail(Term* t);
    void multiply(const polynomial& p,const polynomial& q);
    int size();
    void set();
    void add(Term* t);

    void print();

private:
};

