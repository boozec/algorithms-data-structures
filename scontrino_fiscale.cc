//determinare dati da input il prezzo dei prodotti lo scontrino totale ed applicare lo sconto del 10% fino a due prodotti, lo sconto del 20% fino a 4
//lo sconto del 30% fino a 6, oltre i 6 il 35%. stampare il totale da pagare.
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int prodotti = 0, sconto;
    float totale = 0, prezzo;
    char cn = 'S';
    string oggetto;

    do
    {
        prodotti++;
        cout << "Prodotto numero " << prodotti << ": ";
        getline(cin,oggetto);
        cin.clear();
        while (cin.get() != '\n')
        {
            continue;
        }

        cout << "Prezzo: ";
        cin >> prezzo;

        totale += prezzo;

        cout << "Continuare? S = Si / N = No : ";
        cin >> cn;
    }while(cn == 'S' || cn == 's');

    switch(prodotti)
    {
        case 1:
        case 2:
            sconto = 10;
            break;
        case 3:
        case 4:
            sconto = 20;
            break;
        case 5:
        case 6:
            sconto = 30;
            break;
        default:
            sconto = 35;
    }

    totale = totale - (totale * sconto / 100);

    cout << "Il totale e': " << totale << endl;
    return 0;
}
