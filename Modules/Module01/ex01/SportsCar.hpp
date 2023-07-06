#pragma once
#ifndef __SPORTSCAR_HPP__
# define __SPORTSCAR_HPP__

# include "Car.hpp"

# define DEFAULT_TOPSPEED 300

class SportsCar : public Car
{
private:
	size_t	_topSpeed;
public:
	SportsCar();
	SportsCar(const std::string& make,
			const std::string& model,
			const size_t& year,
			const size_t& topspeed);
	SportsCar(const SportsCar&);
	~SportsCar();

	SportsCar&	operator=(const SportsCar&);

	void		drive();
};

#endif
