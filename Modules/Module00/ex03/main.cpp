#include "Phonebook.hpp"

int	main()
{
	Phonebook	phonebook;

	while (!std::cin.eof())
	{
		std::string	command;

		std::system("clear");
		std::cout << "Enter Command: ";
		std::cin >> command;
		if (command == "ADD")
			phonebook.ADD();
		else if (command == "SEARCH")
			phonebook.SEARCH();
		else if (command == "REMOVE")
			phonebook.REMOVE();
		else if (command == "BOOKMARK")
			phonebook.BOOKMARK();
		else if (command == "EXIT")
			phonebook.EXIT();
		else
		{
			std::cout << "Usage: ADD, SEARCH, REMOVE, BOOKMARK, EXIT" << std::endl;
			std::string	input;
			std::cout << "Press Enter to return...";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, input);
		}
			
	}
}