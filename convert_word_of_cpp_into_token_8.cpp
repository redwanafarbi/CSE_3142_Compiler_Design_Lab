#include <iostream>
#include <string>
using namespace std;

string getTokenType(const string& token) {
    if (token == "int" || token == "float" || token == "double" || token == "char" || token == "bool") {
        return "Data Type";
    }
    else if (token == "if" || token == "else" || token == "while" || token == "for" || token == "do" || token == "switch") {
        return "Keyword";
    }
    else if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%") {
        return "Arithmetic Operator";
    }
    else if (token == "=" || token == "==" || token == "!=" || token == ">" || token == "<" || token == ">=" || token == "<=") {
        return "Comparison Operator";
    }
    else if (token == "true" || token == "false") {
        return "Boolean Literal";
    }
    else if (token.find_first_not_of("0123456789") == string::npos) {
        return "Integer";
    }
    else if (token.find_first_not_of("0123456789.") == string::npos) {
        return "Float";
    }
    else {
        return "Identifier";
    }
}

int main() {
    int test_case;
    cin >> test_case;
    string input;

    while (test_case--)
    {
        cout << "Enter a word/token: ";
        cin >> input;
        string tokenType = getTokenType(input);
        cout << "Output: " << tokenType << endl;
    }

    return 0;
}
