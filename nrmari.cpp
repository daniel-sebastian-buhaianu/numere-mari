#include <iostream>
#include <cstring>
#define NRMAX_CIFRE 1000
using namespace std;
typedef char NrMare[NRMAX_CIFRE];
void citesteNumarMare(NrMare, int &);
void afiseazaNumarMare(NrMare, int);
void adunaNumereMari(NrMare, int, NrMare, int, NrMare, int &);
void scadeNumereMari(NrMare, int, NrMare, int, NrMare, int &);
int main()
{
	NrMare a, b, s, d;
	int na, nb, ns, nd;
	citesteNumarMare(a, na);
	citesteNumarMare(b, nb);
	adunaNumereMari(a, na, b, nb, s, ns);
	afiseazaNumarMare(s, ns);
	scadeNumereMari(a, na, b, nb, d, nd);
	afiseazaNumarMare(d, nd);
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
// s = a+b
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
// d = a-b
void scadeNumereMari(NrMare a, int na, NrMare b, int nb, NrMare d, int & nd)
{
	int i, t, cif;
	for (i = nb; i < na; i++)
	{
		b[i] = 0;
	}
	for (t = i = 0; i < na; i++)
	{
		cif = a[i]-b[i]+t;
		if (cif < 0)
		{
			d[i] = cif+10;
			t = -1;
		}
		else
		{
			d[i] = cif;
			t = 0;
		}
	}
	// ignor zerourile nesemnificative si actualizez nr. de cifre al lui d
	for (nd = na; nd > 1 && d[nd-1] == 0; nd--);
}
