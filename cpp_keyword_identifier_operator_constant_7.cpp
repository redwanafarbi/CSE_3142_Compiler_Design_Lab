#include<bits/stdc++.h>
using namespace std;

bool isKeyword(string x){
    vector<string>keyword = {"auto","break","case","char","const","continue","default","do","double","else","enum","extern",
    "float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union",
    "unsigned","void","volatile","while","asm","dynamic_cast","namespace","reinterpret_cast","bool","explicit","new","static_cast","true","false","catch","operator",
    "template","friend","private","class","this","inline","public","throw","const_cast","try","wchar_t","virtual","protected","using","mutable","typename","typeid","delete"};

    for(int i = 0 ; i<keyword.size(); i++){
        if(x==keyword[i]){
            return true ;
        }
    }

}

bool isOperator(string x){
    vector<string>op = {"+","-","*","/","%"};

    for(int i = 0 ; i<op.size(); i++){
        if(x == op[i]){
            return true ;
        }
    }
    return false;
}

bool isIdentifier(string x){

    if(x[0]>='0' && x[0]<='9'){
        return false ;
    }

    if(x[0]=='_' || (tolower(x[0])>='a' && tolower(x[0])<='z')){
        return true;
    }

    return false;
}

bool isConstant(string x)
{
    char cot = '"';
    if (x[0] == cot and x[x.size() - 1] == cot)
    {
        return true;
    }
    for (int i = 0; x[i]; i++)
    {
        if (isdigit(x[i]) or x[i] == '.')
        {
            continue;
        }
        return false;
    }
    return true;
}


int main(){

    string word;
    cin >> word;
    if (isKeyword(word)) cout << "Keyword\n";
    else if (isIdentifier(word)) cout << "Identifier\n";
    else if (isOperator(word)) cout << "Operator\n";
    else if (isConstant(word)) cout << "Constant\n";
    else cout << "Invalid\n";

}