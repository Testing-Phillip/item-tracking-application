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


#Questions:

# Project Reflection and Analysis

## 1. Project Summary and Problem Solved
This project, called the Corner Grocer Item Tracking Program, is a C++ application designed to help a grocery store figure out how many of each item are sold during the day. The program reads data from files and shows how often each item appears by listing frequencies, creating a simple histogram, and automatically backing up the data to a file. In short, it solves the problem of tracking product popularity, which helps the store decide on the best layout for its produce section.

## 2. What I Did Particularly Well
- **Modular Code:** I created an `ItemTracker` class to handle most of the tasks like loading data, searching for item frequencies, printing lists, and generating histograms. This made the code organized and easier to work with.
- **Input Validation:** I added checks to handle bad user inputs so the program doesn’t crash or behave unexpectedly.
- **Clear Documentation:** I made sure to include comments throughout the code to explain what each section does. This helps anyone reading the code understand it quickly.
- **Efficient Use of STL Maps:** Using STL maps for counting items made the frequency calculation both straightforward and efficient.

## 3. Areas for Enhancement
- **Improved Error Handling:** Although I added basic error checks, using exceptions could make the program more robust and easier to debug.
- **Performance Optimization:** For larger datasets, exploring more efficient data structures or even parallel processing could speed up data handling.
- **Enhanced Security:** More thorough input sanitization might prevent any potential security issues, especially in file handling.
- **User Interface Improvements:** Right now, the interface is text-based. A graphical user interface (GUI) or even just some color formatting could make the program more user-friendly.
- **Better Code Organization:** Splitting the code into separate files (like having separate header and source files for the class) would make the project more modular and maintainable.

## 4. Challenging Code Pieces and How I Overcame Them
- **Case-Insensitive Comparisons:** Handling different letter cases was tricky. I solved this by using the `transform` function to convert strings to lowercase before processing.
- **File I/O Management:** Managing multiple file streams (for reading different input files and writing the backup file) was challenging, but careful error checking and validating that files open properly helped me get through it.
- **Input Validation:** Making sure the program could handle unexpected user inputs without crashing took some trial and error. I used input stream checks and proper error clearing to handle this.
- **Resources:** I leaned on C++ STL documentation, online forums like Stack Overflow, and Visual Studio’s debugging tools to help overcome these challenges.

## 5. Transferable Skills to Other Projects
- **Object-Oriented Design:** Building the `ItemTracker` class improved my understanding of designing modular, reusable code, which is useful for any larger project.
- **Data Structures:** Using STL maps for frequency counting strengthened my skills in efficient data management, which applies to many other programming tasks.
- **File Handling:** Working with file input/output operations is a critical skill for projects that involve data persistence.
- **Error Handling:** Implementing input validation and error checking is key to writing secure and reliable software.
- **Code Documentation:** Writing clear comments and using consistent naming conventions makes the code more maintainable and easier to collaborate on.

## 6. Maintainability, Readability, and Adaptability
- **Structured Organization:** I broke the program into clear sections by using a dedicated class and functions, which makes the code easier to update and expand.
- **In-Line Comments:** Detailed comments throughout the code explain the logic and functionality, helping anyone who reads it to quickly understand the program.
- **Consistent Naming Conventions:** Using meaningful names for variables and functions ensures that the code is self-explanatory.
- **Scalability:** The design allows for future enhancements, like adding more features or even a GUI, without needing a major overhaul.
- **Automatic Backup Feature:** The program automatically creates a backup file, ensuring that data is preserved and can be recovered if needed.

---

