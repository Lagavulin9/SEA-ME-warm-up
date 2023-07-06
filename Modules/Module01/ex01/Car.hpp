#pragma once
#ifndef __CAR_HPP__
# define __CAR_HPP__

# include <string>
# include <iostream>

# define RESET "\033[0m"
# define BOLD "\033[1m"
# define RED "\033[31m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"

# define DEFAULT_MAKE "SEA:ME"
# define DEFAULT_MODEL "PiRacer"
# define DEFAULT_YEAR 2023

class Car {
private:
	std::string	_make;
	std::string	_model;
	size_t		_year;
public:
	Car();
	Car(const std::string& make,
		const std::string& model,
		const size_t& year);
	Car(const Car&);
	~Car();

	Car&	operator=(const Car&);

	std::string	getMake();
	std::string	getModel();
	size_t		getYear();
	void		setMake(const std::string&);
	void		setModel(const std::string&);
	void		setYear(const size_t&);

	void		drive();
};

#endif
