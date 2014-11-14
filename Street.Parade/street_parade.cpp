#include<iostream>
#include<stack>

using namespace std;

string can_be_ordered(int, int*);

int main()
{
    int love_mobiles_in_parade;
    

    while(cin>>love_mobiles_in_parade){
        if(love_mobiles_in_parade == 0)
            break;

        int* moviles_arrival_order = new int[love_mobiles_in_parade];    
        for(int i=0; i<love_mobiles_in_parade;++i){
            cin>>moviles_arrival_order[i];
        }

        cout<<can_be_ordered(love_mobiles_in_parade, moviles_arrival_order)<<endl;

        delete[] moviles_arrival_order;

    }
    
    
    return 0;
}

string can_be_ordered(int love_mobiles_in_parade, int* moviles_arrival_order)
{
    /*
     * This function simulates the sorting process of the love mobiles in the parade 
     * it use a stak to simulate the side street 
     * */
    
    stack<int> side_street;
    int mobile_number = 1;    // holds the mobile number that need to pass the side street (this variable will hold the values from 1 to n)
    
    for(int i=1; i<=love_mobiles_in_parade;++i){

        // if the looked number is found increase by 1 mobile_number to search for the next number
        if(moviles_arrival_order[i-1] == mobile_number)
            mobile_number++;
        
        //if the next number (mobile_number) is in the stack remove it and increase mobile_number
        else if ((!side_street.empty()) && ((side_street.top() == mobile_number))){
            while((!side_street.empty()) && (side_street.top() == mobile_number)){
                mobile_number++;
                side_street.pop();
            }
            // to avoid that i increases when not needed to increase 
            // (delete this line and try 1 2 10 5 4 3 7 6 9, should print yes but without this line will print no, because There 
            // will be more than one element in the stack (side_street) and since this is an else if clause the program will just 
            // follow counting and in the next iteration you will be analysing the value of moviles_arrival_order[i+1] because
            // i will increase and you will miss a value (to understand what i saying delete this line and log the process to stdout))
            --i;
        }
        // if the current analysed number is greather than the number in the top of the stack means that is imposible to sort the parade love mobiles
        else if ((!side_street.empty()) && (moviles_arrival_order[i-1] != mobile_number) && (moviles_arrival_order[i-1] > side_street.top()))
            return "no";
        
        // puts the numbers in the stack when the current number is not the number we are looking for
        else if ((moviles_arrival_order[i-1] != mobile_number) && (side_street.empty() || !side_street.empty()))
            side_street.push(moviles_arrival_order[i-1]);
    }

    return "yes";
}
