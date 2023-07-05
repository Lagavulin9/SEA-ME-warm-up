#include "Phonebook.hpp"

Phonebook::Phonebook(){};
Phonebook::~Phonebook(){};

void	Phonebook::ADD()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::string	name, phoneNumber, nickname;
	name = takeInput("Enter Name: ");
	while(1)
	{
		// std::cout << "Enter PhoneNumber: ";
		// std::cin >> phoneNumber;
		phoneNumber = takeInput("Enter PhoneNumber: ");
		if (!this->isUnique(phoneNumber))
			std::cout << "Phone number '" << phoneNumber << "' is already registered!" << std::endl;
		else
			break;
	}
	nickname = takeInput("Enter NickName: ");

	Contact	newContact(name, phoneNumber, nickname);
	this->_contacts.push_back(newContact);

	std::cout << "Contact added" << std::endl;

	this->pressEnter();
}

void	Phonebook::SEARCH()
{
	if (this->_contacts.empty())
		std::cout << "Phonebook is Empty!" << std::endl;
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
			std::cout << "'" << _contacts[index]._name << "' is added to your bookmark" << std::endl;
		}
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
	std::cout << "Index | Name | PhoneNumber | NickName" << std::endl;
	for (size_t i=0; i < _contacts.size(); i++)
	{
		if (_contacts[i].isBookmarked())
		{
			std::cout.width(5);
			std::cout << i << " | ";
			std::cout << _contacts[i]._name << " | ";
			std::cout << _contacts[i]._phoneNumber << " | ";
			std::cout << _contacts[i]._nickname << std::endl;
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
	std::cout << "Index | Name" << std::endl;
	for (size_t i=0; i < _contacts.size(); i++)
	{
		std::cout.width(5);
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
			std::cout << "Error: This field canoot be an empty field" << std::endl;
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
	std::cout << "Press Enter to return...";
	std::getline(std::cin, input);
}