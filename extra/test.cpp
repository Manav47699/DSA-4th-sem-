#include <stdio.h>
#include <stdlib.h>
#include <cstring>
struct SLL
{
    int data;
    struct SLL *next;
};
struct SLL *first, *last = NULL;
void insertAtBeg(int element)
{
    struct SLL *NewNode;
    NewNode = (struct SLL*)malloc(sizeof(struct SLL));
    NewNode->next = NULL;
    NewNode->data = element;
    if(first == NULL)// List is Empty
        first = last = NewNode;
    else
    {
        NewNode->next = first;
        first = NewNode;
    }
    printf("%d WAS INSERTED AT THE BEGINNING\n",first->data);
}
void insertAtEnd(int element)
{
    struct SLL *NewNode;
    NewNode = (struct SLL*)malloc(sizeof(struct SLL));
    NewNode->next = NULL;
    NewNode->data = element;
    if(first == NULL)// List is Empty
        first = last = NewNode;
    else
    {
        last->next = NewNode;
        last = NewNode;
    }
    printf("%d WAS INSERTED AT THE END\n",last->data);
}
void deletionFromBeg()
{
    struct SLL *temp;
    if(first == NULL)
        printf("EMPTY LIST!\n");
    else if(first->next == NULL)
    {
        temp = first;
        printf("%d IS GOING TO BE DELETED\n",temp->data);
        first = last = NULL;
        free(temp);
    }
    else
    {
        temp = first;
        first = first->next;
        printf("%d IS GOING TO BE DELETED\n",temp->data);
        free(temp);
    }
}
void deletionFromEnd()
{
    struct SLL *temp;
    if(first == NULL)
        printf("EMPTY LIST!\n");
    else if(first->next == NULL)
    {
        temp = first;
        printf("%d IS GOING TO BE DELETED\n",temp->data);
        first = last = NULL;
        free(temp);
    }
    else
    {
        temp = first;
        while(temp->next != last)
        {
            temp = temp->next;
        }
        last = temp;
        temp = temp->next;
        printf("%d IS GOING TO BE DELETED\n",temp->data);
        free(temp);
        last->next = NULL;
    }
}
void display()
{
    struct SLL *temp;
    if(first == NULL)
        printf("EMPTY LIST!\n");
    else
    {
        temp = first;
        while(temp != NULL)
        {
            printf("%d -> ",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
void deletionFromPosition(int pos)
{
    struct SLL *temp, *tempp;
    int i;
    if(first == NULL || pos<=0)
        printf("INVALID DELETION!\n");
    else if(first->next ==  NULL || pos == 1)
    {
        deletionFromBeg();
    }
    else
    {
        temp = first;
        for(i=1;i<pos-1;i++)
            temp = temp->next;
        if(temp->next == last)
            deletionFromEnd();
        else
        {
            tempp = temp->next;
            temp->next = tempp->next;
            printf("%d IS GOING TO BE DELETED\n",tempp->data);
            free(tempp);
        }
    }

}
void search(int key)
{
    struct SLL *temp;
    int flag = 0;
    if(first == NULL)
        printf("EMPTY LIST!\n");
    else
    {
        temp = first;
        while(temp != NULL)
        {
            if(temp->data == key)
            {
                printf("Element Found!\n");
                flag = 1;
            }
            temp = temp->next;
        }
        if(flag == 0)
            printf("SEARCH UNSUCCESSFUL!\n");
    }
}
int main()
{
    insertAtBeg(100);
    insertAtBeg(200);
    insertAtBeg(300);
    insertAtBeg(400);
    insertAtBeg(500);
    insertAtBeg(600);
    display();
    deletionFromPosition(5);
    display();
    deletionFromPosition(1);
    display();
    deletionFromPosition(4);
    display();
    return 0;
}