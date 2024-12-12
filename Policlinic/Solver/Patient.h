#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Schedule.h"

class Patient {

public:

    std::string getName() const;

    int getAge() const;

    void addAppointment(std::shared_ptr<Schedule> appointment);

    void printInfo() const;
   
    void printAppointments() const;

private:
    Patient(const std::string& name, int age);
    std::string name;
    int age;
    std::vector<std::shared_ptr<Schedule>> appointments;
};