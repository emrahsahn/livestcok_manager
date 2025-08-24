# Livestock Management Application

This is a C++ application for managing livestock inventory. It uses Qt for the GUI and SQLite for data storage.

## Features

- Add, query, and update livestock records
- Track details such as animal type, features, price, and ownership
- Simple and intuitive interface

## Requirements

- Qt 5.x
- CMake 3.10 or higher
- C++ compiler with C++14 support
- SQLite

## Building the Project

### Windows

1. Install Qt and CMake
2. Open a command prompt and navigate to the project directory
3. Create a build directory and navigate to it:
```
mkdir build
cd build
```
4. Generate the build files:
```
cmake ..
```
5. Build the project:
```
cmake --build .
```
6. Run the application:
```
.\Debug\LivestockManagement.exe
```

### Linux/macOS

1. Install Qt and CMake
2. Open a terminal and navigate to the project directory
3. Create a build directory and navigate to it:
```
mkdir build
cd build
```
4. Generate the build files:
```
cmake ..
```
5. Build the project:
```
make
```
6. Run the application:
```
./LivestockManagement
```

## Usage

1. Use the buttons on the right side of the application to perform various actions
2. "Müşterileri Göster" (Show Customers) displays all livestock records
3. "Müşterileri Sorgula" (Query Customers) allows you to search for specific records
4. "Müşteri Ekle" (Add Customer) lets you add a new livestock record
5. Other options allow for counting records, summing prices, and updating records

## License

This project is licensed under the MIT License.
