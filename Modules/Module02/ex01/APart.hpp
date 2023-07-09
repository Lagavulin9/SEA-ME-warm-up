#pragma once
#ifndef __APART_HPP__
# define __APART_HPP__

# include <string>
# include <iostream>

enum E_STATUS
{
	GREEN,
	RED
};

# define DEFAULT_STATUS	GREEN
# define DEFAULT_MAKE	"SEA:ME"
# define DEFAULT_MODEL	""
# define DEFAULT_YEAR	2023

# define RESET			"\033[0m"
# define BOLD			"\033[1m"
# define RED_COLOR		"\033[31m"
# define GREEN_COLOR	"\033[32m"
# define YELLOW_COLOR	"\033[33m"

class APart {
protected:
	std::string	_make;
	std::string	_model;
	size_t		_year;
	int			_status;
public:
	APart();
	APart(const std::string& make,
		const std::string& model,
		const size_t& year);
	APart(const APart&);
	virtual ~APart();

	APart&	operator=(const APart&);

	virtual void	showDetail();
	virtual int		healthCheck() = 0;
};

#endif
