#pragma once
#ifndef __TRANSMISSION_CPP__
# define __TRANSMISSION_CPP__

# include "APart.hpp"

class Transmission : public APart
{
private:
	const float	FAILURE_RATE = 0.02;
	bool		_oilLeak;

public:
	Transmission();
	Transmission(const std::string& make,
				const std::string& model,
				const size_t& year);
	Transmission(const Transmission&);
	virtual ~Transmission();

	Transmission&	operator=(const Transmission&);

	int				healthCheck();
	void			shiftGear();
};

#endif
