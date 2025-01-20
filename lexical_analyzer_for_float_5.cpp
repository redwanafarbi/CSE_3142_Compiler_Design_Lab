#include <bits/stdc++.h>
using namespace std;


bool checkFloatVar(string x) {
    int n = x.length();
    bool isStartingOK = false;

    if (n > 1) {
        if ((x[0] >= 'a' && x[0] <= 'h') || (x[0] >= 'A' && x[0] <= 'H') || (x[0] >= 'o' && x[0] <= 'z') || (x[0] >= 'O' && x[0] <= 'Z')) {
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

bool checkFloatNum(string x) {
    int n = x.length();
    bool isStartingOK = false;

    if (n == 4)
    {
        if (x[0] == '0' && x[1] == '.')
        {
            return true;
        }
    }

    if (n >= 4)
    {
        if (x[0] >= '1' && x[n - 3] == '.')
        {
            return true;
        }
    }

    return false;

}

bool checkDouble(string x) {
    int n = x.length();
    int isStartingOK = 0;
    int dotIdx = 0;

    for(int i = 0 ; i<n ; i++)
    {
        if((x[i]>= '0' && x[i] <='9') || x[i]== '.')
        {
            isStartingOK++;
        }

        if(x[i]=='.')
        {
            dotIdx = i ;
        }
    }

    if ((isStartingOK!=n) || (n < 5)) return false;

    if (x[0] == '0' && x[1] == '.')
    {
        return true;
    }

    dotIdx++;
    if (x[0] == '1' && (n-dotIdx)>=3)
    {
        return true;
    }

    return false;

}


int main() {
    freopen("./lexical_analyzer_for_float_5.txt", "r", stdin);
    int testCases;
    cin >> testCases;

    while (testCases--) {
        string line;
        cin >> line;

        if (checkFloatVar(line)) {
            cout << line << ": Float Variable" << endl;
        }
        else if (checkFloatNum(line)) {
            cout << line << ": Float Number" << endl;
        }
        else if (checkDouble(line)) {
            cout << line << ": Double Number" << endl;
        }
        else {
            cout << line << ": Invalid Input" << endl;
        }
    }
}