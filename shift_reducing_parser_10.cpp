#include<bits/stdc++.h>
using namespace std;

map<string, string> rules = {{"S+S", "S"}, {"S*S", "S"}, {"(S)", "S"},{"id", "S"}};

int main(){
    string s;
    cin >> s;

    string temp = "";
    for(int i = 0; i<s.length(); i++){
        if(s[i]=='i' && s[i+1]=='d'){
            temp = temp + 'S';
            i++;
        }else{
            temp = temp + s[i];
        }
    }

    string res="";
    for(int i = 0 ; i<temp.length(); i++){
        res = res + temp[i];
        if(rules[res]!=""){
            res =  rules[res];
        }

        if(i == temp.length()-1 && res.length()==1){
            if(res == "S"){
                cout << "Accepted" << endl;
                return 0;
            }
        }
    }

    cout << "Rejected" << endl;


}