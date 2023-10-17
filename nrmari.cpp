#include <iostream>
#include <cstring>
#define NRMAX_CIFRE 1000
using namespace std;
typedef char NrMare[NRMAX_CIFRE];
void citesteNumarMare(NrMare, int &);
void afiseazaNumarMare(NrMare, int);
int main()
{
	NrMare x;
	int nx;
	citesteNumarMare(x, nx);
	afiseazaNumarMare(x, nx);
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

