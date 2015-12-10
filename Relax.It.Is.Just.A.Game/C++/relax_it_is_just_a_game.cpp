#include<iostream>

using namespace std;

bool isSumOfProbabilities(int ATeamPoints, int BTeamPoints);

int main()
{
    int ATeamPoints, BTeamPoints;

    while(cin>>ATeamPoints>>BTeamPoints){
        if(ATeamPoints == -1 && BTeamPoints == -1)
            break;

        if(isSumOfProbabilities(ATeamPoints, BTeamPoints))
            cout<<ATeamPoints<<"+"<<BTeamPoints<<"="<<ATeamPoints+BTeamPoints<<endl;
        else
            cout<<ATeamPoints<<"+"<<BTeamPoints<<"!="<<ATeamPoints+BTeamPoints<<endl;
    }
}

bool isSumOfProbabilities(int ATeamPoints, int BTeamPoints)
{
    //Returns true if the number probabilities is equal to the sum of the team
    //points, false otherwise
    //
    //the number of probabilities is equal to the sum if one of the teams have
    //one goal

    if(ATeamPoints == 1 || BTeamPoints == 1)
        return true;

    return false;
}
