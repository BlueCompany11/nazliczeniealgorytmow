#include<iostream>
#include"Timer.h"
#include"Algorytmy.h"
using namespace std;

int main() {
	while (1) {
		cout << "Podaj dane: ";
		int n, b;
		// 5 10 4 2 8 1 6 6 10 3 2 3
		cin >> n >> b;
		UI* c = new UI[n + 1];
		UI* a = new UI[n + 1];
		//for (int i = 1; i < n + 1; ++i) {
		//	cin >> c[i];
		//	cin >> a[i];
		//}
		for (int k = 0;k < 3;++k) {
			for (int i = 1;i <= n;++i) {
				c[i] = rand() % 11;
				a[i] = rand() % 11;
			}
			Time time;
			double workTime;
			UI zysk;
			/*time.SetStart();
			zysk = plecakGenerowaniePodzbiorow(n, b, c, a);
			time.SetEnd();
			time.GetDuration(&workTime);
			cout << "AP Wynik: " << zysk << endl<< "Czas: " << workTime << endl;*/
			//time.SetStart();
			//zysk = plecakAlgProgDynamicznego(n, b, c, a);
			//time.SetEnd();
			//time.GetDuration(&workTime);
			//cout << "APD Wynik: " << zysk << endl << "Czas: " << workTime << endl;
			time.SetStart();
			zysk = plecakAlgZachlanny(n, b, c, a);
			time.SetEnd();
			time.GetDuration(&workTime);
			cout << "AZ Wynik: " << zysk << endl << "Czas: " << workTime << endl;
		}
	}
	system("pause");
}