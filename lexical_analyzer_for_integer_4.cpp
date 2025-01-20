#include <bits/stdc++.h>
using namespace std;


bool checkInteger(string x) {
    int n = x.length();
    bool isStartingOK = false;

    if (n > 1) {
        if ((x[0] >= 'i' && x[0] <= 'n') || (x[0] >= 'I' && x[0] <= 'N')) {
            isStartingOK = true;
        }
    }

    bool isRestOk = true;

    for (int i = 1;i < n;i++) {
        if ((x[i] >= 'a' && x[i] <= 'z') || x[i] >= 'A' && x[i] <= 'Z' || x[i] >= '0' && x[i] <= '9') continue;
        else {
            isRestOk = false;
            break;
        }
    }

    return isStartingOK && isRestOk;
}

bool checkShortInteger(string x) {
    int n = x.length();
    bool isStartingOK = false;

    if (n > 0 && n < 5) {
        if (x[0] >= '1' && x[0] <= '9') {
            isStartingOK = true;
        }
    }
    else return false;

    bool isRestOk = true;

    for (int i = 1;i < n;i++) {
        if (x[i] >= '0' && x[i] <= '9') continue;
        else {
            isRestOk = false;
            break;
        }
    }

    return isStartingOK && isRestOk;
}

bool checkLongInteger(string x) {
    int n = x.length();
    bool isStartingOK = false;

    if (n < 5) return false;
    else {
        if (x[0] >= '1' && x[0] <= '9') {
            isStartingOK = true;
        }
    }

    bool isRestOk = true;

    for (int i = 1;i < 5;i++) {
        if (x[i] >= '0' && x[i] <= '9') continue;
        else {
            isRestOk = false;
            break;
        }
    }

    return isStartingOK && isRestOk;
}


int main() {
    freopen("./lexical_analyzer_for_integer_4.txt", "r", stdin);
    int testCases;
    cin >> testCases;

    while (testCases--) {
        string line;
        cin >> line;

        if (checkInteger(line)) {
            cout << line << ": Integer Variable" << endl;
        }
        else if (checkShortInteger(line)) {
            cout << line << ": ShortInt Number" << endl;
        }
        else if (checkLongInteger(line)) {
            cout << line << ": LongInt Number" << endl;
        }
        else {
            cout << line << ": Invalid Input" << endl;
        }
    }
}