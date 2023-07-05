#pragma once
// #ifndef __CONVERTER__HPP__
// # define __CONVERTER_HPP__

# include <iostream>
# include <string>
# include <cstring>

class Converter{
private:

public:
	Converter();
	~Converter();

	std::string convert(std::string cmd, std::string arg);
};

// #endif