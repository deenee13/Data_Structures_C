#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node {
    
    char bracket;
    struct node *next;
};

struct node *top = NULL;
void push(char s);
void pop();

void push (char s) {
    
    printf("In push funtion\n");
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->bracket = s;
    newnode->next = top;

    top = newnode;

}

char is_top() {
    printf("In is_top funtion and value is %c\n", top->bracket);
    return(top->bracket);
}

bool empty() {
    
    printf("In empty funtion\n");
    if (top == NULL) {
        printf("In if condition\n");
        return true;
    }
    return false;
}

void pop() {
    
    printf("In pop funtion\n");
    struct node *dummy = top;
    
    if (top == NULL) {
        return;
    } else {
        printf("In else condition in pop\n");
        top = top->next;
        ////printf("Value in top is %c", top->bracket);
    }
    free(dummy);
}

bool are_balanced (char opening, char closing) {
    printf("In are_balanced funtion\n");
    if (opening == ')' && closing == '(') { 
            return true;
    } else if (opening == '}' && closing == '{') {
            return true;
    } else if (opening == ']' && closing == '[') {
            return true;
    }
    return false;
}


bool isValid(char * s) {
    int i = 0;
    char temp;
    char popped;
    int length = strlen(s);
    for (int i = 0; i < length; i++) {
        temp = *(s + i);
        if (*(s + i) == '(' || *(s + i) == '{' || *(s + i) == '[') {
            push(*(s + i));
        } else if (*(s + i) == ')' || *(s + i) == '}' || *(s + i) == ']') {
            if (empty() || !are_balanced(*(s + i), is_top())) {
                return false;
            } else {
                pop();
            }
        }
    }
    //// printf("data in top is %d\n", top->bracket);
    return (empty() == true ? true:false);
}


int main(void) {
    bool result;
    char s[] = "{[]}";
    result = isValid(&s);
    printf(" answer is %d\n", result);
}