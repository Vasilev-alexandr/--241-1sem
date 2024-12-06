#pragma once
#include <string>
#include <vector>

class Patient {

public:
    Patient(const std::string& name, int age);

    std::string getName() const;

    int getAge() const;

    void addAppointment(const std::string& appointmentInfo);

    void printInfo() const;

    void printAppointments() const;

private:
    std::string name;
    int age;
    std::vector<std::string> appointments;
};