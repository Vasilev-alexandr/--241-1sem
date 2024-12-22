#pragma once
#include <string>
#include <chrono>

/**
* @class Doctor
* @brief Класс, представляющий врача в системе.
* Этот класс инкапсулирует информацию о враче, включая его имя, специализацию и рабочее время.
* Он предоставляет методы для создания объектов типа `Doctor`, получения информации о враче и
* форматированного вывода данных о враче в виде строки.
*/
class Doctor {
public:
    /**
    * @brief Статический метод для создания нового объекта врача.
    * Данный метод используется для создания экземпляра объекта `Doctor`. Он предоставляет интерфейс для создания врача
    * с заданными параметрами (имя, специализация, время начала и окончания рабочего дня).
    * @param name Имя врача.
    * @param specialization Специализация врача (например, терапевт, кардиолог и т.д.).
    * @param workStartTime Время начала рабочего дня.
    * @param workEndTime Время окончания рабочего дня.
    * @return Умный указатель на созданный объект врача.
    */
    static std::shared_ptr<Doctor> CreateDoctor(const std::string& name, const std::string& specialization,
        const std::chrono::system_clock::time_point& workStartTime,
        const std::chrono::system_clock::time_point& workEndTime);

    /**
    * @brief Преобразует объект в строку с информацией о враче.
    * Данный метод предоставляет строковое представление объекта `Doctor`, включая имя, специализацию
    * и рабочие часы. Он используется для вывода данных о враче в удобочитаемом виде.
    * @return Строка с полными данными о враче.
    */
    std::string ToString() const;

    /**
    * @brief Получить имя врача.
    * Данный метод возвращает имя врача.
    * @return Имя врача.
    */
    const std::string& GetName() const;

    /**
    * @brief Получить специализацию врача.
    * Данный метод возвращает специализацию врача.
    * @return Специализация врача.
    */
    const std::string& GetSpecialization() const;

    /**
    * @brief Получить время начала рабочего дня врача.
    * Данный метод возвращает время начала рабочего дня врача в виде `std::chrono::system_clock::time_point`.
    * @return Время начала рабочего дня.
    */
    std::chrono::system_clock::time_point GetWorkStartTime() const;

    /**
    * @brief Получить время окончания рабочего дня врача.
    * Данный метод возвращает время окончания рабочего дня врача в виде `std::chrono::system_clock::time_point`.
    * @return Время окончания рабочего дня.
    */
    std::chrono::system_clock::time_point GetWorkEndTime() const;

    /**
    * @brief Форматированное строковое представление времени начала рабочего дня.
    * Данный метод используется для преобразования времени начала рабочего дня врача в строку,
    * которая представляется в формате "часы:минуты".
    * @return Время начала рабочего дня в формате "HH:MM".
    */
    std::string GetFormattedWorkStartTime() const;

    /**
    * @brief Форматированное строковое представление времени окончания рабочего дня.
    * Данный метод используется для преобразования времени окончания рабочего дня врача в строку,
    * которая представляется в формате "часы:минуты".
    * @return Время окончания рабочего дня в формате "HH:MM".
    */
    std::string GetFormattedWorkEndTime() const;

private:
    /**
    * @brief Конструктор для создания объекта `Doctor`.
    * Данный конструктор используется только внутри класса для создания экземпляров `Doctor`.
    * Все параметры необходимы для инициализации данных объекта.
    * @param name Имя врача.
    * @param specialization Специализация врача.
    * @param workStartTime Время начала рабочего дня.
    * @param workEndTime Время окончания рабочего дня.
    */
    Doctor(const std::string& name, const std::string& specialization,
        const std::chrono::system_clock::time_point& workStartTime,
        const std::chrono::system_clock::time_point& workEndTime);

    std::string name;
    std::string specialization;
    std::chrono::system_clock::time_point workStartTime;
    std::chrono::system_clock::time_point workEndTime;
};