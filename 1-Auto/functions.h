#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int m = 50, n = 50, x, i, l, k;
char ch;

fstream vehicle("Auto.txt");
ofstream vehicle_out("Auto.txt", ios::app);
ifstream vehicle_in("Auto.txt");

fstream comp("Company.txt");
ofstream comp_out("Company.txt", ios::app);
ifstream comp_in("Company.txt");

ofstream models("Models.txt");

fstream fp;

struct Auto
{
	string id_prod_a, model, culoare, tip_combust, tip_cutie_trans;
	int id_auto{}, pret{};
}a[100];

struct Company
{
	string id_prod_c, comp_name, tara;
}c[100];

void principala(int& n);
void afisare(int& l);
void excludere(int l);
void inregistrare(int l);
void actualizare(int& m);

void citire_auto(int& m)
{
	vehicle >> m;

	for (x = 0; x < m; x++)
	{
		vehicle >> a[x].id_auto >> a[x].id_prod_a >> a[x].model >> a[x].culoare >> a[x].pret >> a[x].tip_combust >> a[x].tip_cutie_trans;
	}
}

void citire_comp(int& n)
{
	comp >> n;

	for (x = 0; x < n; x++)
	{
		comp >> c[x].id_prod_c >> c[x].comp_name >> c[x].tara;
	}
}

int m_value(int& m)
{
	vehicle_in >> m;
	return m;
}

int n_value(int& n)
{
	vehicle_in >> n;
	return n;
}

void afisare_auto(int& m)
{
	while (vehicle_in >> noskipws >> ch)
		cout << ch;
	vehicle_in.close();
	cout << endl;
	cout << endl;

	cout << "----------" << endl;
	cout << "|1.Inapoi|" << endl;
	cout << "----------" << endl;
	cout << "|2.Iesire|" << endl;
	cout << "----------" << endl;
	cout << endl;
	cout << "Selecteaza actiunea: "; cin >> i;
	cout << endl;
	switch (i)
	{
	case 1: afisare(m);
		break;
	case 2:cout << " ";
		break;
	}
}

void afisare_comp(int& n)
{
	while (comp_in >> noskipws >> ch)
		cout << ch;
	comp_in.close();
	cout << endl;
	cout << endl;

	cout << "----------" << endl;
	cout << "|1.Inapoi|" << endl;
	cout << "----------" << endl;
	cout << "|2.Iesire|" << endl;
	cout << "----------" << endl;
	cout << endl;
	cout << "Selecteaza actiunea: "; cin >> i;
	cout << endl;
	switch (i)
	{
	case 1: afisare(m);
		break;
	case 2:cout << " ";
		break;
	}
}

void afisare_ordonare(int& m)
{
	int y = 0, auxai, auxp;
	string auxpi, auxm, auxc, auxtc, auxtct;

	citire_auto(m);

	do
	{
		y = 0;
		for (x = 0; x < m; x++)
		{
			if (a[x].pret > a[x + 1].pret)
			{
				auxai = a[x].id_auto;
				a[x].id_auto = a[x + 1].id_auto;
				a[x + 1].id_auto = auxai;

				auxpi = a[x].id_prod_a;
				a[x].id_prod_a = a[x + 1].id_prod_a;
				a[x + 1].id_prod_a = auxpi;

				auxm = a[x].model;
				a[x].model = a[x + 1].model;
				a[x + 1].model = auxm;

				auxc = a[x].culoare;
				a[x].culoare = a[x + 1].culoare;
				a[x + 1].culoare = auxc;

				auxp = a[x].pret;
				a[x].pret = a[x + 1].pret;
				a[x + 1].pret = auxp;

				auxtc = a[x].tip_combust;
				a[x].tip_combust = a[x + 1].tip_combust;
				a[x + 1].tip_combust = auxtc;

				auxtct = a[x].tip_cutie_trans;
				a[x].tip_cutie_trans = a[x + 1].tip_cutie_trans;
				a[x + 1].tip_cutie_trans = auxtct;

				y = 1;
			}
		}
	} while (y == 1);

	for (x = 1; x < m + 1; x++)
	{
		cout << a[x].id_auto << " " << a[x].id_prod_a << " " << a[x].model << " " << a[x].culoare << " " << a[x].pret << " " << a[x].tip_combust << " " << a[x].tip_cutie_trans << endl;
	}
	cout << endl;
	cout << "----------" << endl;
	cout << "|1.Inapoi|" << endl;
	cout << "----------" << endl;
	cout << "|2.Iesire|" << endl;
	cout << "----------" << endl;
	cout << endl;
	cout << "Selecteaza actiunea: "; cin >> i;
	cout << endl;
	switch (i)
	{
	case 1: afisare(m);
		break;
	case 2:cout << " ";
		break;
	}
}

