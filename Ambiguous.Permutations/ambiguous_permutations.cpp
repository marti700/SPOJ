#include<iostream>
#include<map>

using namespace std;

int main()
{
    /*
     * This problem is about subtituting the current number for its position
     * E.X
     * for 2 3 4 5 1 
     * 1 is in the 5th position so, we put a 5 in the first position
     * 2 is in the 1st position so we put a 1 in place of two
     * 3 is in the 2nd position so we put a 2 in place of the three
     * and so on...
     *
     * I used a map and an array to solve This
     * first i place the input in the array and then i map the input to a position for example
     * if the input was 2 i put that 2 in the array and then i place that 2 as a key that maps to 1
     * indicating that 2 is in the first position.
     *
     * after that i loop over the array asking this "map[i+1] = arr[i]"
     * which means is i+1 (because i start looping at 0) equal to the current number in the array
     * if it's not equal means that the permutation is not ambiguous.
     * and if the counter (wich is i) takes the value of permunt_number-1 means that not diferrences
     * were found thus the permutation is ambiguous.
     * */
    
    int permunt_number;
    map<int,int> mapper;

    while(cin>>permunt_number){
        if (permunt_number == 0)
            break;

        int* input = new int[permunt_number];

        for(int i=0;i<permunt_number;++i){
            cin>>input[i];
            mapper[input[i]] = i+1;
        }

        for(int i=0;i<permunt_number;++i){
            if (mapper[i+1] != input[i]){
                cout<<"not ambiguous"<<endl;
                break;
            }
            if (i == permunt_number-1)
                cout<<"ambiguous"<<endl;
        }
        delete[] input;
    }
    
    return 0;
}
