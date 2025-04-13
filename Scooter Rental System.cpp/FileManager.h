#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "Scooter.h"
#include "Customer.h"
#include "LinkedList.h"
#include "Library.h"
using namespace std;

class FileManager 
{
private:
    static bool isNumber(const string& str) 
    {
        if (str.empty()) return false;
        {
            for (int i = 0; i < str.length(); i++) 
            {
                if (!isdigit(str[i])) return false;
            }
        }
        return true;
    }

    static int stringToInt(const string& str) 
    {
        int result = 0;
        for (int i = 0; i < str.length(); i++) 
        {
            result = result * 10 + (str[i] - '0');
        }
        return result;
    }

public:
    static void loadScooters(const string& filename, LinkedList<Scooter>& scooters) 
    {
        ifstream file(filename);
        string line;

        while (getline(file, line)) 
        {
            if (line.empty()) continue;

            size_t pos = 0;
            vector<string> tokens;
            while ((pos = line.find(',')) != string::npos) 
            {
                tokens.push_back(line.substr(0, pos));
                line.erase(0, pos + 1);
            }
            tokens.push_back(line);

            if (tokens.size() != 6) continue;

            if (!isNumber(tokens[0]) || !isNumber(tokens[2]) || !isNumber(tokens[3]) || !isNumber(tokens[4])) continue;

            int id = stringToInt(tokens[0]);
            string location = tokens[1];
            int status = stringToInt(tokens[2]);
            int battery = stringToInt(tokens[3]);
            int distance = stringToInt(tokens[4]);
            string date = tokens[5];

            scooters.add(Scooter(id, location, status, battery, distance, date));
        }

        file.close();
    }

    static void saveScooters(const string& filename, LinkedList<Scooter>& scooters) 
    {
        ofstream file(filename);
        Node<Scooter>* current = scooters.getHead();

        while (current) 
        {
            Scooter s = current->data;
            file << s.getId() << "," << s.getLocation() << "," << s.getStatus() << "," << s.getBatteryLevel() << "," << s.getDistance() << "," << s.getLastUsageDate() << "\n";
            current = current->next;
        }

        file.close();
    }

    static void loadCustomers(const string& filename, LinkedList<Customer>& customers) 
    {
        ifstream file(filename);
        string line;

        while (getline(file, line)) 
        {
            if (line.empty()) continue;

            size_t pos = 0;
            vector<string> tokens;
            while ((pos = line.find(',')) != string::npos) 
            {
                tokens.push_back(line.substr(0, pos));
                line.erase(0, pos + 1);
            }
            tokens.push_back(line);

            if (tokens.size() != 5) continue;

            if (!isNumber(tokens[0])) continue;
            int id = stringToInt(tokens[0]);
            string name = tokens[1];
            string phone = tokens[2];
            string email = tokens[3];
            string address = tokens[4];

            customers.add(Customer(id, name, phone, email, address));
        }

        file.close();
    }

    static void saveCustomers(const string& filename, LinkedList<Customer>& customers) 
    {
        ofstream file(filename);
        Node<Customer>* current = customers.getHead();

        while (current) {
            Customer c = current->data;
            file << c.getId() << "," << c.getNameSurname() << "," << c.getTelephone() << "," << c.getEmail() << "," << c.getaddres() << "\n";
            current = current->next;
        }

        file.close();
    }
};

#endif