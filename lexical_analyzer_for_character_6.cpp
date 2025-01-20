#include<bits/stdc++.h>
using namespace std ;

bool character_var(string x){
    int l = x.length();
    bool isStartOk = false;
    bool isEndOk = true;

    if(l<5) return false;

    if(x[0]=='c' && x[1]=='h' && x[2]=='_'){
        isStartOk = true;
    }

    for(int i = 3 ; i<l ; i++){
        if((x[i]>='a' && x[i]<='z') || (x[i]>='A' && x[i]<='Z') || (x[i]>='0' && x[i]<='9')){
            continue;
        }else{
            isEndOk = false;
            break;
        }
    }

    return isStartOk && isEndOk ;

}

bool binary_var(string x){
    int l = x.length();
    bool isStartOk = false;
    bool isEndOk = true;

    if(l<5) return false;
    
    if(x[0]=='b' && x[1]=='n' && x[2]=='_'){
        isStartOk = true;
    }

    for(int i = 3 ; i<l ; i++){
        if((x[i]>='a' && x[i]<='z') || (x[i]>='A' && x[i]<='Z') || (x[i]>='0' && x[i]<='9')){
            continue;
        }else{
            isEndOk = false;
            break;
        }
    }

    return isStartOk && isEndOk ;
}

bool binary_num(string x){
    int l = x.length();
    bool isStartOk = false;
    bool isEndOk = true;

    if(l<3) return false;

    if(x[0]=='0' && (x[1]=='0' || x[1]=='1')){
        isStartOk = true;
    }

    for(int i = 2 ; i<l ; i++){
        if((x[i]>='a' && x[i]<='z') || (x[i]>='A' && x[i]<='Z') || (x[i]>='0' && x[i]<='9')){
            continue;
        }else{
            isEndOk = false;
            break;
        }
    }

    return isStartOk && isEndOk ;

}

int main(){

    freopen("./lexical_analyzer_for_character_6.txt", "r", stdin);
    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        string line;
        cin >> line ;

        if(character_var(line)){
            cout << line << ": Character variable" << endl;
        }else if(binary_var(line)){
            cout << line << ": Binary variable" << endl;
        }else if(binary_num(line)){
            cout << line << ": Binary Number" << endl;
        }else {
            cout << line << ": Invalid Input or Undefined" << endl;
        }
    }
}