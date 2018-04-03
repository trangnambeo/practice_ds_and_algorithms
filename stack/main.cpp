#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <ctype.h>
#include <sstream>

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
// Leetcode 682: Baseball Game
//
// @param expression input expression to validate
//
// @return True if parens are balanced, False otherwise
///////////////////////////////////////////////////////////////////////////////
int calPoints(const std::vector<std::string> &ops)
{
    int result = 0;
    int c, c1, c2;
    std::stack<int> s;
    for (auto o: ops)
    {
        switch(o[0])
        {
            case '+':
                c1 = s.top();
                s.pop();
                c2 = s.top();
                c = c1 + c2;
                result += c;
                s.push(c1);
                s.push(c);
                break;
            case 'D':
                c = 2 * s.top();
                result += c;
                s.push(c);
                break;
            case 'C':
                c = s.top();
                result -= c;
                s.pop();
                break;
            default:
                std::stringstream(o) >> c;
                s.push(c);
                result += c;
        }
    }
    return result;
}

///////////////////////////////////////////////////////////////////////////////
// Evaluate a RPN expression
//
//  @param[in] expression vector represents a RPN expression
//
//  @return evaluated integer value of the input RPN expression
///////////////////////////////////////////////////////////////////////////////
int evaluateRPN(std::vector<std::string> const &expression)
{
   int num;
   std::stack<int> stk;
   for (auto &c: expression)
   {
      if (c[0] != '+' && c[0] != '-' && c[0] != 'x' && c[0] != '/')
      {
         std::stringstream(c) >> num;
         stk.push(num);
      }
      else
      {
         int opb = stk.top();
         stk.pop();
         int opa = stk.top();
         stk.pop();
         switch (c[0])
         {
            case '+':
               stk.push(opa + opb);
               break;
            case '-':
               stk.push(opa - opb);
               break;
            case 'x':
               stk.push(opa * opb);
               break;
            case '/':
               stk.push(opa / opb);
         }
      }
   }
   return stk.top();
}

///////////////////////////////////////////////////////////////////////////////
// Main program
///////////////////////////////////////////////////////////////////////////////
int main()
{
    std::cout << "Play with Stack!!!\n" << std::endl;

    ///////////////////////////////////////////////////////////////////////////
    std::cout << "\nBalance parenthesis" << std::endl;
    // Create test data
    std::string expn = "{[(a + 5)*(b + 6)] * [(c - 10) * (d + 8)]}";
    std::cout << "Expression is: " << expn << std::endl;
    if (isBalanced(expn))
    {
    	std::cout << "Expression is balanced" << std::endl;
    }
    else
    {
	    std::cout << "Unbalanced expression" << std::endl;
    }

    ///////////////////////////////////////////////////////////////////////////
    std::cout << "\nBaseball game" << std::endl;
    std::vector<std::string> ops = {"5", "2", "C", "D", "+"};
    std::cout << "Result = " << calPoints(ops) << std::endl;

    ///////////////////////////////////////////////////////////////////////////
    std::cout << "\nRPN evaluation" << std::endl;
    std::vector<std::string> rpn= {"4", "13", "5", "/", "+"};
    std::cout << "Result = " << evaluateRPN(rpn) << std::endl;
    
    return 0;
}
