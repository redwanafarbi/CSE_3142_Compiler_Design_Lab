#include<bits/stdc++.h>
using namespace std;

string s;

bool operatorcheck() {
    int l = s.length() - 1;
    if (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/') {
        return false;
    }

    if (s[l] == '+' || s[l] == '-' || s[l] == '*' || s[l] == '/') {
        return false;
    }

    for (int i = 1; i <= l; i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            if (s[i - 1] == '+' || s[i - 1] == '-' || s[i - 1] == '*' || s[i - 1] == '/') {
                return false;
            }
            else if (s[i - 1] == ')') {
                return false;
            }
        }
        if (s[i - 1] == '+' || s[i - 1] == '-' || s[i - 1] == '*' || s[i - 1] == '/') {
            if (s[i] == ')') {
                return false;
            }
        }
    }

    return true;
}

bool bracketCheck() {
    vector<string>bracket;
    int l = s.length() - 1;

    for (int i = 0; i <= l; i++) {
        if (s[i] == '(') {
            bracket.push_back("(");
        }

        else if (s[i] == ')') {
            if (!bracket.empty()) {
                bracket.pop_back();
            }
            else {
                return false;
            }
        }
    }

    if (bracket.empty()) return true;
    return false;

}


int main() {

    cout << "Enter a string: ";
    cin >> s;
    cout << endl;

    if (operatorcheck() && bracketCheck() ) {
        cout << "Valid" << endl;
    }
    else {
        cout << "Invalid" << endl;
    }


}