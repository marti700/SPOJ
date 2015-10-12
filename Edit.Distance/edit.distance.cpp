#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int min_distance (string S1, string S2);
int minimum (int N1, int N2, int N3);

int dp[2001][2001];

int main ()
{
    ios::sync_with_stdio(false);

    int test_cases;
    string S1,S2;

    cin>> test_cases;

    for(int i = 0; i< test_cases; ++i){
        cin>>S1>>S2;
        cout<<min_distance(S1,S2)<<"\n";
    }
    return 0;
}

int min_distance(string S1, string S2)
{
    //this was posible after reading this:
    //https://en.wikipedia.org/wiki/Edit_distance
    //but specially this
    //https://en.wikipedia.org/wiki/Wagner%E2%80%93Fischer_algorithm
    //

    for(int i=0; i<S1.length(); ++i){dp[i][0] = i;}

    for (int i=0; i<S2.length(); ++i){dp[0][i] = i;}

    for(int i=1; i<=S1.length(); ++i){
        for(int j=1; j<=S2.length(); ++j){
            // if current strings are equal no action is needed
            if (S1[i-1] == S2[j-1]){dp[i][j] = dp[i-1][j-1];}
            else{
                dp[i][j] = minimum( dp[i-1][j] + 1,//this is a deletion
                                    dp[i][j-1] + 1, //this is a insertion
                                    dp[i-1][j-1] + 1 //this is a substitution
                                );
            }
        }
    }
    return dp[S1.length()][S2.length()];
}

int minimum (int N1, int N2, int N3)
{
    int temp_min = min(N1,N2);
    return min(temp_min, N3);
}
