#include<iostream>

using namespace std;

//returns the pyani that just apperared once
long long int uniquePyani(long long int numberOfPyani, long long int pyaniList[]);

int main()
{
    std::ios::sync_with_stdio(false);

    long long int numberOfPyani;
    long long int pyaniList[500001];

    cin>>numberOfPyani;

    for(int i = 0; i<numberOfPyani; ++i){
        cin>>pyaniList[i];
    }

    cout<<uniquePyani(numberOfPyani, pyaniList);
}

long long int uniquePyani(long long int numberOfPyani, long long int pyaniList[])
{
    //This problem HOW TO:
    //While I was performing an intense research in the spoj comment section
    //something was brought to my attention and that was that this problem can
    //be solved using XOR
    //
    //when a XOR operation is performed between two equal numbers the result is 0
    //while when is performed between 0 and a different number the result will be the
    //other number. So basically after performing XOR in the entire list the result
    //will be the unique number.

    long long int pyani = pyaniList[0]; //going to hold the unique pyani

    for(int i = 1; i<numberOfPyani; ++i){
        pyani = pyani^pyaniList[i];
    }

    return pyani;
}


