from datetime import datetime, timedelta
def decrypt(a, p):
	k = (p-3)/4
	sqrt = pow(a, k+1, p)
	if sqrt > p/2:
		return p - sqrt
	return sqrt

if __name__ == "__main__":
	p = 4000000007
	mydate = datetime(1970, 1, 1, 00, 00)
	n = decrypt(int(raw_input()), p)
	acdate = mydate + timedelta(seconds = n) 
	print acdate.ctime()
