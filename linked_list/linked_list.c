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
    ListNode *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

//////////////////////////////////////////////////////////////////////////////
ListNode * delete_list(ListNode **head)
{
    ListNode *aux_node = NULL, *p = *head;
    while (p)
    {
	aux_node = p->next;
	free(p);
	p = aux_node;
    }
}

//////////////////////////////////////////////////////////////////////////////
ListNode * print_list(ListNode **head)
{

}

