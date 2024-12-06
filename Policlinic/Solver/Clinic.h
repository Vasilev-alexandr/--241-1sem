#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Doctor.h"
#include "Patient.h"

class Clinic {

public:
    void addDoctor(const std::shared_ptr<Doctor> doctor);

    void addPatient(const std::shared_ptr<Patient> patient);

    void listDoctors() const;

    void listPatients() const;

    void showPatientAppointments(const std::string& patientName) const;

    void addAppointmentToPatient(const std::string& patientName, const std::string& doctorName);

private:
    std::vector<std::shared_ptr<Doctor>> doctors;
    std::vector<std::shared_ptr<Patient>> patients;
};