void afisare_max_min(int& m)
{
	int max = -9999, min = 999999999;
	int l = 0, k = 0;
	citire_auto(m);

	for (x = 0; x < m; x++)
	{
		if (min > a[x].pret)
		{
			min = a[x].pret;
			l = x;
		}
		if (max < a[x].pret)
		{
			max = a[x].pret;
			k = x;
		}
	}
	cout << "Cel mai ieftin automobil: " << a[l].id_auto << " " << a[l].id_prod_a << " " << a[l].model << " " << a[l].culoare << " " << a[l].pret << " " << a[l].tip_combust << " " << a[l].tip_cutie_trans << endl;
	cout << endl;
	cout << "Cel mai scump automobil: " << a[k].id_auto << " " << a[k].id_prod_a << " " << a[k].model << " " << a[k].culoare << " " << a[k].pret << " " << a[k].tip_combust << " " << a[k].tip_cutie_trans << endl;
	cout << endl;

	cout << "----------" << endl;
	cout << "|1.Inapoi|" << endl;
	cout << "----------" << endl;
	cout << "|2.Iesire|" << endl;
	cout << "----------" << endl;
	cout << endl;
	cout << "Selecteaza actiunea: "; cin >> i;
	cout << endl;
	switch (i)
	{
	case 1: afisare(m);
		break;
	case 2:cout << " ";
		break;
	}
}

void afisare_mediu(int& m)
{
	float mean = 0;
	int k = 0;
	string search_model;

	citire_auto(m);

	cout << "Introduceti modelul: ";
	cin >> search_model;

	for (x = 0; x < m; x++)
	{
		if (search_model == a[x].model)
		{
			mean += a[x].pret;
			k++;
		}
	}
	mean /= k;

	cout << "Pretul mediu al modelului " << search_model << " este " << mean << endl;
	cout << endl;

	cout << "----------" << endl;
	cout << "|1.Inapoi|" << endl;
	cout << "----------" << endl;
	cout << "|2.Iesire|" << endl;
	cout << "----------" << endl;
	cout << endl;
	cout << "Selecteaza actiunea: "; cin >> i;
	cout << endl;
	switch (i)
	{
	case 1: afisare(m);
		break;
	case 2:cout << " ";
		break;
	}
}

void inregistrare_auto(int& m)
{
	m = m_value(m);
	citire_auto(m);
	m += 1;

	fp.open("Auto.txt", ios::out | ios::trunc);
	fp << m;
	fp << endl;
	for (x = 0; x < m - 1; x++)
	{
		fp << a[x].id_auto << " " << a[x].id_prod_a << " " << a[x].model << " " << a[x].culoare << " " << a[x].pret << " " << a[x].tip_combust << " " << a[x].tip_cutie_trans << endl;
	}
	cout << endl;

	cout << "Introduceti id-ul automobilului: "; cin >> a[m].id_auto;
	vehicle_out << a[m].id_auto << " ";
	cout << "Introduceti id-ul producatorului: "; cin >> a[m].id_prod_a;
	vehicle_out << a[m].id_prod_a << " ";
	cout << "Introduceti modelul: "; cin >> a[m].model;
	vehicle_out << a[m].model << " ";
	cout << "Introduceti culoarea: "; cin >> a[m].culoare;
	vehicle_out << a[m].culoare << " ";
	cout << "Introduceti pretul: "; cin >> a[m].pret;
	vehicle_out << a[m].pret << " ";
	cout << "Introduceti tipul de combustibil: "; cin >> a[m].tip_combust;
	vehicle_out << a[m].tip_combust << " ";
	cout << "Introduceti tipul cutiei de transmisie: "; cin >> a[m].tip_cutie_trans;
	vehicle_out << a[m].tip_cutie_trans << " ";
	cout << endl;

	cout << "----------" << endl;
	cout << "|1.Inapoi|" << endl;
	cout << "----------" << endl;
	cout << "|2.Iesire|" << endl;
	cout << "----------" << endl;
	cout << endl;
	cout << "Selecteaza actiunea: "; cin >> i;
	cout << endl;
	switch (i)
	{
	case 1: inregistrare(m);
		break;
	case 2:cout << " ";
		break;
	}
}

