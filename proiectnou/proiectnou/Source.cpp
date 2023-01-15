#include "Bilet.h"
#include "Eveniment.h"
#include "Locatie.h"
#include "Meniu.h"
#include "Invitat.h"
#include <cstdlib>
using namespace std;
/*
* daca op=1 vom verifica daca biletul apare ca si cumparat
* daca nu apare vom anunta acest lucru si ii vom da sansa de a cumpara un bilet
* daca apare, vom anunta acest lucru si ii vom da sansa de a cumpara un bilet
* ne intoarcem la meniu
* 
* daca op=2 
* ii vom prezenta locurile disponibile => ii oferim posibilitatea de a cumpara sau nu un bilet => ne intoarcem la meniu
* 
* daca op=3 afisam eveniment
* daca op=4 afisam hai la spectacol si ok devine 1
*/
int op,n;
bool ok;
Eveniment e;
Locatie l;
Invitat a;
Bilet* b;
double Calcul_Pret(int zona, int rand, int loc)
{
	double ct = 1;
	if (zona == 1) ct *= 50;
	else if (zona > 1 && zona <= 3) ct *= 25;

	if (rand >= 1 && rand <= 3) ct *= 2;
	else if (rand > 3) ct *= 1.5;

	if (loc >= 1 && loc <= 5) ct *= 1.2;
	else if (loc >= 6 && loc <= 9) ct *= 1.5;
	else if (loc >= 10) ct *= 1.2;

	return ct;
}
void Optiune1()
{
	int zona=0, rand=0, loc=0,id=0;
	cout << "In continuare vom verifica daca biletul dumneavoastra este valid." << "\n";
	cout << "Va rugam sa introduceti zona: ";
	cin >> zona;
	cout << "\n";
	cout << "\n";
	cout << "Va rugam sa introduceti randul: ";
	cin >> rand;
	cout << "\n";
	cout << "\n";
	cout << "Va rugam sa introduceti locul: ";
	cin >> loc;
	cout << "\n";
	cout << "\n";
	cout << "Va rugam sa introduceti id-ul biletului dumneavoastra: ";
	cin >> id;
	cout << "\n";
	cout << "\n";
	cout << "Imediat vom verifica daca biletul dumneavoastra face parte din baza noastra de date.";
	if (l.VerificaLoc(zona, rand, loc, id))
	{
		cout << "Biletul dumneavoastra este valid!";
		cout << "\n";
		cout << "\n";
	}
	else
	{
		cout << "Biletul dumneavoastra nu este valid!";
		cout << "\n";
		cout << "\n";
	}
}



void CumparaBilet()
{
	if (l.Numar_Locuri_Disponibile() == 0)
	{
		cout << "Nu mai sunt locuri disponibile!" << "\n";
		cout << "\n";
		cout << "\n";
		return;
	}
	int zona, rand, loc, option,ok=1;
	cout << "In continuare veti cumpara un bilet" << "\n";
	cout << "Va vom prezenta toate locuri disponibile: "<<"\n";
	l.Afisare_Locuri_Disponibile();
	cout << "\n";
	cout << "\n";
	while (ok == 1)
	{
		if (l.Numar_Locuri_Disponibile() == 0)
		{
			cout << "Nu mai sunt locuri disponibile!" << "\n";
			return;
		}
		cout << "Introduceti zona pe care o doriti: ";
		cin >> zona;
		cout << "\n";
		cout << "\n";

		cout << "Introduceti randul pe care il doriti: ";
		cin >> rand;
		cout << "\n";
		cout << "\n";

		cout << "Introduceti locul pe care il doriti: ";
		cin >> loc;
		cout << "\n";
		cout << "\n";

		if (l.VerificaLoc(zona, rand, loc) == 1)
		{
			cout << "Pretul biletului dumneavoastra este: ";
			cout << Calcul_Pret(zona, rand,loc);
			cout << "\n";
			cout << "\n";
			cout << "Doriti sa il cumparati?" << "\n";
			cout << "1. DA" << "\n";
			cout << "2. NU" << "\n";
			cin >> option;
			if (option == 1)
			{
				b[n].setNrLoc(loc);
				b[n].setNrRand(rand);
				b[n].setNrZona(zona);
				b[n].setPret(Calcul_Pret(zona,rand,loc));
				l.setLoc(b[n].getIdBilet(), zona, rand, loc);
				if (zona == 1) b[n].setCategorie("VIP");
				else if (zona > 1 && zona < 3) b[n].setCategorie("Loja");
				n++;
				ok = 0;
			}
			if (option == 2) ok = 0;
		}
		else
		{
			cout << "Biletul pe care l-ati ales nu poate fi achizitionat!" << "\n";
			cout << "Doriti sa incercati din nou?" << "\n";
			cout << "1. DA" << "\n";
			cout << "2. NU" << "\n";
			cin >> option;
			if (option == 2) ok = 0;
		}
	}
	cout << "\n";
	cout << "\n";
}
void Citire()
{
	cin >> e;
	cout << "\n";
	cout << "\n";
	cin >> l;
	cout << "\n";
	cout << "\n";
	cin >> a;
	cout << "\n";
	cout << "\n";
}
int main()

{
	Citire();
	l.Initializare_Zone();
	l.Generare_Bilete_Aleatoriu();
	b = new Bilet[l.Numar_Locuri_Disponibile() + 2];
	
	while(ok==0)
	{
		// op=0 = am bilet -> verifica bilet
		// op=1 vreau bilet
		//op=2 Date despre eveniment
		//op=3 hai la spectacol => ok=1
		cout << "In continuare, puteti alege urmatoarele optiuni :" << "\n";
		cout << "Optiunea 1: Am un bilet " << "\n";
		cout << "Optiunea 2: Vreau sa cumpar un bilet: " << "\n";
		cout << "Optiunea 3: Vreau sa stiu date despre acest eveniment: " << "\n";
		cout << "Optiunea 4: Hai la spectacol!"<<"\n";
		cout << "\n";
		cout << "\n";
		cout << "Ce optiune alegeti? ";
		cin >> op;
		
		while (op > 4 || op<1)
		{
			cout << "Optiunea aleasa de dumneavoastra nu exista, va rugam alegeti din nou: ";
			cout << "\n";
			cin >> op;
			cout << "\n";
			cout << "\n";
		}
		if (op == 1)
		{
			Optiune1();
		}

		if (op == 2)
		{
			CumparaBilet();
		}
		if (op == 3)
		{
			cout << l<<"\n";
			cout << e << "\n";
			cout << a << "\n";
		}
		if (op == 4)
		{
			ok = 1;
			cout << "In regula! Sa inceapa evenimentul!";
		}
	}
	delete[] b;
	b = nullptr;
	return 0;
}