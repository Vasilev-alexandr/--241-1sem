#pragma once
#include <memory>
#include <vector>
#include <chrono>
#include <iostream>
#include "Doctor.h"
#include "Patient.h"

/**
* @class Schedule
* @brief Класс для управления расписанием врачей и пациентов.
* Класс `Schedule` позволяет хранить информацию о врачах и пациентах, а также управлять
* расписанием, добавлять пациентов и врачей, а также выводить информацию о записях.
*/
class Schedule final : public std::enable_shared_from_this<Schedule> {
public:
    /**
    * @brief Статический метод для создания нового объекта расписания.
    * Этот метод предоставляет интерфейс для создания нового объекта `Schedule`. Он создает пустое расписание,
    * в котором пока нет пациентов и врачей.
    * @return Умный указатель на созданное расписание.
    */
    static std::shared_ptr<Schedule> CreateSchedule();

    /**
    * @brief Добавляет пациента в расписание.
    * Этот метод позволяет добавить пациента в расписание. Пациент будет добавлен в список
    * пациентов, который хранится в объекте расписания.
    * @param patient Умный указатель на объект пациента, который необходимо добавить.
    */
    void AddPatient(const std::shared_ptr<Patient>& patient, const std::chrono::system_clock::time_point& appointmentTime);

    /**
    * @brief Добавляет врача в расписание.
    * Этот метод позволяет добавить врача в расписание. Врач будет добавлен в список
    * врачей, который хранится в объекте расписания.
    * @param doctor Умный указатель на объект врача, которого необходимо добавить.
    */
    void AddDoctor(const std::shared_ptr<Doctor>& doctor,
        const std::chrono::system_clock::time_point& workStartTime,
        const std::chrono::system_clock::time_point& workEndTime);

    /**
    * @brief Выводит расписание пациентов и врачей.
    * Этот метод выводит в консоль сводную информацию о всех пациентах и врачах,
    * записанных в расписании. Для каждого пациента выводится информация о его имени
    * и времени записи, а для каждого врача — информация о его имени, специализации
    * и рабочем времени.
    */
    void PrintSchedule() const;

    /**
    * @brief Преобразует расписание в строковое представление.
    * Этот метод генерирует строковое представление всего расписания, включая информацию
    * о пациентах и врачах. Он используется для отображения всего расписания в текстовом
    * формате.
    * @return Строка, представляющая расписание с информацией о пациентах и врачах.
    */
    std::string ToString() const;

private:
    struct DoctorSchedule {
        std::shared_ptr<Doctor> doctor;
        std::chrono::system_clock::time_point workStartTime;
        std::chrono::system_clock::time_point workEndTime;
    };

    struct PatientSchedule {
        std::shared_ptr<Patient> patient;
        std::chrono::system_clock::time_point appointmentTime;
    };

    std::vector<DoctorSchedule> doctorSchedules;
    std::vector<PatientSchedule> patientSchedules;
    std::vector<std::shared_ptr<Patient>> patients;
    std::vector<std::shared_ptr<Doctor>> doctors;
};
