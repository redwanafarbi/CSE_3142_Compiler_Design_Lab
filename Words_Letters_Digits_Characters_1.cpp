#include<bits/stdc++.h>
using namespace std ;

void solve(string s){

    int l = s.length();
    int words = 1;
    int letters = 0;
    int digits = 0;
    int other_chars = 0;

    vector<char>letter;
    vector<int>digit;
    vector<char>other_char ;

    for(int i = 0 ; i<l ; i++){
        if((s[i]>= 'A' && s[i]<='Z') || (s[i]>= 'a' && s[i]<='z')){
            letters++;
            letter.push_back(s[i]);
        }else if(s[i]>= '0' && s[i]<='9'){
            digits++;
            digit.push_back(s[i]);
        }else if(s[i] == ' '){
            words++;
        }else{
            other_chars++;
            other_char.push_back(s[i]);
        }
    }

    cout << "Number of words = " << words << endl;
    cout << "Number of letters = " << letters << endl;
    cout << "Number of digits = " << digits << endl;
    cout << "Number of other characters = " << other_chars << endl;

    cout << "Letters: " ;
    for(int i = 0 ; i<letters ; i++){
        cout << letter[i] << " ";
    }

    cout << endl;

    cout << "Digits: " ;
    for(int i = 0 ; i<digits ; i++){
        cout << digit[i]-'0' << " ";
    }

    cout << endl;

    cout << "Other Characters: " ;
    for(int i = 0 ; i<other_chars ; i++){
        cout << other_char[i] << " ";
    }

    cout << endl;

}

int main(){

    freopen("Words_Letters_Digits_Characters.txt" , "r" , stdin);
    string s;

    getline(cin,s);

    solve(s);


}