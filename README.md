# Livestock Management

Livestock Management is a C++ application designed to manage livestock inventory efficiently. The application uses **Qt6** for the graphical user interface (GUI) and **SQLite** for data storage.

## Features
- Add, query, and update livestock records
- Track details such as:
  - Animal type
  - Features
  - Price
  - Ownership
  - Phone numbers
  - Payment methods
- Simple and intuitive interface

## Requirements
- **Qt6** (Core, Widgets, Sql modules)
- **CMake** (Version 3.10 or higher)
- **C++ Compiler** (with C++17 support)
- **SQLite**

## Installation

### Windows
1. Install **Qt6** and **CMake**.
2. Clone the repository:
   ```bash
   git clone https://github.com/emrahsahn/livestock_manager.git
   cd livestock_manager
   ```
3. Create a build directory and navigate to it:
   ```bash
   mkdir build
   cd build
   ```
4. Configure the project (with MinGW):
   ```bash
   cmake .. -G "MinGW Makefiles" -DCMAKE_PREFIX_PATH="C:/Qt/6.8.2/mingw_64"
   ```
   Or with MSVC:
   ```bash
   cmake ..
   ```
5. Build the project (with MinGW):
   ```bash
   mingw32-make
   ```
   Or with MSVC:
   ```bash
   cmake --build . --config Release
   ```
6. Run the application:
   ```bash
   .\LivestockManagement.exe
   ```

### Linux/macOS
1. Install **Qt6** and **CMake**.
2. Clone the repository:
   ```bash
   git clone https://github.com/emrahsahn/livestock_manager.git
   cd livestock_manager
   ```
3. Create a build directory and navigate to it:
   ```bash
   mkdir build
   cd build
   ```
4. Configure the project:
   ```bash
   cmake ..
   ```
5. Build the project:
   ```bash
   make
   ```
6. Run the application:
   ```bash
   ./LivestockManagement
   ```

## Usage
1. Launch the application
2. Use the buttons on the right side to perform various actions:
   - "Müşterileri Göster" (Show Customers) displays all livestock records
   - "Müşterileri Sorgula" (Query Customers) allows you to search for specific records
   - "Müşteri Ekle" (Add Customer) lets you add a new livestock record
3. Additional features:
   - Count the total number of records
   - Sum the prices of all livestock
   - Update existing records

## Application Interface
The application provides the following functionality:
- Display all livestock records
- Search records by animal number, owner, type, or phone number
- Add new livestock entries with detailed information
- Update existing records
- View summary statistics

## Contributing
Contributions are welcome! Please fork the repository and submit a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

**Author:** Emrah Şahin  
**Email:** sahinemrah3344@gmail.com  
**GitHub:** [emrahsahn](https://github.com/emrahsahn)  
**LinkedIn:** [Emrah Şahin](https://www.linkedin.com/in/emrah-şahin-788799253/)
