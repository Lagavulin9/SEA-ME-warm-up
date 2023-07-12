#include "contact.h"

Contact::Contact(){};
Contact::~Contact(){};

Contact::Contact(const Contact& ref):
    name(ref.name),
    address(ref.address),
    email(ref.email),
    phonenumber(ref.phonenumber)
{}

QString Contact::getName() const
{
    return this->name;
};

QString Contact::getAddress() const
{
    return this->address;
}

QString Contact::getEmail() const
{
    return this->email;
}

QString Contact::getPhoneNumber() const
{
    return this->phonenumber;
}

void    Contact::setName(QString name)
{
    this->name = name;
}

void    Contact::setAddress(QString address)
{
    this->address = address;
}

void    Contact::setEmail(QString email)
{
    this->email = email;
}

void    Contact::setPhoneNumber(QString phonenumber)
{
    this->phonenumber = phonenumber;
}

bool    Contact::operator==(const Contact& other) const
{
    return (name == other.name && \
            address == other.address && \
            email == other.email && \
            phonenumber == other.phonenumber);
}

Contact&  Contact::operator=(const Contact& ref)
{
    name = ref.name;
    address = ref.address;
    email = ref.email;
    phonenumber = ref.phonenumber;
    return (*this);
}
