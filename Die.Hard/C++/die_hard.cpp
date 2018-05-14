#include <iostream>

using namespace std;
const int AIR = 0;     // representas the AIR
const int FIRE = 1;    // represents the fire
const int WATER = 2;   // represents the ... Ok, you got the idea.
int dp[1005][1005][4]; // you know what this is don't pretend you don't

/*
recursive function that uses dynamic programing to tell the maximum
amount of time a player can remain alive in the (spoj problem) crazy world.

It works as follows:
The function will take the amount of health and armor the player have available
and the place of the world the player currently is.

if the player is in AIR then max( 1 + go to fire, 1+ go to water )
if the player is not on air then 1 + go to air***

*** The most intelligent thing to do if you are not in air is go to air, because when you
are in air the health and armor increases which guarantees that you will remain alive at least
for one unit of time longer.
*/
int f(int H, int A, int current)
{
    if (H <= 0 || A <= 0)
        return 0;

    if (dp[H][A][current] != -1)
        return dp[H][A][current];

    //if the player is on air return the max between going to fire or water
    if (current == 0)
        return dp[H][A][current] = max(1 + f(H - 5, A - 10, FIRE), 1 + f(H - 20, A + 5, WATER));
    else //always chose air if the player is currently in water or fire
        return dp[H][A][current] = 1 + f(H + 3, A + 2, AIR);
}

/*
Resets the dp array
*/
void resetdp()
{
    for (int i = 0; i < 1005; ++i)
        for (int j = 0; j < 1005; ++j)
            for (int k = 0; k < 3; ++k)
                dp[i][j][k] = -1;
}

int main()
{
    int test_cases;
    int health, armor;
    int in_air;
    int in_water;
    int in_fire;

    cin >> test_cases;

    for (int i = 0; i < test_cases; ++i)
    {
        cin >> health >> armor;
        resetdp();
        //the first play will be to step in to AIR
        cout << f(health + 3, armor + 2, AIR) << endl;
    }
    return 0;
}