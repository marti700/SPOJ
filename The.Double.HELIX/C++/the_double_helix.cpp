#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

//returns the max sum of data from one road and it intersections with other road
long long int max_data_walk(vector<long long int> road1, vector<long long int> road2, long long int initial_index);
//saves the previously computed values
map<long long int,long long int> dp;

int main()
{
    std::ios::sync_with_stdio(false);

    vector<long long int>road1;
    vector<long long int>road2;
    long long int road1_length;
    long long int road2_length;
    long long int dummy;

    while(true){
        cin>>road1_length; //length of the first road
        if (road1_length == 0) //if the length of the first road is 0 there are no more tests
            break;
        else{
            //get first road data
            for(long long int i=0;i<road1_length;++i){
                cin>>dummy;
                road1.push_back(dummy);
            }

            cin>>road2_length; //length of the second road
            //get second road data
            for(long long int i=0; i<road2_length; ++i){
                cin>>dummy;
                road2.push_back(dummy);
            }
        }

        cout<<max(max_data_walk(road1, road2,0), max_data_walk(road2, road1,0))<<"\n";

        //clean containers to compute another test case
        road1.clear();
        road2.clear();
        dp.clear();
    }
    return 0;
}


long long int max_data_walk(vector<long long int> road1, vector<long long int> road2, long long int initial_index)
{
    //THE DOUBLE HELIX HOW TO:
    //
    //Oh WOW,  how can I put this?. This problem can be solve with dynamic programming
    //if the following roads are given:
    //r1 = 1 2 3 4 5 6 7 8
    //r2 = 10 4 16 27 7 9
    //if the recursion tree is developed we will have:
    //                    1                                   10
    //                    |                                   |
    //                    2                                   4
    //                    |                                   /\
    //                    3                                  /  \
    //                    |                                 16   5
    //                    4                                 |    |
    //                    /\                               27    6
    //                   /  \                               |    |
    //                  16   5                              7    7
    //                  |    |                             /\    /\
    //                  27   6                            /  \  /  \
    //                  |    |                            8  9  8   9
    //                  7    7
    //                 /\    /\
    //                /  \   8 9
    //               8    9
    //
    //be looking at the trees above is obvious that the overlapping sub problems occur
    //in the intersections
    //
    //this algorithm deal with this problem as follows:
    //
    //1- look if the problem has already been solved, if it was return the solution plus the previously computed summ
    //
    //2- if the problem was not solved previously look if the value been analyzed in r1
    //is in r2 this is achived using the std::lower_bound which internally use the binary seach algorithm
    //(for more info about lower_bound see: http://www.cplusplus.com/reference/algorithm/lower_bound/)
    //
    //2.1- if the current value is not in r2 sum the value with the previous one
    //2.2- if the current value is in r2 recursivley call the function like this:
    //dp[road1[i]] = road1[i] + max(max_data_walk(road1, road2, i+1), max_data_walk(road2, road1, (intersection-road2.begin()) + 1));
    //adding the result to the dp map.
    //
    //IMPORTAT NOTE:
    //this function returns the max sum of data from one road(r1) and it intersections with other road(r2)
    //which means that if the roads
    //r1 = 1 2 3 4 5
    //r2 = 6 7 3 8 9
    //are given and the function is called like this:
    //max_data_walk(r1,r2,0) it will return 23 as a result of
    //adding the numbers 1 2 3 8 9 it will will only take numbers from r2 when intersections are found
    //in order to obtain the answer to this problem the function shall be called like this:
    //max(max_data_walk(road1, road2,0), max_data_walk(road2, road1,0))

    long long int sum = 0;
    std::vector<long long int>::iterator intersection;
    for(long long int i=initial_index; i<road1.size(); ++i){
        if (dp.count(road1[i]) > 0)
            return dp[road1[i]] + sum;

        //search the index of road1[i] in road 2
        //if road1[i] is not in road2 lower_bound will return an iterator to the las element of road2
        intersection = lower_bound(road2.begin(), road2.end(), road1[i]);

        //if road1[i] is not in road2
        if (road1[i] != road2[intersection - road2.begin()])
            sum += road1[i];

        else{
            dp[road1[i]] = road1[i] + max(max_data_walk(road1, road2, i+1), max_data_walk(road2, road1, (intersection-road2.begin()) + 1));
            sum += dp[road1[i]];
            break;
        }
    }
    return sum;
}

