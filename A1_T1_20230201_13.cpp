#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <map>
#define nl '\n'
using namespace std;

// Function to convert all characters in a string to lower case.
string to_lower(string s, string val = "") {
    for (auto c : s) {
        if (isalpha(c)) {
            val += tolower(c);
        } else {
            return s; // Return the original string if a non-alphabetic character is found.
        }
    }
    return val;
}

int main() {
    // Initiating variables
    string email; // To store the email filename
    string email_contents; // To store the contents of the email
    string line; // To store each line read from the file
    int check = 0; // Counter to determine phishing likelihood

    // Getting the file name from user input
    cin >> email;

    // Opening the file for reading
    ifstream email_read(email);

    // Reading input from the file line by line
    while (getline(email_read, line)) {
        email_contents += to_lower(line) + " "; // Convert each line to lower case and append to contents
    }

    // Initiating a vector with the 30 most common words used in phishing attempts
    vector<string> words {
            "urgent", "immediate", "action required", "account", "verification", "suspicious",
            "lock", "update", "security", "payment", "refund", "invoice",
            "confirm", "click here", "login", "password", "unusual", "congratulations",
            "limited time", "dear valued customer", "you won", "notice", "request", "threat",
            "compromised", "deadline", "important", "review", "contact", "claim",
    };

    // Map for counting the occurrences of each word
    map<string, int> number_occ;

    // Iterate over the common phishing words
    for (const string& word : words) {
        auto pos = 0; // Position to search for the word
        while ((pos = email_contents.find(word, pos)) != string::npos) {
            number_occ[word]++; // Increment count for the word found
            pos += word.length(); // Move position forward to continue searching
        }
    }

    // Output the count of each phishing word found
    for (auto entry : number_occ) {
        cout << entry.first << " " << entry.second << nl; // Print the word and its count
        check += entry.second; // Increment the check counter
    }

    // Determine and output the likelihood of phishing based on the counts
    if (check >= 2) {
        cout << "moderately likely phishing email" << nl;
    } else if (check == 1) {
        cout << "somewhat likely phishing email" << nl;
    } else {
        cout << "highly likely phishing email" << nl;
    }
}
