#include<stdio.h>
#include "charStack.c"

int isValid(char* s){
    char* iter = s;
    Stack_t* stack = newStack(100);
    bool valid ;
    while(*iter != '\0'){
        if(*iter == '(' || *iter == '[' || *iter == '{'){
            stack->pushPtr(stack, *iter);
        }
        else if(*iter == ')' || *iter == ']' || *iter == '}'){
            if(stack->isEmptyPtr(stack)){
                stack->deletePtr(stack);
                return false;
            }
            char top = stack->popPtr(stack);
            if(!((*iter == ')' && top == '(')|| (*iter == ']' && top == '[')||(*iter == '}' && top == '{'))){
                stack->deletePtr(stack);
                return false;
            }
        }
        iter++;
    }
    valid = stack->isEmptyPtr(stack) ? true : false;
    stack->deletePtr(stack);
    return valid;
}

// test cases by AI 
void run_test(const char* test_str, bool expected) {
    bool actual = isValid((char*)test_str);
    printf("Test: \"%s\"\n", test_str);
    printf("Expected: %s, Got: %s -> %s\n\n",
           expected ? "valid" : "not valid",
           actual ? "valid" : "not valid",
           (actual == expected) ? "PASS" : "FAIL");
}

int main() {
    printf("--- Running Parentheses Tests ---\n\n");

    run_test("", true);                // Empty string
    run_test("()", true);               // Simple valid
    run_test("()[]{}", true);           // Sequence of valid pairs
    run_test("([{}])", true);           // Nested valid
    run_test("(]", false);              // Simple mismatched
    run_test("([)]", false);            // Nested mismatched
    run_test("{{", false);              // Unclosed opening brackets
    run_test(")", false);               // Leading closing bracket
    run_test("())", false);             // Extra closing bracket
    run_test("({[]})[]", true);         // Complex valid
    run_test("()(){()()})[()]()", false); // Your original complex invalid case

    return 0;
}