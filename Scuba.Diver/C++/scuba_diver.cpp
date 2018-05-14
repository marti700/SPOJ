#include <iostream>

using namespace std;

int inO[1001]; //representas the amount of oxigen
int inN[1001]; //representas the amount of nitrogen
int inW[1001]; //representas the weigt of the tank
int dp[1001][23][81]; //I know you know what this represents

/*
0/1 knapsack implementation
*/
int f(int index, int O, int N)
{

    if (N <= 0 && O <= 0)

        return 0; // return 0 if diver requirements are met

    if (index < 0)

        return 200000000; // returns a big number to take the minimun

    if (dp[index][O][N] != -1)

        return dp[index][O][N];

    else

        //max is used here to avoid that the array takes a negative index

        return dp[index][O][N] = min(inW[index] + f(index - 1, max(O - inO[index], 0), max(N - inN[index], 0)), f(index - 1, O, N));
}

//sets all values of dp to -1

void resetdp(int cylinders, int O, int N)
{

    for (int i = 0; i < cylinders + 1; i++)
    {
        for (int j = 0; j < O + 1; j++)
        {
            for (int k = 0; k < N + 1; k++)
            {
                dp[i][j][k] = -1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int test_cases;
    int O, N;
    int cylinders;
    cin >> test_cases;

    for (int i = 0; i < test_cases; ++i)
    {
        cin >> O >> N;
        cin >> cylinders;
        resetdp(cylinders, O, N);

        for (int j = 0; j < cylinders; ++j)
        {
            cin >> inO[j] >> inN[j] >> inW[j];
        }
        cout << f(cylinders - 1, O, N) << endl;
    }
    return 0;
}