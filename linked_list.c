#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////////////
// Linked list node
//
///////////////////////////////////////////////////////////////////////////////
struct ListNode
{
    int data;
    struct ListNode *next;
};

///////////////////////////////////////////////////////////////////////////////
// Insert value into a linked list at front
//
// param[in] head pointer to head of linked list
// param[in] data data to insert to a linked list
///////////////////////////////////////////////////////////////////////////////
void insert_front(struct ListNode **head, int data)
{
    struct ListNode *new_node = malloc(sizeof(struct ListNode));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

///////////////////////////////////////////////////////////////////////////////
// Print data in list
///////////////////////////////////////////////////////////////////////////////
void print_list(struct ListNode **head)
{
    struct ListNode *p = *head;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

///////////////////////////////////////////////////////////////////////////////
// Delete a list
///////////////////////////////////////////////////////////////////////////////
void delete_list(struct ListNode **head)
{
    struct ListNode *aux_node = NULL;
    struct ListNode *iterator = *head;
    while(iterator)
    {
        aux_node = iterator->next;
        free(iterator);
        iterator = aux_node;
    }
}



int main()
{
    printf("Hello Nam. Have fun with Cracking the coding interview!!!\n");
    // Allocate head node
    struct ListNode * head = NULL;
    head = malloc(sizeof(struct ListNode));
    head->data = 1;
    head->next = NULL;
    insert_front(&head, 2);
    insert_front(&head, 3);
    print_list(&head);
    delete_list(&head);
    return 0;
}
