#include "Phonebook.hpp"

Phonebook::Phonebook(){};
Phonebook::~Phonebook(){};

void	Phonebook::ADD()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::string	name, phoneNumber, nickname;
	name = takeInput("Name: ");
	while(1)
	{
		phoneNumber = takeInput("PhoneNumber: ");
		if (!this->isUnique(phoneNumber))
			std::cout << "Phone number '" << BOLD << phoneNumber << RESET << "' is already registered!" << std::endl;
		else
			break;
	}
	nickname = takeInput("NickName: ");

	Contact	newContact(name, phoneNumber, nickname);
	this->_contacts.push_back(newContact);

	std::cout << "Contact added" << std::endl;

	this->pressEnter();
}

void	Phonebook::SEARCH()
{
	if (this->_contacts.empty())
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Phonebook is Empty!" << std::endl;
	}
	else
	{
		print();
		size_t index = this->takeIndexInput();
		_contacts[index].showDetails();
		std::string	input;
		std::cout << "Enter 'b' to bookmark, other keys to return: ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, input);
		if (input == "b")
		{
			_contacts[index].setBookmark();
			std::cout << "'" << BOLD << _contacts[index]._name << RESET << "' is added to your bookmark" << std::endl;
		}
		else
			return ;
	}
	this->pressEnter();
}

void	Phonebook::REMOVE()
{
	std::cout << "Which contact to remove?" << std::endl;
	this->print();
	size_t index = this->takeIndexInput();
	this->_contacts.erase(_contacts.begin() + index);
	std::cout << "Contact removed" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	this->pressEnter();
}

void	Phonebook::BOOKMARK()
{
	std::cout << "     Index |    Name    |  NickName  | PhoneNumber" << std::endl;
	for (size_t i=0; i < _contacts.size(); i++)
	{
		if (_contacts[i].isBookmarked())
		{
			std::cout << std::setw(10) << i;
			std::cout << " | ";
			std::cout << std::left;
			if (_contacts[i]._name.length() >= 10)
				std::cout << std::setw(9) << _contacts[i]._name.substr(0,9) << '.';
			else
				std::cout << std::setw(10) << _contacts[i]._name;
			std::cout << " | ";
			std::cout << std::left;
			if (_contacts[i]._nickname.length() >= 10)
				std::cout << std::setw(9) << _contacts[i]._nickname.substr(0,9) << '.';
			else
				std::cout << std::setw(10) << _contacts[i]._nickname;
			std::cout << " | ";
			std::cout << _contacts[i]._phoneNumber;
			std::cout << std::right << std::endl;
		}
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	this->pressEnter();
}

void	Phonebook::EXIT()
{
	std::cout << "Bye~" << std::endl;
	exit(0);
}

void	Phonebook::print()
{
	std::cout << "     Index | Name" << std::endl;
	for (size_t i=0; i < _contacts.size(); i++)
	{
		std::cout.width(10);
		std::cout << i << " | ";
		std::cout << _contacts[i]._name << std::endl;
	}
}

bool	Phonebook::isUnique(const std::string& toCheck)
{
	for (size_t i=0; i < _contacts.size(); i++)
	{
		if (toCheck == _contacts[i]._phoneNumber)
			return false;
	}
	return true;
}

std::string	Phonebook::takeInput(const std::string& msg)
{
	std::string	input;
	while (1)
	{
		std::cout << msg;
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(1);
		else if (input == "")
		{
			std::cout << RED << "Error" << RESET;
			std::cout <<  ": This field can't be Empty!" << std::endl;
		}
		else
			break;
	}
	return input;
}

int	Phonebook::takeIndexInput()
{
	std::string	input;

	while (1)
	{
		std::cout << "Enter Index: ";
		std::cin >> input;

		std::stringstream	ss(input);
		size_t				index;
		if (ss >> index && index < this->_contacts.size())
			return index;
		else
			std::cout << "Invalid input" << std::endl;
	}
}

void	Phonebook::pressEnter()
{
	std::string	input;
	std::cout << "Press ";
	std::cout << BOLD << "Enter";
	std::cout << RESET << " to return...";
	std::getline(std::cin, input);
}