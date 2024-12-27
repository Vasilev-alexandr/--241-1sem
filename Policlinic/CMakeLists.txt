cmake_minimum_required(VERSION 3.10)
project(Policlinic)

set(CMAKE_CXX_STANDARD 17)

# Укажите все исходные файлы
set(SOURCES
    main.cpp
    Doctor.cpp
    Patient.cpp
    Schedule.cpp
)

# Добавьте исполняемый файл
add_executable(Policlinic ${SOURCES})

# Укажите пути к заголовочным файлам
target_include_directories(Policlinic PRIVATE ${CMAKE_SOURCE_DIR})