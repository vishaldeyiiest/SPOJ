#include <bits/stdc++.h>
#define MAX 100000
#define max 50000
using namespace std;

int stprime[max];
int c;
void sieve()
{
	bool primes[max+100];
	memset(primes, true, sizeof(primes));
 
    primes[0] = false;
    primes[1] = false;
    primes[2] = true;
 
    for (int i = 2; i*i <= max; ++i)
    {
        if (primes[i])
        {
            for (int j = i + i; j <= max; j += i)
                primes[j] = false;
        }
    }
 
    c = 0;
    for(int i = 2; i <= max; ++i)
    {
        if (primes[i])
            stprime[c] = i, c++;
	}
}	
			
int main()
{
	sieve();
	int t;
	long int m, n;
	cin >> t;
	while(t--)
	{
		cin >> m >> n;
        bool p[MAX+100];
        memset(p, 1, sizeof p);
        if (m == 0)
        {
			p[0] = false;
            if (n - m > 1)
				p[1] = false;
        }
        if (m == 1)
			p[0] = false;
        for (int i = 0; i < c; i++)
        {
			int prime = stprime[i];
			if (prime * 2 > n)
				break;
             int j = m / prime;
             if (j < 2) j = 2;
             for (;;)
             {
                int prod = prime * j;
                if (prod > n)
					break;
                if (prod >= m)
					p[prod - m] = false;
				j++;
             }
         }
         for(int i = m;i <= n;i++)
		 {
			if( p[i - m])
				cout << i << endl;     
         }
		cout << endl;
	}
}
 		
