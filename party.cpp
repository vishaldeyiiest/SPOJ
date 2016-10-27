#include <bits/stdc++.h>
using namespace std;

int main()
{
	int dp[101][501];
	int cost, fun, n, money;
	
	while(scanf("%d %d", &money, &n) == 2)
	{
		if(money == 0 && n == 0)
			break;
		for(int i = 0; i < money+1; i++)
			dp[0][i] = 0;
		for(int i = 1; i < n+1; i++)
			dp[i][0] = 0;
		
		for(int i = 1; i <= n; i++)
		{	
			cin >> cost >> fun;
			for(int w = 1; w <= money; w++)
			{
				if(cost <= w)
					dp[i][w] = max(dp[i-1][w], dp[i-1][w-cost] + fun);
				else
					dp[i][w] = dp[i-1][w];
			}
		}
		int w, best;
		for(w = money, best = dp[n][money]; w; w--)
			if(dp[n][w] < best)
				break;
		cout << w + 1 <<" "<< dp[n][money]<<endl;
	}
	return 0;
}
