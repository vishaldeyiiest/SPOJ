#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() 
{
	int l;
    while (true)
    {
        scanf("%d", &l);
        if (l == 0)
            break;
        
        double x = (l * l) / (2 * M_PI);
        printf("%.2lf\n", x);
	}
	return 0;
}
