// "." is used only if not pointer was used. In case of a pointer, use "->"
//if we don't use a pointer, "s" will just be a copy of the original struct and we will be operating on a copy

#include <iostream>
using namespace std;

#define MAX 10

struct stack{
    int tos;
    int data[MAX];
};



void push (struct stack *s, int element){                     //
    if (s->tos==MAX-1)                                        // 
    {
        cout << "The stack is full";
    }
    else{ 
        s->tos = s->tos + 1;
        s->data[s->tos] = element;
    }
}
int pop (struct stack *s){                                    //
    if (s->tos == -1)
    {
        cout << "The stack is empty";
    }
    else{
        int element = s->data[s->tos];
        s->tos = s->tos - 1;
        return element;
    }
}

void display(struct stack *s){
    cout << "Tlhe current elements in your stack are";
    for (int i = s->tos; i >= 0; --i)                          //
    {
        cout << s->data[i];
    }
}

int main ()
{
    struct stack s= {-1};                                           //
    
    int element;
    char input;
    
    while (true){
        cout << "What stack action would you like to perform .\n Press 'e' to exit \n Press '1' to PUSH IN THE STACK \n Press '2' to POP FROM THE STACK";
        cin >> input;
        if (input == 'e' || input == 'E' )
        {
            cout << "Exiting the stack......";
            display(&s);                                                                        //
            break;
        }
        else if (input == '1')
        {
            cout << "enter the number you would like to push: ";
            cin >> element;
            push(&s, element);
        }
        else if (input == '2')
        {
            int popped_element = pop(&s);                                                          //
            
            pop (&s);
            cout << popped_element << "was popped";
            
        }
        else{
            cout << " PLease give a valid input";

        }

    }
    return 0;
}