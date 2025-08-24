cmake_minimum_required(VERSION 3.10)
project(LivestockManagement)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Try to find Qt6
find_package(Qt6 COMPONENTS Core Widgets Sql)

add_executable(LivestockManagement
    main.cpp
    livestock_management.cpp
    livestock_management.h
)

# Link with Qt6 if found
if (Qt6_FOUND)
    target_link_libraries(LivestockManagement
        Qt6::Core
        Qt6::Widgets
        Qt6::Sql
    )
else()
    message(FATAL_ERROR "Qt6 not found. Please install Qt6 or set CMAKE_PREFIX_PATH to Qt6 installation directory.")
endif()
