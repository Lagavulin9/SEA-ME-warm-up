#include "Brake.hpp"

Brake::Brake():
	APart(),
	_brakePad(DEFAULT_BRAKEPAD)
{}

Brake::Brake(const size_t& brakePad):
	APart(),
	_brakePad(brakePad)
{}

Brake::Brake(const std::string& make,
			const std::string& model,
			const size_t& year):
	APart(make, model, year),
	_brakePad(DEFAULT_BRAKEPAD)
{}

Brake::Brake(const Brake& ref):
	APart(ref),
	_brakePad(ref._brakePad)
{}

Brake&	Brake::operator=(const Brake& ref)
{
	new (this)(Brake)(ref);
	return (*this);
}

Brake::~Brake(){}

int	Brake::healthCheck()
{
	std::cout << "Running dignostics on Brake..." << std::endl;
	std::cout << "Brake Status: ";
	if (this->_status == GREEN)
		std::cout << GREEN_COLOR << BOLD << "OK";
	else
		std::cout << RED_COLOR << BOLD << "Too thin brake pad";
	std::cout << RESET << std::endl;
	return this->_status;
}

void	Brake::hitBrake()
{
	this->_brakePad -= 1;
	if (this->_brakePad < 10)
		this->_status = RED;
}
