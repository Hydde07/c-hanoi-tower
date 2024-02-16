# C++ Tower of Hanoi Project

## Overview

This project implements the classic Tower of Hanoi puzzle in C++. The objective of the puzzle is to move a stack of disks from one rod to another, with the constraint that only one disk can be moved at a time and a larger disk cannot be placed on top of a smaller disk.

## Features

- **Implementation in C++:** The core logic of the Tower of Hanoi puzzle is implemented in `hanoi-tower.cpp`, making use of object-oriented programming principles.
- **Modular Code:** The project includes a header file `Mstack.ed.h` which likely contains definitions and helper functions used in the main implementation.
- **Executable File:** An executable file `hanoi-tower.exe` is provided for quick testing and demonstration on Windows systems.
- **Enhanced Terminal Interface:** Utilizes the `conio2` library for advanced terminal screen management, including text coloring and cursor positioning.

## Prerequisites

- C++ Compiler: To compile the source code, you will need a C++ compiler. The project was likely developed using GCC or MSVC.
- Visual Studio Code (optional): The project was developed using VS Code, which can be used for editing and debugging.
- `conio2` Library: For enhanced terminal interface features, the `conio2` library is required.

## Using conio2 for Enhanced Terminal Interface

This project utilizes the `conio2` library to manage the terminal screen, allowing for a more interactive and visually appealing user experience. `conio2` provides functionalities such as text coloring, cursor movement, and screen clearing, which enhance the overall presentation of the Tower of Hanoi puzzle.

### Downloading and Installing conio2

`conio2` is not included in the standard C++ libraries and needs to be downloaded and installed separately. Follow these steps to install `conio2`:

1. **Download the conio2 library:** You can find the `conio2` library from various online sources. A common repository for `conio2` can be found on GitHub or through community forums related to C/C++ development.
2. **Include the library in your project:** Once downloaded, place the `conio2` header file(s) in your project's include directory or alongside your project's source files. Ensure that your compiler knows where to find these files.
3. **Link against the conio2 library (if applicable):** If `conio2` comes with a library file (.lib or .a), you may need to link against it when compiling your project. This can be done by adding the appropriate flag to your compiler command, such as `-lconio2` for GCC.
4. **Update your source code (if necessary):** Include the `conio2` header at the beginning of your source file(s) using `#include "conio2.h"` or the appropriate path to the header file.

Please note that `conio2` is primarily designed for use on Windows systems. If you are using a different operating system, you might need to use alternative libraries or conditional compilation to ensure compatibility.

## Compilation and Execution

To compile the project, navigate to the project directory and use a C++ compiler to compile `hanoi-tower.cpp`. For example, using g++:

```bash
g++ hanoi-tower.cpp -o hanoi-tower
```

To run the program:

```bash
./hanoi-tower
```
