#pragma once
#ifndef __BRAKE_HPP__
# define __BRAKE_HPP__

# include "APart.hpp"

# define DEFAULT_BRAKEPAD 100

class Brake : public APart
{
private:
	size_t	_brakePad;

public:
	Brake();
	Brake(const size_t&);
	Brake(const std::string& make,
		const std::string&	model,
		const size_t& year);
	Brake(const Brake&);
	virtual ~Brake();

	Brake&	operator=(const Brake&);

	int		healthCheck();
	void	hitBrake();
};

#endif
