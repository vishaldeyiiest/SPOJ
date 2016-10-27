#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, i, j;
	long long n;
	long long sqr[1000001];
	for (i = 0; i <= 1000000; i++)
		sqr[i] = (long long)i*i;
	
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		i = 0;
		j = sqrt((long double)n);
		while(i <= j)
		{
			if(sqr[i] + sqr[j] == n)
				break;
			else if(sqr[i] + sqr[j] < n)
				i++;
			else
				j--;
		}
		if (sqr[i] + sqr[j] == n)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
