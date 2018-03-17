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
        // Since even moves faster than odd, when even is the last node or
        // NULL, guranteed odd is not NULL
        odd->next = evenhead;
    }
}

///////////////////////////////////////////////////////////////////////////////
// Arrange list into even-odd nodes
//
// @param nums pointer to the head of a linked list
///////////////////////////////////////////////////////////////////////////////
void rearrange_even_odd(ListNode **nums)
{
    if (*nums != NULL)
    {

        ListNode *odd = *nums;
        ListNode *evenhead = (*nums)->next;
        ListNode *even = evenhead;
        while (even && even->next)
        {
            odd->next = (odd->next)->next;
            odd = odd->next;
            even->next = (even->next)->next;
            even = even->next;
        }
        // Since even moves faster than odd, we need to traverse again to the
        // last even node
        even = evenhead;
        while (even->next)
        {
            even = even->next;
        }
        even->next = *nums;
        *nums = evenhead;
        if (odd)
        {
            odd->next = NULL;
        }
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
    ListNode dummy = {.val = 0, .next = NULL};
    ListNode *tail = &dummy;
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
    return result->next;
}

///////////////////////////////////////////////////////////////////////////////
// Swap pairs
//
// @param num pointer to the first linked list
//
// @example
//  Input: 1 ->2 ->3 ->4 ->5 ->6
//  Output: 2 ->1 ->4 ->3 ->6 ->5
///////////////////////////////////////////////////////////////////////////////
void swapPairs(ListNode **head)
{
    // Use a new head to point to the head of list
    ListNode new_head = {.val = 0, .next = *head};

    ListNode *temp = &new_head;

    ListNode *prev = NULL;
    ListNode *cur = NULL;
    while (temp && temp->next)
    {
        prev = temp->next;
        cur = (temp->next)->next;
        prev->next = cur->next;
        cur->next = prev;
        // The first time the next command is called, new head is set
        temp->next = cur;
        temp = prev;
    }
    *head = new_head.next;
}


///////////////////////////////////////////////////////////////////////////////
// Right rotate list by k positions
//
// @param nums pointer to the head of a linked list
// @param k number of positions to shift
//
// @example
// Given 1->2->3->4->5->NULL and k = 2,
//
// return 4->5->1->2->3->NULL.
///////////////////////////////////////////////////////////////////////////////
void rotateRight(ListNode** head, int k) 
{
    ListNode *fast = *head;
    ListNode *slow = *head;
    ListNode *newhead = NULL;
    ListNode *newtail = NULL;
    while (k--)
    {
        fast = fast->next;
    }
    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    newhead = slow->next;
    newtail = slow;
    newtail->next = NULL;
    fast->next = *head;
    *head = newhead;
}

///////////////////////////////////////////////////////////////////////////////
// Insertion sort
//
// @param head pointer to head of a linked list
///////////////////////////////////////////////////////////////////////////////
void insertionSortList(ListNode** head) 
{

}

///////////////////////////////////////////////////////////////////////////////
// List pivoting
//
// @param head pointer to head of a linked list
// @param k pivot value
///////////////////////////////////////////////////////////////////////////////
void pivotList(ListNode** head, int k) 
{
    ListNode lsmaller = {.val = 0, .next = NULL};
    ListNode llarger = {.val = 0, .next = NULL};
    ListNode *smaller_ptr = &lsmaller;
    ListNode *larger_ptr = &llarger;
    ListNode *cur = *head;
    while (cur)
    {
        if (cur->val <= k)
        {
            // Construct list of nodes with values smaller than k
            smaller_ptr->next = cur;
            // Note: the first time the previous assignment is called,
            // lsmaller.next is set forever
            smaller_ptr = smaller_ptr->next;
        }
        else
        {
            // Construct list of nodes with values greater than k
            larger_ptr->next = cur;
            // Note: the first time the previous assignment is called,
            // llarger.next is set forever
            larger_ptr = larger_ptr->next;
        }
        cur = cur->next;
    }
    larger_ptr->next = NULL;
    smaller_ptr->next = llarger.next;
    *head = lsmaller.next;
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
    ListNode * head2 = create_list(num2, 5, false);
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
    printf("Even-odd numbers\n");
    int nums2[] = {1, 2, 3, 4, 5, 6, 7, 8};
    ListNode *pre_list = create_list(nums2, 8, false);
    rearrange_even_odd(&pre_list);
    printf("Results: \n");
    print_list(&pre_list);
    delete_list(&pre_list);
    
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
    
    ///////////////////////////////////////////////////////////////////////////
    printf("Rotate list\n");
    int rotate[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ListNode *rotate_list = create_list(rotate, 9, false);
    rotateRight(&rotate_list, 3);
    printf("Results: \n");
    print_list(&rotate_list);
    delete_list(&rotate_list);
    
    ///////////////////////////////////////////////////////////////////////////
    printf("Pivot ordering list\n");
    int pivot_pairs[] = {1, 4, 3, 2, 5, 2};
    ListNode *pivot_list = create_list(pivot_pairs, 6, false);
    pivotList(&pivot_list, 3);
    printf("Results: \n");
    print_list(&pivot_list);
    delete_list(&pivot_list);

    // Clean up resources
    delete_list(&head1);
    //delete_list(&head2);
    delete_list(&result);
    delete_list(&nums_list);
    return 0;
}
