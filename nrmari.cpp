#include <iostream>
#include <cstring>
#define NRMAX_CIFRE 1000
using namespace std;
typedef char NrMare[NRMAX_CIFRE];
void citesteNumarMare(NrMare, int &);
void afiseazaNumarMare(NrMare, int);
void adunaNumereMari(NrMare, int, NrMare, int, NrMare, int &);
void scadeNumereMari(NrMare, int, NrMare, int, NrMare, int &);
void inmultesteNumarMareCuNumarMic(NrMare, int, int, NrMare, int &);
void inmultesteNumereMari(NrMare, int, NrMare, int, NrMare, int &);
int main()
{
	NrMare a, b, s, d, c;
	int na, nb, ns, nd, nrmic, nc;
	cout << "a = ";
	citesteNumarMare(a, na);
	cout << "b = ";
	citesteNumarMare(b, nb);
	adunaNumereMari(a, na, b, nb, s, ns);
	cout << "a+b = ";
	afiseazaNumarMare(s, ns);
	scadeNumereMari(a, na, b, nb, d, nd);
	cout << "a-b = ";
	afiseazaNumarMare(d, nd);
	cout << "nr. mic: "; cin >> nrmic;
	inmultesteNumarMareCuNumarMic(a, na, nrmic, c, nc);
	cout << "a*nrmic = ";
	afiseazaNumarMare(c, nc);
	inmultesteNumarMareCuNumarMic(b, nb, nrmic, c, nc);
	cout << "b*nrmic = ";
	afiseazaNumarMare(c, nc);
	inmultesteNumereMari(a, na, b, nb, c, nc);
	cout << "a*b = ";
	afiseazaNumarMare(c, nc);
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
	int i, t, val;
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
		val = a[i]+b[i]+t;
		s[i] = val%10;
		t = val/10;
	}
	if (t)
	{
		s[ns++] = t;
	}
}
// d = a-b
void scadeNumereMari(NrMare a, int na, NrMare b, int nb, NrMare d, int & nd)
{
	int i, t, val;
	for (i = nb; i < na; i++)
	{
		b[i] = 0;
	}
	for (t = i = 0; i < na; i++)
	{
		val = a[i]-b[i]+t;
		if (val < 0)
		{
			d[i] = val+10;
			t = -1;
		}
		else
		{
			d[i] = val;
			t = 0;
		}
	}
	// ignor zerourile nesemnificative si actualizez nr. de cifre al lui d
	for (nd = na; nd > 1 && d[nd-1] == 0; nd--);
}
void inmultesteNumarMareCuNumarMic(NrMare a, int na, int b, NrMare c, int & nc)
{
	int i, val, t;
	if (b == 0 || (a[0] == 0 && na == 1))
	{
		c[0] = 0;
		nc = 1;
		return;
	}
	for (t = i = 0; i < na; i++)
	{
		val = a[i]*b+t;
		c[i] = val%10;
		t = val/10;
	}
	for (nc = na; t; nc++)
	{
		c[nc] = t%10;
		t /= 10;
	}
}
void inmultesteNumereMari(NrMare a, int na, NrMare b, int nb, NrMare p, int & np)
{
	int i, t, j, val;
	if (b[0] == 0 && nb == 1
		|| a[0] == 0 && na == 1)
	{
		p[0] = 0;
		np = 1;
		return;
	}
	for (i = 0; i < NRMAX_CIFRE; i++)
	{
		p[i] = 0;
	}
	for (i = 0; i < nb; i++)
	{
		for (t = j = 0; j < na; j++)
		{
			val = p[i+j] + b[i]*a[j] + t;
			p[i+j] = val%10;
			t = val/10;
		}
		if (t)
		{
			p[i+j] = t;
		}
	}
	np = na+nb-1;
	if (p[np])
	{
		np++;
	}
}
