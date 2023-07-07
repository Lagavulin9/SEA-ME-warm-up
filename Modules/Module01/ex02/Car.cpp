#include "Car.hpp"

Car::Car(): Engine(), Wheel()
{};

Car::Car(const Car& ref): Engine(ref), Wheel(ref)
{}

Car::Car(const Engine& engine, const Wheel& wheel):
	Engine(engine),
	Wheel(wheel)
{}

Car&	Car::operator=(const Car& ref)
{
	new (this)(Car)(ref);
	return (*this);
}

Car::~Car(){};

void	Car::showDetail()
{
	std::cout << GREEN_COLOR << BOLD << "Engine Info" << RESET << std::endl;
	Engine::showDetail();
	std::cout << std::endl;
	std::cout << YELLOW_COLOR << BOLD << "Wheel Info" << RESET << std::endl;
	Wheel::showDetail();
	std::cout << std::endl;
}

void	Car::drive()
{
	int	engineStatus = Engine::healthCheck();
	int	wheelStatus = Wheel::healthCheck();

	if (engineStatus == RED || wheelStatus == RED)
	{
		std::cout << "Failed to drive. Please repair" << std::endl;
		return ;
	}
	std::cout << "We are driving!" << std::endl;
}