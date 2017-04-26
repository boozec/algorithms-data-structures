fib = []
fib.append(1)
fib.append(1)

def fibonacci(N):
    for i in range(2, N):
        fib.append(fib[i - 1] + fib[i - 2])

        if fib[i] > N:
            break
            
    return i


with open('input.txt', 'r') as fin:
    N = int(fin.readline())

lst = fibonacci(N)

fib.reverse()
print()

somma = 0
seq = []
for i in range(0,len(fib)-1):
    potSomma = somma + fib[i]
    if potSomma < N:
        somma = potSomma
        seq.append(1)
    else:
        seq.append(0)

seq.append(1)
seq.reverse()

if N == 1 or N > 4:
    seq.pop()

with open('output.txt', 'w') as fout:
    for i in seq:
        fout.write(str(i))
