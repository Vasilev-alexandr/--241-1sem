#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Doctor.h"
#include "Patient.h"
#include "Schedule.h"

class Clinic final : public std::enable_shared_from_this<Clinic> {

public:
    void addDoctor(const std::shared_ptr<Doctor> doctor);

    void addPatient(const std::shared_ptr<Patient> patient);

    void listDoctors() const;

    void listPatients() const;

    void showPatientAppointments(const std::string& patientName) const;

    void addAppointmentToPatient(const std::string& patientName, std::shared_ptr<Schedule> schedule);

private:
    std::vector<std::shared_ptr<Doctor>> doctors;
    std::vector<std::shared_ptr<Patient>> patients;
};