posBici = []
m = [0, 0]

with open('input.txt', 'r') as fin:
    info = fin.readline().split(' ')

    for i in range(int(info[0])):
        posBici.append(int(fin.readline()))

    for i in range(int(info[1])):
        passo = fin.readline().split(' ')

        for j in range(int(info[0])):
            if posBici[j] == passo[0]:
                m[0] = j

            if posBici[j] == passo[1]:
                m[1] = j


        posBici[m[0]] = passo[1]
        posBici[m[1]] = passo[0]


with open('output.txt', 'w') as fout:
    fout.write(str(posBici[0]))
