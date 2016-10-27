def fact(a):
	res = 1
	for i in range(a):
		res = res*(i+1)
	print(res)

t = int(raw_input())
for i in range(t):
	a = int(raw_input())
	fact(a)
