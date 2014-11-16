#include<iostream>

using namespace std;

long long winner(long long);

int main()
{
    
    /*
     * After a lot of thinking and a lot of simulations at paper i realize that the first player will win if he (or she) takes the last digit of the number
     * if this last digit is not zero. So if we have a number like 20 the first player will lose because this last digit is zero but if this last digit is 
     * diferent that zero the first player will win. So if we have 21 we have to substract the 1 so the next integer will be 20 and with this the second player
     * will loose. this works for all numbers (i have a lot of game simulations in papaer that prove this XD). 
     *
     * I was about to code this testing for the last digit of the number whether if it ends in zero or not, but after a bit of reading i realize that all numbers that 
     * end at zero are divisors of 10 (i was like Duh!!) I putting this last paragraph here because i did not realize of this alone. If i haven't read the article i
     * read (i readed because i wanted to see if i was right about this problem) the code would be much more large.
     * */
    
    long long start_number;
    cin>>start_number;

    if(winner(start_number) == 1)
        cout<<1<<endl<<(start_number % 10)<<endl;
    else
        cout<<2<<endl;

    return 0;
}

long long winner(long long start_number)
{
    if ((start_number % 10) == 0)
        return 2;
    
    return 1;
}
