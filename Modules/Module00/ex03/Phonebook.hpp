#pragma once
#ifndef __PHONEBOOK_HPP__
# define __PHONEBOOK_HPP__

# include "Contact.hpp"
# include <vector>
# include <iostream>
# include <string>
# include <sstream>
# include <cstdlib>
# include <iomanip>

class Phonebook {
private:
	std::vector<Contact>	_contacts;
	bool					isUnique(const std::string&);
	void					print();
	std::string				takeInput(const std::string&);
	int						takeIndexInput();
	void					pressEnter();
public:
	Phonebook();
	~Phonebook();

	void	ADD();
	void	SEARCH();
	void	REMOVE();
	void	BOOKMARK();
	void	EXIT();
};

#endif
