#include "Transmission.hpp"

Transmission::Transmission():
	APart(),
	_oilLeak(false)
{}

Transmission::Transmission(const std::string& make,
						const std::string& model,
						const size_t& year):
	APart(make, model, year),
	_oilLeak(false)
{}

Transmission::Transmission(const Transmission& ref):
	APart(ref),
	_oilLeak(ref._oilLeak)
{}

Transmission&	Transmission::operator=(const Transmission& ref)
{
	new (this)(Transmission)(ref);
	return (*this);
}

Transmission::~Transmission(){};

int	Transmission::healthCheck()
{
	std::cout << "Running dignostics on Transmission..." << std::endl;
	std::cout << "Oil Leak: ";
	if (this->_status == GREEN)
		std::cout << GREEN_COLOR << BOLD << "No";
	else
		std::cout << RED_COLOR << BOLD << "LEAK";
	std::cout << RESET << std::endl;
	return this->_status;
}

void	Transmission::shiftGear()
{
	int	threshold = static_cast<int>(RAND_MAX * FAILURE_RATE);
	if (std::rand() <= threshold)
		this->_status = RED;
}