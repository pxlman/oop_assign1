#include <iostream>
#include <vector>
using namespace std;
//Function to split the string base on a certain delimter
void split(string target,char splt, vector<string>& ans){
    //Intiating empty string to add the answer to it
    string add;

    for(auto i = 0; i < target.length(); i++){
        //Check if the char is not equal to the delimter
        if(target[i] != splt){
            add += target[i];
        }
        else {
            //Adding the string add to the vector if the char is a delimter
            ans.push_back(add);
            //Resting the string add
            add = "";
        }
    }
    //Pushing the last sub string (if any) to the vector
    ans.push_back(add);
}
