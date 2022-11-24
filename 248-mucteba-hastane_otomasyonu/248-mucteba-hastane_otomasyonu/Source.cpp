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
	string i, tc, si, tel, mh, sk, ilce, tar;
	int apt, isl;
	system("cls");
	cout << endl << "_______Randevu bilgileri_______" << endl;
	cout << endl << "-----Ýstediðiniz randevuyu seçin-----" << endl;


	//@ErcanDuman
	int Set[] = { 7,7,7 };
	int counter = 1;
	char key;

	for (int i = 0;;)
	{


		gotoxy(1, 4);
		color(Set[0]);
		cout << "Muayene randevusu (500 TL)";

		gotoxy(1, 5);
		color(Set[1]);
		cout << "Operason randevusu(2500 TL)";

		gotoxy(1, 6);
		color(Set[2]);
		cout << "Exit";

		key = _getch();
		//@ErcanDuman
		if (key == 72 && (counter >= 2 && counter <= 3))
		{
			counter--;
		}
		if (key == 80 && (counter >= 1 && counter <= 2))
		{
			counter++;
		}
		if (key == '\r')
		{
			if (counter == 1)
			{
				isl = 1;
				break;

			}
			if (counter == 2)
			{
				isl = 2;
				break;
			}
			if (counter == 3)
			{
				exit(0);
			}

		}

		//@ErcanDuman

		Set[0] = 7;
		Set[1] = 7;
		Set[2] = 7;

		if (counter == 1)
		{
			Set[0] = 75;
		}
		if (counter == 2)
		{
			Set[1] = 75;
		}
		if (counter == 3)
		{
			Set[2] = 75;
		}
		//@ErcanDuman
	}
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
	cout << endl << "Telefon numarasý:";
	cin >> tel;

	Hasta h1(mh, sk, ilce, apt, tel, tc, i, si, isl, tar);//@ErcanDuman
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

//@ErcanDuman
void DoktorSec(Doktor& dok1, Doktor& dok2)
{


	cout << endl << "-------Doktor seçim ekranýna hoþgeldiniz randevu almak istediðiniz doktoru seçiniz-------";
	int Set[] = { 7,7,7 };
	int counter = 1;
	char key;

	for (int i = 0;;)
	{


		gotoxy(1, 2);
		color(Set[0]);
		cout << "Dr.Mehmet Çiftçi";

		gotoxy(1, 3);
		color(Set[1]);
		cout << "Dr.Sevgi Gülsen";

		gotoxy(1, 4);
		color(Set[2]);
		cout << "Exit";

		key = _getch();
		//@ErcanDuman
		if (key == 72 && (counter >= 2 && counter <= 3))
		{
			counter--;
		}
		if (key == 80 && (counter >= 1 && counter <= 2))
		{
			counter++;
		}
		if (key == '\r')
		{
			if (counter == 1)
			{
				RandevuOluþtur(dok1);

				break;
			}
			if (counter == 2)
			{
				RandevuOluþtur(dok2);

				break;
			}
			if (counter == 3)
			{
				exit(0);
			}

		}
		//@ErcanDuman
		Set[0] = 9;
		Set[1] = 12;
		Set[2] = 7;

		if (counter == 1)
		{
			Set[0] = 75;
		}
		if (counter == 2)
		{
			Set[1] = 75;
		}
		if (counter == 3)
		{
			Set[2] = 10;
		}

	}

}



int main() {
	setlocale(LC_ALL, "Turkish");	//@NurullahSahin @Ercan Duman burasi Randevu sistemi olarak kalsin daha iyi olur
	system("title Ýskenderun Devlet Hastanesi Randevu Sistemi                                                                                                        ");


	Doktor d1("kýrkevler mahallesi", "Bilmemne sokak", "merkez", 52, "05555", "23232", "Mehmet", "Ciftci", 1);//@ErenAyguer
	Doktor d2("kýrkevl2er mah2allesi2", "Bilmemne2 sokak", "merkez", 51, "03333", "12121", "Sevgi", "Gulsen", 2);
	DoktorSec(d1, d2);
	system("pause");

}
