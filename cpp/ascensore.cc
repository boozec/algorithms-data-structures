#include <iostream>
#include <stdlib.h>
#include <string>
#include <unistd.h>

class Ascensore 
{
private:
	unsigned short int floor;
	bool doors;
	unsigned short int maxFloor;
public:
	Ascensore(unsigned short int plan = 0) {floor = plan; maxFloor = 5;}
	void Up(void);
	void Down(void);
	void Doors(void);
	void getFloor(void);
};

void _clear(void);

using namespace std;

int main(void)
{
	char choose;
	Ascensore *ascensore = new Ascensore();
	do {
		ascensore->getFloor();
		cin >> choose;
		choose = tolower(choose);
		if(choose == 'u' || choose == 'd') ascensore->Doors();
		sleep(2);
		switch(choose)
		{
			case 'u' : ascensore->Up(); break;
			case 'd' : ascensore->Down(); break;
			case 'e' : break;
		}
		_clear();
		if(choose == 'u' || choose == 'd') ascensore->Doors();
	} while(choose != 'e');
	
	cout << "SEI USCITO DALL'ASCENSORE CON SUCCESSO!";
	
	return 0;
}

void _clear(void)
{
	#ifdef OS_WINDOWS
		system("CLS");
	#else
		system("clear");
	#endif
}

void Ascensore::getFloor(void)
{
	if(floor == maxFloor) cout << "Sei arrivato all'ultimo piano" << endl;
	if(floor == 0) cout << "Non puoi scendere più di così" << endl;
	cout << "SEI ATTUALMENTE AL PIANO " << floor << endl;
	cout << "\nQUALE AZIONE SI VUOLE COMPIERE?" << endl;
	cout << "U - salire" << endl;
	cout << "D - scendere" << endl;
	cout << "E - Uscire" << endl;
	cout << "> ";
}

void Ascensore::Up(void)
{	
	if(floor < maxFloor) floor+=1;
}

void Ascensore::Down(void)
{	
	if(floor > 0) floor-=1;
}

void Ascensore::Doors(void)
{
	if(doors == true)
	{
		cout << "> APERTURA PORTE" << endl;
		doors = false;
	} else {
		cout << "> CHIUSURA PORTE..." << endl;
		doors = true;
	}
}
