#include<iostream>
using namespace std;

int const MAX = 100;
int top = -1;
char stack[MAX];

void push(char n);
char pop();
int isFull();
int isEmpty();
int precedence(char x);

int main() {

    string infix;
    cin >> infix;

    push('(');
    infix += ')';

    for(int i = 0 ; i<infix.length(); i++){
        char ch = infix[i];

        if(isalpha(ch)){
            cout << ch ;
        }else {
            char top_ch = stack[top];

            if(precedence(top_ch)>precedence(ch) && ch!='(' ){
                cout << pop() ;
                push(ch);
            }

            else if(ch==')'){
                while (stack[top] != '(')
                {
                    cout << pop() ;
                }
                pop();
            }

            else{
                push(ch);
            }
        }
    }

}

void push(char n) {

    if (!isFull()) {
        top++;
        stack[top] = n;
    }
    else {
        cout << "Stack is Full" << endl;
    }
}

char pop() {

    if (!isEmpty()) {
        char temp = stack[top];
        top--;
        return temp;
    }else{ 
        cout << "Stack is Empty" << endl;
        return -1;
    }
}

int isFull() {
    if(top == MAX){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty() {
    if(top == -1){
        return 1;
    }else{
        return 0 ;
    }
}

int precedence(char x) {

    if(x == '('){
        return 0;
    }else if(x=='+' || x=='-'){
        return 1;
    }else if(x=='*' || x=='/'){
        return 2;
    }else{
        return 3;
    }

}


/*
(A-B)*(D/E)
*/