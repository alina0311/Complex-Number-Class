#include <iostream>
#include <cstring>
using namespace std;
class persoana {
	string nume; 
	int an;
	char s;
public:
	persoana(string s="", int n=0, char c='-');
	persoana(const persoana&);
	persoana& operator=(const persoana&);
	void Set_nume(string name);
	void Set_an(int n);
	void Set_sex(char c);
	string Get_nume();
	int Get_an();
	char Get_sex();
	void Afisare();
	friend istream& operator>>(istream& in, persoana& A);
	friend ostream& operator<<(ostream& out, persoana& A);
};
class baza_de_date {
	int capacitate;
	int nr;
	persoana* arr;
public:
	baza_de_date(int=100);
	baza_de_date(const baza_de_date&);
	baza_de_date& operator=(const baza_de_date&);
	~baza_de_date();
	void Add(persoana);
	void Delete(int);
	void Delete(string);
	void Delete(char);
	void afiseaza();
	void Print_by_Name();
	void Print_by_Age();
};
persoana::persoana(const persoana& P) {
	this->an = P.an;
	this->nume = P.nume;
	this->s = P.s;
}
persoana& persoana::operator=(const persoana& P) {
	if (this == &P) return *this;
	this->an = P.an;
	this->nume = P.nume;
	this->s = P.s;
	return *this;
}

persoana::persoana(string name, int n, char c) {
	nume = name;
	an = n;
	this->s = c;
}
void persoana::Set_nume(string name) {
	this->nume = name;
}
void persoana::Set_an(int n) {
	this->an = n;
}
void persoana::Set_sex(char c) {
	s = c;
}
string persoana::Get_nume() {
	return nume;
}

int persoana::Get_an() {
	return an;
}
char persoana::Get_sex() {
	return s;
}
void persoana::Afisare() {
	cout << "Numele este " << nume << '\n';
	cout << "Anul nasterii este " << an << '\n';
	cout << "Sexul este " << s << '\n';
}
istream& operator>>(istream& in, persoana& A) {
	cout << "Introdu numele:\n";
	in >> A.nume;
	cout << "Introdu anul nasterii:\n";
	in >> A.an;
	cout << "Introdu sexul:\n";
	in >> A.s;
	return in;
}
 ostream& operator<<(ostream& out, persoana& A) {
	out << A.nume << ' ' << A.an << ' ' << A.s << '\n';
	return out;
}
baza_de_date::baza_de_date(int n) {
	capacitate = n;
	nr = 0;
	arr = new persoana[n];
}

baza_de_date::baza_de_date(const baza_de_date& B) {
	capacitate = B.capacitate;
	nr = B.nr;
	arr = new persoana[capacitate];
	for (int i = 0; i < nr; i++) {
		arr[i] = B.arr[i];
	}
}

baza_de_date& baza_de_date::operator=(const baza_de_date& B) {
	if (this == &B) {
		return *this;
	}
	if (arr) delete[] arr;
	arr = NULL;
	capacitate = B.capacitate;
	nr = B.nr;
	arr = new persoana[capacitate];
	for (int i = 0; i < nr; i++) {
		arr[i] = B.arr[i];
	}
	return *this;
}

baza_de_date::~baza_de_date() {
	if(arr) delete[] arr;
}
void baza_de_date::Add(persoana P) {
	arr[nr].Set_an(P.Get_an());
	arr[nr].Set_nume(P.Get_nume());
	arr[nr].Set_sex(P.Get_sex());
	nr++;
}
void baza_de_date::Delete(int age) {
	int aparitie = -1;
	while (true) {
		if (nr == 0) break;
		int pozitie = -1;
		for (int i = 0; i < nr; i++) {
			if (arr[i].Get_an() == age) {
				pozitie = i;
				break;
			}
		}
		if (pozitie == -1) {
			break;
		}
		else {
			for (int i = pozitie; i < nr-1; i++) {
				arr[i] = arr[i + 1];
			}
			arr[nr].Set_an(0);
			arr[nr].Set_sex('-');
			arr[nr].Set_nume("");
			nr--;
		}
	}
	if (nr == 0) cout << "Baza de date e goala!";
}
void baza_de_date::Delete(string x) {
	int aparitie = -1;
	while (true) {
		if (nr == 0) break;
		int pozitie = -1;
		for (int i = 0; i < nr; i++) {
			if (arr[i].Get_nume() == x) {
				pozitie = i;
				break;
			}
		}
		if (pozitie == -1) {
			break;
		}
		else {
			for (int i = pozitie; i < nr - 1; i++) {
				arr[i] = arr[i + 1];
			}
			arr[nr].Set_an(0);
			arr[nr].Set_sex('-');
			arr[nr].Set_nume("");
			nr--;
		}
	}
	if (nr == 0) cout << "Baza de date e goala!";
}
void baza_de_date::Delete(char x) {
	int aparitie = -1;
	while (true) {
		if (nr == 0) break;
		int pozitie = -1;
		for (int i = 0; i < nr; i++) {
			if (arr[i].Get_sex() == x) {
				pozitie = i;
				break;
			}
		}
		if (pozitie == -1) {
			break;
		}
		else {
			for (int i = pozitie; i < nr - 1; i++) {
				arr[i] = arr[i + 1];
			}
			arr[nr].Set_an(0);
			arr[nr].Set_sex('-');
			arr[nr].Set_nume("");
			nr--;
		}
	}
	if (nr == 0) cout << "Baza de date e goala!";
}
void baza_de_date::afiseaza() {
	for (int i = 0; i < nr; i++) {
		cout << arr[i] << ' ';
	}
}
void baza_de_date::Print_by_Age() {
	//ordinea crescatoare a varstelor inseamna ordine descrescatoare a anilor de nastere
	for (int i = 0; i < nr-1; i++) 
		for (int j = i + 1; j < nr; j++) {
			if (arr[i].Get_an() < arr[j].Get_an()) swap(arr[i], arr[j]);
		}
	for (int i = 0; i < nr; i++)
		cout << arr[i] << '\n';
}
void baza_de_date::Print_by_Name() {
	for (int i = 0; i < nr - 1; i++)
		for (int j = i + 1; j < nr; j++) {
			if (arr[i].Get_nume() > arr[j].Get_nume()) swap(arr[i], arr[j]);
		}
	for (int i = 0; i < nr; i++)
		cout << arr[i] << '\n';
}
int main() {
	persoana A("Popescu", 2000, 'M');
	persoana B("Ionescu", 1999, 'M');
	persoana C("Georgescu", 1970, 'F');
	persoana E("Enescu", 1950, 'F');
	persoana D;
	cin >> D;
	cout << D;
	A.Set_an(1978); A.Set_nume("Radu"); A.Set_sex('M');
	cout << A.Get_nume() << ' ' << A.Get_an() << ' ' << A.Get_sex() << '\n';
	baza_de_date P;
	P.Add(A);
	P.Add(B);
	P.Add(C);
	P.Add(D);
	P.Add(E);
	P.Delete('F');
	P.Delete("Ionescu");
	P.Delete(2001);
	P.Print_by_Name();
	P.Print_by_Age();
	return 0;
}
