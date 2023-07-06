#include "Car.hpp"

Car::Car():
	_name(DEFAULT_NAME),
	_speed(DEFAULT_SPEED)
{
	std::cout << "Default Constructor Called" << std::endl;
}

Car::Car(const std::string& name, const size_t& speed):
	_name(name),
	_speed(speed)
{
	std::cout << "Constructor Called" << std::endl;
};

Car::Car(const Car& ref):
	_name(ref._name),
	_speed(ref._speed)
{
	std::cout << "Copy Constructor Called" << std::endl;
}
Car::~Car()
{
	std::cout << "Destructor Called" << std::endl;
};

Car&	Car::operator=(const Car& ref)
{
	std::cout << "Copy Assign Operator Called" << std::endl;
	new (this)(Car)(ref);
	return *this;
}

std::string	Car::getName()
{
	return this->_name;
}

size_t	Car::getSpeed()
{
	return this->_speed;
}

void	Car::setName(const std::string& name)
{
	this->_name = name;
}

void	Car::setSpeed(const size_t& speed)
{
	this->_speed = speed;
}

void	Car::showInfo()
{
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Speed: " << this->_speed << std::endl;
}