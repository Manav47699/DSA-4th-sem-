
#include <iostream>
#include <cstring>  // for strtok
#include <cmath>    // for pow

using namespace std;

#define MAX 100


struct stack{
    int tos;
    int data[MAX];
};

struct stack s = {-1};


void push(struct stack *s,int element){
    if (s->tos == MAX-1)
    {
        cout << "stack is full";
    }
    else{
        s->tos = s->tos + 1;
        s->data[s->tos] = element;
    }
}

int pop(struct stack *s){
    if (s->tos == -1)
    {
        cout << "stack is empty";
        return 0;
    }
    else{
        int element = s->data[s->tos];
        s->tos = s->tos - 1;
        return element;
    } 
}



void input(char* expression) {
    cout << "Enter the postfix expression: ";
    cin.getline(expression, 100);  // cin.getline(var, size)
}


/*
void tokenization(char* expression) {
    char* token = strtok(expression, " ");    // gets the first token
    while (token != nullptr) {
        cout << "Token: " << token << endl;
        token = strtok(nullptr, " ");       //"Continue tokenizing the same string from where you left off, splitting by spaces.".................// gets the next token
    }
}
*/

void evaluate_postfix(char* expression, int* result){
    char *token = strtok(expression, " ");
    while (token != nullptr)
    {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])))       // checking for +ve and -ve numbers
        {       
            int num = atoi(token);
            push(&s, num);
        }
        else
        {
            int op1, op2 ;
            op2 = pop(&s);
            op1 = pop(&s);

            if (strcmp( token, "+") == 0)
            {
                *result = op1 + op2;
            } 
            else if (strcmp(token, "-") == 0)
            {
                *result = op1 - op2;
            }
            else if (strcmp(token, "*") == 0)
            {  
                *result = op1 * op2;
            }
            else if (strcmp(token, "/") == 0)
            {
                *result = op1 / op2;
            }
            else if (strcmp(token, "^") == 0 || (strcmp(token, "$") == 0))
            {
                *result = pow(op1, op2);
            }
            
            else 
            {
                cout << "Unknown operator: " << token << endl;
                return;
            }
        push(&s, *result);
        }
    token = strtok(nullptr, " ");
    }
}

void display(int result)
{
    cout << result;
}


int main() {
    char expression[100];
    int result;            
    input(expression);     
    evaluate_postfix(expression, &result);  
    display(result);
    return 0;
}



