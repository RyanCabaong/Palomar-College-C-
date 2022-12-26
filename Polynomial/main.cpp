#include <iostream>
#include <string>
#include <vector>
#include "polynomial.h"
#include "Term.h"

using namespace std;
int main()
{
	//create polynomials
	//prev polynomial *
	polynomial p = polynomial(new Term(4,6));
	p.add(new Term(12,2));
	p.add(new Term(3,1));
	//p.print();
	//polynomial p(new Term(12,2));
	//p->print();
	polynomial q = polynomial(new Term(3,3));
	q.add(new Term(2,2));
	//q.print();
	polynomial m = polynomial(new Term(0,0));
	p.set();
	q.set();
	m.multiply(&p,&q);
	m.print();//(12,9) ,(8,8) ,(36,5) ,(24,4), (9,3) ,(6,2)
	//m->print();


}
