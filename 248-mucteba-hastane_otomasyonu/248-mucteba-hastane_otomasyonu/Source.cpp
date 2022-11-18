#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>

using namespace std;

void color(int color) //@ErcanDuman
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y) //@ErcanDuman
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

class Adres   //@NurullahSahin
{
	string mahalle, sokak, ilcee, tel_no;
	int apt_no;
public:
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

class Insan {

	string isim, soyisim, tcNo;
	Adres adres;
public:
	Insan(string mh, string sk, string ilce, int apt, string tel, string tc, string i, string si) :adres(mh, sk, ilce, apt, tel) {
		tcNo = tc;
		isim = i;
		soyisim = si;

	}
	virtual void BilgiAl() = 0;
	friend void ekranaBas(Insan& ob1, Insan& ob2);

};

//@NurullahSahin
class Doktor :public Insan
{
	int poliklinik_no;

public:
	Doktor(string mh, string sk, string ilce, int apt, string tel, string tc, string i, string si, int p_no) : Insan(mh, sk, ilce, apt, tel, tc, i, si) {
		poliklinik_no = p_no;
	}
	void BilgiAl() {
		cout << endl << "Poliklinik numarasý : " << poliklinik_no << endl;
	}

};

class Randevu //@ErenAyguer
{
	string tarih, islemturu;
	int ucret, islem;
public:
	Randevu(int isl, string tar)
	{
		islem = isl;
		tarih = tar;
		if (isl == 1)
		{
			islemturu = "muayene";
			ucret = 200;
		}
		if (isl == 2)
		{
			islemturu = "operasyon";
			ucret = 2000;
		}
	}
	void ekranaBasRanvdevu() {
		cout << endl << "________________________" << endl << "Tarih : " << tarih << endl << "Ýþlem : " << islemturu << endl << "Alýnacak ücret : " << ucret;
	}

};

class Hasta : public Insan {
	Randevu randevu;
public:
	Hasta(string mh, string sk, string ilce, int apt, string tel, string tc, string i, string si, int isl, string tar) :randevu(isl, tar), Insan(mh, sk, ilce, apt, tel, tc, i, si) {}

	void BilgiAl() {

		randevu.ekranaBasRanvdevu();
	}
};
//@ErenAyguer
void RandevuOluþtur(Doktor& d)
{
	string i, tc, si, mh, sk, ilce, tar;
	int apt, isl;
	system("cls");
	cout << endl << "_______Randevu bilgileri_______" << endl;
	cout << endl << "-----Ýstediðiniz randevuyu seçin-----" << endl;



	cout << endl << "-----Hastanýn bilgileri-----" << endl;

	cout << endl << "Hasta Adý : ";
	getline(cin, i);
	cout << endl << "Hasta Soyadý : ";
	getline(cin, si);
	cout << endl << "Randevu almak istediðiniz tarihi girin (18/11/2022): ";
	getline(cin, tar);
	cout << endl << "Hasta TC'si : ";
	getline(cin, tc);
	cout << endl << "mahalleyi girin : ";
	getline(cin, mh);
	cout << endl << "sokaðý girin : ";
	getline(cin, sk);
	cout << endl << "ilçeyi girin : ";
	getline(cin, ilce);
	cout << endl << "daire no girin : ";
	cin >> apt;

	ekranaBas(h1, d);


}
//@ErenAyguer
void ekranaBas(Insan& hasta, Insan& doktor)
{
	system("color fd");
	system("cls");
	cout << "---------Randevu baþarýyla oluþturuldu---------" << endl;
	cout << "_______Hasta Bilgileri_______" << endl;
	cout << "Hastanýn Ýsmi :";
	cout << hasta.isim << endl;
	cout << "Hastanýn Soyismi :";
	cout << hasta.soyisim << endl;
	cout << "Hastanýn TC No'su :";
	cout << hasta.tcNo << endl;
	cout << "Hastanýn Adresi:";
	hasta.adres.ekranaBasAdres();
	hasta.BilgiAl();
	cout << endl << "______Doktor Bilgileri______" << endl;
	cout << "Doktorun Ýsmi :";
	cout << doktor.isim << endl;
	cout << "Doktorun Soyismi :";
	cout << doktor.soyisim << endl;
	doktor.BilgiAl();
}







int main() {
	setlocale(LC_ALL, "Turkish");
	system("title Ýskenderun Devlet Hastanesi  Randevu Sistemi                                                                                                   "); //@NurullahSahin


	system("pause");

}