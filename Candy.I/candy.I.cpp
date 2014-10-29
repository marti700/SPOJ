#include<iostream>

using namespace std;

int number_of_moves(int, int, int*);

int main()
{
    int number_of_packets;
    int number_of_candies_in_packet;
    int total_candies = 0;
    int max_candies_per_packets;

    while (cin>>number_of_packets){
        if (number_of_packets == -1)
            break;
        
        int* number_of_candies_per_packet = new int[number_of_packets];
        
        //Reads the candies of each packet
        for (int i=0; i<number_of_packets; ++i){
            cin>>number_of_candies_per_packet[i];
            total_candies += number_of_candies_per_packet[i];   //sum the total number of candies to calculate the mean leater
        }
 
        // if the modulo of the total candies and the number of candy packets are not 0 theres no way each candy packet
        // can have the same number of candies, this is easy math :)
        if (total_candies % number_of_packets !=0)           
            cout<<"-1"<<endl;

        else {
            max_candies_per_packets = total_candies/number_of_packets;   //this is the number of candies a packet should have
            cout<<number_of_moves(max_candies_per_packets, number_of_packets, number_of_candies_per_packet)<<endl;
        }

        delete [] number_of_candies_per_packet;  
        total_candies = 0;
    }

    return 0;

}

int number_of_moves(int max_candies_per_packets, int number_of_packets, int* number_of_candies_per_packet)
{
    
    /* The terminates the max number of moves using the following ecuation:
     * current_number_of_candies - X = max_candies_per_packets
     * this ecuation is only applied to those candy packets that have more candies that it should have 
     * and this is determinated by:  sum_of_all_candies/ number_of_candies_per_packets
     *
     * what the algotithm does is iterate through the array until it finds a number greater than the 
     * max number of candies a packet should have and then applies the above explained ecuation.
     * */
    
    int moves = 0;
    
    for(int i=0; i<number_of_packets; ++i){
        if (number_of_candies_per_packet[i] > max_candies_per_packets)
            moves += number_of_candies_per_packet[i] - max_candies_per_packets; 
    }

    return moves;
}
