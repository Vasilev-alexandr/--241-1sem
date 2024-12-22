#pragma once
#include <string>
#include <chrono>
#include <memory>

/**
* @class Patient
* @brief Класс, представляющий пациента, с информацией о его имени, возрасте и времени записи на прием.
* Класс `Patient` хранит данные о пациенте, такие как имя, возраст и время записи на прием.
* Он предоставляет методы для создания экземпляра пациента, получения информации о нем и форматирования времени записи.
*/
class Patient {
public:
    /**
    * @brief Статический метод для создания нового объекта пациента.
    * Данный метод используется для создания экземпляра объекта `Patient`. Он предоставляет интерфейс для создания пациента
    * с заданными параметрами (имя, возраст, время записи).
    * @param name Имя пациента.
    * @param age Возраст пациента.
    * @param appointmentTime Время записи на прием.
    * @return Умный указатель на созданный объект пациента.
    */
    static std::shared_ptr<Patient> CreatePatient(const std::string& name, int age, const std::chrono::system_clock::time_point& appointmentTime);

    /**
    * @brief Метод для получения строкового представления пациента.
    * Этот метод формирует строку с информацией о пациенте, включая имя, возраст и отформатированное время записи.
    * @return Строка, содержащая информацию о пациенте.
    */
    std::string ToString() const;

    /**
    * @brief Геттер для получения имени пациента.
    * Этот метод возвращает имя пациента.
    * @return Строка с именем пациента.
    */
    const std::string& GetName() const;

    /**
    * @brief Геттер для получения возраста пациента.
    * Этот метод возвращает возраст пациента.
    * @return Возраст пациента.
    */
    int GetAge() const;

    /**
    * @brief Геттер для получения времени записи пациента.
    * Этот метод возвращает время записи пациента на прием.
    * @return Время записи пациента.
    */
    std::chrono::system_clock::time_point GetAppointmentTime() const;

    /**
    * @brief Метод для получения отформатированного времени записи на прием.
    * Этот метод форматирует время записи пациента в строковый формат.
    * @return Строка с отформатированным временем записи.
    */
    std::string GetFormattedAppointmentDate() const;

private:
    /**
     * @brief Конструктор для создания экземпляра пациента.
     * Конструктор доступен только внутри класса, чтобы объект мог быть создан только через статический метод `CreatePatient`.
     * @param name Имя пациента.
     * @param age Возраст пациента.
     * @param appointmentTime Время записи на прием.
     */
    Patient(const std::string& name, int age, const std::chrono::system_clock::time_point& appointmentTime);
    std::string name;
    int age;
    std::chrono::system_clock::time_point appointmentTime;
};
