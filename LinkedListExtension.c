//Created by Jacob Watters


/* Cases for insertion
 *   1) List is empty: insert at head
 *   2) data being inserted is smaller than data in head: Make data the new head
 *   3) data being inserted is larger than data in tail: Make data the new tail
 *   4) data being inserted is already in list: insert in front of original
 *   5) data being inserted does not match any of these: Find place where previous nodes data is smaller
 *                                                    and next nodes data is larger, insert here.
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* next;
    struct node* last;
}node;

node* head;
node* tail;
node* current;

void printListFromHead()
{
    if (head != 0)
    {
        current = head;
        printf("head");

        while (current != tail->next)
        {
            printf("->%d", current->value);
            current = current->next;
        }
        printf("<-tail\n");
    }
    else
    {
        printf("List is empty\n");
    }
}

void printListFromTail()
{
    if (head != 0)
    {
        current = tail;
        printf("tail");

        while (current != head->last)
        {
            printf("->%d", current->value);
            current = current->last;
        }
        printf("<-Head\n");
    }
    else
    {
        printf("List is empty\n");
    }
}

void insert(int value)
{
    current = head;
    if (head == 0) //empty list
    {
        head = (node*) malloc(sizeof(node));
        head->next = 0;
        head->value = value;
        tail = head;
    }
    else //non-empty list
    {
        if (value < head->value)
        {
            node *temp = head;
            head = (node*) malloc(sizeof(node));
            head->value = value;
            head->next = temp;
        }
        else if (value >= tail->value)
        {
            tail->next = (node*) malloc(sizeof(node));
            tail = tail->next;
            tail->value = value;
            tail->next = 0;
        }
        else
        {
            while (value >= current->next->value)
            {
                current = current->next;
            }

            node *temp = current->next;
            current->next = (node *) malloc(sizeof(node));
            current = current->next;

            current->value = value;
            current->next = temp;
        }
    }
}

void delete(int index)
{
    current = head;
    if (index == 0)
    {
        head = head->next;
        free(current);
        current = 0;
    }
    else if (index > 0)
    {
        for (int i = index; i > 1 && current != tail; i--)
        {
            current = current->next;
        }
        if (current == tail)
        {
            printf("index %d is too large\n", index);
        }
        else
        {
            if (current->next == tail) tail = current;
            node *temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
    }
    else
    {
        printf("index %d is too small\n", index);
    }
}

void freeList()
{
    current = head;
    while (current != 0)
    {
        head = head->next;
        free(current);
        current = head;
    }
    head = 0;
    tail = 0;
    current = 0;
}

void run_linked_list()
{
    printf("Running linked list\n");

    head = 0;
    tail = 0;
    current = 0;

    int rand_max = 100;

    /*
    list_insert(67);            //test for case 1
    for(int i = 0; i < 4; i++)  //test for case 2
    {
        list_insert(i);
    }
    for(int i = 3; i >= 0; i--) //test for case 3
    {
        list_insert(i);
    }
    for(int i = 3; i >= 0; i--) //test for case 4
    {
        list_insert(3);
    }
    //test for case 5
     list_insert(3);
     list_insert(5);
     list_insert(6);
     list_insert(7);
     list_insert(8);
     list_insert(2);
     list_insert(4);
     list_insert(0);
    */

    for(int i = 0; i < 10; i++)  //insert random numbers
    {
        insert(rand() % rand_max+1);
    }

    printListFromHead();
    printListFromTail();
    freeList();
}

