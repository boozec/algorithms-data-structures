stringa = []

with open('input.txt', 'r') as fin:
    linea = fin.readline()

    for i in linea:
        if i is not ' ':
            stringa.append(i)


t = q = g = 0
tot = 0


for i in range(len(stringa)):
    if stringa[i] == '(':
        t += 1
    elif stringa[i] == '[':
        q += 1
    elif stringa[i] == '{':
        g += 1

    if stringa[i] == ')' and t > 0:
        t -= 1
        tot += 1
    elif stringa[i] == ']' and q > 0:
        q -= 1
        tot += 1
    elif stringa[i] == '}' and g > 0:
        g -= 1
        tot += 1


with open('output.txt', 'w') as fout:
    fout.write(str(tot))
