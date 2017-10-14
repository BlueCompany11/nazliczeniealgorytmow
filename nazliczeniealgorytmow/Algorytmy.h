#pragma once
#include<iostream>

using namespace std;

typedef unsigned int UI;
const UI BARDZO_DUZA = INT_MAX;
UI plecakAlgProgDynamicznego(UI n, UI b, UI* c, UI* a);
UI plecakGenerwoaniePodzbiorow(UI n, UI b, UI* c, UI* a);

struct Element {
	UI numer;
	double wartosc;
};

int porownaj(const void* x, const void* y);
UI plecakAlgZachlanny(UI n, UI b, UI* c, UI* a);

UI plecakGenerowaniePodzbiorow(UI n, UI b, UI* c, UI* a) {
	bool* podzbior = new bool[n + 1];
	for (UI i = 0; i <= n; i++)
	{
		podzbior[i] = 0;
	}
	UI suma_zysku = 0, suma_nakladow = 0;
	UI tmp_zysk = 0, tmp_naklady = 0;
	
	UI p, j, k=0;
	do {
		if (k) {
			if (podzbior[p]) {
				tmp_naklady += a[p];
				tmp_zysk += c[p];
			}
			else {
				tmp_naklady -=+ a[p];
				tmp_zysk -= c[p];
			}
			if (tmp_naklady <= b) {
				if (tmp_zysk > suma_zysku) {
					suma_zysku = tmp_zysk;
					suma_nakladow = tmp_naklady;
				}
			}
		}
		k++;p = 1;j = k;
		while (j % 2 == 0) {
			j = j / 2;
			p++;
		}
		if (p <= n) {
			podzbior[p] = 1 - podzbior[p];
		}
	} while (p<=n);
	delete[] podzbior;
	return suma_zysku;
}

UI plecakAlgProgDynamicznego(UI n, UI b, UI* c, UI* a) {
	UI**t = new UI*[2];
	for (UI j = 0;j <= 1;j++) {
		t[j] = new UI[b + 1];
	}
	for (UI i = 0;i <= b;i++) {
		t[0][i] = 0;
	}
	for (UI j = 1; j <=n; j++)
	{
		for (UI i = 0;i <= b;i++) {
			t[j % 2][i] = t[(j - 1) % 2][i];
		}
		for (UI i = 0; i <= b - a[j];i++) {
			if (t[(j - 1) % 2][i] + c[j] > t[j % 2][i + a[j]]) {
				t[j % 2][i + a[j]] = t[(j - 1) % 2][i] + c[j];
			}
		}
	}
	UI zysk = t[n % 2][b];
	for (UI j = 0; j <= 1; j++) {
		delete[]t[j];
	}
	delete[] t;
	return zysk;
}

int porownaj(const void* x, const void* y) {
	const Element* ex = (const Element*)x;
	const Element* ey = (const Element*)y;
	return ((*ex).wartosc < (*ey).wartosc);
}

UI plecakAlgZachlanny(UI n, UI b, UI* c, UI* a) {
	Element* lista = new Element[n + 1];
	for (UI i = 1;i <= n;i++) {
		lista[i].numer = i;
		lista[i].wartosc = double(c[i]) / a[i];
	}
	lista[0].numer=0;
	lista[0].wartosc = BARDZO_DUZA;
	qsort(lista, n + 1, sizeof(Element), porownaj);
	UI suma_zysku = 0;
	UI suma_nakladow = 0;
	for (int i = 0;i <= n;++i) {
		if (suma_nakladow + a[lista[i].numer] <= b) {
			suma_nakladow += a[lista[i].numer];
			suma_zysku += c[lista[i].numer];
		}
	}
	delete[] lista;
	return suma_zysku;
}