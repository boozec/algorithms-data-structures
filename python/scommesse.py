carteV = []
carteOut = []


def cOutPresente(x):
    s = False
    for i in range(len(carteOut)):
        if (carteOut[i] == x):
            s = True

    if not s:
        carteOut.append(x)


def fCarte(N, start):
    c = carteV[:]

    while len(c) > 1:
        tot = len(c)
        for i in range(start, tot - 1):
            x = c[i]
            x1 = c[i + 1]
            x2 = x + x1

            if ((x2 % 2) != 0):
                c.remove(x)
                c.remove(x1)
                break

        start = 0

    cOutPresente(c[0])


with open('input.txt', 'r') as fin:
    N = int(fin.readline())
    carteV = fin.readline().split(' ')

for i in range(N):
    carteV[i] = int(carteV[i])

for i in range(N):
    fCarte(N, start=i)

with open('output.txt', 'w') as fout:
    fout.write(str(len(carteOut)))
    fout.write('\n')

    for i in carteOut:
        fout.write(str(i) + ' ')
