#include "polynomial.h"
#include "Term.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;
polynomial::polynomial(){
	this->head = NULL;
	this->tail = NULL;
}
polynomial::polynomial(Term* t){
	this->head = t;
	this->tail = t;
}
polynomial::polynomial(polynomial* p){
	this->head = p->gethead();
	this->tail = p->gettail();
}
polynomial::polynomial(const polynomial& p){
	polynomial t = p;
	head = t.gethead();
	tail = t.gettail();
}
Term* polynomial::gethead(){
	return head;
}
Term* polynomial::gettail(){
	return tail;
}
void polynomial::sethead(Term* t){
	head = t;
}
void polynomial::settail(Term* t){
	tail = t;
}
void polynomial::multiply(const polynomial& p,const polynomial& q){
	//determine sizes of both polynomials to find # of terms in result
//	int sizep = p->size();
//	int sizeq = q->size();
//	p.set();
//	q.set();
//	polynomial r = new polynomial();
//	r = p;
//	polynomial l = new polynomial();
//	l = q;
	Term* templhs = p.head;//traversing polynomial terms left hand side
	while(templhs != NULL){
		Term* temprhs = q.head;
		this->set();
		while(temprhs != NULL){
			//traverse left to right, lhs is outer loop and rhs is inner loop
			//with set u can reliably use head and tail
			//free to multiply adding terms to new polynomial
			int coe = temprhs->getcoe() * templhs->getcoe();
			int exp = temprhs->getexp() + templhs->getexp();
			this->add(new Term(coe, exp));

			//end with going to next term
			temprhs = temprhs->getnext();
		}
	templhs = templhs->getnext();
	}
	this->set();
	//return this;
}
int polynomial::size(){
	if(this->head != NULL){
		int size = 0;
		Term* temp = this->head;
		while(temp != NULL){
			size++;
			temp = temp->getnext();
		}
		return size;
	}
	else{
		return 0;
	}
}
//create new methods that need to
//RESET TAIL AND HEAD TO CORRECT SPOTS
void polynomial::set(){
	//set head
	Term* temp = this->tail;
	while(temp != NULL){
		if(temp->getprev() == NULL){
			this->sethead(temp);
			break;
		}
		temp = temp->getprev();
	}
	//set tail
	temp = this->head;
	while(temp != NULL){
		if(temp->getnext() == NULL){
			this->settail(temp);
			break;
		}
		temp = temp->getnext();
	}
}
void polynomial::add(Term* t){//e.g. new Term(10,2)
	this->set();
	bool expmatch = false;
	if(this->head != NULL){
		Term* temp = this->head;//traversing forward (AKA, great to least, head to tail)
		while (temp != NULL){//traverse exponents in the polynomial to find a matching expo to add coefficients
			if(t->getexp() == temp->getexp()){
				//if selected term's exp = to temp exp than
				temp->setcoe(t->getcoe() + temp->getcoe());
				expmatch = true;
				this->set();
				break;
			}
			else{
				temp = temp->getnext();
			}
		}
		//if term t does not match exponents then traverse list (tail to head, least to great)
		//if (t exponent > current term exponent) then {place t in list}
		//else {continue on list}
		if(expmatch == false){
			if(this->tail != NULL){
				this->set();
				temp = this->tail;
				while(temp != NULL){//what if the t is the biggest exponent?
					if(t->getexp() < temp->getexp()){
						//take any tail end term to assign to t and assign t's next term
						if(temp->getnext() != NULL){
							temp->getnext()->setprev(t);
							t->setnext(temp->getnext());
							//this->set();//places tail and head back
						}
						t->setprev(temp);
						temp->setnext(t);
						this->set();
						break;
					}
					//if t is the end or highest expo
					else if(temp->getprev() == NULL){//place as head
						t->setnext(temp);
						temp->setprev(t);
						this->set();//places tail and head back
						break;
					}
					else{
						temp = temp->getnext();
					}

				}
			}
		}
	}
}


void polynomial::print() //const
{
	this->set();
    Term* temp = this->head;
    while(temp != NULL){
    	cout<<"(" << temp->getcoe() << "," << temp->getexp() << ") ,";
    	temp = temp->getnext();
    }
}
