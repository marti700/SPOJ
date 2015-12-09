#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

int minInsertions(string str, int startIndex, int endIndex);

int main()
{
    //std::ios::sync_with_stdio(false);

    int testCases;
    string inStr;

    cin>>testCases;

    for(int i=0; i<testCases; ++i){
        cin>>inStr;
        cout<<minInsertions(inStr,0,inStr.length()-1)<<endl;
    }

    return 0;
}

int minInsertions(string str, int startIndex, int endIndex)
{

   //AIBOHPHOBIA HOW TO:
   //I NEEDED HELP WITH THI ONE
   //CHECK:
   //http://www.geeksforgeeks.org/dynamic-programming-set-28-minimum-insertions-to-form-a-palindrome/

    // the max length a string can have for this problem is 6200
    // You can not declare a 2D array of that size if you do you
    // will get segmentation fault (Or some other compiler dependent error)
    // and thats why I use a dynamically allocated array;

    int **dp;
    dp = new int* [6201];
    for(int x=0;x<6201;++x){
        dp[x] = new int[6201];
    }

    int i,j,k;

    //memset(dp, 0, sizeof(int) * 8000 * 8000);
    for(i=1; i<str.length(); ++i){
        for(j=0, k=i; k<str.length(); ++j, ++k){
            if(str[j]==str[k]){
                dp[j][k] = dp[j+1][k-1];
            }
            else{
                dp[j][k] = (min(dp[j][k-1],dp[j+1][k]) + 1);
            }
        }
    }
    return dp[0][str.length() - 1];

    //clears the memory
    for(int x=0;x<6201;++x){
        delete [] dp[x];
    }
    delete [] dp;
}
