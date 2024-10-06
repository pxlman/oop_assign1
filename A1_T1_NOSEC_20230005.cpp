// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int problem1()
{
  string sent;
  getline(cin, sent);
  if (sent.length() > 100)
  {
    cout << "Sentece must be less than 100 characters";
    return 1;
  }
  // blanking
  {
    int secondSpace = -1;
    for (int i = 1; i < sent.length(); i++)
    {
      if((sent[i] != ' ' && sent[i] != '\t')){
        if(secondSpace > -1){
          sent.erase(secondSpace, i - secondSpace);
          secondSpace = -1;
        }
      }else{
        if(secondSpace == -1 && (sent[i-1] == ' ' || sent[i-1] == '\t')) secondSpace = i;
      }
    }
    for (int i = sent.length()-1; i > 0; i--)
    {
      if(sent[i] == ' ' || sent[i] == '\t'){
        sent.erase(sent.begin() + i);
      }else{
        break;
      }
    }
    while(sent[0] == ' ' || sent[0] == '\t'){
      sent.erase(sent.begin());
    }
  }
  // First char
  sent[0] = (sent[0] <= 'z' && sent[0] >= 'a') ? sent[0] - 32 : sent[0];
  // Other must be lowerd
  for (int i = 1; i < sent.length(); i++)
  {
    if (sent[i] >= 'A' && sent[i] <= 'Z')
    {
      sent[i] += 32;
    }
  }

  // Adding dot to the end
  if(sent[sent.length()-1] != '.'){
    sent += '.';
  }
  if(sent[sent.length()-2] == ' '){
    sent.erase(sent.begin() + sent.length() - 2);
  }

  // Adding space after comma
  for (int i = 0; i < sent.length(); i++)
  {
    if (sent[i] == ',')
    {
      if(sent[i+1] != ' ') sent.insert(sent.begin() + i + 1, ' ');
      if(sent[i-1] == ' ') sent.erase(sent.begin() + i - 1);
    }
  }
  

  cout << sent;
  return 0;
}
int problem4(){

}
int main()
{
  problem1();
  return 0;
}