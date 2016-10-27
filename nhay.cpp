#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(string pat, int M, int *lps)
{
    int len = 0;  
    int i;

    lps[0] = 0; 
    i = 1;
    while (i < M)
    {
		if (pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len != 0)
				len = lps[len-1];
	
			else 
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMPSearch(string pat, string txt)
{
	int M = pat.length();
	int N = txt.length();
	int *lps;
	lps = new int[M];
    int i = 0, j  = 0;
    computeLPSArray(pat, M, lps); 
   
    while (i < N)
    {
		if (pat[j] == txt[i])
		{
			j++;
			i++;
		}
		if (j == M)
		{	
			cout << i-j << endl;
			j = lps[j-1];
		}
		else if (pat[j] != txt[i])
		{
			if(j == 0)
				i++;
			else
				j = lps[j-1];
		}
    }
    delete lps;
}

int main()
{
	string pat, txt;
	int n;
	while(scanf("%d",&n)==1)
	{
		cin >> pat >> txt;
		KMPSearch(pat, txt);
		cout << endl;
	}
   return 0;
}
