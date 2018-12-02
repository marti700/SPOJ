#include <iostream>
#include <algorithm>

int dp[2001][2001];
int treats_stash[2005];

using namespace std;

/** 0-1 knapsack implementation*/
int f(int lower_index, int upper_index, int year){
    
    if (lower_index > upper_index)
        return 0;

    if (dp[lower_index][upper_index] != -1)
        return dp[lower_index][upper_index];
    
    
    return dp[lower_index][upper_index] = max((f(lower_index + 1, upper_index, year + 1) + (treats_stash[lower_index] * year)),
     (f(lower_index, upper_index - 1, year + 1) + (treats_stash[upper_index] * year)));
}

void init_dp(){
   for(int i = 0; i < 2001; i++){
       for (int j = 0; j < 2001; ++j){
           dp[i][j] = -1;
       }
   } 
}

int main(){
    ios_base::sync_with_stdio(false);
    int number_of_treats;
    cin >> number_of_treats;

    for(int i = 0 ; i < number_of_treats; i++){
        cin>>treats_stash[i];
    }

    init_dp();

    cout<<f(0,number_of_treats - 1, 1);

    return 0;
}