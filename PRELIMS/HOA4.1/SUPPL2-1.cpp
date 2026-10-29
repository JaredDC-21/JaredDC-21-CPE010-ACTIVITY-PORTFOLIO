#include <iostream>
#include <string>
#include "SUPPL_listStack.h"

bool isOpening(char ch){
    return ch == '(' || ch == '{' || ch == '[';
}

bool isClosing(char ch){
    return ch == ')' || ch == '}' || ch == ']';
}

bool isMatching(char open, char close){
//returns true if the symbols match, otherwise false
    if(open == '(' && close == ')')
        return true;
    if(open == '{' && close == '}')
        return true;
    if(open == '[' && close == ']')
        return true;
    return false;
}

bool checkBalanced(std::string expression){
    // Clear the stack to avoid errors from previous expression
    while(!isEmpty<char>())
        pop<char>();

    for(char ch : expression){
        //Push to stack if opening symbol
        if(isOpening(ch)){
            push<char>(ch);
        }
        //Now for closing symbols
        else if(isClosing(ch)){
            // If the stack is empty, there is no matching opening symbol
            if(isEmpty<char>()){
                std::cout << "Error with Closing symbol '" << ch << "' mismatch with the opening symbols.\n";
                return false;
            }
            //Start popping
            char open = pop<char>();
            // Compare the opening and closing symbols
            if(!isMatching(open, ch)){
                std::cout << "Error: '" << open << "' mismatch detected '" << ch << "'.\n";
                return false;
            }
        }
    }
    // Check if there are still opening symbols left in the stack
    if(!isEmpty<char>()){
        std::cout << "Error. There are mismatches with the opening symbols.\n";
        return false;
    }
    // If no errors were found, the expression is balanced
    return true;
}

int main(){
    std::string expression;

    std::cout << "Enter a sample expression: ";
    getline(std::cin, expression);

    if(checkBalanced(expression))
        std::cout << "The given sample expression is Balanced.\n";
    else
        std::cout << "The given sample expression is Unbalanced.\n";

    return 0;
}