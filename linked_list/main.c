#include "linked_list.h"

///////////////////////////////////////////////////////////////////////////////
// Add Two Numbers
//
// @param num1 first pointer to the first number represented by a linked list
// @param num2 second pointer to the number represented by a linked list
///////////////////////////////////////////////////////////////////////////////
ListNode *add_two_numbers(ListNode **num1, ListNode **num2)
{
    ListNode *ptr_1 = *num1;
    ListNode *ptr_2 = *num2;
    unsigned int remainder = 0;
    unsigned int sum = 0;
    ListNode *result = NULL;
    while(ptr_1 != NULL || ptr_2 != NULL)
    {
	sum = remainder;
	if (ptr_1)
	{
	    sum += ptr_1->val;
	    ptr_1 = ptr_1->next;
	}
	if (ptr_2)
	{
	    sum += ptr_2->val;
	    ptr_2 = ptr_2->next;
	}
	insert_front(&result, sum % 10);
	remainder = sum / 10;
    }
    if (remainder != 0)
    {
	insert_front(&result, remainder);
    }
    return result;
}


///////////////////////////////////////////////////////////////////////////////
// Add Two Numbers in correct order
//
// @param num1 first pointer to the first number represented by a linked list
// @param num2 second pointer to the number represented by a linked list
///////////////////////////////////////////////////////////////////////////////
ListNode *add_two_numbers_inorder(ListNode **num1, ListNode **num2)
{
}

///////////////////////////////////////////////////////////////////////////////
// Arrange list into odd-even nodes
//
// @param nums pointer to the head of a linked list
///////////////////////////////////////////////////////////////////////////////
void rearrange_odd_even(ListNode **nums)
{
    if (*nums != NULL)
    {

        ListNode *odd = *nums;
        ListNode *evenhead = (*nums)->next;
        ListNode *even = evenhead;
        while (even && even->next)
        {
            odd->next = (odd->next)->next;
            even->next = (even->next)->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenhead;
    }
}

///////////////////////////////////////////////////////////////////////////////
// Merge two sorted lists
//
// @param l1 pointer to the first linked list
// @param l2 pointer to the the second linked list
///////////////////////////////////////////////////////////////////////////////
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
    ListNode *tail = malloc(sizeof(ListNode));
    tail->val = 0;
    ListNode *result = tail;
    while(l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next; 
    }
    tail->next = l1?l1:l2;
    ListNode *dummy = result;
    result = result->next;
    free(dummy);
    return result;
    return result->next;
}

///////////////////////////////////////////////////////////////////////////////
// Swap pairs
//
// @param num pointer to the first linked list
//
// @question
//  Input: 1 ->2 ->3 ->4 ->5 ->6
//  Output: 2 ->1 ->4 ->3 ->6 ->5
///////////////////////////////////////////////////////////////////////////////
void swapPairs(ListNode **head)
{
    // Use a new head to point to the head of list
    ListNode *new_head = malloc(sizeof(ListNode));
    new_head->next = *head;

    ListNode *temp = new_head;

    ListNode *prev = NULL;
    ListNode *cur = NULL;
    while (temp && temp->next)
    {
        prev = temp->next;
        cur = (temp->next)->next;
        prev->next = cur->next;
        cur->next = prev;
        temp->next = cur;
        temp = prev;
    }
    *head = new_head->next;
    if (new_head)
    {
        free(new_head);
    }
}

///////////////////////////////////////////////////////////////////////////////
// Main program
///////////////////////////////////////////////////////////////////////////////
int main()
{
    printf("Play with Linked List!!!\n");

    ///////////////////////////////////////////////////////////////////////////
    printf("Add two numbers\n");
    // Create test data
    int num1[] = {1, 4, 5, 7};
    int num2[] = {2, 3, 6, 7, 8};
    ListNode * head1 = create_list(num1, 4, false);
    ListNode * head2 = create_list(num2, 4, false);
    printf("First number: \n");
    print_list(&head1);
    printf("Second number: \n");
    print_list(&head2);

    ListNode *result = add_two_numbers(&head1, &head2);
    printf("Results: \n");
    print_list(&result);

    ///////////////////////////////////////////////////////////////////////////
    printf("Odd-even numbers\n");
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ListNode *nums_list = create_list(nums, 10, false);
    rearrange_odd_even(&nums_list);
    printf("Results: \n");
    print_list(&nums_list);
    
    
    ///////////////////////////////////////////////////////////////////////////
    printf("Merge two list\n");
    ListNode *merged_list = mergeTwoLists(head1, head2);
    printf("Results: \n");
    print_list(&merged_list);

    ///////////////////////////////////////////////////////////////////////////
    printf("Swap pairs in linked list\n");
    int pairs[] = {1, 2, 3, 4, 5, 6};
    ListNode *swap_list = create_list(pairs, 6, false);
    swapPairs(&swap_list);
    printf("Results: \n");
    print_list(&swap_list);
    delete_list(&swap_list);
    
    // Clean up resources
    delete_list(&head1);
    //delete_list(&head2);
    delete_list(&result);
    delete_list(&nums_list);
    return 0;
}
