#include<iostream>
#include <stack>

using namespace std;

string transform_to_RPN(string);

int main()
{
    int number_of_expresions;
    string math_expression;

    cin>>number_of_expresions;

    for(int i=0; i<number_of_expresions; ++i){
        cin>>math_expression;
        cout<<transform_to_RPN(math_expression)<<endl;
    }
    return 0;
}

string transform_to_RPN(string a_math_expression)
{
    
    /* THE ALGORITHM
     * for the imput (a+(b*c)) the program will do the following:
     * it will iterate over the whole string char by char 
     * when a '(' is found the program will execute a continue because a '(' is not result
     * when an operator is found (+,-,*,/,^) the program will put it on a stack 
     * when a ')' is found the program will add the operator that is at the top of the stack to the result string
     * and when the program found anything else it will just add it to the result string
     * E.X
     *
     * for the input (a+(b*c)) the program will do the following:
     *
     * a '(' found: execute continue (result string still empty
     * an 'a' found: add it to the result string (restult string = 'a')
     * a '+' found: add it to the stack (in stack '+')
     * an '(' found: continue (result string = 'a')
     * a 'b' found: add it to the result string (result string = 'ab')
     * a '*' found: add it to the stack (in stack '+',*)
     * a 'c' found: add it to the result string (result string = 'abc'
     * a ')' found: add the operator at the top of the stack to the result string and remove it from the stack(result string = 'abc*; stack = '+')
     * a ')' found: add the operator at the top of the stack to the result string and remove it from the stack(result string = 'abc*+; stack is now empty)
     * value returned = 'abc*+'
     * */
    
    int parentesis_balance = 0;
    stack<char> operators;
    string result = "";
    
    for(int i=0; i< a_math_expression.length();++i){
        if (a_math_expression[i] == '(')
            continue;
        
        else if (a_math_expression[i] == '+'
                || a_math_expression[i] == '-'
                || a_math_expression[i] == '*'
                || a_math_expression[i] == '/'
                || a_math_expression[i] == '^'){

            operators.push(a_math_expression[i]);
        }
        else if(a_math_expression[i]== ')'){
            //parentesis_balance--;
            result += operators.top();
            operators.pop();
        }

        else
            result += a_math_expression[i];

    }


    return result;
}
