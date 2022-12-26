
#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
#include <cmath>
#include <climits>
using namespace std;

/**
   Tests if a token is an operator.
   @param token the token
   @return true if the token is one of: + - * / ^
*/
bool is_operator(string token)
{
   return token == "+" || token == "-" || token == "*" || token == "/";
}

/**
   Tests if a token is a digit.
   @param token the token
   @return true if token is one of: 0 1 2 3 4 5 6 7 8 9
*/
bool is_digit(string token)
{
   return token.length() == 1 && "0" <= token && token <= "9";
}

/**
   Computes the precedence level of an operator.
   @param op the operator
   @return the precedence level (1 = lowest, 3 = highest)
*/
int precedence(string op)
{
   if (op == "+" || op == "-") { return 1; }
   else if (op == "*" || op == "/") { return 2; }
   else { return 0; }
}

//output an error message
void error(string message)
{
   cout << "ERROR: " << message << "." << endl;
   exit(1);
}

class ExpressionCalculator
{
public:

   int evaluate(string expression);
   int isOperator(char ch);
   int isOperand(char ch);
   float operation(int a, int b, char op);
   float scanNum(char ch);
   float postfixEval(string postfix);
   // Computes a new value and pushes it on the stack.
   void evaluate_top();
private:
   stack<int> numstack;
   stack<string> opstack;
};

void ExpressionCalculator::evaluate_top()
{
   if (opstack.size() == 0) { error("Syntax error"); }
   string op = opstack.top();
   opstack.pop();
   if (numstack.size() == 0) { error("Syntax error"); }
   int y = numstack.top();
   numstack.pop();
   if (numstack.size() == 0) { error("Syntax error"); }
   int x = numstack.top();
   numstack.pop();
   int z = 0;
   if (op == "*") { z = x * y; }
   else if (op == "/")
   {
      if (y == 0) { error("Divide by 0"); }
      else { z = x / y; }
   }
   else if (op == "+") { z = x + y; }
   else if (op == "-") { z = x - y; }
   else { error("Syntax error"); }
   numstack.push(z);
}
int ExpressionCalculator::isOperator(char ch){
   if(ch == '+'|| ch == '-'|| ch == '*'|| ch == '/' || ch == '^')
      return 1;//character is an operator
   return -1;//not an operator
}
int ExpressionCalculator::isOperand(char ch){
   if(ch >= '0' && ch <= '9')
      return 1;//character is an operand
   return -1;//not an operand
}
float ExpressionCalculator::scanNum(char ch){
   int value;
   value = ch;
   return float(value-'0');//return float from character
}
float ExpressionCalculator::operation(int a, int b, char op){
   //Perform operation
   if(op == '+')
      return b+a;
   else if(op == '-')
      return b-a;
   else if(op == '*')
      return b*a;
   else if(op == '/')
      return b/a;
   else if(op == '^')
      return pow(b,a); //find b^a
   else
      return INT_MIN; //return negative infinity
}

float ExpressionCalculator::postfixEval(string postfix){
   int a, b;
   stack<float> stk;
   string::iterator it;
   for(it=postfix.begin(); it!=postfix.end(); it++){
      //read elements and perform postfix evaluation
      if(isOperator(*it) != -1){
    	  //take two elements from stack
         a = stk.top();
         stk.pop();
         b = stk.top();
         stk.pop();
         stk.push(operation(a, b, *it));
      }
      else if(isOperand(*it) > 0){
         stk.push(scanNum(*it));
      }
   }
   return stk.top();
}
//normal
int ExpressionCalculator::evaluate(string expression)
{
   int pos = 0;
   while (pos < expression.length())
   {
      string ch = expression.substr(pos, 1);
      pos++;
      if (is_operator(ch))
      {
         while (opstack.size() > 0 &&
            precedence(opstack.top()) >= precedence(ch))
         {
            evaluate_top();
         }

         opstack.push(ch);
      }
      else if (ch == "(") { opstack.push(ch); }
      else if (ch == ")")
      {
         bool done = false;
         while (!done)
         {
            if (opstack.size() == 0) { error("No matching ("); }
            if (opstack.top() == "(") { opstack.pop(); done = true; }
            else { evaluate_top(); }
         }
      }
      else if (is_digit(ch))
      {
         int start = pos - 1;
         while (pos < expression.length()
            && is_digit(expression.substr(pos, 1))) { pos++; }
         string num = expression.substr(start, pos - start);
         numstack.push(stoi(num));
      }
      else if (ch != " ")
      {
         error ("Number, operator, or parenthesis expected.");
      }
   }
   while (opstack.size() > 0)
   {
      if (opstack.top() == "(") { error("No matching )"); }
      else { evaluate_top(); }
   }
   if (numstack.size() != 1) { error("Syntax error"); }
   int result = numstack.top();
   numstack.pop();
   return result;
}


int main()
{
   cout << "Enter an arithmetic expression such as 13+12/*55*+: ";//25
   string expr;
   getline(cin, expr);
   ExpressionCalculator calc;
   cout << calc.postfixEval(expr) << endl;

   return 0;
}
