#include<iostream>
#include <string.h>

using namespace std;

/**
 Implements a range update range query binary index tree
 For info about binary index tree see:
 https://www.hackerearth.com/practice/notes/binary-indexed-tree-made-easy-2/
 https://www.youtube.com/watch?v=v_wj_mOAlig
 http://zobayer.blogspot.com/2013/11/various-usage-of-bit.html
 https://stackoverflow.com/questions/27875691/need-a-clear-explanation-of-range-updates-and-range-queries-binary-indexed-tree
**/
class BinaryIndexTree{
    private:
        long long *bit;
        long long *bit2;
        long long bit_size;
    
    /**
        updates the value in the given index by the given value in the given tree
    **/
    void internal_update(long long index, long long v, long long tree[]){
        index++;
        while(index < bit_size){
            tree[index] += v;
            index += index & (-index);
        }
        
    }

    /**
        returns the point sum for the given index of the given tree
    **/
    long long internal_sum(long long index, long long tree[]){
        long long sum = 0;
        index++;
        while(index > 0){
            sum += tree[index];
            index -= index & (-index);
        }
        return sum;
    }

    long long getSum(long long index){
        return (internal_sum(index, bit)*index) - internal_sum(index,bit2);
    }

    public:
        BinaryIndexTree(long long bit_size){
            this -> bit_size = bit_size;
            this -> bit = new long long[bit_size];
            this -> bit2 = new long long[bit_size];
        }
        ~BinaryIndexTree(){
            delete [] bit;
            delete [] bit2;
        }

        /**
            Sets to zero all the positions of the two binary index trees arrays
        **/
        void initTree(){
            memset(bit, 0, bit_size*sizeof(bit));
            memset(bit2, 0, bit_size*sizeof(bit2));
        }

        /**
            Update the binary index tree in the given range by the given value
        **/
        void update(long long a, long long b, long long v){
            
            internal_update(a, v, bit);
            internal_update(b+1, -v, bit);
            
            internal_update(a, v*(a-1), bit2);
            internal_update(b+1, -v*b, bit2);
        }

        /**
            returns the sum of all the elements in the given range inclusive
        **/
        long long sum(long long a, long long b){
            return getSum(b) - getSum(a-1);
        }
};

int main(){
    long long test_cases;
    long long N,C,o,p,q,v;
    
    ios_base::sync_with_stdio(false);
    cin>>test_cases;
    for(long long i = 0; i < test_cases; ++i){
        cin>>N>>C;
        BinaryIndexTree bit(100005);
        bit.initTree();
        for(long long j = 0; j < C; ++j){
            cin>>o;
            if(o == 0){
                cin>>p>>q>>v;
                bit.update(p,q,v);
            }
            else{
                cin>>p>>q;
                cout<<bit.sum(p,q)<<endl;
            }
        }
        //bit.initTree();
    }
    return 0;
}