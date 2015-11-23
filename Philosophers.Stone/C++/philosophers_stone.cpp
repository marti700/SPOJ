#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

/*
 * PHILOSOPHERS STONE HOW TO
 * first is good to know this is a Dynamic Programming problem that can (and will)
 * be solved using a 2 dimensions array to make possible the meoization of previously
 * calculated values.
 *
 * A matrix is given, each cell of the matrix indicates how many philosphers stones
 * are in that tile. this program works as follows:
 *
 * 1- start by looking at the last cell of the matrix ()
 *  E.X: in the matrix:
 *  1  2  3  4
 *  5  6  7  8
 *  9 10 11 12
 *
 *  12 is the last element of the matrix
 *  and from this point traverse the matrix all the way up
 *  using this recursive formula (for the sake of the example
 *  the formula will be espefic to the above matrix):
 *
 *  if col == 3
 *      //this means the last colum is being processed
 *      max(matrix[x][y]+f(matrix,row-1,col), matrix[x][y]+f(matrix,row-1,col-1))
 *  else if col == 0
 *      //this means the first colum is being processed
 *      max(matrix[x][y]+f(matrix,row-1,col), matrix[x][y]+f(matrix,row-1,col+1))
 *  else
 *      //this means the colum being processed is not the last or the first (Duh!)
 *      max(matrix[x][y]+f(matrix,row-1,col+1), matrix[x][y]+f(matrix,row-1,col), matrix[x][y], f(field,row-1, col-1))
 *
 * */


int dp[1001][1001];

int maximum(int a, int b, int c)
{
    //calculates the maximum of three given numbers
    int temp = max (a,b);
    return max(temp,c);
}

int expUp(int field[][300], int h, int w, int cols)
{
    //given a the coordinates of Harry's current position and the max number of
    //colums of the matrix, explores up the paths harry can take to collect stones
    //and return the max number of stones Harry can collect from
    //his current position using one of the paths he can travel through
    //(this function does not keep track of the paths)

    //if the current coordinates have been previously computed
    if(dp[h][w] != -1)
        return dp[h][w];
    //if reached the first row
    if (h==0)
        return field[h][w];

    //if the current coordinates uses the last column
    if(w == cols)
        return dp[h][w] = max(field[h][w]+expUp(field,h-1,w,cols),
                              field[h][w]+ expUp(field,h-1,w-1,cols));
    //if the current coordinates uses the first column
    else if(w == 0)
        return dp[h][w] = max(field[h][w]+expUp(field,h-1,w,cols),
                              field[h][w]+ expUp(field,h-1,w+1,cols));
    //if the current coordinates do not use the first or last column
    else
        return dp[h][w] = maximum(field[h][w]+expUp(field, h-1, w+1,cols),
                                  field[h][w]+expUp(field,h-1,w,cols),
                                  field[h][w]+expUp(field,h-1,w-1,cols));
}

int maxStones(int field[][300], int h, int w)
{

    //calculates the max number of philosphers stones that can be
    //gathered in a single trip by Harry Potter.

    int i;

    //uses expUp function to calculate the max number of stones harry
    //can collect if he were standing in the current column.
    for(i=w; i>0; --i)
       //extracts the max of stones(that can be collected) between the current
       //column and the next one
        dp[h][i-1] = max(expUp(field, h, i, w), expUp(field, h, i-1, w));

    return dp[h][i];
}


int main()
{
    std::ios::sync_with_stdio(false);

    int h,w,testCases;
    int field[300][300];

    cin>>testCases;

    for(int i=0; i<testCases; ++i){

        memset(dp,-1,sizeof(dp));
        //getting input according to test cases
        cin>>h>>w;
        for(int j=0; j<h; ++j){
            for(int k=0; k<w; ++k){
                cin>>field[j][k];
            }
        }
        //printing the anser by making maxStones perform the needed calculations
        cout<<maxStones(field,h-1,w-1)<<"\n";
        memset(field,0,sizeof(field)); //setting all field matrix entries to 0

    }
    return 0;
}
