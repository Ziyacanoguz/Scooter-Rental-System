#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Library.h"
using namespace std;

class Customer 
{
private:
    int id;
    string name;
    string telephone;
    string email;
    string addres;

public:
    Customer(int id, const string& name, const string& telephone,const string& email, const string& addres)
        : id(id), name(name), telephone(telephone), email(email), addres(addres) {}
    int getId() const { return id; }
    string getNameSurname() const { return name; }
    string getTelephone() const { return telephone; }
    string getEmail() const { return email; }
    string getaddres() const { return addres; }

    void updateDetails(const string& new_name, const string& new_telephone,const string& new_email, const string& new_addres) 
    {
        name = new_name;
        telephone = new_telephone;
        email = new_email;
        addres = new_addres;
    }

    void display() const 
    { 
        cout << "Customer " << id << ": " << name << ", Phone: " << telephone << ", Email: " << email<< ", addres: " << addres << endl;
    }
};

#endif