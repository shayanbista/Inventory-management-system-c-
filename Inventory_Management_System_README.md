
# Inventory Management System

## Overview

This is a C++ Inventory Management System that allows users to manage their inventory, including adding, updating, deleting, and viewing items. This system provides a command-line interface to interact with the program.

## Requirements

- C++ Compiler (e.g., `g++`)
- Python 3 (for running `run.py`)
- A Unix-like operating system (Linux, macOS, etc.) or Windows with a compatible environment (e.g., Git Bash, WSL)

## Setup Instructions

1. Clone this repository to your local machine:
    ```bash
    git clone <repository_url>
    cd inventory-management-system
    ```

2. Ensure you have the necessary dependencies for your system. If you're using a Linux distribution, you can install a C++ compiler like `g++`:
    ```bash
    sudo apt update
    sudo apt install build-essential
    ```

3. The `run.py` script is provided to manage the build, clean, and run processes. Ensure it is executable:
    ```bash
    chmod +x run.py
    ```

## Commands for Building and Running the Program

### 1. **Build the Project**

To compile the C++ project, use the `build` command:
```bash
python3 run.py build
```
This will compile your project and generate the necessary build files.

### 2. **Run the Compiled Program**

Once compiled, you can run the program using the `run` command:
```bash
python3 run.py run
```
This will execute the compiled program.

### 3. **Compile and Run in One Step**

To compile and run the program in one command, use the `build:run` command:
```bash
python3 run.py build:run
```
This command will compile the project and run the program immediately after the build process is complete.

### 4. **Clean the Build Directory**

To clean the build directory and remove all generated files, use the `clean` command:
```bash
python3 run.py clean
```
This is useful if you want to reset the build state and remove all compiled files.

### 5. **Build with Debug Symbols**

To build the project with debug symbols for easier debugging, use the `debug` command:
```bash
python3 run.py debug
```
This will include additional information in the compiled program to help with debugging.

## Project Structure

```
inventory-management-system/
│
├── build/                 # Build directory (generated during compilation)
├── include/               # Header files for the project
├── src/                   # Source files for the project
│   ├── main.cpp           # Main entry point for the program
│   └── inventory.cpp      # Inventory class implementation
│
├── run.py                 # Python script to manage build, run, clean, and debug
├── Makefile               # Optional Makefile for compilation (if needed)
└── README.md              # This file
```
