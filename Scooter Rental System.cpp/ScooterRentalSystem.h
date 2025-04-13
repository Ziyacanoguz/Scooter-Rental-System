#ifndef SCOOTER_RENTAL_SYSTEM_H
#define SCOOTER_RENTAL_SYSTEM_H

#include "Scooter.h"
#include "Customer.h"
#include "LinkedList.h"
#include "Library.h"
using namespace std;

class ScooterRentalSystem 
{
private:
    LinkedList<Scooter> scooters;
    LinkedList<Customer> customers;

public:
    void addScooter(const Scooter& scooter) 
    {
        scooters.add(scooter);
        cout << "Scooter has been added successfully.\n";
    }

    void listAvailableScooters() const 
    {
        cout << "Available Scooters:\n";
        Node<Scooter>* current = scooters.getHead();
        while (current) 
        {
            if (current->data.getStatus() == 0)
                current->data.display();
            current = current->next;
        }
    }

    void rentScooter(int scooterId, int customerId) 
    {
        Scooter* scooter = scooters.find(scooterId);
        Customer* customer = customers.find(customerId);

        if (!scooter || !customer) 
        {
            cout << "Invalid Scooter or Customer ID.\n";
            return;
        }

        if (scooter->getStatus() == 1) 
        {
            cout << "Scooter is already rented.\n";
            return;
        }

        cout << "Renting scooter " << scooterId << " to customer " << customerId << "...\n";
        scooter->rent();
        cout << "Scooter " << scooterId << " has been rented to customer " << customerId << ".\n";
    }

    void returnScooter(int scooterId) 
    {
        Scooter* scooter = scooters.find(scooterId);
        if (!scooter) 
        {
            cout << "Scooter not found.\n";
            return;
        }

        cout << "Returning scooter " << scooterId << "...\n";
        scooter->returnScooter();
        cout << "Scooter " << scooterId << " has been returned and is now available.\n";
    }

    void deleteScooter(int scooterId) 
    {
        cout << "Deleting scooter " << scooterId << "...\n";
        if (scooters.remove(scooterId))
        {
            cout << "Scooter " << scooterId << " has been deleted from the system.\n";
        }    
        else
        {
            cout << "Scooter not found.\n";
        }
    }

    void updateScooter(int scooterId, int status, int battery_level, int distance, const string& date) {
        Scooter* scooter = scooters.find(scooterId);
        if (!scooter) 
        {
            cout << "Scooter not found.\n";
            return;
        }

        scooter->updateDetails(status, battery_level, distance, date);
        cout << "Scooter " << scooterId << "'s details have been updated successfully.\n";
    }

    void registerCustomer(const Customer& customer) 
    {
        customers.add(customer);
        cout << "Customer has been added successfully.\n";
    }

    void deleteCustomer(int customerId) 
    {
        cout << "Deleting customer " << customerId << "...\n";
        if (customers.remove(customerId))
        {
            cout << "Customer " << customerId << " has been deleted from the system.\n";
        }
        else
        {
            cout << "Customer not found.\n";
        }
    }

    void updateCustomer(int customerId, const string& name_surname,const string& telephone, const string& email, const string& addres)
    {
        Customer* customer = customers.find(customerId);
        if (!customer) 
        {
            cout << "Customer not found.\n";
            return;
        }

        customer->updateDetails(name_surname, telephone, email, addres);
        cout << "Customer " << customerId << " details have been updated successfully.\n";
    }

    void viewCustomerHistory(int customerId) 
    {
        Customer* customer = customers.find(customerId);
        if (!customer) 
        {
            cout << "Customer not found.\n";
            return;
        }

        cout << "Customer " << customerId << " Rental History:\n";
        Node<Scooter>* current = scooters.getHead();
        while (current) 
        {
            if (current->data.getStatus() == 1) 
            {
                current->data.display();
            }
            current = current->next;
        }
    }

    LinkedList<Scooter>& getScooters() 
    { 
        return scooters; 
    }
    LinkedList<Customer>& getCustomers() 
    { 
        return customers; 
    }
};

#endif