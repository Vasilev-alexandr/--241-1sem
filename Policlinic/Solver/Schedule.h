#pragma once
#include <string>
#include <iostream>

class Schedule {
public:

    std::string getDateTime() const;

    void setDateTime(const std::string& newDateTime);

    void print() const;

private:
    Schedule(const std::string& dateTime) : dateTime(dateTime) {}
    std::string dateTime; 
};