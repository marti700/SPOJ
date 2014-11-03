#include <iostream>
#include <map>
#include<algorithm>      //to use std::max to return the maximized sum (for more info on max google it!!!! XD :))

using namespace std;


map<unsigned long long,unsigned long long > previously_computed_values;   // to store calculated sums of a given coin

unsigned long long maximun_amount_of_dollars(unsigned long long);         // returns the maximun amount of dollars you can make with a bytelandian coin

int main()
{
    unsigned long long a_bytelandian_gold_coin; // unsigned long long because the input is large

    while(cin>>a_bytelandian_gold_coin){
        cout<<maximun_amount_of_dollars(a_bytelandian_gold_coin)<<endl;
    }
    return 0;
}

unsigned long long maximun_amount_of_dollars(unsigned long long a_bytelandian_gold_coin)
{

    /* My first Spoj DP problem Yay!!!!
     * 
     * I use Memoization to solve this problem thats why i have a global map to save the values of all calculations made by the program 
     * because without this the recursive function will enter in a phenomenon calle overlapping problems wich basically means that the algorithm
     * will recalculate things that have already been calculated (for more info search for dynamic programming in wikipedia and then go to the fibonacci secction)
     *
     * what i did basically was:
     *
     * check if the evaluated bytelandian gold coin was evaluated previosly if thats the case i just return the result from may map
     * if not then i calculate the answer and then i add it to the map
     * */
    
    if (a_bytelandian_gold_coin == 0)
        return 0;
    
   
    // check if the input was processed previosly (because if it was i have the answer in the map
    if (previously_computed_values[a_bytelandian_gold_coin] != 0)
       return previously_computed_values[a_bytelandian_gold_coin];
    
    //if not was previously processed then calculate it and add the result to the map
    else
       return previously_computed_values[a_bytelandian_gold_coin] = max(a_bytelandian_gold_coin, 
            (maximun_amount_of_dollars(a_bytelandian_gold_coin/2) + 
            maximun_amount_of_dollars(a_bytelandian_gold_coin/3) + 
            maximun_amount_of_dollars(a_bytelandian_gold_coin/4)));
}
