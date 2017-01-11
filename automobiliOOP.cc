#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class automobili {
protected:
	string marca;
	int anno_matricola;
public:
	int cilindrata;
	void get_marca(string m) {marca = m;}
	void get_cilindrata(int c) {cilindrata = c;}
	void get_annoMatricola(int am) {anno_matricola = am;}
	int annoMatricola(void) {return anno_matricola;}
};

class acquirente : public automobili {
	string nome;
	string cognome;
public:
	void get_nome(string n) {nome = n;}
	void get_cognome(string cn) {cognome = cn;}
	void visualizza_cognome(void) { cout << cognome << endl; }
};

int main(int argc, char *argv[])
{
	int i = 0, toshow = 0, anno_richiesto, N;
	char ch;
	acquirente *p;
	string marca, nome, cognome;
	int cilindrata, anno_matricola;

	cout << "Quante auto vorresti inserire? ";
	cin >> N;
	acquirente var[N];

	do {
		p = &var[i];
		cout << "Marca auto: ";
	 	cin >> marca;
	 	cout << "Cilindrata: ";
	 	cin >> cilindrata;
	 	cout << "Anno di immatricolazione: ";
	 	cin >> anno_matricola;
	 	cout << "Cognome del proprietario: ";
	 	cin >> cognome;
	 	cout << "Nome del proprietario: ";
	 	cin >> nome;
	 	cout << "-------------" << endl;

		ofstream myFile;
		myFile.open("db.txt", ios::app);
		myFile << "Marca auto: " << marca << endl;
		myFile << "Cilindrata: " << cilindrata << endl;
		myFile << "Anno di immatricolazione: " << anno_matricola << endl;
		myFile << "Cognome del proprietario: " << cognome << endl;
		myFile << "Nome del proprietario: " << nome << endl;
		myFile << "--------------" << endl;
		myFile.close();

		p->get_marca(marca);
		p->get_cilindrata(cilindrata);
		p->get_annoMatricola(anno_matricola);
		p->get_nome(nome);
		p->get_cognome(cognome);
		i++;
	} while(i < N);

	cout << "Persone con auto di cilindrata maggiore a 1500: " << endl;
	for(i = 0; i < N; i++){
		if(p->cilindrata > 1500)
			p->visualizza_cognome();
	}

	while(ch != 'n') {
		cout << "Quale anno di immatricolazione si vuole visualizzare? ";
		cin >> anno_richiesto;

		for(i = 0; i < N; i++){
			if(anno_richiesto == p->annoMatricola())
				toshow++;
		}

		if(toshow > 0)
			cout << "Nell'anno " << anno_richiesto << " sono state immatricolate num auto: " << toshow << endl;
		else
			cout << "Non ci sono immatricolazioni nell'anno " << anno_richiesto << endl;

		toshow = 0;

		cout << "Continuare? (S)ì | (N)o : ";
		cin >> ch;
		ch = tolower(ch);
	}
	return 0;
}
