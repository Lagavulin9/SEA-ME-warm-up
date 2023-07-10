#include "Car.hpp"
Car::Car():
	_engine(std::make_shared<Engine>()),
	_wheels(NUMBER_OF_WHEELS),
	_brakes(NUMBER_OF_WHEELS),
	_tranmission(std::make_shared<Transmission>())
{
	for (size_t i = 0; i < NUMBER_OF_WHEELS; i++)
	{
		_wheels[i] = std::make_shared<Wheel>();
		_brakes[i] = std::make_shared<Brake>();
	}
}

Car::Car(const Car& ref):
	_engine(std::make_shared<Engine>(*ref._engine)),
	_wheels(NUMBER_OF_WHEELS),
	_brakes(NUMBER_OF_WHEELS),
	_tranmission(std::make_shared<Transmission>(*ref._tranmission))
{
	for (size_t i = 0; i < NUMBER_OF_WHEELS; i++)
	{
		_wheels[i] = std::make_shared<Wheel>(*ref._wheels[i]);
		_brakes[i] = std::make_shared<Brake>(*ref._brakes[i]);
	}
}

Car::Car(const Engine& engine,
		 const Wheel& wheel,
		 const Brake& brake,
		 const Transmission& transmission):
	_engine(std::make_shared<Engine>(engine)),
	_wheels(NUMBER_OF_WHEELS),
	_brakes(NUMBER_OF_WHEELS),
	_tranmission(std::make_shared<Transmission>(transmission))
{
	for (size_t i = 0; i < NUMBER_OF_WHEELS; i++)
	{
		_wheels[i] = std::make_shared<Wheel>(wheel);
		_brakes[i] = std::make_shared<Brake>(brake);
	}
}

Car&	Car::operator=(const Car& ref)
{
	new (this)(Car)(ref);
	return (*this);
}

Car::~Car(){};

void	Car::showDetail()
{
	std::cout << GREEN_COLOR << BOLD << "Engine Info" << RESET << std::endl;
	_engine->showDetail();
	std::cout << std::endl;
	std::cout << YELLOW_COLOR << BOLD << "Wheel Info" << RESET << std::endl;
	_wheels[0]->showDetail();
	std::cout << std::endl;
	std::cout << GREEN_COLOR << BOLD << "Brake Info" << RESET << std::endl;
	_brakes[0]->showDetail();
	std::cout << std::endl;
	std::cout << YELLOW_COLOR << BOLD << "Transmission Info" << RESET << std::endl;
	_tranmission->showDetail();
	std::cout << std::endl;
}

void	Car::drive()
{
	int	engineStatus = _engine->healthCheck();
	int transmissionStatus = _tranmission->healthCheck();
	int	wheelStatus = GREEN;
	int	brakeStatus = GREEN;

	std::cout<< "Running dignostics on wheels..." << std::endl;
	std::cout << "Wheels [";
	for (size_t i = 0; i < NUMBER_OF_WHEELS; i++)
	{
		if (_wheels[i]->healthCheck() == RED)
		{
			std::cout << RED_COLOR << BOLD << "Low tyre pressure" << RESET;
			wheelStatus = RED;
		}
		else
			std::cout << GREEN_COLOR << BOLD << "OK" << RESET;
		if (i + 1 != NUMBER_OF_WHEELS)
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;

	std::cout << "Running dignostics on brakes..." << std::endl;
	std::cout << "Brakes [";
	for (size_t i = 0; i < NUMBER_OF_WHEELS; i++)
	{
		if (_brakes[i]->healthCheck() == RED)
		{
			std::cout << RED_COLOR << BOLD << "Thin brake pad" << RESET;
			wheelStatus = RED;
		}
		else
			std::cout << GREEN_COLOR << BOLD << "OK" << RESET;
		if (i + 1 != NUMBER_OF_WHEELS)
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;

	if (engineStatus == RED || \
		wheelStatus == RED || \
		transmissionStatus == RED || \
		brakeStatus == RED)
	{
		std::cout << "Failed to drive. Please repair" << std::endl;
		return ;
	}
	std::cout << "We are driving!" << std::endl;
	for (size_t i = 0; i < NUMBER_OF_WHEELS; i++)
	{
		_wheels[i]->spin();
		_brakes[i]->hitBrake();
	}
	_tranmission->shiftGear();

}