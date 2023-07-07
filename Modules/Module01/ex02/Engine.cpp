#include "Engine.hpp"

Engine::Engine():
	APart()
{};

Engine::Engine(const std::string& make,
			const std::string& model,
			const size_t& year):
			APart(make, model, year)
{}

Engine::Engine(const Engine& ref):
	APart(ref)
{};

Engine&	Engine::operator=(const Engine& ref)
{
	new	(this)(Engine)(ref);
	return (*this);
}

Engine::~Engine(){};

int	Engine::healthCheck()
{
	std::cout << "Running dignostics on engine..." << std::endl;
	std::cout << "Engine Status: ";
	if (this->_status == GREEN)
		std::cout << GREEN_COLOR << "OK";
	else
		std::cout << RED_COLOR << "Malfuncion";
	std::cout << RESET << std::endl;
	return this->_status;
}

void	Engine::startEngine()
{
	std::cout << "Engine is running" << std::endl;
	int	threshold = static_cast<int>(RAND_MAX * FAILURE_RATE);
	if (std::rand() <= threshold)
		this->_status = RED;
}