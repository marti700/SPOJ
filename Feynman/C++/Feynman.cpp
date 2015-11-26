#include<iostream>

using namespace std;

int how_many_squares(int N);

int main()
{
    int N = -1;   // -1 is a place holder for N
    
    while(N != 0){
        //cout<<"Before cin"<<endl;
        cin>>N;
        if (N > 0)
            cout<<how_many_squares(N)<<endl;
    }
    return 0;
}

int how_many_squares(int N)
{
    /*  This is a easy one, once you figured how to do it, you just have to calculate the area of all the squares up to N
     *  E.X. if N is 8 the number of N X N squares that are in an 8X8 square are (8*8)+(7*7)+(6*6)+(5*5)+(4*4)+(3*3)+(2*2)+(1*1) = 204
     * */
    
    int number_of_squares = 0;

    if (N == 1)
        return 1;
    else
        return number_of_squares += (N*N) + how_many_squares(N-1); 
}

