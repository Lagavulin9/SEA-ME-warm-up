#include "Car.hpp"
#include "time.h"

#include <unistd.h>

void	test()
{
	Engine			eng("A", "MQW-123", 2020);
	Wheel			wh("B", "E-1234", 2022);
	Brake			br("C", "HK1", 2022);
	Transmission	trns("D", "TR-12D9", 2023);

	Car	A(eng, wh, br, trns);

	A.showDetail();

	srand(time(NULL));
	while (!std::cin.eof())
	{
		std::string	input;
		std::cout << "Press ";
		std::cout << BOLD << "Enter" << RESET;
		std::cout << " to drive, cntl + D to exit" << std::endl;
		std::getline(std::cin, input);
		A.drive();
		std::cout << std::endl;
	}
}

void	leak()
{
	system("leaks myCar -q");
}

int	main()
{
	atexit(leak);
	test();
}

