from math import pow

b = 32
v = [0 for i in range(b)]

str = input('Stringa: ')

if len(str) < b:
    valVuoto = len(str)

i = b - valVuoto
j = 0

while i < b:
    v[i] = int(str[j])
    i += 1
    j += 1

i = b - 1
j = num = 0

while i > -1:
    num += v[i] * pow(2, j)
    i -= 1
    j += 1

print(int(num))
