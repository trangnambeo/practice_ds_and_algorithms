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
// Main program
///////////////////////////////////////////////////////////////////////////////
int main()
{
    printf("Play with Linked List!!!\n");

    printf("Add two numbers\n");
    // Create test data
    int num1[] = {1, 2, 3, 4};
    int num2[] = {5, 6, 7, 8};
    ListNode * head1 = create_list(num1, 4, false);
    ListNode * head2 = create_list(num2, 4, false);
    printf("First number: \n");
    print_list(&head1);
    printf("Second number: \n");
    print_list(&head2);

    ListNode *result = add_two_numbers(&head1, &head2);
    printf("Results: \n");
    print_list(&result);

    // Clean up resources
    delete_list(&head1);
    delete_list(&head2);
    delete_list(&result);
    return 0;
}
