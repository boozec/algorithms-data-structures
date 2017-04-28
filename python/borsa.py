class ValoreNegativo(ValueError):
    def __str__(self):
        return 'Il valore non e\' maggiore di 0'

a = []
i = 0

while i < 14:
    try:
        num = input()
        if num < 0:
            raise ValoreNegativo

        a.append(num)
        i += 1
    except ValoreNegativo, e:
        print(e)


diff = i = 0
tot = len(a)

for i in range(tot):
    minore = a[i]

    for j in range(i, tot-1):
        if a[j] == minore:
            continue
        elif a[j] > minore:
            diffp = a[j] - minore

        if diffp > diff and diffp > 0:
            x = i
            y = j
            diff = diffp


print('Ti conviene comprare a {} giorno {} e vendere a {} giorno {}'.format(a[x], x + 1, a[y], y + 1))
print('Guadagneresti ' + str(diff))