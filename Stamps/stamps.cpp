#include<iostream>
#include<algorithm>


int needed_friends(int,int, int*);

using namespace std;

int main()
{
    
    /*
     * The problem is asking for the minimun amount of friends Lucy needs to borrow stamps
     * all you need to do is sort the input and pick the friends that has more stamps
     * E.X
     * 100 stamps needed 
     * 4 friends who has 50 25 51 6 stamps 
     * after sorting the stamps array 6 25 50 51
     * now substract 100(wich is the number of stamps needed - 51 (the number of stamps a friend can offer) thus 100 - 51 = 49 
     * now you just need 49 and by repeating the procces we take the next friend that offers the higher number of stamps which is 50 
     * thus 49-50 = -1 thus Lucy just need 2 friends 
     *
     * */
    
    int scenarios;
    int number_of_stamps_needed, number_of_aviable_friends;

    cin>>scenarios;

    for (int i=0;i<scenarios;++i){
        cin>>number_of_stamps_needed>>number_of_aviable_friends;
        int* stamps = new int[number_of_aviable_friends];
    
        for(int j=0;j<number_of_aviable_friends;++j){
            cin>>stamps[j];
        }

        sort(stamps, stamps + number_of_aviable_friends);
        reverse(stamps, stamps + number_of_aviable_friends);    //you don't need to do this you can loop backwards in the sorted array
        
        if (needed_friends(number_of_stamps_needed,number_of_aviable_friends,stamps) == 0 && i < scenarios-1)
            cout<<"Scenario #"<<i+1<<":"<<endl<<"impossible"<<endl<<endl;
        else if (i < scenarios -1)
            cout<<"Scenario #"<<i+1<<":"<<endl<<needed_friends(number_of_stamps_needed,number_of_aviable_friends,stamps)<<endl<<endl;
   
        // to treat the last line of output wich should not have an extra new line
        if(i == scenarios-1){
            if (needed_friends(number_of_stamps_needed,number_of_aviable_friends,stamps) == 0)
                cout<<"Scenario #"<<i+1<<":"<<endl<<"impossible"<<endl;
            else
                cout<<"Scenario #"<<i+1<<":"<<endl<<needed_friends(number_of_stamps_needed,number_of_aviable_friends,stamps)<<endl;
        }
    

        delete[] stamps;
    }
    return 0;
}

int needed_friends(int number_of_stamps_needed, int number_of_aviable_friends, int* stamps)
{
    /*
     * Identify needed friends by substracting the number of stamps that a friend have
     * from the number of stamps needed until it is 0 or less than 0
     * */
    
    
    int needed_friends = 0;
    for(int i=0; i<number_of_aviable_friends;++i){
        if (number_of_stamps_needed <= 0)
            return needed_friends;
        else{
            number_of_stamps_needed -= stamps[i];
            needed_friends++;
        }
    }

    if (number_of_stamps_needed > 0)
        return 0;

    return 0;
}
