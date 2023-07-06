#include "Car.hpp"
#include "SportsCar.hpp"

int	main()
{
	SportsCar	A;
	SportsCar	B("Tesla", "Model Y", 2022, 100);
	SportsCar	C(B);
	SportsCar	D = A;
	A.drive();
	B.drive();
	C.drive();
	D.drive();
}