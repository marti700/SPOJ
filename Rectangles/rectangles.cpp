#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    /*
     * The first thing to know is that squares are also rectangles 
     * The second thing to know is that the input give to you a number of combinatios (E.X is input is 6 there are 6 + N number of rectangles)
     * after a lot of thinking i realize that i can obtain the remaining number of combinations with the following formula:
     * rectangles_that_can_be_formed += (number_of_squares / i) - (i-1); 
     * i made my self a mental image of size 1 squares that can be arranged in rows (that forthe first part of the formula number_of_squares/i where i is a loop counter) 
     * so if the input is 6 and you do 6/3 you can arrange the 6 squares in 2 rows of 3 like (image '-' are squares):
     * --- 
     * ---
     * the last part of the formula (i-1) is substracted from the first part of the formula (number_of_squares/i):
     * this effectively substract the number of repeated rectangles from the "number_of_squares/i"  calculation which generates repeated rectangles.
     * 
     * */
    
    int number_of_squares;           
    int rectangles_that_can_be_formed;    
    
    cin>>number_of_squares;
    rectangles_that_can_be_formed = number_of_squares;
   
    for(int i=2; i<=sqrt(number_of_squares); ++i){
            rectangles_that_can_be_formed += (number_of_squares / i) - (i-1); 
    }

    cout<<rectangles_that_can_be_formed<<endl;
    
    return 0;
}
