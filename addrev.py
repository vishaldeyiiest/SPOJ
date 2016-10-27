def reverse(a):
	rev = 0
	while(a > 0):
		rev = rev*10 + a%10
		a = a/10
	return rev
	
t = int(raw_input())
for i in range(t):
	a,b = map(int, raw_input().split(' '))
	s = reverse(a) + reverse(b)
	print(reverse(s))