void inregistrare_comp(int& n)
{
	n = n_value(n);
	citire_comp(n);
	n += 1;

	fp.open("Company.txt", ios::out | ios::trunc);
	fp << n;
	fp << endl;
	for (x = 0; x < n - 1; x++)
	{
		fp << c[x].id_prod_c << " " << c[x].comp_name << " " << c[x].tara << endl;
	}
	cout << endl;

	comp_out << endl;
	cout << "Introduceti ID-ul producatorului: "; cin >> c[n].id_prod_c;
	comp_out << c[n].id_prod_c << " ";
	cout << "Introduceti numele companiei: "; cin >> c[n].comp_name;
	comp_out << c[n].comp_name << " ";
	cout << "Introduceti tara companiei: "; cin >> c[n].tara;
	comp_out << c[n].tara;
	cout << endl;

	cout << "----------" << endl;
	cout << "|1.Inapoi|" << endl;
	cout << "----------" << endl;
	cout << "|2.Iesire|" << endl;
	cout << "----------" << endl;
	cout << endl;
	cout << "Selecteaza actiunea: "; cin >> i;
	cout << endl;
	switch (i)
	{
	case 1: inregistrare(n);
		break;
	case 2:cout << " ";
		break;
	}
}

void stergere_auto(int& m)
{
	m = m_value(m);
	int id;
	int i;
	citire_auto(m);
	cout << "Introduceti identificatorul automobilului pe care ii doriti sa-i stergeti informatia: "; cin >> id;
	for (x = 0; x < m; x++)
	{
		if (id == a[x].id_auto)
		{
			for (i = x; i < m; i++)
			{
				a[i].id_auto = a[i + 1].id_auto;
				a[i].id_prod_a = a[i + 1].id_prod_a;
				a[i].model = a[i + 1].model;
				a[i].culoare = a[i + 1].culoare;
				a[i].pret = a[i + 1].pret;
				a[i].tip_combust = a[i + 1].tip_combust;
				a[i].tip_cutie_trans = a[i + 1].tip_cutie_trans;
			}
			m--;
		}
	}


	fp.open("Auto.txt", ios::out | ios::trunc);
	fp << m;
	fp << endl;
	for (x = 0; x < m; x++)
	{
		fp << a[x].id_auto << " " << a[x].id_prod_a << " " << a[x].model << " " << a[x].culoare << " " << a[x].pret << " " << a[x].tip_combust << " " << a[x].tip_cutie_trans << endl;
	}
	cout << endl;

	cout << "----------" << endl;
	cout << "|1.Inapoi|" << endl;
	cout << "----------" << endl;
	cout << "|2.Iesire|" << endl;
	cout << "----------" << endl;
	cout << endl;
	cout << "Selecteaza actiunea: "; cin >> i;
	cout << endl;
	switch (i)
	{
	case 1: excludere(m);
		break;
	case 2:cout << " ";
		break;
	}
}

void stergere_comp(int& n)
{
	n = n_value(n);
	string name;
	citire_comp(n);
	cout << "Introduceti numele companiei careia sa-i stergeti informatia: "; cin >> name;
	for (x = 0; x < n; x++)
	{
		if (name == c[x].comp_name)
		{
			for (i = x; i < n; i++)
			{
				c[i].id_prod_c = c[i + 1].id_prod_c;
				c[i].comp_name = c[i + 1].comp_name;
				c[i].tara = c[i + 1].tara;
			}
			n--;
		}
	}

	fp.open("Company.txt", ios::out | ios::trunc);
	fp << n;
	fp << endl;
	for (x = 0; x < n; x++)
	{
		fp << c[x].id_prod_c << " " << c[x].comp_name << " " << c[x].tara << endl;
	}
	cout << endl;

	cout << "----------" << endl;
	cout << "|1.Inapoi|" << endl;
	cout << "----------" << endl;
	cout << "|2.Iesire|" << endl;
	cout << "----------" << endl;
	cout << endl;
	cout << "Selecteaza actiunea: "; cin >> i;
	cout << endl;
	switch (i)
	{
	case 1: excludere(n);
		break;
	case 2:cout << " ";
		break;
	}
}

