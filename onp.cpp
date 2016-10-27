#include <bits/stdc++.h>
#include <cstring>
#include <stack>
using namespace std;

int getprec(char ch)
{
   switch (ch)
   {
      case '/':
      case '^':
      case '*': return 2;
      case '+':
      case '-': return 1;
      default : return 0;
   }
}

void infix2postfix(char infix[], char postfix[], int size)
{
   stack<char> s;
	int weight;
   int i = 0;
   int k = 0;
   char ch;
   // iterate over the infix expression   
   while (i < size)
   {
      ch = infix[i];
      if (ch == '(')
      {
         s.push(ch);
         i++;
         continue;
      }
      if (ch == ')') 
      {
         while (!s.empty() && s.top() != '(')
         {
            postfix[k++] = s.top();
            s.pop();

         }
         // pop off the opening parenthesis also
         if (!s.empty())
            s.pop();
         i++;
         continue;
      }
      weight = getprec(ch);
      if (weight == 0)
         postfix[k++] = ch;
      else
      {
         if (s.empty())
            s.push(ch);
         else
         {
           
            while (!s.empty() && s.top() != '(' && weight <= getprec(s.top()))
            {
               postfix[k++] = s.top();
               s.pop();

            }
            // push the current operator onto stack
            s.push(ch);
         }
      }
      i++;
   }
   // pop of the remaining operators present in the stack
   // and append it to postfix expression 
   while (!s.empty())
   {
      postfix[k++] = s.top();
      s.pop();
   }
	postfix[k] = 0;
}

int main()
{
   int t;
   cin >> t;
   while(t--)
   {
      char infix[401];
      scanf("%s", infix);
      int size = strlen(infix);
      char postfix[size];
      infix2postfix(infix,postfix,size);
      cout << postfix << endl;
   }
   return 0;
}
