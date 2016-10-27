#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, a[10001];
	cin >> t;
	while(t--)
	{
		int e, f;
		a[0] = 0;
		cin >> e >> f;
		int W = f - e;
		fill(&a[1], &a[1]+W, INT_MAX);
		
		int n, w, p;
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			cin >> p >> w;
			for(int j = 0; j+w <= W; j++)
				if(a[j] != INT_MAX)
				a[j+w] = min(a[j+w], a[j] + p);
		}
		if(a[W] != INT_MAX)
			cout << "The minimum amount of money in the piggy-bank is " << a[W] <<"." <<endl;
		else
			cout << "This is impossible." << endl; 
	}
}
