#include "APart.hpp"

APart::APart():
	_make(DEFAULT_MAKE),
	_model(DEFAULT_MODEL),
	_year(DEFAULT_YEAR),
	_status(DEFAULT_STATUS)
{};

APart::APart(const std::string& make,
			const std::string& model,
			const size_t& year):
			_make(make),
			_model(model),
			_year(year)
{}

APart::APart(const APart& ref):
	_make(ref._make),
	_model(ref._model),
	_year(ref._year),
	_status(ref._status)
{}

APart&	APart::operator=(const APart& ref)
{
	this->_make = ref._make;
	this->_model = ref._model;
	this->_year = ref._year;
	this->_status = ref._status;
	return (*this);
}

APart::~APart(){};

void	APart::showDetail()
{
	std::cout << "Make: ";
	std::cout << BOLD << _make << RESET << std::endl;
	std::cout << "Model: ";
	std::cout << BOLD << _model << RESET << std::endl;
	std::cout << "Year: ";
	std::cout << BOLD << _year << RESET << std::endl;
}
