#include "SportsCar.hpp"

SportsCar::SportsCar():
	Car(),
	_topSpeed(DEFAULT_TOPSPEED)
{
	std::cout << "Default Constructor Called" << std::endl;
}

SportsCar::SportsCar(const std::string& make,
					const std::string& model,
					const size_t& year,
					const size_t& topSpeed):
	Car(make, model, year),
	_topSpeed(topSpeed)
{
	std::cout << "Constructor Called" << std::endl;
}

SportsCar::SportsCar(const SportsCar& ref):
	Car(ref),
	_topSpeed(ref._topSpeed)
{
	std::cout << "Copy Constructor Called" << std::endl;
}

SportsCar::~SportsCar()
{
	std::cout << "Destructor Called" << std::endl;
}

SportsCar& SportsCar::operator=(const SportsCar& ref)
{
	std::cout << "Copy Assign Operator Called" << std::endl;
	new (this)(SportsCar)(ref);
	return (*this);
}

void	SportsCar::drive()
{
	std::cout << "Driving ";
	std::cout << RED << this->getMake() << " ";
	std::cout << BLUE << this->getModel() << " ";
	std::cout << YELLOW << this->getYear() << " ";
	std::cout << RESET << "edition with ";
	std::cout << BOLD << _topSpeed;
	std::cout << RESET << "km/h" << std::endl;
}
