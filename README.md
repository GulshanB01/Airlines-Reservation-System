---

# Airline Reservation System (Streamlit + C++)

A full-stack **Airline Reservation System** built using **Python with Streamlit** for a modern web interface and **C++** for core backend logic.
This hybrid application simulates a real-world flight booking system — enabling users to book/cancel tickets, select seats and meals, and manage reservations through an intuitive UI or command-line interface.

---

## Live Demo

**Try the app online:**
[Streamlit Web App](https://airlines-reservation-system-4gmyjmcyshx4oriyfroava.streamlit.app/)

---

## Web Application Preview (Python Streamlit)

* Book, cancel, and view reservations through a web interface
* Built with Python and Streamlit for interactive UI
* Uses Pandas to manage booking and passenger data
* Optional C++ backend included for offline or terminal use

---

## Key Features

### Python (Streamlit Version)

* Book and cancel tickets
* Visual seat layout (booked vs available)
* Select food preferences (Veg / Non-Veg / No Food)
* View all passengers in a tabular format
* Real-time updates with a responsive interface

### C++ Backend (Console Version)

* Built using object-oriented programming and linked lists
* Handles booking logic, seat allocation, and meal tracking
* Console-based UI ideal for understanding data structures

---

## Tech Stack

| Language | Tools & Libraries      |
| -------- | ---------------------- |
| Python   | Streamlit, Pandas      |
| C++      | Standard Library (STL) |
| Others   | Git, GitHub            |

---

## Feature Comparison

| Feature            | C++ Console App | Python Streamlit App |
| ------------------ | --------------- | -------------------- |
| Book Tickets       | Yes             | Yes                  |
| Cancel Reservation | Yes             | Yes                  |
| Modify Seats       | Yes             | Yes                  |
| User Interface     | Console-based   | Web-based            |
| Data Export (CSV)  | No              | Yes                  |

---

## How to Run the Project

### Running the Python Streamlit App

1. **Clone the repository**

   ```bash
   git clone https://github.com/AnushkaSontakke2005/airline-reservation-system.git
   cd airline-reservation-system/Python Version
   ```

2. **Install dependencies**

   ```bash
   pip install -r requirements.txt
   ```

3. **Launch the app**

   ```bash
   streamlit run ARSpy.py
   ```

---

### Compiling and Running the C++ Console App

1. **Navigate to the C++ directory**

   ```bash
   cd cpp
   ```

2. **Compile using `g++`**

   ```bash
   g++ main.cpp -o airline
   ```

3. **Run the compiled executable**

   ```bash
   ./airline
   ```

---

