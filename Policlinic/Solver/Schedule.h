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
    static std::shared_ptr<Schedule> CreateSchedule(std::chrono::system_clock::time_point workStartTime, std::chrono::system_clock::time_point workEndTime);

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
    void AddDoctor(const std::shared_ptr<Doctor>& doctor);

    /**
    * @brief Преобразует расписание в строковое представление.
    * Этот метод генерирует строковое представление всего расписания, включая информацию
    * о пациентах и врачах. Он используется для отображения всего расписания в текстовом
    * формате.
    * @return Строка, представляющая расписание с информацией о пациентах и врачах.
    */
    std::string ToString() const;

private:
    Schedule(std::chrono::system_clock::time_point workStartTime, std::chrono::system_clock::time_point workEndTime);
    std::vector<std::shared_ptr<Patient>> patients;
    std::vector<std::shared_ptr<Doctor>> doctors;
    std::chrono::system_clock::time_point workStartTime;
    std::chrono::system_clock::time_point workEndTime;
};