#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

int pour(int a, int b, int A, int B, int c)
{
	int count = 0;
	while(a != c && b != c)
	{
		if(a == 0)
			a = A;
		else if(b == B)
			b = 0;
		else if(a != 0 && b < B)
		{
			if(a <= B-b)
			{
				b = a+b;
				a = 0;
			}
			else
			{
				a=a-(B-b);
				b=b+(B-b);
			}
		}
		count++;
	}
	return count;
}

int main()
{
	int t;
	int r, m, n, A, B, C;
	cin >> t;
	while(t--)
	{
		cin >> A >> B >> C;
		r=gcd(A,B);
		if(C%r != 0 || (C>A && C>B))
			cout<<"-1"<<endl;
		else
		{
			m = pour(0, 0, A, B, C);
			swap(A, B);
			n=pour(0, 0, A, B, C);
			cout << min(m,n) << endl;
		}
	}
	return 0;
}