void actualizare_auto(int& m)
{

	int id, l = 0, r_pr;
	string r_id_p, r_m, r_c, r_t_c, r_t_c_t;

	citire_auto(m);

	cout << "Introduceti ID-ul automobilului: "; cin >> id;

	for (x = 0; x < m; x++)
	{
		if (id == a[x].id_auto)
			l = x;
	}

	cout << "Introduceti ID-ul producatorului de actualizat: "; cin >> r_id_p;
	cout << "Introduceti modelul automobilului de actualizat: "; cin >> r_m;
	cout << "Introduceti culoarea automobilului de actualizat: "; cin >> r_c;
	cout << "Introduceti pretul automobilului de actualizat: "; cin >> r_pr;
	cout << "Introduceti tipul de combustibil de actualizat: "; cin >> r_t_c;
	cout << "Introduceti tipul cutiei de transmisie de actualizat: "; cin >> r_t_c_t;

	a[l].id_prod_a = r_id_p;
	a[l].model = r_m;
	a[l].culoare = r_c;
	a[l].pret = r_pr;
	a[l].tip_combust = r_t_c;
	a[l].tip_cutie_trans = r_t_c_t;

	fp.open("Auto.txt", ios::out | ios::trunc);
	fp << m;
	fp << endl;
	for (x = 0; x < m; x++)
	{
		if (x == l)
		{
			fp << a[l].id_auto << " " << a[l].id_prod_a << " " << a[l].model << " " << a[l].culoare << " " << a[l].pret << " " << a[l].tip_combust << " " << a[l].tip_cutie_trans << endl;
		}
		else
		{
			fp << a[x].id_auto << " " << a[x].id_prod_a << " " << a[x].model << " " << a[x].culoare << " " << a[x].pret << " " << a[x].tip_combust << " " << a[x].tip_cutie_trans << endl;
		}
	}
	cout << endl;

	cout << "----------" << endl;
	cout << "|1.Inapoi|" << endl;
	cout << "----------" << endl;
	cout << "|2.Iesire|" << endl;
	cout << "----------" << endl;
	cout << endl;
	cout << "Selecteaza actiunea: "; cin >> i;
	cout << endl;
	switch (i)
	{
	case 1: actualizare(m);
		break;
	case 2:cout << " ";
		break;
	}
}

void actualizare_comp(int& n)
{
	int l = 0;
	string r_id, name, r_t;

	citire_comp(n);

	cout << "Introduceti numele producatorului: "; cin >> name;

	for (x = 0; x < n; x++)
	{
		if (name == c[x].comp_name)
		{
			l = x;
		}
	}

	cout << "Introduceti ID-ul producatorului de actualizat: "; cin >> r_id;
	cout << "Introduceti tara producatorului de actualizat: "; cin >> r_t;

	c[l].id_prod_c = r_id;
	c[l].tara = r_t;

	fp.open("Company.txt", ios::out | ios::trunc);
	fp << n;
	fp << endl;
	for (x = 0; x < n; x++)
	{
		if (x == l)
		{
			fp << c[l].id_prod_c << " " << c[l].comp_name << " " << c[l].tara << endl;
		}
		else
		{
			fp << c[x].id_prod_c << " " << c[x].comp_name << " " << c[x].tara << endl;
		}
	}
	cout << endl;

	cout << "----------" << endl;
	cout << "|1.Inapoi|" << endl;
	cout << "----------" << endl;
	cout << "|2.Iesire|" << endl;
	cout << "----------" << endl;
	cout << endl;
	cout << "Selecteaza actiunea: "; cin >> i;
	cout << endl;
	switch (i)
	{
	case 1: actualizare(n);
		break;
	case 2:cout << " ";
		break;
	}
}

