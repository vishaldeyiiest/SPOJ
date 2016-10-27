#include	<iostream>
#include	<fstream>
#include 	<stdio.h>
#include	<stack>
#include	  <string.h>
#include	<stdlib.h>
using	namespace std;

char	inp[1002];
char	op1[501], op2[501], ans[1002];

typedef	struct
{
	 int	ndigits;
	 char *aptr;
	 char	*eptr;	//and of partial so that one can add it to running sum
	 char	ans[502];
}	Partials;

Partials	Partial[501];

void	OutChars(char c,int n)
{
	 while (n-- > 0)
		putchar(c);
}


void	DoAddition(void)
{
	int	l0,l1,l2,l3;	//lengths of each
	int	ld;		//len difference

	l1 = strlen(op1);
	l2 = strlen(op2);
	ld = l1 -l2;

	//adjust so that they line up
	if (ld < 0) //op2 is longer
	{
		//move op1 to right ld chars
		ld = -ld;
		memmove(op1+ld, op1, l1+1);
		memset(op1,'0',ld);
		ld = l2;
	}
	else if (ld > 0)	//op1 is longer
	{
		//move op2 to right ld chars
		memmove(op2+ld, op2, l2+1);
		memset(op2,'0',ld);
		ld = l1;
	}
	else ld = l1;

	l0 = ld;
	//ok as we may have a carry when adding the 2 leftmost digits
	//we offset the addition of op1, op2 by one digit to the right in the ans array
	char *o1 = op1 + ld-1;
	char *o2 = op2 + ld-1;
	char *an = ans + ld+1;
	int	cy = 0;
	int	sum = 0;

	*an-- = 0;	//terminate answer
	while (ld-- > 0 )
	{
		sum = *o1 + *o2 - 0x60 + cy;	//add as integers
		if ( sum > 9 )
		{
			cy = 1;
			sum -= 10;
		}
		else
			cy = 0;

		//now store the digits
		*an-- = sum + 0x30;
		o1--;
		o2--;
	}
	*an = cy + 0x30;	//deal with any final carry;

	//now format the thing
	ld = l0;
	if ( *an == '0')	//lose leading zeros
		an++;
	l3 = strlen(an);	//answer length
	l0 = l3;
	if (l1 > l0)
		l0 = l1;
	if ( (l2+1) > l0)
		l0 = l2 + 1;	//allow for operator

	o1 = op1;
	while (*o1 == '0')
		o1++;
	OutChars(' ',l0-l1);
	printf("%s\n",o1);

	o2 = op2;
	while (*o2 == '0')
		o2++;
	OutChars(' ',l0 - l2 - 1);
	printf("+%s\n",o2);

	OutChars('-',l0);
	printf("\n");


	OutChars(' ',l0 - l3);
	printf("%s\n", an);

	printf("\n");

}

