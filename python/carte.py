class punteggioGiocatori:
    def __init__(self, idGiocatore, punteggio):
        self.idGiocatore = idGiocatore
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
            if players[j].idGiocatore == futID:
                rID = j
                break

        if rID == -1:
            players[last].idGiocatore = futID
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
            t[0] = players[k].idGiocatore
            t[1] = players[k].punteggio

            players[k].idGiocatore = players[k + 1].idGiocatore
            players[k].punteggio = players[k + 1].punteggio

            players[k + 1].idGiocatore = t[0]
            players[k + 1].punteggio = t[1]

            s = True

    k -= 1


with open('output.txt', 'w') as fout:
    fout.write(str(players[0].idGiocatore) + ' ' + str(players[0].punteggio))
