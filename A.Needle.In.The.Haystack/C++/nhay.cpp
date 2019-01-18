#include <iostream>
#include <vector>

using namespace std;

/**
 * Solved using kmp algorithm
 * I know you wont be implementig this every day 
 * so is only natural that you forget it
 * a nice explanation of the algorithm can be found
 * here:
 * http://jakeboxer.com/blog/2009/12/13/the-knuth-morris-pratt-algorithm-in-my-own-words/
 **/


/**
 * Creates the table of prefixes for the kmp search
 * */

vector<int> kmp_table(string pattern)
{
    vector<int> t; //table of the prefixes
    int j = 0;

    t.push_back(0); //first position of table will always be zero (no prefix or suffix)
    for (int i = 1; i < pattern.length(); i++)
    {
        if (pattern[i] == pattern[j])
        {
            j++;
            t.push_back(j);
        }
        else
        {
            if (j != 0)
            {
                j = t[j - 1];
                i--; // to eliminate the effect of increasing i in the loop
            }
            else
            {
                t.push_back(0);
            }
        }
    }
    return t;
}

/**
 * perform kmp algorithm search on a given text and pattern
 * it is also necesary to specify the table of prefixes of the
 * pattern
 * */
vector<int> kmp_search(string text, string pattern, vector<int> kmp_table)
{
    int i = 0, j = 0;
    vector<int> indexes;

    while (i < text.length())
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }

        if (j == pattern.length())
        {
            indexes.push_back(i - j);
            j = kmp_table[j - 1];
        }
        else if (i < text.length() && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = kmp_table[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
        return indexes;
}

int main()
{
    std::ios::sync_with_stdio(false);

    int needle_size;
    string needle;
    string haystack;
    vector<int> indexes;

    while (cin >> needle_size)
    {
        cin >> needle >> haystack;
        indexes = kmp_search(haystack, needle, kmp_table(needle));
        //if(indexes.size() == 0)
        //cout<<endl;
        for (int i = 0; i < indexes.size(); i++)
        {
            cout << indexes[i] << endl;
        }
        cout << endl;
    }
    return 0;
}
