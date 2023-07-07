#include "Wheel.hpp"

Wheel::Wheel():
	APart(),
	_pressure(DEFAULT_PRESSURE)
{};

Wheel::Wheel(const std::string& make,
			const std::string& model,
			const size_t& year):
			APart(make, model, year),
			_pressure(DEFAULT_PRESSURE)
{}

Wheel::Wheel(const Wheel& ref):
	APart(ref),
	_pressure(ref._pressure)
{};

Wheel&	Wheel::operator=(const Wheel& ref)
{
	new	(this)(Wheel)(ref);
	return (*this);
}

Wheel::~Wheel(){};

int	Wheel::healthCheck()
{
	std::cout << "Running dignostics on wheels..." << std::endl;
	this->spin();
	std::cout << "Wheel Status: ";
	if (this->_status == GREEN)
		std::cout << GREEN_COLOR << BOLD << "OK";
	else
		std::cout << RED_COLOR << BOLD << "Low tyre pressure";
	std::cout << RESET << std::endl;
	return this->_status;
}

void	Wheel::spin()
{
	std::cout << "Wheels are spinning..." << std::endl;
	if (this->_pressure >= 30)
		this->_pressure -= 10;
	else
		this->_status = RED;
}