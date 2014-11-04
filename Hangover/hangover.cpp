#include<iostream>

using namespace std;

int cards_needed_for_overhang(float);

int main()
{
    float hang_length;

    while(cin>>hang_length){
        //0.00 means the end of the inputs
        if (hang_length == 0.00) 
            break;
        
        cout<<cards_needed_for_overhang(hang_length)<<" card(s)"<<endl;
    }
    
    return 0;
}

int cards_needed_for_overhang(float hang_length)
{
    /* find the number of cards needed so that the cards can hang an N distance in a table
     * 
     * just accumulate the sum of 1/2 + 1/3 + 1/4 ... + 1/(n+1) until this sum becomes equal or greather 
     * than the hang length specified in the input
     * */
    
    int cards_needed = 0;  
    float n = 2; 
    float length_checker = 0;     // used to hold the sum of 1/2 + 1/3 ... + 1/(n+1) 
    
    //when length_checker is greather or equal than the hang_length the work is done!
    while (length_checker <= hang_length){
        length_checker += 1/n++;
        cards_needed++;
    }

    return cards_needed;
}


