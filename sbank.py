from collections import defaultdict

t = int(raw_input())

for i in range(t):
	n = int(raw_input())
	acc = defaultdict(int)
	for j in range(n):
		acc[str(raw_input())] += 1
	keys = acc.keys()
	keys.sort()
	for each in keys:
		print each, acc[each]
	if i < t-1:
		raw_input()
		print
