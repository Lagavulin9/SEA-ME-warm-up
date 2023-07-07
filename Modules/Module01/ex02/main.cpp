#include "Car.hpp"
#include "time.h"

int	main()
{
	Engine	eng("A", "MQW-123", 2020);
	Wheel	wh("B", "E-1234", 2022);

	Car	A(eng, wh);

	A.showDetail();

	srand(time(NULL));
	while (!std::cin.eof())
	{
		std::string	input;
		std::cout << "Press ";
		std::cout << BOLD << "Enter" << RESET;
		std::cout << " to drive" << std::endl;
		std::getline(std::cin, input);
		A.drive();
		std::cout << std::endl;
	}
}
