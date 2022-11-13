#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>

using namespace std;

class Adres {
	string mahalle, sokak, ilcee, tel_no;
	int apt_no;

	Adres(string mh, string sk, string ilce, int apt, string tel) {
		mahalle = mh;
		sokak = sk;
		ilcee = ilce;
		apt_no = apt;
		tel_no = tel;
	}
	void ekranaBasAdres()
	{
		cout << " " << mahalle << " " << sokak << " " << ilcee << " " << apt_no << " " << tel_no << endl;
	}
};
int main() {
	setlocale(LC_ALL, "Turkish");
	system("title Ýskenderun Devlet Hastanesi                                                                                                          ");



	system("pause");

}