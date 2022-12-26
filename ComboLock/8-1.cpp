#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
/**
   A bank account whose balance can be changed by deposits and withdrawals.
 */
class BankAccount
{
public:
	/**
      Constructs a bank account with zero balance.
	 */
	BankAccount();
	/**
      Constructs a bank account with a given balance.
      @param initial_balance the initial balance
	 */
	BankAccount(double initial_balance);
	/**
      Makes a deposit into this account.
      @param amount the amount of the deposit
	 */
	void deposit(double amount);
	/**
      Makes a withdrawal from this account, or charges a penalty if
      sufficient funds are not available.
      @param amount the amount of the withdrawal
	 */
	void withdraw(double amount);
	/**
      Adds interest to this account.
      @param rate the interest rate in percent
	 */
	void add_interest(double rate);
	/**
      Gets the current balance of this bank account.
      @return the current balance
	 */
	double get_balance() const;
private:
	double balance;
};
BankAccount::BankAccount()
{
	balance = 0;
}
BankAccount::BankAccount(double initial_balance)
{
	balance = initial_balance;
}
void BankAccount::deposit(double amount)
{
	balance = balance + amount;
}
void BankAccount::withdraw(double amount)
{
	const double PENALTY = 10;
	if (amount > balance)
	{
		balance = balance - PENALTY;
		balance = balance - amount;
	}
	else
	{
		balance = balance - amount;
	}
}
void BankAccount::add_interest(double rate)
{
	double amount = balance * rate / 100;
	deposit(amount);
}
double BankAccount::get_balance() const
{
	return balance;
}
class Portfolio {//has checkings and savings
public:
	Portfolio(double);
	Portfolio();
	void deposit(double amount, string a);
	void withdraw(double amount, string a);
	void transfer(double amount, string a);
	void print_balances();
	//two new methods to return savings and checking balances
	double checkingb();
	double savingb();
private:
	BankAccount checking = BankAccount();
	BankAccount savings = BankAccount();
	//implement transfer method ("C") money taken from "C" to "S"
};
Portfolio::Portfolio(double inital){
	savings.deposit(inital);
}
Portfolio::Portfolio(){

}
void Portfolio::deposit(double amount, string a)
{
	//if c then deposit amount to c
	//if s then deposit amount to s
	if(a.compare("S") == 0){//string.compare returns 0 when true
		//deposit (add) money to balance
		savings.deposit(amount);
	}
	else{
		checking.deposit(amount);
	}
}
void Portfolio::withdraw(double amount, string a)
{
	if(a.compare("S") == 0){//string.compare returns 0 when true
		//withdraw
		savings.withdraw(amount);
	}
	else{
		checking.withdraw(amount);
	}
}
void Portfolio::transfer(double amount, string a)
{
	//balance = balance + amount;
	if(a.compare("S") == 0){//string.compare returns 0 when true
		//implement transfer method ("S") money taken from "S" to "C"
		checking.deposit(amount);
		savings.withdraw(amount);

	}
	else{

		savings.deposit(amount);
		checking.withdraw(amount);
	}
}
void Portfolio::print_balances(){
	cout<<"[Checking account balance: "<<checkingb()<<"] , [Savings account balance: "<<savingb()<<"]"<<endl;
}
double Portfolio::checkingb(){
	return checking.get_balance();
}
double Portfolio::savingb(){
	return savings.get_balance();
}
int main()
{
//	BankAccount harrys_account(1000);
//	harrys_account.deposit(500);
//	harrys_account.withdraw(2000);
//	harrys_account.add_interest(1);
//	cout << fixed << setprecision(2)
//    				  << harrys_account.get_balance() << endl;
	Portfolio ryans_account(50000);//50k automatically put in savings
	ryans_account.transfer(20450.75 , "S");//transfer 20k from S (Savings) to Checking
	ryans_account.print_balances();

	return 0;
}
