#include "stdafx.h"
#include <iostream>
using namespace std;

char tab[] = { '1','2','3','4','5','6','7','8','9' };
char rysujPlansze();
char wyborZnaku();
char ktoZaczyna();
void ruchGracza(char znak);
void ruchKomputera(char znak);
char czyWygrana();

int main()
{
	setlocale(LC_ALL, "polish");
	int odNowaGra;
	cout << "Witaj w grze kó³ko i krzy¿yk" << endl << endl;
	do
	{
		char znakGracza = wyborZnaku();
		char znakKomputera;
		char wygrana;
		if (znakGracza == 'X')
			znakKomputera = 'O';
		else
			znakKomputera = 'X';

		char zaczyna = ktoZaczyna();
		int licznik = 0;

		rysujPlansze();
		if (zaczyna == '1'){
			ruchGracza(znakGracza);
			licznik++;
		}
		do{
			ruchKomputera(znakKomputera);
			rysujPlansze();
			licznik++;
			wygrana = czyWygrana();
			if (wygrana != 0)
				goto koniec;
			ruchGracza(znakGracza);
			rysujPlansze();
			licznik++;
			wygrana = czyWygrana();
			if (wygrana != 0)
				goto koniec;
		} while (licznik < 8);
		if (zaczyna == '2'){
			ruchKomputera(znakKomputera);
			rysujPlansze();
			wygrana = czyWygrana();
		}
		koniec:
		if (wygrana == 0)
			cout << "Remis!! \n \n";
		else if (wygrana == znakGracza)
			cout << "Wygrana!!! \n \n";
		else if (wygrana == znakKomputera)
			cout << "Przegrana! \n \n";

		cout << "Chcesz zagraæ jeszcze raz? 1/2: \n 1: Tak \n 2: Nie \n ";
		cin >> odNowaGra; 
		system("cls");
	} while (odNowaGra == 1);
    return 0;
}
//FUNKCJE:
char wyborZnaku(){
	char znakGracza;
	char znak;
	do{
		cout << "Wybierz znak gracza 1/2: \n 1: O \n 2: X \n";
		cin >> znak;
		if (znak == '1')
			znakGracza = 'O';
		else if (znak == '2')
			znakGracza = 'X';
		else{
			system("cls");
			cout << "B³êdny znak gracza." <<endl << endl;
		}
	} while (znak != '1' && znak != '2');
	return znakGracza;
}
char ktoZaczyna(){
	char zaczyna;
	system("cls");
	do{
		cout << "Wybierz kto zaczyna 1/2:  \n 1: Gracz \n 2: Komputer \n";
		cin >> zaczyna;
		if (zaczyna != '1' || zaczyna != '2'){
			system("cls");
			cout << "B³êdny wybór. \n";
		}
	} while (zaczyna != '1' && zaczyna != '2');
	return zaczyna;
}
char czyWygrana(){
	if (tab[0] == tab[1] && tab[1] == tab[2])
		return tab[0];
	else if (tab[3] == tab[4] && tab[4] == tab[5])
		return tab[3];
	else if (tab[6] == tab[7] && tab[7] == tab[8])
		return tab[6];
	else if (tab[0] == tab[3] && tab[3] == tab[6])
		return tab[0];
	else if (tab[1] == tab[4] && tab[4] == tab[7])
		return tab[1];
	else if (tab[2] == tab[5] && tab[5] == tab[8])
		return tab[2];
	else if (tab[0] == tab[4] && tab[4] == tab[8])
		return tab[0];
	else if (tab[2] == tab[4] && tab[4] == tab[6])
		return tab[2];
	else
		return 0;
}

