#include <iostream>
#include <string>

#define SIZE 2

using namespace std;

int main(int argc, char **argv)
{
  int i = 0;
  int anno_richiesto, toshow = 0;
  char ch;

  struct automobili {
    char marca[30];
    int cilindrata;
    int anno_matricola;
    struct acquirente {
      char nome[30];
      char cognome[30];
    } user;
  } autom[SIZE];

  do {
    cout << "Marca auto: ";
    cin >> autom[i].marca;
    cout << "Cilindrata: ";
    cin >> autom[i].cilindrata;
    cout << "Anno di immatricolazione: ";
    cin >> autom[i].anno_matricola;
    cout << "Cognome del proprietario: ";
    cin >> autom[i].user.cognome;
    cout << "Nome del proprietario: ";
    cin >> autom[i].user.nome;
    cout << "-------------" << endl;

    i++;
  }while(i < SIZE);

  for(int i = 0; i < SIZE; i++){
    if(autom[i].cilindrata > 1500)
      cout << autom[i].user.cognome << endl;
  }

  do {
    cout << "Quale anno di immatricolazione vuoi visualizzare?";
    cin >> anno_richiesto;

    for(int i = 0; i < SIZE; i++){
      if(anno_richiesto == autom[i].anno_matricola )
        toshow++;
    }

    if(toshow > 0)
      cout << "Nell'anno " << anno_richiesto << " sono state immatricolate " << toshow << " auto.\n" << endl;
    else
      cout << "Nessun'auto e' stata immatricolata nel " << anno_richiesto << endl << endl;

    cout << "(U)scire | (C)ontinua: ";
    cin >> ch;
    ch = tolower(ch);

    toshow = 0;
  } while(ch != 'u');


  return 0;
}
