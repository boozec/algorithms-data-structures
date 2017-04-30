class punteggioGiocatori:
    def __init__(self, id, punteggio):
        self.id = id
        self.punteggio = punteggio


last = 0

with open('input.txt', 'r') as fin:
    N = int(fin.readline())
    players = [punteggioGiocatori(0,0) for i in range(N)]

    for i in range(N):
        ch = fin.readline().split(' ')
        futID = int(ch[0])
        futPunteggio = int(ch[1])

        rID = -1

        for j in range(N):
            if players[j].id == futID:
                rID = j
                break

        if rID == -1:
            players[last].id = futID
            players[last].punteggio = futPunteggio
            last += 1

        else:
            players[rID].punteggio += futPunteggio

s = True
t = [0,0]

while(s):
    s = False

    for k in range(last):
        if players[k].punteggio < players[k+1].punteggio:
            t[0] = players[k].id
            t[1] = players[k].punteggio

            players[k].id = players[k + 1].id
            players[k].punteggio = players[k + 1].punteggio

            players[k + 1].id = t[0]
            players[k + 1].punteggio = t[1]

            s = True

    k -= 1


with open('output.txt', 'w') as fout:
    fout.write(str(players[0].id) + ' ' + str(players[0].punteggio))