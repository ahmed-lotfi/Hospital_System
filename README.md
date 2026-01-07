# Hospital System (C++)

A simple console-based hospital queue manager for multiple specializations. Patients can be added as Regular or Urgent, printed per specialization, and served in priority order.

## Overview
- Specializations: 20 (indexed 0–19)
- Queue size per specialization: 5 patients
- Priority: Urgent patients are placed at the front of the queue
- Menu actions:
  1. Add new patient
  2. Print all patients
  3. Get next patient
  4. Exit

Core logic lives in `main.cpp`. Build configuration is defined by `CMakeLists.txt`.

## Requirements
- CMake (the project currently declares `cmake_minimum_required(VERSION 4.1)`) 
  - If your CMake version is lower, you may adjust the minimum in `CMakeLists.txt` to match your installed version.
- A C++20 compiler (MSVC, GCC, or Clang)
- Windows, macOS, or Linux

## Build (Windows PowerShell)
```powershell
# From the project root
cmake -S . -B build
cmake --build build --config Release
```

On single-config generators (e.g., Ninja/Makefiles), omit `--config Release`:
```powershell
cmake --build build
```

## Run
- On Windows (MSVC multi-config):
```powershell
./build/Release/hospital_system.exe
```
- On Ninja/Makefiles:
```powershell
./build/hospital_system
```

## Usage
The program is interactive. Typical flows:

1) Add new patient
```
Enter specialization, name, status: 3 Alice 1
# status: 0 = Regular, 1 = Urgent
```

2) Print all patients
```
***************************
There are 2 patients in specialization 3
Alice	Urgent
Bob	Regular
```

3) Get next patient (serve from a specialization)
```
Enter specialization: 3
Alice Please go with the Dr
```

## Notes
- Specialization indices must be between 0 and 19.
- Each specialization queue holds up to 5 patients.
- Urgent patients (status = 1) are inserted at the front.

## Alternative: Build without CMake
```bash
g++ -std=c++20 -O2 -o hospital_system main.cpp
# Windows PowerShell equivalent:
# g++ -std=c++20 -O2 -o hospital_system.exe main.cpp
```

## Project Structure
```
CMakeLists.txt
main.cpp
cmake-build-debug/   # IDE-generated build artifacts (optional)
```

## Troubleshooting
- If configuration fails due to CMake version constraints, consider lowering `cmake_minimum_required` in `CMakeLists.txt` to match your installed CMake.
- If the executable path differs, check your generator:
  - MSVC multi-config: `build/Debug/` or `build/Release/`
  - Ninja/Makefiles: `build/` directly

## License
No license specified. Add one if you plan to share/distribute.
