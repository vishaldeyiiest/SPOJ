#include <iostream>
using namespace std;

void countzeros(long int n)
{
	int count = 0;
	while(n > 0)
	{
		count += n/5;
		n = n/5;
	}
	cout<<count<<endl;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long int n;
		cin >> n;
		countzeros(n);
	}
}
