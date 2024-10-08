#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<pair<string, int>> player;

void Problem2() {
    cout << "Enter a sentence: ";
    string s;
    getline(cin, s);
    string word = "";
    bool flag = true;
    string male[6] = {"He", "he", "Him", "him", "His", "his"};
    string all[6] = {"He or she", "he or she", "Him or her", "him or her",
                     "His or her", "his or her"};
    vector <string> wrd;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] != ' ')
            word += s[i];
        if(s[i] == ' ' || i == s.size()-1){
            wrd.push_back(word);
            word = "";
        }
    }
    for(string p: wrd){
        for (int i = 0; i < 6; ++i) {
            if(p == male[i]) {
                p = all[i];
                break;
            }
            else if(p == male[i] + '.'){
                p = all[i] + '.';
                break;
            }
        }
        cout << p << " ";
    }
}
// -----------------------------------------
void Add();
void Show();
void Find();

void Problem5(){
    cout << "A) Add a New Player and Score\n"
         << "B) Print the top 10 names and scores\n"
         << "C) Find a Player with their name\n"
         << "D) Exit\n"
         << "Choice: ";
    char ch;
    cin >> ch;
    ch = char(toupper(ch));
    while(ch != 'A' && ch != 'B' && ch != 'C' && ch != 'D'){
        cout << "Please choose A or B or C!\n"
             << "Choice: ";
        cin >> ch;
        ch = char(toupper(ch));
    }
    if(ch == 'A'){
        Add();
    }
    else if(ch == 'B'){
        Show();
    }
    else if(ch == 'C'){
        Find();
    }
    else{
        exit(0);
    }
}

void Add(){
    cout << "Player's Name: ";
    string name;
    cin >> name;

    cout << "Player's Score: ";
    int score;
    cin >> score;

    bool flag;
    int first;
    player.push_back({name, score});
    if(player.size() > 1){
        for (int j = 0; j < player.size()-1; ++j) {
            for (int i = 0; i < player.size()-1; ++i) {
                if (player.at(i).second < player.at(i + 1).second) {
                    swap(player.at(i).second, player.at(i + 1).second);
                    swap(player.at(i).first, player.at(i + 1).first);
                }
            }
        }
        if(player.back().second > player.at(player.size()-2).second){
            swap(player.back().second, player.at(player.size()-2).second);
            swap(player.back().first, player.at(player.size()-2).first);

        }
    }

    Problem5();
}

void Show(){
    if(player.empty()){
        cout << "There are no players in the list!\n"
             << "1) Add a New Player and Score\n"
             << "2) Exit\n"
             << "Choice: ";
        int action;
        cin >> action;
        while(action < 1 || action > 2){
            cout << action << " is out of the range!\n"
                 << "Please choose 1 or 2\nChoice: ";
            cin >> action;
        }
        if(action == 1)
            Add();
        else
            exit(0);
    }
    if(player.size() > 10) {
        for (int i = 0; i < 10; ++i) {
            cout << player.at(i).first << " " << player.at(i).second << endl;
        }
    }
    else{
        for (int i = 0; i < player.size(); ++i) {
            cout << player.at(i).first << " " << player.at(i).second << endl;
        }
    }
}

void Find(){
    if(player.empty()){
        cout << "There are no players in the list!\n"
             << "1) Add a New Player and Score\n"
             << "2) Exit\n"
             << "Choice: ";
        int action;
        cin >> action;
        while(action < 1 || action > 2){
            cout << action << " is out of the range!\n"
                 << "Please choose 1 or 2\nChoice: ";
            cin >> action;
        }
        if(action == 1)
            Add();
        else
            exit(0);
    }
    string s;
    bool b;

    cout << "Name: ";
    cin >> s;
    while(true) {
        for (char c: s) {
            if (!isalpha(c)) {
                b = false;
            }
        }
        if(b == 0){
            cout << "Please characters only!\n"
                 << "Name: ";
            cin >> s;
        }
        else{
            break;
        }
    }
    vector <int> find;
    bool flag1;
    bool flag2;
    if(player.size() > 10) {
        flag2 = false;
        for (int i = 0; i < 10; ++i) {
            if (s == player.at(i).first){
                find.push_back(player.at(i).second);
                flag2 = true;
            }
        }
    }
    else {
        flag1 = false;
        for (const pair<string, int> &print: player) {
            if (s == print.first) {
                find.push_back(print.second);
                flag1 = true;
            }
        }
    }
    if(flag1 == 0)
        cout << "Sorry, this name doesn't exist in the list!\n";
    else if(flag2 == 0)
        cout << "Sorry, this name doesn't exist in the top 10\n";
    else
        cout << *max_element(find.begin(), find.end());

    cout << "\n1) Other Name\n2) Main menu\nChoice: ";
    int ch;
    cin >> ch;
    while(ch < 1 || ch > 2){
        cout << "Please choose 1 or 2!\n" << "Choice: ";
        cin >> ch;
    }
    if(ch == 1)
        Find();
    else
        Problem5();

}
bool check(int num){
    return(ceil(log2(num) == floor(log2(num))));
}
void Problem8(int n, int i, int num){
    for (int j = 0; j < i; ++j) {
        cout << ' ';
    }
    static int cnt = 0;
    string space = "";
    cnt++;
    cout << "*\n";
    for (int j = 0; j < num; ++j) {
        cout << "* ";
        space += ' ';
    }
    cout << endl << space;

    if(cnt != n){
        if(num * 2 > n)
            return Problem8(n,i,num);
        else{
            num *= 2;
            return Problem8(n,i,num);
        }

    }
    else
        return;

}

void Problem11(){
    cout << "First file name: ";
    string file1, file2;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, file1);
    cout << "Second file name: ";
    getline(cin, file2);
    ifstream input1(file1 + ".txt");
    ifstream input2(file2 + ".txt");
    cout << "1) Character by Character\n2) Word by Word\nChoice: ";
    int ch;
    cin >> ch;
    while(ch < 1 || ch > 2){
        cout << "Please choose 1 or 2\nChoice: ";
        cin >> ch;
    }
    if(ch == 1){
        bool flag = true;
        char wrd1, wrd2;
        while(!input1.eof() || !input2.eof()) {
            input1.get(wrd1);
            input2.get(wrd2);
            if(wrd1 != wrd2) {
                cout << wrd1;
                flag = false;
            }
        }
        if(flag == 1){
            ifstream print(file1 + ".txt");
            while(!print.eof()){
                char  wrd;
                print.get(wrd);
                cout << wrd;
            }
        }
    }
    else{
        bool flag = true;
        string wrd1, wrd2;
        while(!input1.eof() || !input2.eof()) {
            input1 >> wrd1;
            input2 >> wrd2;
            if(wrd1 != wrd2) {
                cout << wrd1;
                flag = false;
            }
        }
        if(flag == 1){
            ifstream print(file1 + ".txt");
            while(!print.eof()){
                string wrd;
                print >> wrd;
                cout << wrd;
            }
        }
    }
}

int main() {
    int problem;
    cin >> problem;
    if(problem == 8) {
        cout << "Welcome To Our Program!\n";
        // Problem2();
        // menu();

        int n, i;
        cout << "Please enter a power of 2: ";
        cin >> n;
        while (n == 1 || check(n) == 0) {
            cout << "Power of 2 only please: ";
            cin >> n;

        }
        cout << "Start from index: ";
        cin >> i;
        Problem8(n, i, 2);
    }
}