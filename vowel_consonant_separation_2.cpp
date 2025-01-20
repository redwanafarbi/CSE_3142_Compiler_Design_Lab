#include<bits/stdc++.h>
using namespace std;

void solve(string s) {
    int l = s.length();

    vector<char>vowels;
    vector<char>consonants;
    vector<string>v_str;
    vector<string>c_str;
    map<char,char>mp;

    for (int i = 0; i < l;i++) {
        char c = s[i];
        if (c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' || c == 'i' || c == 'O' || c == 'o' || c == 'U' || c == 'u') {
            vowels.push_back(c);
            mp[c] = 'V';
        }
        else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            consonants.push_back(c);
            mp[c] = 'C';
        }
    }

    int pre_idx = 0 ;
    int idx = 0;

    for(int i = 0; i<l ; i++){
        if(s[i] == ' ' || s[i] == '.'){
            idx = i;
            string x = s.substr(pre_idx,abs(idx-pre_idx));
            pre_idx = i+1;

            char first = x[0];
            if(mp[first] == 'V'){
                v_str.push_back(x);
            }else if(mp[first] == 'C'){
                c_str.push_back(x);
            }
        }
    }

    cout << "Number of vowels: " << vowels.size() << endl;
    cout << "Number of consonants: " << consonants.size() << endl;

    cout << "Vowels in the string are: ";
    for (int i = 0; i < vowels.size();i++) {
        cout << vowels[i] << " ";
    }
    cout << endl;

    cout << "Consonants in the string are: ";
    for (int i = 0; i < consonants.size();i++) {
        cout << consonants[i] << " ";
    }
    cout << endl;

    cout << "Strings started with vowels: ";
    for(int k = 0 ; k<v_str.size() ; k++){
        cout << v_str[k] << " ";
    }
    cout << endl;

    cout << "Strings started with consonants: ";
    for (int i = 0; i<c_str.size();i++) {
        cout << c_str[i] << " ";
    }
    cout << endl;

}

int main() {
    freopen("vowel_consonant_separation.txt", "r", stdin);

    string s;
    getline(cin, s);
    cout << s << endl;

    solve(s);
}