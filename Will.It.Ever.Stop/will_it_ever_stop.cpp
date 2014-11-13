#include<iostream>
#include<cmath>
#include<map>

using namespace std;

bool will_stop(unsigned long long a_number);
//unsigned long long will_sto(unsigned long long a_number);

int main()
{
    
    /*
     * To solve this problem you just have to find if the given number is a power of 2
     * */

    unsigned long long the_number;
    map<unsigned long long, string> stop;

    //calculate all power of two posibilities within the input range 
    //I did this because my great idea wasn't working you can check it in the will_stop funciton comment
    for(unsigned long long i=0;i<60;++i){
        stop[(unsigned long long)pow(2,i)] = "TAK";
    }

    cin>>the_number;


    if (stop[the_number] == "")
        cout<<"NIE"<<endl;
    else
        cout<<stop[the_number]<<endl;
    
    /*if(will_stop(the_number))
        cout<<"TAK"<<endl;
    else
        cout<<"NIE"<<endl;
    */
    return 0;
}

bool will_stop(unsigned long long a_number)
{
    /*
     * If the base 2^log in base 2 of a_number == a_number the the number is a power of two
     * E.X
     * the log in base 2 of 64 = 6 and 2^6 == 64 and this means that 64 is a power of 2
     * since you can not specified the base of a log function in c++ i perform a change of base
     * using the following formula: (log in base 2 of x = log in base 10 of x divided log in base 10 of 2
     *
     * but i couldn't get accepted with this perhaps because the log10 function dislikes integers even when you cast them to int XD
     * */
    if ((unsigned long long)pow(2,(unsigned long long)(log10(a_number)/log10(2))) == a_number)
        return true;

    return false;
}


