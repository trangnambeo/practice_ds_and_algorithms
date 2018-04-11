#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <ctype.h>
#include <sstream>
#include <stdexcept>
#include <unordered_map>

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
// Simplify path
//
///////////////////////////////////////////////////////////////////////////////
std::string simplifyPath(std::string path)
{
   std::stack<std::string> tokens;
   std::stringstream ss(path);
   std::string token;
   std::string result;
   if (path.front() == '/')
   {
      tokens.push("/");
   }
   while (std::getline(ss, token, '/'))
   {
      if (token == "..")
      {
         if (tokens.empty() || tokens.top() == "..")
         {
            tokens.push(token);
         }
         else if (tokens.top() == "/")
         {
            throw std::runtime_error("Invalid path");
         }
         else
         {
            tokens.pop();
         }
      }
      else if (token != "." && token != "")
      {
         tokens.push(token);
      }   
   }
   while (!tokens.empty())
   {
      token = tokens.top();
      if (token != "/")
      {
         result.insert(0, "/" + token);
      }
      else
      {
         result.insert(0, token);
      }
      tokens.pop();
   }
   return result;
}

///////////////////////////////////////////////////////////////////////////////
// Longest valid parens
//
//  @param[in] expression vector represents parens
//
//  @return length of the longest sequence of parens
///////////////////////////////////////////////////////////////////////////////
unsigned int longestParen(std::vector<std::string> const &parens)
{
   (void)parens;
   return 0;
}

///////////////////////////////////////////////////////////////////////////////
// Next greater element
//
//  @param[in] findNums numbers to find for next greater element
//  @param[in] nums numbers that being searched
//
//  @return next greater numbers of findNums in nums
///////////////////////////////////////////////////////////////////////////////
std::vector<int> nextGreaterElements(std::vector<int> findNums,
   std::vector<int> nums)
{
   std::stack<int> temp;
   std::vector<int> results;
   std::unordered_map<int, int> map;
   int ele = 0;
   for (auto const it: nums)
   {
      if (!temp.empty())
      {
         while (temp.top() < it)
         {
            ele = temp.top();
            map.emplace(ele, it);
            temp.pop();
            if (temp.empty())
            {
               break;
            }
         }
         temp.push(it);
      }
      else
      {
         temp.push(it);
      }
   }

   while (!temp.empty())
   {
      map.emplace(temp.top(), -1);
      temp.pop();
   }

   for (auto const it: findNums)
   {
      results.emplace_back(map[it]);
   }
   return results;
}

///////////////////////////////////////////////////////////////////////////////
// Next greater element for rounded array
//
//  @param[in] nums numbers that being searched
//
//  @return next greater numbers of each number in nums, if not found, search
//   from the beginning.
//
//  @remarks [3, 5, 7, 4] ---> [5, 7, -1, 5] 
///////////////////////////////////////////////////////////////////////////////
std::vector<int> nextGreaterElementsRounded(std::vector<int> const &nums)
{
   std::stack<int> stk;
   std::vector<int> results;
   std::unordered_map<int, int> map;
   int ele = 0;
   int length = nums.size();
   
   // Duplicate numbers
   std::vector<int> double_nums = nums;
   double_nums.resize(2 * length);
   for (int i = 0; i < length; i++)
   {
      double_nums[length + i] = double_nums[i];
   }

   for (int i = 0; i < 2 * length; i++)
   {
      if (!stk.empty())
      {
         while (double_nums[stk.top()] < double_nums[i])
         {
            ele = stk.top();
            map.emplace(ele, double_nums[i]);
            stk.pop();
            if (stk.empty())
            {
               break;
            }
         }
         stk.push(i);
      }
      else
      {
         stk.push(i);
      }
   }

   while (!stk.empty())
   {
      map.emplace(stk.top(), -1);
      stk.pop();
   }

   for (int i = 0; i < length; i++)
   {
      results.emplace_back(map[i]);
   }
   return results;
}

///////////////////////////////////////////////////////////////////////////////
// Main program
///////////////////////////////////////////////////////////////////////////////
void printVector(std::vector<int> const &v)
{
   for (auto const it: v)
   {
      std::cout << it << " ";
   }
   std::cout << std::endl;
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
    
    ///////////////////////////////////////////////////////////////////////////
    std::cout << "\nSimplify path" << std::endl;
    std::string path = "usr//././../home/namly/../Documents/./study/";
    std::cout << "Before, path = " << path << std::endl;
    std::cout << "Result = " << simplifyPath(path) << std::endl;
    
    ///////////////////////////////////////////////////////////////////////////
    std::cout << "\nNext greater element" << std::endl;
    std::vector<int> findNums = {4, 1, 2};
    std::vector<int> nums = {1, 3, 4, 2};
    std::cout << "Result = ";
    printVector(nextGreaterElements(findNums, nums));

    ///////////////////////////////////////////////////////////////////////////
    std::cout << "\nRounded next greater element" << std::endl;
    std::vector<int> nums2 = {100, 1, 11, 1, 120, 11, 123, 1, -1, -100};
    std::cout << "Original numbers = ";
    printVector(nums2);
    std::cout << "Result = ";
    printVector(nextGreaterElementsRounded(nums2));

    return 0;
}
