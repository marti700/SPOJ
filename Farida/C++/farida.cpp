#include <iostream>
#include <map>

using namespace std;

long monster_coins[10001];

map<int, long long> dp;

/*

Cantors pairing function implementation

https://en.wikipedia.org/wiki/Pairing_function

*/

int get_key(int k1, int k2)
{

    return (int)(0.5 * (k1 + k2) * (k1 + k2 + 1) + k2);
}

/*

I have decided that this function explains itself, the most complicated thing about it is

the fact that it uses a pairing function to hash the function arguments which are an int and a bool

and that pairing funciton recives 2 integer arguments but a integer and a bool are sent, but you should

remember that bool in c++ is represented by an integer value 1 is true and 0 is false, so, you are always

sending the index (the i argument) and 0 or 1 (depending if you can add the moster coin or not) to the get_key

function.

*/

long long f(int i, bool can_take)
{

    long x = 0, y = 0;

    if (i < 0)

        return 0;

    if (dp.find(get_key(i, can_take)) != dp.end())

        return dp[get_key(i, can_take)];

    if (can_take)

        x = monster_coins[i] + f(i - 1, false);

    y = f(i - 1, true);

    return dp[get_key(i, can_take)] = max(x, y);
}

int main()
{

    ios_base::sync_with_stdio(false);

    int test_cases;

    int number_of_monsters;

    cin >> test_cases;

    for (int i = 0; i < test_cases; ++i)
    {

        cin >> number_of_monsters;

        for (int j = 0; j < number_of_monsters; ++j)
        {

            cin >> monster_coins[j];
        }

        dp.clear(); //resets the dp map

        cout << "Case " << i + 1 << ": " << f(number_of_monsters - 1, true) << endl;
    }

    return 0;
}