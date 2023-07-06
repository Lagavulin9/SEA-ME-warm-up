#include "Car.hpp"

int main()
{
	Car	A("Car A", 100);
	A.showInfo();

	Car B(A);
	B.showInfo();

	Car C;
	C = A;
	C.showInfo();
}