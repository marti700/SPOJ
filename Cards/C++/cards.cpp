#include <iostream>

using namespace std;

//returns the number of cards to build a pyramind of N % 1,000,007 Levels
unsigned long long int number_of_cards(unsigned long long int N);

int main()
{
    //turn off sync with printf and scanf
    std::ios::sync_with_stdio(false);

    unsigned long long int test_cases,levels;

    cin>>test_cases;

    for(unsigned long long int i=0;i<test_cases;++i){
        cin>>levels;
        cout<<number_of_cards(levels)<<"\n";
    }
}

unsigned long long int  number_of_cards(unsigned long long int N)
{
    //After a bit of thinkig I end up realizing that the number of cards
    //for each level is given by (N*2 + N-1) where N is the level then if
    //I multiply this by N (like N*(N*2 + N-1) this will give the number of
    //cards needed to build a tower of N levels(not a pyramind, but a tower with the
    //same number of cards in each level), after examining the image I
    //realize that the difference of cards in each level of the pyramind is 3 (e.x the difference
    //of cards from level 3 to level 2 is 3 and the difference of cards from Level
    //3 to level 1 is 6) and this is an aritmetic serie so i just apply the formula to
    //sum the elements in an aritmetic serie and then substracted this sum from the result
    //obtainded from N*(2*N + N-1) and that give the answer to the problem.

    unsigned long long int r,t,d;

    t = ((N*((2*N)+(N-1))));
    d =(N*(0+(N-1)*3))/2;
    r = t - d;
    return (r % 1000007);
}
