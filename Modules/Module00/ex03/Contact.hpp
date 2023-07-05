#pragma once
#ifndef __CONTACT_HPP__
# define __CONTACT_HPP__

# include <iostream>
# include <string>

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
