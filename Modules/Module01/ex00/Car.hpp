#pragma once
#ifndef __CAR_HPP__
# define __CAR_HPP__

# include <string>
# include <iostream>

# define DEFAULT_NAME "Default name"
# define DEFAULT_SPEED 100

class Car {
private:
	std::string	_name;
	size_t		_speed;
public:
	Car();
	Car(const std::string& name, const size_t& speed);
	Car(const Car&);
	~Car();

	Car&	operator=(const Car&);

	std::string	getName();
	size_t		getSpeed();
	void		setName(const std::string&);
	void		setSpeed(const size_t& speed);

	void		showInfo();
};

#endif
