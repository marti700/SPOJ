#include <iostream>
#include <vector>
#include <utility>
#include <map>

using namespace std;

vector<pair<int, int>> testCase; //describes the parties available (entry fee and amount of fun)
map<int, pair<int, int>> dp;

/*
Cantor's pairing function implementation
https://en.wikipedia.org/wiki/Pairing_function
*/

int get_hash_key(int k1, int k2)
{
    return (int)(0.5 * (k1 + k2) * (k1 + k2 + 1) + k2);
}
/*

Overload the < operator to use it with pairs it is implemented as fallows:
1- Will return true for the pair that poseses the less amount of fun (pair.second) with less
entrance fee (pair.first).

2- Will return true for the pair that poseses the less amount of fun (pair.second) with the greather
entrance fee (pair.first).

3- I don't even know why I writing this if it is clearly described in the function.
*/

bool operator<(pair<int, int> lhs, pair<int, int> rhs)
{
    if ((lhs.first < rhs.first) && (lhs.second < rhs.second))
        return true;
    else if ((lhs.first == rhs.first) && (lhs.second < rhs.second))
        return true;
    else if ((lhs.first > rhs.first) && (lhs.second == rhs.second))
        return true;
    else if ((lhs.first > rhs.first) && (lhs.second < rhs.second))
        return true;
    else
        return false;
}

/*
Returns the maximun of two given pairs, is uses an overloaded version
of the < operator (you can check it at line 34 to 49.) to decide the max pair
*/

pair<int, int> maximize_pair(pair<int, int> a, pair<int, int> b)
{
    if (a < b)
        return b;
    else
        return a;
}

/*
Overloads the + operator to add pairs, it basically add the first and second
properties of the pairs together and returns it as a new pair.
*/

pair<int, int> operator+(pair<int, int> lhs, pair<int, int> rhs)
{
    return make_pair((lhs.first + rhs.first), (lhs.second + rhs.second));
}

/*
Implementation of the 0/1 knapsack, don't know how it works ?
Google it!!!
*/

pair<int, int> f(int c, int W)
{
    if (dp.find(get_hash_key(c, W)) != dp.end())
        return dp[get_hash_key(c, W)];
    else
    {
        if (c == 0 || W == 0)
            return make_pair(0, 0);
        if (testCase[c].first > W)
            return f(c - 1, W);
        else
            return dp[get_hash_key(c, W)] = maximize_pair(testCase[c] + f(c - 1, (W - testCase[c].first)), f(c - 1, W));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int budget;
    int n_parties;
    int entry, fun;
    pair<int, int> t;

    while (cin >> budget >> n_parties)
    {
        testCase.push_back(make_pair(0, 0));
        if (budget == 0 && n_parties == 0)
            break;

        for (int i = 0; i < n_parties; ++i)
        {
            cin >> entry >> fun;
            testCase.push_back(make_pair(entry, fun));
        }

        t = f(n_parties, budget);
        cout << t.first << " " << t.second << endl;
        testCase.clear(); // clears
        dp.clear();
    }
    return 0;
}