#include <iostream>
#include <string>

const size_t maxCap = 100;
char stack[maxCap];
int top = -1, elements = maxCap;
char newData;

bool isEmpty();
bool isFull();
void push(char);
char pop();
char Top();
bool isOpening(char);
bool isClosing(char);
bool isMatching(char, char);
bool checkBalanced(std::string);

int main(){
    std::string expression;

    std::cout << "Enter a sample expression: ";
    getline(std::cin, expression);

    if(checkBalanced(expression))
        std::cout << "\nThe given expression is Balanced.\n";
    else
        std::cout << "\nThe given expression is Unbalanced.\n";

    return 0;
}

bool isEmpty(){
    if(top == -1){
        return true;
    }
    return false;
}

bool isFull(){
    if(top >= elements - 1){
        std::cout << "Stack Overflow\n";
        return true;
    }
    return false;
}

void push(char symbol){
    if(isFull()) return;
    stack[++top] = symbol;
}

char pop(){
    if(isEmpty()){
        return '\0';
    }
    return stack[top--];
}

char Top(){
    if(isEmpty()){
        return '\0';
    }
    return stack[top];
}

bool isOpening(char ch){
    return ch == '(' || ch == '{' || ch == '[';
}

bool isClosing(char ch){
    return ch == ')' || ch == '}' || ch == ']';
}

bool isMatching(char open, char close){
    if(open == '(' && close == ')')
        return true;
    if(open == '{' && close == '}')
        return true;
    if(open == '[' && close == ']')
        return true;
    return false;
}

bool checkBalanced(std::string expression){
    top = -1;

    for(char ch : expression){
        if(isOpening(ch)){
            push(ch);
        }
        else if(isClosing(ch)){
            if(isEmpty()){
                std::cout << "Error with Closing Symbol '" << ch << "' Symbol Mismatch.\n";
                return false;
            }
            char open = pop();
            if(!isMatching(open, ch)){
                std::cout << "Error. '" << open << "' mismatch '" << ch << "'.\n";
                return false;
            }
        }
    }

    if(!isEmpty()){
        std::cout << "Error detected. Mismatch with Opening Symbols.\n";
        return false;
    }
    return true;
}