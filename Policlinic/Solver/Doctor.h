#pragma once
#include <string>
#include <memory>
#include "Schedule.h"

/**
* @class Doctor
* @brief Класс, представляющий врача в системе.
* Этот класс инкапсулирует информацию о враче, включая его имя, специализацию и рабочее время.
* Он предоставляет методы для создания объектов типа `Doctor`, получения информации о враче и
* форматированного вывода данных о враче в виде строки.
*/
class Doctor final : public std::enable_shared_from_this<Doctor> {
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
    static std::shared_ptr<Doctor> CreateDoctor(const std::string& name, const std::string& specialization);

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

    std::weak_ptr<Schedule> schedule;
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
    Doctor(const std::string& name, const std::string& specialization);

    std::string name;
    std::string specialization;
    
};