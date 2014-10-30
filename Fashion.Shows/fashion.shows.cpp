#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int test_cases;
    int number_of_participants;
    int couples_max_level_of_hotness = 0;
    
    cin>>test_cases;
    
    for(int i=0; i< test_cases; ++i){

        cin>>number_of_participants;
        
        int* woman_participants_hotness = new int[number_of_participants];
        int* man_participants_hotness = new int[number_of_participants];
        
        for (int i=0; i<number_of_participants; ++i){
            cin>>woman_participants_hotness[i];
        }
        
        for(int i=0; i<number_of_participants; ++i){
            cin>>man_participants_hotness[i];
        }   

        // the person who made the program don't state crerly that the sum of hotness should be maxemized
        // to do that i have to sort the array of women and men to obtain the max sum
        sort(woman_participants_hotness, woman_participants_hotness + number_of_participants);
        sort(man_participants_hotness, man_participants_hotness +number_of_participants);


        for(int i=0; i< number_of_participants; ++i)
            couples_max_level_of_hotness += man_participants_hotness[i] * woman_participants_hotness[i];    

        cout<<couples_max_level_of_hotness<<endl;
       
        couples_max_level_of_hotness = 0;
        delete [] woman_participants_hotness;
        delete [] man_participants_hotness;
    }
    return 0;
}
