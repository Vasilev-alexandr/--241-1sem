#pragma once
#include <vector>
#include <chrono>
#include <iostream>
#include "Patient.h"
#include "Doctor.h"
#include <sstream>

/**
* @class Doctor
* @brief Класс, представляющий врача в системе.
* Этот класс инкапсулирует информацию о враче, включая его имя, специализацию и рабочее время.
* Он предоставляет методы для создания объектов типа `Doctor`, получения информации о враче и
* форматированного вывода данных о враче в виде строки.
*/
class Doctor;

/**
* @class Patient
* @brief Класс, представляющий пациента, с информацией о его имени, возрасте и времени записи на прием.
* Класс `Patient` хранит данные о пациенте, такие как имя, возраст и время записи на прием.
* Он предоставляет методы для создания экземпляра пациента, получения информации о нем и форматирования времени записи.
*/
class Patient;

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
    * @param workStartTime Время начала работы.
    * @param workEndTime Время конца работы.
    * @return Умный указатель на созданное расписание.
    */
    static std::shared_ptr<Schedule> CreateSchedule(std::chrono::system_clock::time_point workStartTime, std::chrono::system_clock::time_point workEndTime);

    /**
    * @brief Добавляет пациента в расписание.
    * Этот метод позволяет добавить пациента в расписание. Пациент будет добавлен в список
    * пациентов, который хранится в объекте расписания.
    * @param patient Умный указатель на объект пациента, который необходимо добавить.
    * @return true Если пациент был добавлен.
    */
    bool AddPatient(const std::shared_ptr<Patient>& patient);

    /**
    * @brief Добавляет врача в расписание.
    * Этот метод позволяет добавить врача в расписание. Врач будет добавлен в список
    * врачей, который хранится в объекте расписания.
    * @param doctor Умный указатель на объект врача, которого необходимо добавить.
    * @return true Если доктор был добавлен.
    */
    bool AddDoctor(const std::shared_ptr<Doctor>& doctor);

    /**
    * @brief Преобразует расписание в строковое представление.
    * Этот метод генерирует строковое представление всего расписания, включая информацию
    * о пациентах и врачах. Он используется для отображения всего расписания в текстовом
    * формате.
    * @return Строка, представляющая расписание с информацией о пациентах и врачах.
    */
    std::string ToString() const;

private:
    /**
    * @brief Конструктор для создания расписания.
    * Конструктор доступен только внутри класса, чтобы объект мог быть создан только через статический метод `CreateSchedule`.
    * @param workStartTime Время начала работы.
    * @param workEndTime Время конца работы.
    */
    Schedule(std::chrono::system_clock::time_point workStartTime, std::chrono::system_clock::time_point workEndTime);

    /**
    * @brief Вектор указателей на пациентов.
    */
    std::vector<std::shared_ptr<Patient>> patients;

    /**
    * @brief Вектор указателей на докторов.
    */
    std::vector<std::shared_ptr<Doctor>> doctors;

    /**
    * @brief Время начала работы.
    */
    std::chrono::system_clock::time_point workStartTime;

    /**
    * @brief Время конца работы.
    */
    std::chrono::system_clock::time_point workEndTime;
};