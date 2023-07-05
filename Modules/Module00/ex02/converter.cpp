#include "converter.hpp"

Converter::Converter(){};
Converter::~Converter(){};

std::string Converter::convert(std::string cmd, std::string arg)
{
	if (cmd == "up")
	{
		for (size_t i=0; i<arg.length(); i++)
		{
			char c = arg.data()[i];
			// by substracting 'a', lowercase 'a' becomes 0.
			// Then add Captital letters to make upper cases.
			if ('a' <= c && c <= 'z')
				arg.replace(i, 1, 1, (c - 'a') + 'A');
		}
	}
	else if (cmd == "down")
	{
		for (size_t i=0; i<arg.length(); i++)
		{    
			char c = arg.data()[i];
			if ('A' <= c && c <= 'Z')
				arg.replace(i, 1, 1, (c - 'A') + 'a');
		}
	}
	else
	{
		std::cerr << "error" << std::endl;
		return "";
	}
	return arg;
}