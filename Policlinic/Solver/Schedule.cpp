#include "Schedule.h"
#include <iostream>

std::string Schedule::getDateTime() const
{
    return dateTime;
}

void Schedule::setDateTime(const std::string& newDateTime)
{
    dateTime = newDateTime;
}

void Schedule::print() const
{
    std::cout << "Расписание: " << dateTime << std::endl;
}