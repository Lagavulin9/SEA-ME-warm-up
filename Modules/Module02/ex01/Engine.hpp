#pragma once
#ifndef __ENGINE_HPP__
# define __ENGINE_HPP__

# include "APart.hpp"
# include <cstdlib>

class Engine : public APart
{
private:
	const float	FAILURE_RATE = 0.01;

public:
	Engine();
	Engine(const std::string& make,
			const std::string& model,
			const size_t& year);
	Engine(const Engine&);
	virtual ~Engine();

	Engine&	operator=(const Engine&);

	int		healthCheck();
	void	startEngine();
};

#endif
