#include <iostream>
#include <cmath>
using namespace std;
class Numar_Complex {
	double re, im;
	public:
		//constr de initializare
		Numar_Complex();
		Numar_Complex(double, double);
		//constr de copiere
		Numar_Complex(const Numar_Complex&);
		Numar_Complex& operator=(const Numar_Complex&);
		//destructor
		~Numar_Complex();
		void Set_re(double a);
		void Set_im(double a);
		double Get_re();
		double Get_im();
		void Afisare();
		double Modul();
		friend Numar_Complex operator+(const Numar_Complex&, const Numar_Complex&);
		//Numar_Complex operator+(const Numar_Complex&);
		Numar_Complex operator*(const Numar_Complex&);
		Numar_Complex operator/(const Numar_Complex&);
		friend istream& operator>>(istream &in, Numar_Complex &A);
		friend ostream& operator<<(ostream& out, const Numar_Complex& A);
		Numar_Complex* SqrtC(const Numar_Complex&);
		friend void Ecuatie(double a, double b, double c);
};
Numar_Complex::Numar_Complex() {
	re = 0;
	im = 0;
	//this->im = 0;
	//this->re = 0;
}
Numar_Complex::Numar_Complex(double a, double b) {
	re = a;
	im = b;
}

Numar_Complex::Numar_Complex(const Numar_Complex& A) {
	re = A.re;
	im = A.im;
}

Numar_Complex& Numar_Complex::operator=(const Numar_Complex& A) {
	if (this == &A) {
		return *this;
	}
	re = A.re;
	im = A.im;
	return *this;
}
Numar_Complex::~Numar_Complex() {
	re = 0;
	im = 0;
}
void Numar_Complex::Set_re(double a) {
	re = a;
}
void Numar_Complex::Set_im(double a) {
	im = a;
}
double Numar_Complex::Get_re() {
	return re;
}
double Numar_Complex::Get_im() {
	return im;
}
void Numar_Complex::Afisare() {
	if (re == 0)
		if (im == 0) cout << "Numarul este 0";
		else if (im < 0) cout << "-i*" << abs(im);
			else cout << "i*" << im;
	else {
		if (im == 0) cout << re;
		else if (im < 0) cout << re << " - i*" << abs(im);
			else cout << re << " + i*" << im;
	}
}

double Numar_Complex::Modul() {
	return sqrt(im * im + re * re);
}
Numar_Complex operator+(const Numar_Complex& A, const Numar_Complex& B) {
	Numar_Complex C;
	C.re = A.re + B.re;
	C.im = A.im + B.im;
	return C;
}
/*Numar_Complex Numar_Complex::operator+(const Numar_Complex& B) {
	Numar_Complex C;
	C.re = this->re + B.re;
	C.im = this->im + B.im;
	return C;
}*/
Numar_Complex Numar_Complex::operator*(const Numar_Complex& B) {
	//a*c + a*d*i + b*c*i - b*d
	Numar_Complex C;
	C.re = this->re * B.re - this->im * B.im;
	C.im = this->re * B.im + this->im * B.re;
	return C;
}
Numar_Complex Numar_Complex::operator/(const Numar_Complex& B) {
	Numar_Complex C;
	C.re = (this->re * B.re + this->im * B.im) / (B.re * B.re + B.im * B.im);
	C.im = (this->im * B.re - this->re * B.im) / (B.re * B.re + B.im * B.im);
	return C;
}

istream& operator>>(istream& in, Numar_Complex& A) {
	cout << "Introdu parte reala:\n";
	in >> A.re;
	cout << "Introdu parte imaginara:\n";
	in >> A.im;
	return in;
}
ostream& operator<<(ostream& out,const Numar_Complex& A) {
	out << "Numarul complex are partea reala " << A.re << " si partea imaginara " << A.im << "\n";
	return out;
}
Numar_Complex* Numar_Complex::SqrtC(const Numar_Complex& A) {
	Numar_Complex* v = new Numar_Complex[2];
	v[0].re = sqrt((A.re + sqrt(A.re * A.re + A.im * A.im)) / 2);
	v[1].re = (-1) * sqrt((A.re + sqrt(A.re * A.re + A.im * A.im)) / 2);
	v[0].im = (A.im) / (2 * v[0].re);
	v[1].im = (A.im) / (2 * v[1].re);
	return v;
}
void Ecuatie(double a, double b, double c) {
	double d;
	d = b * b - 4 * a * c;
	if (d == 0) cout << "x1 = x2 = " << ((-1) * b / 2 * a);
	else if (d > 0) {
		cout << "x1 = " << ((-1) * b + sqrt(d)) / 2 * a << '\n';
		cout << "x2 = " << ((-1) * b - sqrt(d)) / 2 * a;
	}
	else {
		Numar_Complex x1, x2;
		x1.re = x2.re = (-1) * b / 2 * a;
		x1.im = sqrt(-d) / 2 * a;
		x2.im = (-1) * sqrt((-1)*d) / 2 * a;
		cout << "x1 = "; x1.Afisare();
		cout << '\n';
		cout << "x2 = "; x2.Afisare();
	}
	
}
int main()
{   //citirea a n obiecte, memorarea, afisarea si stergerea lor
	int n;
	cout << "Dati dimensiunea vectorului: \n "; 
	cin >> n;
	Numar_Complex* arr = new Numar_Complex[n];
	cout << "Dati elementele vectorului \n";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << "Elementele vectorului sunt: \n";
	for (int i = 0; i < n; i++) {
		arr[i].Afisare();
		cout << '\n';
	}

	delete[] arr;

	Numar_Complex A, B;
	cout << "Dati doua numere complexe\n";
	cin >> A >> B;
	Numar_Complex C(1, 3); //initializare
	cout << C << '\n' ;
	C = A + B;
	cout << "Suma lui A si B este "; C.Afisare(); cout << '\n';
	C = A * B;
	cout << "Produsului lui A si B este "; C.Afisare(); cout << '\n';
	C = A / B;
	cout << "Impartirea lui A la B este "; C.Afisare(); cout << '\n';
	C = A; //copiere
	cout << C << '\n';
	cout << "Modului lui C este: " << C.Modul() << '\n';
	cout << "Partea reala a lui "; C.Afisare(); cout << " este " << C.Get_re() << '\n';
	cout << "Partea imaginara a lui "; C.Afisare(); cout << " este " << C.Get_im() << '\n';
	C.Set_re(2);
	C.Set_im(34);
	C.Afisare(); cout << '\n';
	//radacinile unui nr complex si rezolvarea ecuatiei
	Numar_Complex* v = new Numar_Complex[2];
	v = A.SqrtC(A);
	cout << "Radacinile numarului complex ";
	A.Afisare();
	cout << " sunt: \n";
	for (int i = 0; i < 2; i++) {
		v[i].Afisare();
		cout << '\n';
	}
	cout << "Solutiile ecuatiei sunt: \n";
	Ecuatie(1, 1, 1);
	
}









