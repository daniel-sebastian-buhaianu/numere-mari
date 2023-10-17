#include <iostream>
#include <cstring>
#define NRMAX_CIFRE 1000
using namespace std;
typedef char NrMare[NRMAX_CIFRE];
void citesteNumarMare(NrMare, int &);
void afiseazaNumarMare(NrMare, int);
void adunaNumereMari(NrMare, int, NrMare, int, NrMare, int &);
int main()
{
	NrMare a, b, s;
	int na, nb, ns;
	citesteNumarMare(a, na);
	citesteNumarMare(b, nb);
	adunaNumereMari(a, na, b, nb, s, ns);
	afiseazaNumarMare(s, ns);
	return 0;
}
void citesteNumarMare(NrMare nr, int & nrcif)
{
	int i;
	char s[NRMAX_CIFRE+1];
	cout << "Numar mare: "; cin >> s;
	nrcif = strlen(s);
	for (i = nrcif-1; i >= 0; i--)
	{
		nr[nrcif-i-1] = s[i]-'0';
	}
	for (i = nrcif; i < NRMAX_CIFRE; i++)
	{
		nr[i] = 0;
	}
}
void afiseazaNumarMare(NrMare nr, int nrcif)
{
	for (int i = nrcif-1; i >= 0; i--)
	{
		cout << (int)nr[i];
	}
	cout << '\n';
}
void adunaNumereMari(NrMare a, int na, NrMare b, int nb, NrMare s, int & ns)
{
	int i, t, cif;
	// completeaza numarul cel mai mic cu zerouri nesemnificative
	if (na < nb)
	{
		for (i = na; i < nb; i++)
		{
			a[i] = 0;
		}
		ns = nb;
	}
	else
	{
		for (i = nb; i < na; i++)
		{
			b[i] = 0;
		}
		ns = na;
	}
	// aduna cele doua numere si retine rezultatul in s si ns
	for (t = i = 0; i < ns; i++)
	{
		cif = a[i]+b[i]+t;
		s[i] = cif%10;
		t = cif/10;
	}
	if (t)
	{
		s[ns++] = t;
	}
}
