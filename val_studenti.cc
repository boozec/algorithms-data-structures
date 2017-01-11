//visualizzare la media e i voti positivi di n materie di n studenti
//usato il compilatore GNU GCC

#include <iostream>
#include <string>

using namespace std;

int main()
{
  int studenti, somma = 0, materie, positivi, i = 0, j;
  float media, voto;
  string nome;

  cout << "Quanti studenti? ";
  cin >> studenti;


  cout << "Quante materie? ";
  cin >> materie;
  cout << "\n";

  do {
    positivi = 0;
    media = 0;
    j = 0;
    somma = 0;
    cout << "Nome: ";
    cin >> nome;

    do {
      cout << "Inserisci voto: ";
      cin >> voto;

      if (voto >= 6) positivi++;

      somma += voto;
      j++;
    } while(j < materie);

    media = (float) somma / (float) materie;
    cout << "La media dei voti dell'alunno " << nome << " e': " << media << ". Considerando " << positivi << " voti positivi.\n" << endl;
    i++;
  } while(i < studenti);

  return 0;
}
