#include "Converter.hpp"

int main(int argc, char **argv)
{
	Converter converter;

	if (argc < 3)
		std::cerr << "Usage: ./convert up/down <string>" << std::endl;
	else
	{
		std::string to_convert;

		for (int i=2; i < argc; i++)
		{
			to_convert.append(argv[i]);
			if (i != argc - 1)
				to_convert.append(" ");
		}
		std::cout << converter.convert(argv[1], to_convert) << std::endl;
	}
}
