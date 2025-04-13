#ifndef SCOOTER_H
#define SCOOTER_H

#include "Library.h"
using namespace std;

class Scooter 
{
private:
    int id;
    string location;
    int status;
    int battery_level;
    int distance;
    string last_usage_date;

public:
    Scooter(int id, const string& location, int status, int battery_level, int distance, const string& last_usage_date)
        : id(id), location(location), status(status), battery_level(battery_level), distance(distance), last_usage_date(last_usage_date) {}

    int getId() const 
    { 
        return id; 
    }

    string getLocation() const 
    { 
        return location; 
    }
    int getStatus() const 
    { 
        return status; 
    }

    int getBatteryLevel() const 
    { 
        return battery_level; 
    }

    int getDistance() const 
    { 
        return distance; 
    }

    string getLastUsageDate() const 
    { 
        return last_usage_date; 
    }

    void rent() 
    { 
        status = 1; 
    }
    void returnScooter() 
    { 
        status = 0; 
    }

    void updateDetails(int new_status, int new_battery_level, int new_distance, const string& new_last_usage_date) 
    {
        status = new_status;
        battery_level = new_battery_level;
        distance = new_distance;
        last_usage_date = new_last_usage_date;
    }

    void display() const 
    {
        cout << "Scooter " << id << ": Location: " << location  << ", Status: " << (status == 0 ? "Available" : "Rented")  << ", Battery Level: " << battery_level << "%" << ", Distance: " << distance << " km" << ", Last Usage: " << last_usage_date << endl;
    }
};

#endif