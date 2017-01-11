/* realizzare un programma in grado di caricare un vettore di dimensione 10
con dei numeri interi divisibili per il numero 2
utilizzato compilatore GCC 5.0.2 */
#include <iostream>

using namespace std;

bool pari(int n);

int main(int argc, char *argv[])
{
  int N, num, i, totale = 0;
  while(true)
  {
    cout << "Inserisci lunghezza vettore: ";
    cin >> N;
    if(N < 1)
      cout << "Lunghezza vettore con consentita." << endl;
    else
      break;
  }
  
  int vett[N];

  for(i = 0; i < N; i++)
  {
    while(true)
    {
      cout << "Inserisci un numero pari: ";
      cin >> num;
      if(pari(num) == true){
      vett[i] = num;
      break;
      }else cout << "Non hai inserito un numero pari, riprova!" << endl;
    }
    totale += num;
  }

  cout << "----------" << endl;
  for(i = 0; i < N; i++) cout << "vett[" << i << "] = " << vett[i] << endl;
  cout << "----------" << endl;
  cout << "La somma dei valori dell'array e': " << totale << endl;
  cout << "----------" << endl;
  cout << "La media dei valori dell'array e': " << totale / N << endl;

  return 0;
}

bool pari(int n)
{
  return ((n % 2) == 0) ? true : false;
}
