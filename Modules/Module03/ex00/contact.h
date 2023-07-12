#ifndef CONTACT_H
#define CONTACT_H

#include <qstring.h>

class Contact
{
private:
    QString name;
    QString address;
    QString email;
    QString phonenumber;

public:
    Contact();
    Contact(const Contact&);
    ~Contact();

    bool operator==(const Contact &other) const;

    Contact& operator=(const Contact&);

    QString getName() const;
    QString getAddress() const;
    QString getEmail() const;
    QString getPhoneNumber() const;
    void    setName(QString name);
    void    setAddress(QString address);
    void    setEmail(QString email);
    void    setPhoneNumber(QString phonenumber);
};

#endif // CONTACT_H

