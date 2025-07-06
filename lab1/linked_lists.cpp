#include <iostream>
#include <cstdlib>                    //for malloc
using namespace std;

struct SLL
{
    int data;
    struct SLL *next;            // self-referential structure
};

struct SLL *temp;

struct SLL *NewNode, *first, *last = NULL;

void insertAtBeg(int element)
{
    
    NewNode = (struct SLL*)malloc(sizeof(struct SLL));     //memory allocatio for newnode
    //NewNode->next = NULL;
    NewNode->data = element;
    //NewNode->next = NULL;
    if (first == NULL)
    {
        first = last = NewNode;
    }
    else
    {
        NewNode->next = first;
        first = NewNode;
    }
    cout << element << "was inserted at the beginning" << endl;
}



void insertatend(int element)
{
    NewNode = (struct SLL*)malloc(sizeof(struct SLL));
    NewNode->next = NULL;
    NewNode->data = element;
    if (first == NULL)          //empty list. SO we add our first node
    {
        first = last = NewNode;
    }
    else
    {
        last->next = NewNode;
        last = NewNode;
    }
    cout << element << " Was inserted at the end of the list" << endl;
}

// void insertfromposition(int pos)
// {
//     struct SLL *tempp;
//     if (first == NULL)
//     {
//         first = last = NewNode;
//     }
//     else if (pos <=0)
//     {
//         cout << "PLease enter a vaild position";
//     }
//     else if(first->next == NULL || pos == 1)
//     {
//         deletionFromBeg();
//     }
//     else
//     {
//         temp = first;
//         for (int i = 1; i < pos; i++)
//         {
//             temp = temp->next;
//             if (temp->next == last)
//             {
//                 deletionformend();
//             }
//             else
//             {
//                 tempp = temp->next;
//                 temp->next = tempp->next;
//                 cout << temp->data << " is going to be deleted";
//                 free(tempp);
//             }
//         }
//     }
    
        
// }


void deletionFromBeg()
{
    if(first == NULL)
    {
        cout << "The list is empty" << endl;
    }
    else if (first->next == NULL)                         //only 1 element
    {
        temp = first;
        cout << temp->data << " is deleted" << endl;
        first = last = NULL;                             // list is empty now
        free(temp);
    }
    else
    {
        temp = first;
        first = first->next;
        cout << temp->data << " is deleted" << endl;
        free(temp);
    }
    
}




void deletionformend()
{
    if(first == NULL)
    {
        cout << "The list is empty" << endl;
    }
    else if (first->next == NULL)                         //only 1 element
    {
        temp = first;
        cout << temp->data << " is deleted" << endl;
        first = last = NULL;                             // list is empty now
        free(temp);
    }
    else
    {
        temp = first;
        while (temp->next != last)
        {
            temp = temp->next;
        }
        last = temp;
        temp = temp->next;
        cout << temp->data << " is deleted" << endl;
        free(temp);
        last->next = NULL;                            // yo halena bhane garbage value auxa
    }
}

void deletionfromposition(int pos)
{
    struct SLL *tempp;
    if(first == NULL)
    {
        cout << "The list is empty"<< endl;
    }
    else if (pos <0)
    {
        cout << "PLease enter a vaild position";
    }
    else if(first->next == NULL || pos == 1)
    {
        deletionFromBeg();
    }
    else
    {
        temp = first;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
            if (temp->next == last)
            {
                deletionformend();
            }
            else
            {
                tempp = temp->next;
                temp->next = tempp->next;
                cout << tempp->data << " is going to be deleted";
                free(tempp);
            }
        }
    }
    
        
}


void insertfromposition(int pos, int element)
{
    struct SLL *tempp;
    struct SLL *NewNode = (struct SLL*)malloc(sizeof(struct SLL));
    NewNode->data = element;
   // NewNode->next = NULL;
    if (pos < 0)
    {
        cout << "Please enter a valid position" << endl;
    }
    else if (pos == 1)
    {
        insertAtBeg(element);
    }
    else
    {
        temp = first;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next; 
        }
        if(temp->next == last)
        {
            insertatend(element);
        }
        else
            
        {
                         //pos -1
            tempp = temp->next;            // pos
            temp->next = NewNode;          // creating newnode at middle of pos-1 and pos
            NewNode->next = tempp;         
        }
        
    }      
}




void search(int key)
{
    int flag = 0;
    temp = first;
    if (first == NULL)
    {
        cout << "Empty list" << endl;
    }
    else
    {
        while(temp != NULL)
    {
        if (temp->data == key)
        {
            cout << "You searched for " << key << " and it was found:)" << endl;
            flag = 1;
        }
        temp = temp->next;       //temp will go to NULL eventually
    }
    if (flag == 0)
    {
        cout << "You searched for" << key <<  "but the search was not succesfull:(" << endl;
    }
    }
}

void display()
{
    if(first == NULL)
    {
        cout << "empty list";
    }
    else
    {
        temp = first;
        while (temp !=NULL)
        {
            cout << " " << temp->data;
            temp = temp->next;                   
        }
    }
    cout << " are in the list currently" << endl;
}


int main()
{
    insertAtBeg(100);                    //100
    insertAtBeg(400);                    //400-100
    insertAtBeg(200);                    //200-400-100
    insertatend(1000);                   //200-400-100-1000
    insertatend(2000);                   //200-400-100-1000-2000
    deletionFromBeg();                   //400-100-1000-2000
    deletionformend();                  //400-100-1000 
    display();
    deletionfromposition(2);            //400-100
    display();
    insertfromposition(2, 101);         //400-100-101
    display();
    search(100);
    display();

    //display();
    return 0;
}



