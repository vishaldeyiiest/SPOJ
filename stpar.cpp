#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	while(scanf("%d", &n) == 1 && n > 0)
	{
		stack<int> s;
		int a[1001];
		
		for(int i = 0; i < n; i++)
			cin >> a[i];
		s.push(a[0]);
		int p = 1;
		int flag = 1;
		
		for(int i = 1; i < n && flag; i++)
		{
			while(!s.empty() && a[i] > s.top() && s.top()==p++)
				s.pop();
			s.push(a[i]);
		}
		
		while(flag && !s.empty() && s.top()==p++)
			s.pop();
		if(flag && s.empty())
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}
