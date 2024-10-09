#include <iostream>
#define nl '\n'
using namespace std;


bool bears(int k){
    if(k == 42){
        return true;
    }
    if (k < 42){
        return false;
    }


    if(k % 5 == 0){
        if(bears (k- 42)){
            return true;
        }
    }

    if(k % 4 == 0 || k % 3 == 0){
        int l_digit = k % 10;
        int l2_digit = (k % 100) / 10;
        int value_to_return = l_digit * l2_digit;
        if(value_to_return > 0){
            if(bears((k - value_to_return))){
                return true;
            }
        }
    }

    if(k % 2 == 0){
        if(bears (k / 2)){
            return true;
        }
    }
    return false;
}

int main() {
    int k;
    cin >> k;
    cout << (bears(k) ? "true" : "false");
}
