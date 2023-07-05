#include "Contact.hpp"

Contact::Contact(std::string name,
				std::string phoneNumber,
				std::string nickname):
	_name(name),
	_phoneNumber(phoneNumber),
	_nickname(nickname),
	_bookmarked(false)
{}
Contact::~Contact(){};

bool	Contact::isBookmarked()
{
	return this->_bookmarked;
}

void	Contact::setBookmark()
{
	_bookmarked = true;
}

void	Contact::showDetails()
{
	std::cout << BOLD;
	std::cout << "Name: " << _name << std::endl;
	std::cout << "PhoneNumber: " << _phoneNumber << std::endl;
	std::cout << "NickName: " << _nickname << std::endl;
	std::cout << RESET;
}