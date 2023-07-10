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
	return this->_status;
}

void	Brake::hitBrake()
{
	int	min = 1;
	int	max = 10;
	int	randomValue = min + (std::rand() % (max - min + 1));

	this->_brakePad -= randomValue;
	if (this->_brakePad < 10)
		this->_status = RED;
}
