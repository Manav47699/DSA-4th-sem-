#include <stdio.h>
#include <stdlib.h>

struct DLL
{
    int data;
    struct DLL *next, *prev;
};

struct DLL *first = NULL, *last = NULL;

void insert_at_beginning(int element)
{
    struct DLL *Newnode;
    Newnode = (struct DLL *)malloc(sizeof(struct DLL));
    Newnode->data = element;
    Newnode->next = NULL;
    Newnode->prev = NULL;
    if (first == NULL)
    {
        first = last = Newnode;
    }
    else
    {
        Newnode->next = first;
        first->prev = Newnode;
        first = Newnode;
    }
    printf("%d was inserted . \n", first->data);
}

void insert_at_end(int element)
{
    struct DLL *Newnode;
    Newnode = (struct DLL *)malloc(sizeof(struct DLL));
    Newnode->next = NULL;
    Newnode->prev = NULL;
    Newnode->data = element;
    if (first == NULL)
    {
        first = last = Newnode;
    }
    else
    {
        Newnode->prev = last;
        last->next = Newnode;
        last = Newnode;
    }
    printf("%d has been inserted . \n", last->data);
}

void insert_at_position(int element, int pos)
{
    struct DLL *Newnode;
    int i;
    Newnode = (struct DLL *)malloc(sizeof(struct DLL));
    Newnode->next = NULL;
    Newnode->prev = NULL;
    Newnode->data = element;
    if (pos <= 0)
        printf("Invalid postion.\n");
    else if (pos == 1 || first == NULL)
        insert_at_beginning(element);
    else
    {
        struct DLL *temp;
        temp = first;
        for (i = 1; i < pos - 1 && temp->next != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == last)
        {
            insert_at_end(element);
        }
        else
        {
            struct DLL *tempP;
            tempP = temp->next;
            temp->next = Newnode;
            Newnode->prev = temp;
            Newnode->next = tempP;
            tempP->prev = Newnode;
        }
        printf("%d was inserted at %d postion.\n", element, pos);
    }
}

void display_list()
{
    struct DLL *temp;
    if (first == NULL)
    {
        printf("List is empty. \n");
    }
    else
    {
        temp = first;
        while (temp != NULL)
        {
            printf("%d ->", temp->data);
            temp = temp->next;
        }
        printf("NULL \n");
    }
}

void delete_from_beginning()
{
    if (first == NULL)
    {
        printf("List is empty ! ");
    }
    else if (first->next == NULL)
    {
        struct DLL *temp;
        temp = first;
        first = last = NULL;
        free(temp);
    }
    else
    {
        struct DLL *temp;
        temp = first;
        first = first->next;
        printf("%d has been deleted \n", temp->data);
        free(temp);
        first->prev = NULL;
    }
}

void delete_from_end()
{
    if (first == NULL)
    {
        printf("List is empty ! ");
    }
    else if (first->next == NULL)
    {
        delete_from_beginning();
    }
    else
    {
        struct DLL *temp;
        temp = last;
        last = last->prev;
        printf("%d is going to be delted \n", temp->data);
        free(temp);
        last->next = NULL;
    }
}

void delete_at_position(int pos)
{
    int i;
    if (pos <= 0 || first == NULL)
    {
        printf("Invalid postion for deletion ! \n");
    }
    else if (pos == 1 || first->next == NULL)
    {
        delete_from_beginning();
    }
    else
    {
        struct DLL *temp;
        temp = first;
        for (i = 1; i < pos - 1 && temp->next != last; i++)
        {
            temp = temp->next;
        }
        if (temp->next == last)
        {
            delete_from_end();
        }
        else
        {
            struct DLL *tempP;
            tempP = temp->next;
            temp->next = tempP->next;
            (temp->next)->prev = temp;
            printf("%d is going to delete from the list. \n", tempP->data);
            free(tempP);
        }
    }
}

int main()
{
    insert_at_beginning(100);
    insert_at_beginning(200);
    insert_at_end(30);
    insert_at_position(40, 3);
    display_list();
    insert_at_position(400, 1);
    display_list();
    insert_at_position(500, 6);
    display_list();
    delete_from_end();
    display_list();
    delete_at_position(1);
    display_list();
    delete_at_position(2);
    display_list();
    return 0;
}