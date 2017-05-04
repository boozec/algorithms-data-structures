import math

b = 32
v = [0 for i in range(b)]

stringa = input('Stringa: ')

if len(stringa) < b:
    valVuoto = len(stringa)

i = b - valVuoto
j = 0

while i < b:
    v[i] = int(stringa[j])
    i += 1
    j += 1

i = b - 1
j = num = 0

while i > -1:
    num += v[i] * math.pow(2, j)
    i -= 1
    j += 1

print(int(num))
