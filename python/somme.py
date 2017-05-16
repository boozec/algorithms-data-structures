def sequenza(n, pollatz, tCollatz = -1):
	tot = 1
	
	if pollatz:
		m = 5
	else:
		m = 3
		
	pari = lambda n: ((n % 2) == 0)

	while n != 1:
		if pari(n):
			n /= 2
		else:
			n = n*m+1
			
		tot += 1
		
		if tCollatz != -1 and tot > tCollatz:
			break
			
	
	return tot


with open('input.txt') as fin:
	N = fin.readline().split(' ')

	
N[0] = int(N[0])
N[1] = int(N[1])

tot = 0

for i in range(N[0], N[1]+1):
	collatz = sequenza(i, False)
	
	if sequenza(i, True, collatz) < collatz:
		tot += 1
		
with open('output.txt', 'w') as fout:
	fout.write(str(tot))