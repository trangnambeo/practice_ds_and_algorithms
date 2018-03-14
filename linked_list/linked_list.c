#include "linked_list.h"

//////////////////////////////////////////////////////////////////////////////
ListNode * create_node(int data)
{
   ListNode *new_node = malloc(sizeof(ListNode));
   if (!new_node)
   {
       printf("Out of memory\n");
       exit(-1);
   }
   new_node->val = data;
   new_node->next = NULL;
   return new_node;
}

//////////////////////////////////////////////////////////////////////////////
void insert_front(ListNode **head, int data)
{
    if (*head == NULL)
    {
        *head = create_node(data);
    }
    else
    {
        ListNode *new_node = create_node(data);
        new_node->next = *head;
        *head = new_node;
    }
}

//////////////////////////////////////////////////////////////////////////////
void insert_back(ListNode **head, int data)
{
    if (*head == NULL)
    {
        *head = create_node(data);
    }
    else
    {
	ListNode *p = *head;
	// Traverse to the last node
	while (p->next != NULL)
	{
	    p = p->next;
	}
        ListNode *new_node = create_node(data);
        p->next = new_node;
    }
}

//////////////////////////////////////////////////////////////////////////////
ListNode * delete_list(ListNode **head)
{
    ListNode *aux_node = NULL, *p = *head;
    while (p != NULL)
    {
	aux_node = p->next;
	free(p);
	p = aux_node;
    }
}

//////////////////////////////////////////////////////////////////////////////
ListNode * print_list(ListNode **head)
{
   ListNode *p = *head;
   while (p != NULL)
   {
       printf("%d ", p->val);
       p = p->next;
   }
   printf("\n");
}

//////////////////////////////////////////////////////////////////////////////
ListNode *create_list(int const data[], unsigned int const size,
   bool inverse)
{
    ListNode *head = NULL;
    for (int i = 0; i < size; i++)
    {
	if (inverse)
	{
	    insert_front(&head, data[i]);
	}
	else
	{
            insert_back(&head, data[i]);
	}
    }
    return head;
}

//////////////////////////////////////////////////////////////////////////////
unsigned int size(ListNode **head)
{
    unsigned int length = 0;
    ListNode *p = *head;
    while (p != NULL)
    {
	length++;
	p = p->next;
    }
    return length;
}
