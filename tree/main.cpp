#include <iostream>
#include <stack>
#include <string>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} TreeNode;

TreeNode *newNode(int data)
{
    TreeNode * new_node = new TreeNode;
    new_node->data = data;
    new_node->left = nullptr;
    new_node->right = nullptr;
    return new_node;
}



///////////////////////////////////////////////////////////////////////////////
// Pre-order tree traversal recursive
//
// @param expression input expression to validate
//
// @return True if parens are balanced, False otherwise
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Main program
///////////////////////////////////////////////////////////////////////////////
int main()
{
    std::cout << "Play with Tree!!!\n" << std::endl;

    ///////////////////////////////////////////////////////////////////////////
    std::cout << "Pre-order tree traversal recursive\n" << std::endl;
    // Create test data

    freturn 0;
}
