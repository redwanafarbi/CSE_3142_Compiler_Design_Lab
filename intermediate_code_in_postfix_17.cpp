#include<iostream>
using namespace std;

int const MAX = 100;
int top = -1;
char stack[MAX];

void solve(string s);
void infixToPostfix(string s);
void push(char n);
char pop();
int isFull();
int isEmpty();
int precedence(char x);
bool els = false;
vector<char>ans;

int main() {

    string infix;
    getline(cin, infix);

    solve(infix);

}

void solve(string s) {
    string temp = "";
    string res = "";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            continue;
        }

        temp = temp + s[i];
        //cout << temp << endl;

        if (temp == "if") {
            temp = "";
        }

        if (temp.length() > 4) {
            if (temp.find("then") != -1) {
                temp.erase(temp.length() - 4);
                res = res + temp + "";
                infixToPostfix(temp);
                temp = "";
            }

            else if (temp.find("else") != -1) {
                temp.erase(temp.length() - 4);
                res = res + temp + "";
                infixToPostfix(temp);
                temp = "";
                els = true;
            }
        }
    }

    res = res + temp;
    infixToPostfix(temp);
    cout << "Infix Notation: " << res << endl;

    cout << "Postfix Notation: " ;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
    cout << endl;
}

void infixToPostfix(string s) {

    push('(');
    s += ')';

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        if (isalpha(ch)) {
            //cout << ch;
            ans.push_back(ch);
        }

        else {
            char top_ch = stack[top];

            if (precedence(top_ch) > precedence(ch) && ch != '(') {
                char tc = stack[top];
                ans.push_back(tc);
                //cout << "TOP" << tc << endl;
                //cout << pop();
                pop();
                push(ch);
            }

            else if (ch == ')') {
                while (stack[top] != '(')
                {
                    char tc = stack[top];
                    ans.push_back(tc);
                    //cout << "TOP" << tc << endl;
                    //cout << pop();
                    pop();
                }
                pop();
            }

            else {
                push(ch);
            }
        }
    }

    if (els) {
        // cout << "?";
        ans.push_back('?');
        els = false;
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
    }
    else {
        cout << "Stack is Empty" << endl;
        return -1;
    }
}

int isFull() {
    if (top == MAX) {
        return 1;
    }
    else {
        return 0;
    }
}

int isEmpty() {
    if (top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int precedence(char x) {

    if (x == '(') {
        return 0;
    }
    else if (x == '+' || x == '-') {
        return 1;
    }
    else if (x == '*' || x == '/') {
        return 2;
    }
    else {
        return 3;
    }

}


/*
if a then if c-d then a+c else a*c else a+b
*/