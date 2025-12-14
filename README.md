#HOSTEL MANAGEMENT SYSTEM (HMS)

The Hostel Management System is a command-line application developed in C. 
It is designed to allow administrators to efficiently manage student records,
handle room assignments, and track fee status within a hostel or dormitory environment.

#Project Overview
The system provides a robust set of functionalities, storing persistent data in simple CSV files (students.csv and users.csv).

#Core Features

1.Authentication & Security: User registration, login, and an option to change passwords (data_entry.c, fees_security.c).
2.Student Management: Add, View All, Search, Edit, and Delete student records (data_entry.c, data_operations.c).
3.Financial Tracking: Mark student fees as Paid and generate a list of fee defaulters (fees_security.c).
4.Room Management: Assign rooms to students and check the occupancy/capacity of a specific room (room_management.c).

#Getting Started
#Prerequisites
The system is written in C and requires a standard C compiler (like GCC or Clang) to build and run.

#Local Development
The project is structured with multiple C source files and a header file for organization:
File Name,Purpose
main.c,Contains the main program loop and menu flow.

hostel.h,              Defines the Student and User data structures and all function prototypes.
data_entry.c,          "Implements authentication, adding students, and viewing all records."
data_operations.c,     "Implements searching, editing, and deleting student records."
fees_security.c,      "Handles fee updates, defaulter reports, and password changes."
room_management.c,    Handles room assignment and capacity checks.
students.csv,         "Data file for student records (Name, ID, Phone, Room, Fees)."
users.csv,            "Data file for system users (Username, Password)."

