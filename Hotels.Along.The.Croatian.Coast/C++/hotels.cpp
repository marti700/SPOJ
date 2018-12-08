#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;


/**
 * Calculates the max sum of consecutive hotels values, this sum will always
 * be less than the constraint value.
 * 
 * This Function sum all contiguous values until it reaches a sum that is greather
 * than the contraint, when that happends it substract the first value of the list 
 * and then tries to sum the current value if the resulting sum is still greather than the 
 * constraint it repeats the process until the max value is found.
 * 
 * e.x 
 * 
 * Let's soupouse that our input is this:
 *      9 23
        2 8 18 9 91 6 4 2 1 
 * that's a list of nine hotels values and the constraint is 23
 * the process starts by adding 2 and 8 together (2 + 8 = 10)
 * then it tries to add 18 to 10 which is greter than the constraint (18 + 10 = 28; #constraint = 23)
 * then it substracts 2 fron the previous sum (10 - 2 = 8)
 * then it tries to add 18 to 10 but this is still greater that the contraint (18 + 8 = 26)
 * then in substracts 8 from the previous valid sum (8 - 8 = 0)
 * then it tries to add 18 to the 0, this time is succeeds since 18 is less then the contraint
 * 
 * this proccess is repeated until there are no values left to process (btw the final result of our example is 18)
 * 
 * 
 * */
long long hotels_greatest_total_value(deque<long long> hotels_values, long long constraint){
    long long max = 0; //holds the historical max hotel values lower than the constraint
    long long sum = 0; //holds the sum of continuous hotel values less than the constraint

    for(long long i = 0; i < hotels_values.size(); i++){
        //don't take in cosideration the values higher than the constraint
    	if (hotels_values[i] <= constraint){
	        if (sum + hotels_values[i] <= constraint){
	            sum = std::max(sum, sum + hotels_values[i]);
	            max = std::max(max, sum);
	        }
	        else {
                //subsctract the value at the front of the deque from sum
	        	sum -= hotels_values.front();
                //removes the element at the front of the deque
	            hotels_values.pop_front();

                /* since an element was remove from the deque elments indexes have change
                 2 is substracted fron the counter here because is necesary to keep i pointing 
                 to the element index that broke the sum validity in order to see if summing it 
                 with the new sum (the one we just created in line 47) will give a greater max
                 value.
                */
	            i -= 2;
	        }
    	}
        else{
            //since whats matters is the sum of consecutive hotels values less than the constraint
            //if a hotel value is higher that the constraint max should be zero because continuity is
            //broken
        	sum = 0;
        }
    }
    return max;
}

int main(){
    ios_base::sync_with_stdio(false);
    long hotels;
    long long lotery_prize;
    deque<long long> hotels_values;
    long long temp;
    
    cin>>hotels>>lotery_prize;
    
    for(long long i = 0; i < hotels; ++i){
        cin>>temp;
        hotels_values.push_back(temp);
    }
    cout<<hotels_greatest_total_value(hotels_values, lotery_prize);
    return 0;
}

