#include <iostream>
#include <stack>
#include <string>

///////////////////////////////////////////////////////////////////////////////
// Balance parenthesis
//
// @param expression input expression to validate
//
// @return True if parens are balanced, False otherwise
///////////////////////////////////////////////////////////////////////////////
bool isBalanced(const std::string &expression)
{
    // Create a stack of char to validate parens
    std::stack<char> stk;
    char val;
    // Interate through expression
    for (auto ch : expression)
    {
	switch (ch)
	{
	    case '{':
	    case '[':
	    case '(':
	    	stk.push(ch);
		break;
	    case '}':
	        if (!stk.empty())
		{
	            val = stk.top();
	   	    stk.pop();
   		    if (val != '{')
		    {
		        return false;
		    }
		}
		else
		{
		    return false;
		}
		break;
	    case ']':
	        if (!stk.empty())
		{
	            val = stk.top();
	   	    stk.pop();
   		    if (val != '[')
		    {
		        return false;
		    }
		}
		else
		{
		    return false;
		}
		break;
	    case ')':
	        if (!stk.empty())
		{
	            val = stk.top();
	   	    stk.pop();
   		    if (val != '(')
		    {
		        return false;
		    }
		}
		else
		{
		    return false;
		}
		break;
	}
    }
    return stk.empty();
}

///////////////////////////////////////////////////////////////////////////////
// Main program
///////////////////////////////////////////////////////////////////////////////
int main()
{
    std::cout << "Play with Stack!!!\n" << std::endl;

    ///////////////////////////////////////////////////////////////////////////
    std::cout << "Balance parenthesis\n" << std::endl;
    // Create test data
    std::string expn = "{[(a + 5)*(b + 6)] * [(c - 10) * (d + 8)]}}";
    std::cout << "Expression is: " << expn << std::endl;
    if (isBalanced(expn))
    {
	std::cout << "Expression is balanced" << std::endl;
    }
    else
    {
	std::cout << "Unbalanced expression" << std::endl;
    }
    return 0;
}
