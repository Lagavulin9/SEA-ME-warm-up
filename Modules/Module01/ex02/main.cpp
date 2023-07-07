#include "Car.hpp"
#include "time.h"

int	main()
{
	Car	A;

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
