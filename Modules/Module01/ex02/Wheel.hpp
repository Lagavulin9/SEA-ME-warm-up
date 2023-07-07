#pragma once
#ifndef __WHEEL_HPP__
# define __WHEEL_HPP__

# include "APart.hpp"

class Wheel : public APart
{
private:
	int		_pressure;

protected:
	int		healthCheck();
	void	spin();

public:
	Wheel();
	Wheel(const std::string& make,
		const std::string& model,
		const size_t& year);
	Wheel(const Wheel&);
	virtual ~Wheel();

	Wheel&	operator=(const Wheel&);
};

#endif
