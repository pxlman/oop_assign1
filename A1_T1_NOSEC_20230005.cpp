// Online C++ compiler to run C++ program online
#include <iostream>
#include<set>
#include<vector>
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
bool isInt(float n){
  if((float)(n) - (int)n == 0) return true;
  else return false;
}
int problem4(){
  int N; cin >> N;
  int nPrimes = 0;
  set<int>marked;
  set<int>unmarked;
  for (int i = 2; i < N; i++)
  {
    if(marked.count(i)){
      continue;
    }else{
      nPrimes++;
      unmarked.insert(i);
      for (int j = 2; j*i <= N; j++)
      {
        marked.insert(i*j);
      }
    }
  }
  for (auto &&i : unmarked)
  {
    cout << i << ' ';
  }
  cout << '\n';
  cout << nPrimes;
  return 0;
}
struct dominoC {
  int l;
  int r;
};
int findDomin(int n, bool left, vector<dominoC> dominos, int start){
  int found = -1;
  if (left) {
    for (int i = start; i < dominos.size(); i++) {
      if(dominos[i].l == n) return i;
    }
  }else {
    for (int i = start; i < dominos.size(); i++) {
      if(dominos[i].r == n) return i;
    }
  }
  return found;
}
// bool FormsDominoChain(vector<dominoC> & dominos, int end){
//   int start = 0;
//   static int back = 0;
//   // base case
//   if(end == dominos.size()){
//     return true;
//   }
//   // 
//   int foundr = findDomin(dominos[end].r, true, dominos, end+1);
//   if(foundr != -1){
//     // add the domino to the right of the ranged dominos
//     dominoC val = dominos[foundr];
//     dominos.erase(dominos.begin() + foundr);
//     dominos.insert(dominos.begin()+ end + 1, val);
//     return FormsDominoChain(dominos,end+1);
//   }else{
//     int foundl = findDomin(dominos[start].l, false, dominos, end+1);
//     if(foundl == -1){
//       if(dominos.size() - back -1 > end){
//         dominoC val = dominos[end];
//         dominos.erase(dominos.begin() + end);
//         dominos.emplace_back(val);
//         back++;
//         return FormsDominoChain(dominos,end+1);
//       }else {
//         return false;
//       }
//     }
//     else {
//       // add the domino to the left of the ranged dominos
//       dominoC val = dominos[foundl];
//       dominos.erase(dominos.begin() + foundl);
//       dominos.insert(dominos.begin()+ start, val);
//     return FormsDominoChain(dominos, end+1);
//     }
//   }
// }

bool FormsDominoChain(vector<dominoC> & dominos, int sortedi){
  if(sortedi == dominos.size()){
    return true;
  }
  // Trying to add to the right
  int foundr = findDomin(dominos[sortedi].r, false, dominos, sortedi+1);
  // if failed to find a domino to the right will break
  bool solve = false;
  if(foundr != -1){
    dominoC val = dominos[foundr];
    dominos.erase(dominos.begin()+ foundr);
    dominos.insert(dominos.begin() + ++sortedi,val);
    solve = FormsDominoChain(dominos,sortedi);
  }

  if(solve) return false;
  // 10 1 6 2 3 5 1 0 6 2 4 3 5 4 0 6 2 3 3 6 6
  int foundl = findDomin(dominos[0].l, true, dominos, sortedi+1);
  if(foundl == -1 && foundr == -1) return false;
  dominoC val = dominos[foundl];
  dominos.erase(dominos.begin()+ foundl);
  dominos.insert(dominos.begin() + ++sortedi,val);
  solve = FormsDominoChain(dominos,sortedi);

  if(solve) return true; else return false;
}
  
int problem7(){
  int n; cin >> n;
  vector<dominoC> dominos;
  while(n--){
    int r,l; cin >> l >> r;
    dominos.push_back({l,r});
  }
  if(FormsDominoChain(dominos, 0)) cout << "Yes\n";
  for (auto &&i : dominos){
    cout << i.l << '|' << i.r << " ";
  }
  return 0;
}
int main()
{
  problem7();
  return 0;
}