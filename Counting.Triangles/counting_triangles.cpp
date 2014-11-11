#include<iostream>

using namespace std;

unsigned long long cont_triangles(unsigned long long);

int main()
{
    int number_of_test_cases;
    int input;

    cin>>number_of_test_cases;

    for (int i=0;i<number_of_test_cases; ++i){
        cin>>input;
        cout<<cont_triangles(input)<<endl;
    }
    return 0;
}

unsigned long long cont_triangles(unsigned long long tringle_level)
{
    /*
     * I was trying to get the math behind this problem so i google "how many tringles are in a tringle
     * and i fount this formula (n(n+2)*((2*n)+1))/8 which can be used to calculate how many tringles 
     * are inside any n level triangles.
     * */
    return (tringle_level* (tringle_level+2) * ((2*tringle_level) + 1))/8;
}
