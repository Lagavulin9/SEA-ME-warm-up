#pragma once
#ifndef __CAR_HPP__
# define __CAR_HPP__

# include "Engine.hpp"
# include "Wheel.hpp"

class Car : public Engine, public Wheel
{
private:

public:
	Car();
	Car(const Engine&, const Wheel&);
	Car(const Car&);
	virtual ~Car();

	Car&	operator=(const Car&);

	void	drive();
};

#endif
