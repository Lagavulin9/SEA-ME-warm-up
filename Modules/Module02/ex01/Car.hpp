#pragma once
#ifndef __CAR_HPP__
# define __CAR_HPP__

# include "Engine.hpp"
# include "Wheel.hpp"
# include "Brake.hpp"
# include "Transmission.hpp"
# include <vector>

# define NUMBER_OF_WHEELS 4

class Car {
private:
	std::shared_ptr<Engine> 			_engine;
	std::vector<std::shared_ptr<Wheel>>	_wheels;
	std::vector<std::shared_ptr<Brake>>	_brakes;
	std::shared_ptr<Transmission>		_tranmission;

public:
	Car();
	Car(const Engine&,
		const Wheel&,
		const Brake&,
		const Transmission&);
	Car(const Car&);
	virtual ~Car();

	Car&	operator=(const Car&);

	void	showDetail();
	void	drive();
};

#endif
