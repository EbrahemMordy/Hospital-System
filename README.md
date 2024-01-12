# Hospital System Simulation

**Overview:**

This C++ console project simulates a basic hospital system with functionalities for managing patients, rooms, and specializations.

**Features:**

- `addPatient()`: Record name, specialization, and critical condition status.
- `printRows()`: Display specializations, patient queues, and occupancy percentages.
- `getNextPatient()`: Retrieve the next patient in line for a chosen specialization.
- `printArchive()`: List treated patients and their specializations.
- `addNewRooms()`: Add new rooms to increase overall hospital capacity.

**Usage:**

1. Compile project using a C++ compiler (e.g., GCC, Clang).
2. Run the executable file.
3. Follow console prompts to interact with the system.

**Dependencies:**

- C++ compiler

**Additional Information:**

- Data storage: Patient and room data in vectors of deques and pairs.
- Program structure: Functions for each feature, controlled by a main menu loop.
- Known issues:
    - No validation for patient name or age.
    - No patient discharge functionality.
    - No patient history or diagnoses tracking.
- Future plans:
    - Implement patient discharge.
    - Add patient search and history tracking.
    - Explore file I/O for data persistence.

**Code Structure:**

- `main()`: Handles menu loop and function calls.
- `menu()`: Displays menu and handles user input for feature selection.
- `addPatient()`: Prompts for patient information and adds them to the right specialization queue.
- `printRows()`: Displays information about all specializations and their patient queues.
- `getNextPatient()`: Retrieves the next patient from a selected specialization queue.
- `printArchive()`: Displays a list of all treated patients.
- `addNewRooms()`: Prompts for the number of new rooms and increases overall capacity.
