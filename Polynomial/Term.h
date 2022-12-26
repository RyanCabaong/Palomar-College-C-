#ifndef TERM_H
#define TERM_H
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Term
{
public:  // member functions
	Term();
	Term(int coefficient, int exp);
     void SetTerm (int coefficient, int exp);
     Term* getnext();   // returns data member next
     void setnext(Term* n);
     Term* getprev();
     void setprev(Term* n);
     int getexp();
     void setexp(int n);
     int getcoe();
     void setcoe(int n);

private: // data members
     int coeff;
     int exponent;
     Term* next;
     Term* prev;
};
#endif
