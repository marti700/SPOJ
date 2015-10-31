#include <iostream>
#include <string>

using namespace std;

//calculates the max number of combinations given a numeric code
unsigned long long int combinations(string code);

int main()
{
    std::ios::sync_with_stdio(false);

    string code;

    while(cin>>code){
        if (code.compare("0") == 0 )
            break;
        else
            cout<<combinations(code)<<"\n";
    }
    return 0;
}

unsigned long long int combinations(string code)
{
   // ALPHACODE HOW TO:
   //
   // Consider the following input
   // 23121312321
   //
   // If just the initial 23 is taken and analysed to find out how many
   // combinations we can take out of it the result will be 2 because
   // is possible that the the one who has writed the code wants the 2 and the 3
   // to be separated but is also posible that he or she wants them to be together
   // as 23 and that makes two combinations:
   // -: 2 3 -> the 2 and the 3 separated
   // -: 23 -> together as 23
   //
   // now if we add to this 23 (wich has two possible combinations) the
   // next number we will have 231 which still has two possible combinations
   // -: 23 1 -> 23 and 1
   // -: 2 3 1 -> all separated
   // -: (2 31) -> is not a valid combination because the alphabet just have
   //    26 characters and 31 > 26
   //
   // below is the number of combinations formed if we keep adding the next
   // number to the previous numbers ( I start in with 23)
   //
   // 23 -> 2 combinations possible
   // 231 -> 2 combinations possible
   // 2312 -> 4 combinations possible
   // 23121 -> 6 combinations possible
   // 231213 -> 10 combinations possible
   // 2312131 -> 10 combinations possible
   // 23121312 -> 20 combinations possible
   // 231213123 -> 30 combinations possible
   // 2312131232 -> 30 combinations possible
   // 23121312321 -> 60 combinations possible
   //
   // As probably was noticed is the two previous numbers of combinations are added
   // this gives the actual number of combination (ex. if the number of combinations
   // in 23(2 combinations) is added to the number of combinations in 231 (2 combinations)
   // the result will be the number of combinations in 2312 (4 combinations))
   //
   // this is true if the following rules are applied to the input
   //
   // 1-> if the last number of the combination is 0 then the number of combinations
   //     is the last number of combinations (E.x for the input 20022 :-> in 2 are
   //     1 combinations the next number to add is 0 so, the number of combinations is still 1
   //     and so on.)
   //
   // 2-> if the last pair of digits is greather than 26 the number of combinations
   //     is the last number of combinations (E.x for the input 231 :-> 23 the number
   //     of combinations is 2 the next number to add is 1 so, the next number of
   //     combinations is still 2 (for 231))
   //


    unsigned long long int dp[5000],result,i;
    string pairTemp; //

    // if input's first number is 0
    // the number of combinations is 0
    // because SPOJ says so
    if (code[0] == '0')
        return 0;

    else
        dp[0] = 1;

    // String(1,a_char) convert a char into a string
    pairTemp = string(1,code[0]) + string(1,code[1]);
    if (code[1] == '0' || pairTemp.compare("26") > 0 )
        dp[1] = dp[0] + 0;
    else
        dp[1] = 1;

    for(i=2; i<=code.length();i++){
        pairTemp = string(1,code[i-2]) + string(1,code[i-1]);

        //this line takes car of zeros and if pairTemp(the current last pair of digits) is greather than 26
        if (code[i] == '0' || code[i-1] == '0' || pairTemp[0] == '0' || pairTemp.compare("26") > 0)
            dp[i] = dp[i-1];
        else
            dp[i] = dp[i-2] + dp[i-1];
        result = dp[i-1];
    }

    return dp[i-1];
}
