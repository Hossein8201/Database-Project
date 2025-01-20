# Final Project: Data Structure and Algorithm Design

## Project Overview
This project involves the design and implementation of a simple database system with the following capabilities:
- Creating and deleting tables.
- Adding, deleting, and updating records.
- Querying tables with optional sorting functionality.
- Indexing based on a primary key.

The system is implemented in **C programming language** without using any external libraries.

---

## Features
1. **Table Management:**
   - Create and delete tables with predefined structures.

2. **Record Operations:**
   - Add new records.
   - Delete existing records.
   - Update record values.

3. **Query Functionality:**
   - Select records based on specific criteria.
   - Optionally sort results in ascending order (if applicable).

4. **Indexing:**
   - Build a red-black tree index for efficient search operations.
   - Automatically update the index upon record modification.

---

## Requirements
- **Programming Language:** C
- **Data Structures:**
  - Doubly linked lists for record management.
  - Hash maps for table lookup.
  - Red-black trees for indexing.
- **Algorithm:** Merge sort for sorting queries.

**Note:** The use of external libraries is strictly prohibited.

---

## How to Run
1. Clone or download the project files.
2. Ensure you have a C compiler installed (e.g., GCC).
3. Compile the code:
   ```bash
   gcc -o database_system .\main.c .\functions\*.c 
   ```
4. Run the program:
   ```bash
   .\database_system.exe
   ```
5. Interact with the program using the following commands:
   - `CREATE TABLE <table_name>`
   - `DELETE TABLE <table_name>`
   - `ADD <table_name> <column_name> <value> ...`
   - `DELETE <table_name> <column_name> <value>`
   - `UPDATE <table_name> <column_name> <value> <new_value>`
   - `SELECT <table_name> <column_name> <value> [SORTED]`

---

## Data Structures Used
1. **Doubly Linked List:**
   - Used for managing records in each table.

2. **Hash Map:**
   - Keeps track of all created tables.

3. **Red-Black Tree:**
   - Indexes records based on the primary key.

---

## Implementation Details
1. **Table Structure:**
   Each table has a predefined structure with the following fields:
   - `Student Number`: Unique integer key.
   - `General Course Name`: String (max 32 characters).
   - `General Course Instructor`: String (max 32 characters).
   - `General Course Score`: Integer (0-20).
   - `Core Course Name`: String (max 32 characters).
   - `Core Course Instructor`: String (max 32 characters).
   - `Core Course Score`: Integer (0-20).

2. **Commands:**
   - **CREATE/DELETE TABLE:** Create or remove tables.
   - **ADD:** Insert new records into a table.
   - **DELETE:** Remove records based on specific conditions.
   - **UPDATE:** Modify existing records.
   - **SELECT:** Query records with optional sorting.

---

## Acknowledgments
Special thanks to our course instructors and teaching assistants for their guidance throughout the project.