void creare_file(int& m)
{
	int k, i;

	citire_auto(m);

	for (x = 0; x < m; x++)
	{
		k = 0;
		for (i = 0; i < m; i++)
		{
			if (c[x].id_prod_c == a[i].id_prod_a)
				k++;
		}
		models << c[x].id_prod_c << " " << c[x].comp_name << " " << k << endl;
	}
}

void afisare(int& m)
{
	cout << "-----------------------------------------------------------" << endl;
	cout << "|1.Afisarea Automobilelor                                 |" << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "|2.Afisarea Companiilor                                   |" << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "|3.Afisarea automobilelor in ordine creascatoare dupa pret|" << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "|4.Afisarea celui mai scump si celui mai ieftin automobil |" << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "|5.Pretul mediu a unui model                              |" << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "|6.Inapoi                                                 |" << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << endl;
	cout << "Selecteaza actiunea: "; cin >> l;
	cout << endl;
	switch (l)
	{
	case 1:afisare_auto(m);
		break;
	case 2:afisare_comp(m);
		break;
	case 3:afisare_ordonare(m);
		break;
	case 4:afisare_max_min(m);
		break;
	case 5:afisare_mediu(m);
		break;
	case 6:principala(m);
		break;
	}
}

void excludere(int m)
{
	cout << "------------------------------------------" << endl;
	cout << "|1.Excluderea informatiei unui automobil |" << endl;
	cout << "------------------------------------------" << endl;
	cout << "|2.Excluderea informatiei unui producator|" << endl;
	cout << "------------------------------------------" << endl;
	cout << "|3.Inapoi                                |" << endl;
	cout << "------------------------------------------" << endl;
	cout << endl;
	cout << "Selecteaza actiunea: "; cin >> l;
	cout << endl;
	switch (l)
	{
	case 1:stergere_auto(i);
		break;
	case 2:stergere_comp(i);
		break;
	case 3: principala(i);
		break;
	}
}

void inregistrare(int m)
{
	cout << "--------------------------------------------" << endl;
	cout << "|1.Inregistreaza informatia unui automobil |" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "|2.Inregistreaza informatia unui producator|" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "|3.Inapoi                                  |" << endl;
	cout << "--------------------------------------------" << endl;
	cout << endl;
	cout << "Selecteaza actiunea: "; cin >> l;
	cout << endl;
	switch (l)
	{
	case 1:inregistrare_auto(m);
		break;
	case 2:inregistrare_comp(m);
		break;
	case 3: principala(m);
		break;
	}
}

void actualizare(int& m)
{
	cout << "-------------------------------------------" << endl;
	cout << "|1.Actualizeaza informatia unui automobil |" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "|2.Actualizeaza informatia unui producator|" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "|3.Inapoi                                  |" << endl;
	cout << "--------------------------------------------" << endl;
	cout << endl;
	cout << "Selecteaza actiunea: "; cin >> l;
	cout << endl;
	switch (l)
	{
	case 1:actualizare_auto(m);
		break;
	case 2:actualizare_comp(m);
		break;
	case 3: principala(m);
		break;
	}
}

void principala(int& m)
{
	citire_auto(m);
	citire_comp(m);
	cout << "---------------------------------" << endl;
	cout << "|1.Afisarea la ecran a datelor  |" << endl;
	cout << "---------------------------------" << endl;
	cout << "|2.Inregistrarea unui fisier nou|" << endl;
	cout << "---------------------------------" << endl;
	cout << "|3.Exluderea unei informatii    |" << endl;
	cout << "---------------------------------" << endl;
	cout << "|4.Actualizarea unor date       |" << endl;
	cout << "---------------------------------" << endl;
	cout << "|5.Iesire                       |" << endl;
	cout << "---------------------------------" << endl;
	cout << endl;
	cout << "Selecteaza actiunea: "; cin >> l;
	cout << endl;
	switch (l)
	{
	case 1: afisare(m);
		break;
	case 2:inregistrare(m);
		break;
	case 3:excludere(m);
		break;
	case 4:actualizare(m);
		break;
	case 5:cout << " ";
		break;
	}
}