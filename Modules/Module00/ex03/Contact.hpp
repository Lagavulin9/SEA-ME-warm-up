#pragma once
#ifndef __CONTACT_HPP__
# define __CONTACT_HPP__

# include <iostream>
# include <string>

# define RESET			"\033[0m"
# define BOLD			"\033[1m"
# define BLACK			"\033[30m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"

class Contact {
private:
	std::string	_name;
	std::string	_phoneNumber;
	std::string	_nickname;
	bool		_bookmarked;
public:
	Contact(std::string name,
			std::string phoneNumber,
			std::string nickname);
	~Contact();

	bool		isBookmarked();
	void		setBookmark();
	void		showDetails();

	friend		class Phonebook;
};

#endif
