#include <iostream>
using namespace std;
#define nl '\n'


//Decimal to binary function
int bin(int n){
    if(n == 0) // base case
        return 0;

    return n % 2 + 10 * (bin( n / 2)); // recursive case
}
//Function to get all possible suffix combinations
void all_suffix_combination(string prefix, int k){
    //Base case
    if(k == 0)
        cout << prefix << nl;

        //Recursive case
    else {
        all_suffix_combination(prefix + '0',k-1);
        all_suffix_combination(prefix + '1',k-1);
    }
}

