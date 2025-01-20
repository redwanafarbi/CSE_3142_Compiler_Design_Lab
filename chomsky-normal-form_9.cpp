#include<bits/stdc++.h>
using namespace std;


int main() {

    string s;
    cout << "Enter a sentence: " ;
    getline(cin, s);

    set<string>pn = { "Sagor","Selim","Salma","Nipu" };
    set<string>p = { "he","she","I","you","we","they" };
    set<string>n = { "book","cow","dog","home","grass","rice","mango" };
    set<string>v = { "read","eat","take","run","write" };
    vector<string>words;

    int pre = 0;
    int end = 0;
    int l = s.length();

    for (int i = 0; i < l; i++) {
        if (s[i] == ' ' || s[i] == '.') {
            end = i;
            string x = s.substr(pre, abs(end - pre));
            pre = i + 1;
            //cout << x << endl;
            words.push_back(x);
        }
    }

    int count = 0;

    if (words.size() != 3) {
        cout << "Invalid" << endl;
        return 0;
    }

    else {
        int idx = 3;
        while (idx--)
        {
            string word = words[count];
            //cout << word << endl;
            count++;

            if (count == 1 && !pn.count(word) && !p.count(word)) {
                cout << "Invalid" << endl;
                return 0;
            }
            else if (count == 2 && !v.count(word)) {
                cout << "Invalid" << endl;
                return 0;
            }
            else if (count == 3 && !n.count(word)) {
                cout << "Invalid" << endl;
                return 0;
            }
        }
    }

    cout << "VALID" << endl;
}

/*
Sagor eat rice
*/