void ruchKomputera(char znak){
	char znakG;
	if (znak == 'X')
		znakG = 'O';
	else 
		znakG = 'X';

	if (((tab[0] == tab[1] && tab[1] == znak) || (tab[4] == tab[6] && tab[6] == znak) || (tab[5] == tab[8] && tab[8] == znak)) && (tab[2] != 'O' && tab[2] != 'X'))
		tab[2] = znak;
	else if (((tab[1] == tab[2] && tab[2] == znak) || (tab[4] == tab[8] && tab[8] == znak) || (tab[3] == tab[6] && tab[6] == znak)) && (tab[0] != 'O' && tab[0] != 'X'))
		tab[0] = znak;
	else if (((tab[0] == tab[3] && tab[3] == znak) || (tab[4] == tab[2] && tab[2] == znak) || (tab[7] == tab[8] && tab[8] == znak)) && (tab[6] != 'O' && tab[6] != 'X'))
		tab[6] = znak;
	else if (((tab[2] == tab[5] && tab[5] == znak) || (tab[4] == tab[0] && tab[0] == znak) || (tab[6] == tab[7] && tab[7] == znak)) && (tab[8] != 'O' && tab[8] != 'X'))
		tab[8] = znak;

	else if (((tab[4] == tab[7] && tab[7] == znak) || (tab[0] == tab[2] && tab[2] == znak)) && (tab[1] != 'O' && tab[1] != 'X'))
		tab[1] = znak;
	else if (((tab[4] == tab[5] && tab[5] == znak) || (tab[0] == tab[6] && tab[6] == znak)) && (tab[3] != 'O' && tab[3] != 'X'))
		tab[3] = znak;
	else if (((tab[4] == tab[3] && tab[3] == znak) || (tab[2] == tab[8] && tab[8] == znak)) && (tab[5] != 'O' && tab[5] != 'X'))
		tab[5] = znak;
	else if (((tab[4] == tab[1] && tab[1] == znak) || (tab[6] == tab[8] && tab[8] == znak)) && (tab[7] != 'O' && tab[7] != 'X'))
		tab[7] = znak;

	else if ((tab[0] == tab[1] || tab[4] == tab[6] || tab[5] == tab[8]) && (tab[2] != 'O' && tab[2] != 'X'))
		tab[2] = znak;
	else if ((tab[1] == tab[2] || tab[4] == tab[8] || tab[3] == tab[6]) && (tab[0] != 'O' && tab[0] != 'X'))
		tab[0] = znak;
	else if ((tab[0] == tab[3] || tab[4] == tab[2] || tab[7] == tab[8]) && (tab[6] != 'O' && tab[6] != 'X'))
		tab[6] = znak;
	else if ((tab[2] == tab[5] || tab[4] == tab[0] || tab[6] == tab[7]) && (tab[8] != 'O' && tab[8] != 'X'))
		tab[8] = znak;

	else if ((tab[4] == tab[7] || tab[0] == tab[2]) && (tab[1] != 'O' && tab[1] != 'X'))
		tab[1] = znak;
	else if ((tab[4] == tab[5] || tab[0] == tab[6]) && (tab[3] != 'O' && tab[3] != 'X'))
		tab[3] = znak;
	else if ((tab[4] == tab[3] || tab[2] == tab[8]) && (tab[5] != 'O' && tab[5] != 'X'))
		tab[5] = znak;
	else if ((tab[4] == tab[1] || tab[6] == tab[8]) && (tab[7] != 'O' && tab[7] != 'X'))
		tab[7] = znak;

	else if ((tab[4] == znak && tab[5] == znakG) && (tab[2] != 'O' && tab[2] != 'X') && tab[6] == '7')
		tab[2] = znak;
	else if ((tab[4] == znak && tab[7] == znakG) && (tab[8] != 'O' && tab[8] != 'X') && tab[0] == '1')
		tab[8] = znak;
	else if ((tab[4] == znak && tab[3] == znakG) && (tab[6] != 'O' && tab[6] != 'X') && tab[2] == '3')
		tab[6] = znak;
	else if ((tab[4] == znak && tab[1] == znakG) && (tab[0] != 'O' && tab[0] != 'X') && tab [8] == '9')
		tab[0] = znak;

	else if ((tab[4] == znak && tab[2] == znak && tab[1] == '2') && (tab[0] != 'O' && tab[0] != 'X'))
		tab[0] = znak;
	else if ((tab[4] == znak && tab[8] == znak && tab[5] == '6') && (tab[2] != 'O' && tab[2] != 'X'))
		tab[2] = znak;
	else if ((tab[4] == znak && tab[6] == znak && tab[7] == '8') && (tab[8] != 'O' && tab[8] != 'X'))
		tab[8] = znak;
	else if ((tab[4] == znak && tab[0] == znak && tab[3] == '4') && (tab[6] != 'O' && tab[6] != 'X'))
		tab[6] = znak;
	else if (tab[4] != 'O' && tab[4] != 'X')
		tab[4] = znak;
	else if ((tab[1] == '2' && tab[7] == '8') && (tab[0] != '1'))
		tab[7] = znak;
	else if ((tab[3] == '4' && tab[5] == '6') && (tab[0] != '1' || tab[6] != '7'))
		tab[5] = znak;
	
	
	else if ((tab[0] != 'O' && tab[0] != 'X') && tab[8] == '9')
		tab[0] = znak;
	else if (tab[2] != 'O' && tab[2] != 'X')
		tab[2] = znak;
	else if (tab[6] != 'O' && tab[6] != 'X')
		tab[6] = znak;
	else if (tab[8] != 'O' && tab[8] != 'X')
		tab[8] = znak;
	else if (tab[1] != 'O' && tab[1] != 'X')
		tab[1] = znak;
	else if (tab[3] != 'O' && tab[3] != 'X')
		tab[3] = znak;
	else if (tab[5] != 'O' && tab[5] != 'X')
		tab[5] = znak;
	else if (tab[7] != 'O' && tab[7] != 'X')
		tab[7] = znak;
}
void ruchGracza(char znak){
	int wykonano = 0;
	do{
		cout << "Podaj numer pola, w którym chcesz wstawiæ " << znak << endl;
		char numerPola;
		cin >> numerPola;
		for (int i = 0; i < 9; i++){	
			if (tab[i]==numerPola){
				tab[i] = znak;
				wykonano++;
			}
		}
		if (wykonano == 0)
			cout << "Z³y ruch. \n";
	} while (wykonano == 0);
}
char rysujPlansze() {
	system("cls");
	int k = 0;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			cout << " | " << tab[k];
			k++;
		}
		cout << " |" << endl;
	}
	return 0;
}