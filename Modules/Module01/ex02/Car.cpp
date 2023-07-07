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

void	Car::drive()
{
	int	engineStatus = Engine::healthCheck();
	int	wheelStatus = Wheel::healthCheck();

	if (engineStatus == RED || wheelStatus == RED)
	{
		std::cout << "Failed to drive. Please repair" << std::endl;
		return ;
	}
	Engine::startEngine();
	Wheel::spin();
	std::cout << "We are driving!" << std::endl;
}
