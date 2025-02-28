# Corner Grocer Item Tracking Program

## Overview
This C++ project implements an item-tracking application for the fictional Corner Grocer. The program analyzes text records that list items purchased throughout the day, providing key insights into purchase frequencies. These insights help optimize the layout of the produce section to better serve customer needs.

## Key Features
- **Search Functionality:**  
  Prompt users to input an item name and display its frequency from a purchase record file (`records.txt`).

- **Frequency Listing:**  
  Display a complete list of all items and their respective frequencies from the input file (`CS210_Project_Three_Input_File.txt`).

- **Histogram Display:**  
  Generate a text-based histogram where each item is represented by a series of asterisks that correspond to its frequency.

- **Dynamic Data Backup:**  
  Automatically create a backup file (`frequency.dat`) that stores the item frequencies, ensuring data persistence.

- **Robust Input Handling:**  
  Incorporates user input validation and error handling to provide a reliable and user-friendly experience.

- **Object-Oriented Design:**  
  Utilizes an `ItemTracker` class to encapsulate the core functionality and manage data using STL maps.

## Technical Details
- **Programming Language:** C++
- **Core Concepts:**  
  File I/O, STL maps, string manipulation, object-oriented programming, and input validation.
- **Documentation:**  
  The code is well-documented with in-line comments and follows industry-standard best practices to ensure clarity and maintainability.

## Project Structure
- `main.cpp`  
  Contains the main program loop and menu options for interacting with the application.
- `ItemTracker` class  
  Encapsulates the functionality for loading data, searching item frequencies, displaying frequency lists, printing histograms, and backing up data.
- Input Files:  
  - `records.txt` – Used for individual item frequency search.
  - `CS210_Project_Three_Input_File.txt` – Contains the complete list of purchased items.
- Output File:  
  - `frequency.dat` – Dynamically generated backup of the frequency data.

## Usage
1. **Compile the Project:**  
   Use your preferred C++ compiler to compile the project. For example:
   ```bash
   g++ -o CornerGrocer main.cpp
