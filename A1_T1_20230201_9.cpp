#include <iostream>
#define nl '\n'
using namespace std;

//Function to check bears count can reach 42 using recurrsion
bool bears(int k){
    //Case cases
        if(k == 42){
            return true;
        }
        if (k < 42){
            return false;
        }
        
    //Check if the number mod 5 equalls 0
    if(k % 5 == 0){
        if(bears (k- 42)){
            return true;
        }
    }
    //Check if number is mod 4 or 3 equalls 0
    if(k % 4 == 0 || k % 3 == 0){

        int l_digit = k % 10; //Getting last digit
        int l2_digit = (k % 100) / 10;//Getting second last digit
        int value_to_return = l_digit * l2_digit;
       //Condition to check if the multiplying condtion doesn't equal 0
        if(value_to_return > 0){
            if(bears((k - value_to_return))){
                return true;
            }
        }
    }
    //Check if number is even
    if(k % 2 == 0){
        if(bears (k / 2)){
            return true;
        }
    }

    //basic return value
    return false;
}

int main() {
    int k;
    cin >> k;
    cout << (bears(k) ? "true" : "false");
}
