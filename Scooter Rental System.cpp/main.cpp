#include "ScooterRentalSystem.h"
#include "FileManager.h"
#include "Library.h"
using namespace std;

void showMenu() 
{
    cout << "-------------------------------------------------------\n";
    cout << "1. List Available Scooters\n";
    cout << "2. Rent a Scooter\n";
    cout << "3. Return a Scooter\n";
    cout << "4. View Customer Rental History\n";
    cout << "5. Register a New Scooter\n";
    cout << "6. Delete a Scooter\n";
    cout << "7. Update a Scooter\n";
    cout << "8. Register a New Customer\n";
    cout << "9. Delete a Customer\n";
    cout << "10. Update a Customer\n";
    cout << "11. Exit\n";
    cout << "-------------------------------------------------------\n";
}

int main() 
{
    ScooterRentalSystem system;

    FileManager::loadScooters("scooters.txt", system.getScooters());
    FileManager::loadCustomers("customers.txt", system.getCustomers());

    int choice;

    do 
    {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                system.listAvailableScooters();
                break;
            case 2: 
            {
                int scooterId, customerId;
                cout << "Enter Scooter ID: ";
                cin >> scooterId;
                cout << "Enter Customer ID: ";
                cin >> customerId;
                system.rentScooter(scooterId, customerId);
                break;
            }
            case 3: 
            {
                int scooterId;
                cout << "Enter Scooter ID: ";
                cin >> scooterId;
                system.returnScooter(scooterId);
                break;
            }
            case 4: 
            {
                int customerId;
                cout << "Enter Customer ID: ";
                cin >> customerId;
                system.viewCustomerHistory(customerId);
                break;
            }
            case 5: 
            {
                int id, status, battery, distance;
                string location, date;
                cout << "Enter Scooter ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Location: ";
                getline(cin, location);
                cout << "Enter Status (0 = Available, 1 = Rented): ";
                cin >> status;
                cout << "Enter Battery Level: ";
                cin >> battery;
                cout << "Enter Distance (km): ";
                cin >> distance;
                cin.ignore();
                cout << "Enter Last Usage Date: ";
                getline(cin, date);

                Scooter scooter(id, location, status, battery, distance, date);
                system.addScooter(scooter);
                break;
            }
            case 6: 
            {
                int id;
                cout << "Enter Scooter ID to delete: ";
                cin >> id;
                system.deleteScooter(id);
                break;
            }
            case 7: 
            {
                int id, status, battery, distance;
                string date;
                cout << "Enter Scooter ID: ";
                cin >> id;
                cout << "Enter New Status (0 = Available, 1 = Rented): ";
                cin >> status;
                cout << "Enter New Battery Level: ";
                cin >> battery;
                cout << "Enter New Distance: ";
                cin >> distance;
                cin.ignore();
                cout << "Enter New Last Usage Date: ";
                getline(cin, date);
                system.updateScooter(id, status, battery, distance, date);
                break;
            }
            case 8: 
            {
                int id;
                string name, phone, email, addres;
                cout << "Enter Customer ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Name Surname: ";
                getline(cin, name);
                cout << "Enter Phone: ";
                getline(cin, phone);
                cout << "Enter Email: ";
                getline(cin, email);
                cout << "Enter Addres: ";
                getline(cin, addres);

                Customer customer(id, name, phone, email, addres);
                system.registerCustomer(customer);
                break;
            }
            case 9: 
            {
                int id;
                cout << "Enter Customer ID to delete: ";
                cin >> id;
                system.deleteCustomer(id);
                break;
            }
            case 10: 
            {
                int id;
                string name, phone, email, addres;
                cout << "Enter Customer ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter New Name Surname: ";
                getline(cin, name);
                cout << "Enter New Phone: ";
                getline(cin, phone);
                cout << "Enter New Email: ";
                getline(cin, email);
                cout << "Enter New Addres: ";
                getline(cin, addres);
                system.updateCustomer(id, name, phone, email, addres);
                break;
            }
            case 11:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 11);


    FileManager::saveScooters("scooters.txt", system.getScooters());
    FileManager::saveCustomers("customers.txt", system.getCustomers());

    cout << "Program exited. Data saved.\n";
    return 0;
}
