# Livestock Management

Livestock Management is a C++ application designed to manage livestock inventory efficiently. The application uses **Qt6** for the graphical user interface (GUI) and **SQLite** for data storage.

## Features
- Add, query, and update livestock records.
- Track details such as:
  - Animal type
  - Features
  - Price
  - Ownership
- Simple and intuitive interface.

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
   git clone https://github.com/emrahsahn/livestcok_manager.git
   cd livestcok_manager
   ```
3. Create a build directory and navigate to it:
   ```bash
   mkdir build
   cd build
   ```
4. Configure the project:
   ```bash
   cmake .. -G "MinGW Makefiles" -DCMAKE_PREFIX_PATH="C:/Qt/6.8.2/mingw_64"
   ```
5. Build the project:
   ```bash
   mingw32-make
   ```
6. Run the application:
   ```bash
   .\LivestockManagement.exe
   ```

### Linux/macOS
1. Install **Qt6** and **CMake**.
2. Clone the repository:
   ```bash
   git clone https://github.com/emrahsahn/livestcok_manager.git
   cd livestcok_manager
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
1. Launch the application.
2. Use the GUI to:
   - Add new livestock records.
   - Query existing records.
   - Update or delete records.
3. Explore additional features like counting records and summing prices.

## Contributing
Contributions are welcome! Please fork the repository and submit a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

**Author:** Emrah Şahin
