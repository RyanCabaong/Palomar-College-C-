#include <iostream>
#include "Term.h"
//poly methods

	Term::Term(){
		coeff = 0;
		exponent = 0;
		next = NULL;
		prev = NULL;
		}
	Term::Term(int coefficient, int exp){
		coeff = coefficient;
		exponent = exp;
		next = NULL;
		prev = NULL;
	}
	void Term::SetTerm (int coefficient, int exp){
		coeff = coefficient;
		exponent = exp;
	}
	Term* Term::getnext(){
		// returns data member next
		return next;
	}
	void Term::setnext(Term* n){
		// returns data member next
		next = n;
	}
	Term* Term::getprev(){
		// returns data member next
		return prev;
	}
	void Term::setprev(Term* n){
		// returns data member next
		prev = n;
	}
	int Term::getexp(){
		return exponent;
	}
	void Term::setexp(int n){
		exponent = n;
	}
	int Term::getcoe(){
		return coeff;
	}
	void Term::setcoe(int n){
		coeff = n;
	}
	//     double coeff;
	//     int exponent;
	//     Term* next;
	//     Term* prev;