void	DoSubtraction(void)
{
	int	l0,l1,l2,l3;	//lengths of each
	int	ld;		//len difference

	l1 = strlen(op1);
	l2 = strlen(op2);
	ld = l1 -l2;

	//adjust so that they line up
	if (ld < 0) //op2 is longer
	{
		//move op1 to right ld chars
		ld = -ld;
		memmove(op1+ld, op1, l1+1);
		memset(op1,'0',ld);
		ld = l2;
	}
	else if (ld > 0)	//op1 is longer
	{
		//move op2 to right ld chars
		memmove(op2+ld, op2, l2+1);
		memset(op2,'0',ld);
		ld = l1;
	}
	else ld = l1;

	l0 = ld;
	char *o1 = op1 + ld-1;
	char *o2 = op2 + ld-1;
	char *an = ans + ld-1;
	int	cy = 0;
	int	res = 0;

	*an-- = 0;	//terminate answer
	while (ld-- > 0 )
	{
		if ( (*o1-cy) < *o2)
		{
			res = 10 + *o1 - cy - *o2;
			cy = 1;
		}
		else
		{
			res = *o1 -cy - *o2;
			cy = 0;
		}

		//now store the digits
		*an-- = res + 0x30;
		o1--;
		o2--;
	}
	*an = cy + 0x30;	//deal with any final carry;

	//now format the thing
	ld = l0;
	while ( (*an == '0') && ( *(an+1) != 0))	//lose leading zeros
		an++;
	l3 = strlen(an);	//answer length
	l0 = l3;
	if (l1 > l0)
		l0 = l1;
	if ( (l2+1) > l0)
		l0 = l2 + 1;	//allow for operator

	o1 = op1;
	while (*o1 == '0')
		o1++;
	OutChars(' ',l0-l1);
	printf("%s\n",o1);

	o2 = op2;
	while (*o2 == '0')
		o2++;
	OutChars(' ',l0 - l2 - 1);
	printf("-%s\n",o2);

	OutChars('-',l0);
	printf("\n");


	OutChars(' ',l0 - l3);
	printf("%s\n", an);

	printf("\n");

}
void	DoMultiplication(void)
{
	int	l1,l2;	//lengths of each
	int	ld;		//len difference
	int	dans;		//digits in answer - max
	int	incld = 0;

	l1 = strlen(op1);
	l2 = strlen(op2);
	dans = l1 + l2;		//max number of digits in answer
	ld = l1 -l2;		//adjust for *

	//adjust so that they line up
	if (ld < 0) //op2 is longer
	{
		//move op1 to right ld chars
		ld = -ld;
		memmove(op1+ld, op1, l1+1);
		memset(op1,' ',ld);
		ld = l2;
		incld = 1;
	}
	else if (ld > 0)	//op1 is longer
	{
		//move op2 to right ld chars
		memmove(op2+ld, op2, l2+1);
		memset(op2,' ',ld);
		ld = l1;
	}
	else ld = l1;

	int value = 0;
	int prod;
	int sum = 0;
	int q;
	int cy;
	int r = 0;
	int lp;
	int lmax = 0;
	char *o1 = op1;
	char *o2 = &op2[ld-1];
	char *ansptr;
	Partials	*pptr;

	memset(ans,0x20,1001);
	ans[1001] = 0;
	ansptr = &ans[1000];	//repoint to answer
	*ansptr = 0;
	for (int i = 0; i< l2; i++)   //need this many partials
	{
		char  *o1 = &op1[ld-1];
		pptr = &Partial[i]; //point at terminating zero if string
		pptr->aptr = &pptr->ans[dans - i + 1];

		*pptr->aptr-- = 0;	//terminate
		pptr->eptr = pptr->aptr;

		ansptr = &ans[1001-i];	//repoint to answer

		q = 0;
		for (int j= 0; j<l1; j++) //do each mutiplicand digit
		{
			prod = (*o2 - 0x30) * (*o1 -0x30) + q;
			q = prod / 10;
			r = prod % 10;
			*pptr->aptr-- = r + 0x30;	//terminate
			*pptr->aptr = 0x20;
			o1--;

		}
		if (q != 0 )
		{
			*pptr->aptr-- = q + 0x30;	//terminate
			*pptr->aptr = 0x20;
		}
		if (l2 != 1 )
			o2--;
		pptr->aptr++;
//		printf("%s\n",pptr->aptr);
		lp = strlen(pptr->aptr);
		if (lp > lmax )
			lmax = lp;

		//now add partial to running sum
		int	sum = 0;
		char	*psptr = pptr->eptr;
		cy = 0;

		for (int j = 0; j<lp; j++)
		{
			sum = cy;
			if ( *psptr > 0x20)
				sum += (*psptr - 0x30);
			if ( *ansptr > 0x20)
				sum += (*ansptr - 0x30);	//add value

			cy = sum / 10;

			*ansptr-- = (sum % 10) + 0x30;
			psptr--;
		}
		while (*ansptr < 0x31)
			ansptr++;
//		pptr->aptr = ansptr;
		while( (*pptr->aptr == 0x30) && ( *(pptr->aptr+1) != 0))
			pptr->aptr++;
		pptr->ndigits = strlen(pptr->aptr);
	}

	//now format the answer
	ld += incld; //when op2 is longer
	int la = strlen(ansptr);
	if ( (l2==1) )	//single digit multiplier - so only answer needed
	{
		if ( la==1) //then op1 is also 1
		{
			printf(" %s\n",o1);
			printf("*%s\n",o2);
			OutChars('-',2);
			printf("\n");
			printf(" %s\n", ansptr);

			printf("\n");
			return;
			}
		//longer answer - and la is longest
		OutChars(' ',la-l1);
		printf("%s\n",o1);

		OutChars(' ',la-l2-1);
		printf("*%s\n",o2);
		OutChars('-',la);
		printf("\n");
		printf("%s\n", ansptr);

		printf("\n");
		return;
	}
	 if (ld > la) //then short answer
	{
		while ( (*o1 == '0') || ((*o1==0x20) && (*o1) != 0))
			o1++;
		OutChars(' ',ld-l1);
		printf("%s\n",o1);

		o2 = op2;
		while ( (*o2 == '0') || ((*o2==0x20) && (*o2) != 0))
			o2++;
		OutChars(' ',ld - l2 - 1);
		printf("*%s\n",o2);

		OutChars('-',ld);
		printf("\n");

		//now the partials
		for (int i = 0; i < l2; i++)
		{
			OutChars(' ',ld -i -Partial[i].ndigits);
			printf("%s\n", Partial[i].aptr);
		}

		//answer
		if (l2 != 1)
		{
			OutChars(' ',ld - la);
			OutChars('-',la);
			printf("\n");
		}

		OutChars(' ',ld - la);
		printf("%s\n", ansptr);

		printf("\n");
		return;
	}
	//then long answer
	if ( ld = la)
	{
		while ( (*o1 == '0') || ((*o1==0x20) && (*o1) != 0))
			o1++;
		OutChars(' ',ld-l1);
		printf("%s\n",o1);

		o2 = op2;
		while ( (*o2 == '0') || ((*o2==0x20) && (*o2) != 0))
			o2++;
		OutChars(' ',ld - l2-1); //less one cos we need ot allow for *
		printf("*%s\n",o2);

		OutChars('-',ld);
		printf("\n");

		//now the partials
		for (int i = 0; i < l2; i++)
		{
			OutChars(' ',ld -i -Partial[i].ndigits);
			printf("%s\n", Partial[i].aptr);
		}

		//answer
		if (l2 != 1)
		{
			OutChars(' ',ld - la);
			OutChars('-',la);
			printf("\n");
		}

		OutChars(' ',ld - la);
		printf("%s\n", ansptr);
		printf("\n");

		return;
	}
	return;

	if ( l2 < l1)
	{
		while ( (*o1 == '0') || ((*o1==0x20) && (*o1) != 0))
			o1++;
		OutChars(' ',ld-l2);
		printf("%s\n",o1);

		o2 = op2;
		while ( (*o2 == '0') || ((*o2==0x20) && (*o2) != 0))
			o2++;
		OutChars(' ',ld - l2);
		printf("*%s\n",o2);

		OutChars('-',ld+1);
		printf("\n");

		//now the partials
		for (int i = 0; i < l2; i++)
		{
			OutChars(' ',ld -i -Partial[i].ndigits + 1);
			printf("%s\n", Partial[i].aptr);
		}

		//answer
		if (l2 != 1)
		{
			OutChars(' ',ld - la);
			OutChars('-',la);
			printf("\n");
		}

		OutChars(' ',ld - la);
		printf("%s\n", ansptr);
	}

	printf("\n");

}

int main(int argc, char* argv[])
{
	char	op;
	char	*expr;
	int	tests;

	cin >> tests;
	while (tests-- > 0 )
	{
		cin >> inp;

		//look for operator
		expr = inp;
		while ( *expr >= '0')
			expr++;
		op = *expr;

		//grab operands
		*expr++ = 0;
		strcpy(op1, inp);
		strcpy(op2,expr);

		switch (op)
		{
			case '+' :	DoAddition(); 			break;
			case '-'	:	DoSubtraction();    	break;
			   case '*' :	DoMultiplication();	break;
		}
	}
	return 0;
}
