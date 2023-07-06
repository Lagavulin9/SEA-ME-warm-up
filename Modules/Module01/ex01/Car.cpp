#include "Car.hpp"

Car::Car():
	_make(DEFAULT_MAKE),
	_model(DEFAULT_MODEL),
	_year(DEFAULT_YEAR)
{
	std::cout << "Default Constructor Called" << std::endl;
}

Car::Car(const std::string& make,
		const std::string& model,
		const size_t& year):
	_make(make),
	_model(model),
	_year(year)
{
	std::cout << "Constructor Called" << std::endl;
};

Car::Car(const Car& ref):
	_make(ref._make),
	_model(ref._model),
	_year(ref._year)
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

std::string	Car::getMake()
{
	return this->_make;
}

std::string	Car::getModel()
{
	return this->_model;
}

size_t	Car::getYear()
{
	return this->_year;
}

void	Car::setMake(const std::string& make)
{
	this->_make = make;
}

void	Car::setModel(const std::string& model)
{
	this->_model = model;
}

void	Car::setYear(const size_t& year)
{
	this->_year = year;
}

void	Car::drive()
{
	std::cout << "Driving ";
	std::cout << RED << this->_make << " ";
	std::cout << BLUE << this->_model << " ";
	std::cout << YELLOW << this->_year << " ";
	std::cout << RESET << "edition" << std::endl;
}
