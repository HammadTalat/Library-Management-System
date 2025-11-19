# Library Management System

A console-based Library Management System built in C++ for efficient management of library operations including book inventory, lending, returns, and treasury tracking.

---

## 📋 Problem / Objective

### Problem Statement
Traditional library management involves manual record-keeping, which is time-consuming, error-prone, and difficult to maintain. Tracking book availability, managing lending records, calculating fines, and maintaining treasury data requires an automated solution.

### Why This Project Was Created
This project was developed to:
- Automate library operations and reduce manual paperwork
- Provide a digital system for tracking book inventory and lending records
- Implement efficient search algorithms (binary search) for quick book retrieval
- Manage late return fines and library treasury automatically
- Create a user-friendly console interface for library staff
- Demonstrate practical application of data structures and file handling in C++

---

## 🛠️ Tech Stack / Tools Used

### Language
- **C++** (Standard C++11 or higher)

### Libraries & Headers
- `<iostream>` - Input/output operations
- `<fstream>` - File handling (reading/writing book and lending data)
- `<string>` - String manipulation
- `<conio.h>` - Console input/output (Windows-specific)
- `<dirent.h>` - Directory operations for file management
- `<windows.h>` (implicitly) - Console color manipulation and Windows API

### Development Tools
- **C++ Compiler** - MinGW/GCC or MSVC (Visual Studio)
- **Windows OS** - Required for `conio.h` and Windows-specific console functions
- **Text Editor/IDE** - Visual Studio, Code::Blocks, or any C++ IDE

### Data Storage
- **File-based storage** using `.txt` files
- Three main directories: `books/`, `lend/`, and `treasury/`
- CSV-like format for structured data storage

---

## ✨ Features

### Core Features
- **User Authentication System**
  - Sign up and login functionality
  - Credential storage in text files

- **Book Management**
  - Add new books with details (ISBN, title, author, publication date, quantity)
  - Delete books from inventory
  - Search books by title or ISBN using binary search algorithm
  - Display all available books in the library

- **Lending System**
  - Issue books to users with automatic date tracking
  - Record borrower information
  - Automatic quantity management
  - 7-day lending period

- **Return System**
  - Return books by title or ISBN
  - Late return detection
  - Automatic fine calculation (Rs. 1000 for late returns)
  - Quantity restoration upon return

- **Treasury Management**
  - Track library revenue from fines
  - View total treasury amount
  - Persistent storage of financial data

- **Data Persistence**
  - All data stored in text files
  - Automatic loading on startup
  - File-based directory structure for organization

### Additional Features
- **Color-coded console interface** for better user experience
- **Sorting algorithms** (bubble sort) for organizing book data
- **Binary search implementation** for efficient book retrieval
- **Input validation** to prevent errors
- **Menu-driven navigation** with looping options

---

## 🚀 How to Run the Project

### Prerequisites
- Windows Operating System (required for `conio.h` and Windows console functions)
- C++ Compiler (MinGW-w64, MSVC, or GCC)
- Command Prompt or PowerShell

### Installation Steps

#### 1. **Clone or Download the Project**
```bash
cd "c:\BS(SE) FAST\ALL_PROJECTS\1st_sem_Library_Management_System"
```

#### 2. **Create Required Directories**
Before running, create these folders in the project directory:
```bash
mkdir books
mkdir lend
mkdir treasury
```

#### 3. **Initialize Treasury File**
Create an initial treasury file:
```bash
echo 0 > treasury\treasury.txt
```

#### 4. **Compile the Program**

**Using MinGW (g++):**
```bash
g++ l227858_l227866_l227931_l227966_l227930.cpp -o LibraryManagementSystem.exe
```

**Using MSVC (Visual Studio Developer Command Prompt):**
```bash
cl l227858_l227866_l227931_l227966_l227930.cpp
```

#### 5. **Run the Program**
```bash
.\LibraryManagementSystem.exe
```

### First-Time Setup

1. **Sign Up**: Create an account when prompted
   - Enter a username
   - Enter a password
   - Credentials will be saved as `<username>.txt`

2. **Login**: Use your credentials to access the system

3. **Navigate the Menu**: Follow the console prompts to:
   - Add books (Option 1)
   - Search books (Option 2)
   - Lend books (Option 3)
   - Return books (Option 4)
   - Delete books (Option 5)
   - Check treasury (Option 6)
   - View available books (Option 7)
   - View lended books (Option 8)
   - Exit (Option 9)

### Important Notes
- **ISBN Requirements**: Must be more than 4 digits
- **Lending Period**: 7 days from issue date
- **Late Fine**: Rs. 1000 for late returns
- **Data Format**: Books and lending records are stored as comma-separated values in `.txt` files

### Troubleshooting
- **Compilation errors with `conio.h`**: This is Windows-specific. Ensure you're compiling on Windows.
- **Directory errors**: Make sure `books/`, `lend/`, and `treasury/` folders exist.
- **Missing files**: The program creates files automatically, but requires the directory structure.

---

## 📸 Sample Output / Screenshots

### Welcome Screen
```
*************************************************************
***************** Welcome to Our Library! *****************
*************************************************************

Please select your choice:
1. Sign up
2. Login
```

### Main Menu
```
*****************************************************
**************** Menu of the library ****************
*****************************************************

1. Add Book
2. Search Book
3. Lend Book
4. Return Book
5. Delete Book
6. Library Treasury
7. Show Available books
8. Show Lended books
9. Exit
```

### Book Search Result
```
<<Book found!>>

**********Found Book details are *************

       Title of book is                   : Introduction to Algorithms
     ISBN number of book is               : 97801
      Author of the book is               : Thomas Cormen
   Date of publication of book is         : 01/01/2009
Quantity of book availaible in library is : 5
```
