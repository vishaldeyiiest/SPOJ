#include <iostream>
#include <string.h>
using namespace std;

template <class T>
class stack
{
public:
	stack(int len = 50)
	{
		elem = new T[len];
		m_top = -1;
	}
	~stack()
	{
		delete []elem;
	}
	void Push(const T &val)
	{
		elem[++m_top] = val;
	}
	bool isEmpty()
	{
		return m_top == -1;
	}T& Pop() 
	{
		return elem[m_top--];
	}
	T& getTop()
	{
		return elem[m_top];
	}
private:
	T *elem;
	int m_top;
};

int getPriority(char ch)
{
	if(ch == '+' || ch == '-')
		return 1;
	if(ch == '*' || ch == '/')
		return 2;
	return 0;
}
void addBacket(string &str)
{
	string s1 = "(";
	string s2 = ")";
	s1+=str;
	str = s1;
	str+=s2;
}
string InfixtoPostfix(char* exp,int len)
{
	int x = 0;
	string tmpExp;
	stack<char> opStack(len/2);
	for(int i = 0;i<len;i++)
	{
		switch(exp[i])
		{
		case'(':
			opStack.Push(exp[i]);
			break;
		case ')':
			while(opStack.getTop() != '(')
				tmpExp+= opStack.Pop();
			opStack.Pop();
			break;case '+':case '-':	case '*':case '/':
			while(!opStack.isEmpty() && opStack.getTop() !='(' &&
				getPriority(opStack.getTop()) >= getPriority(exp[i]))
				tmpExp+= opStack.Pop();
			opStack.Push(exp[i]);
			break;
		default:
			tmpExp+= exp[i];
			break;
		}
	}
	while(!opStack.isEmpty())
	{
		char tmp = opStack.Pop();
		if(tmp != '(')
			tmpExp+= tmp;
	}
	return tmpExp;
}

void PostfixtoInfix(char* exp,int len)
{
	string tmp = InfixtoPostfix(exp,len);
	int x = tmp.length();
	stack<char> op(x);
	stack<string> result(x);
	string tmp1, tmp2;
	for (int i = 0; i < x; i++) 
	{
		if (tmp[i] >= 'a' && tmp[i] <= 'z') 
		{
			op.Push(tmp[i]);
			result.Push(string(1,tmp[i]));
		} 
		else 
		{
			if (getPriority(op.getTop()) != 0 && (getPriority(tmp[i]) > getPriority(op.getTop()) || 
				(getPriority(tmp[i]) == getPriority(op.getTop()) && (tmp[i] == '-' || tmp[i] == '/')))) 
			{
				tmp2 = "(";
				tmp2 += result.getTop();
				tmp2 += ")";
			} else tmp2 = result.getTop();
			result.Pop();
			op.Pop();
			if (getPriority(op.getTop()) != 0 && getPriority(tmp[i]) > getPriority(op.getTop()))
			{
				tmp1 = "(";
				tmp1 += result.getTop();
				tmp1 += ")";
			} else tmp1 = result.getTop();
			op.Pop();
			result.Pop();
			tmp1 += tmp[i];
			tmp1 += tmp2;
			result.Push(tmp1);
			op.Push(tmp[i]);
		}
	}
	cout << result.Pop() << endl;
}
int main()
{
	int num = 0;
	cin>>num;
	while(num--)
	{
		char exp[250];
		cin>>exp;
		PostfixtoInfix(exp,strlen(exp));
	}
}
