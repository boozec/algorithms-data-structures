class puntiVedita:
    def __init__(self):
        citta = ''
        entrate = uscite = 0

	
pV = [puntiVedita() for i in range(5)]


def carica():
    pV[0].citta = "Catania";
    pV[0].entrate = 380;
    pV[0].uscite = 245;
    pV[1].citta = "Ragusa";
    pV[1].entrate = 231;
    pV[1].uscite = 175;
    pV[2].citta = "Siracusa";
    pV[2].entrate = 214;
    pV[2].uscite = 227;
    pV[3].citta = "Messina";
    pV[3].entrate = 294;
    pV[3].uscite = 189;
    pV[4].citta = "Enna";
    pV[4].entrate = 145;
    pV[4].uscite = 175;
	
	
def ordx():
    s = True
    t = puntiVedita()
    last = 4
	
    while s:
        s = False
		
        for i in range(last):
            if pV[i].entrate > pV[i+1].entrate:
                t.citta = pV[i].citta;
                t.entrate = pV[i].entrate;
                t.uscite = pV[i].uscite;
				
                pV[i].citta = pV[i+1].citta;
                pV[i].entrate = pV[i+1].entrate;
                pV[i].uscite = pV[i+1].uscite;
				
                pV[i+1].citta = t.citta;
                pV[i+1].entrate = t.entrate;
                pV[i+1].uscite = t.uscite;

                s = True;
		
        last -= 1
	
	
def util(p):
    if p.entrate < p.uscite:
        r = False
    else:
        r = True
		
    return r
	
	
for i in pV:
    carica()
	
    if not util(i):
        print("Attenzione -> {}".format(i.citta))

ordx()

for i in pV:
    print(i.entrate)
