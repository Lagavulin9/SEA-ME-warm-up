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
	return this->_status;
}

void	Wheel::spin()
{
	int	min = 1;
	int	max = 10;
	int	randomValue = min + (std::rand() % (max - min + 1));

	this->_pressure -= randomValue;
	if (_pressure < 30)
		this->_status = RED;
}