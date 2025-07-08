#include <bits/stdc++.h>
using namespace std;

// Total seats available in the flight
const int MAX_SEATS = 100;
int seats[MAX_SEATS] = {0};
int next_reservation_id = 1001;
int cancelled_tickets = 0;
bool is_seat_taken = false;

class AirlineSystem {
public:
    public : 
	   AirlineSystem()
	   {
		  head = NULL;
	   }

    void reserveSeat();
    void cancelReservation();
    void updateSeat();
    void showPassenger();
    void showAllBookings();

private:
    struct Passenger {
        string firstName, lastName, ID, phone, mealPref;
        int seatNumber, reservationID;
        Passenger* next;
    };

    Passenger* head;
    Passenger* current;
    Passenger* previous;
};

AirlineSystem systemManager;

void suggestSeats(int seatChoice) {
    for (int i = 0; i < MAX_SEATS; i++) {
        if (seats[i] == -1 && i + 1 == seatChoice) {
            is_seat_taken = true;
            cout << "\nSeat already booked. Choose from available seats:\n";
            for (int j = 0; j < MAX_SEATS; j++) {
                if (seats[j] == 0)
                    cout << "|" << j + 1 << "| ";
                if ((j + 1) % 10 == 0) cout << endl;
            }
            break;
        }
    }
}

void AirlineSystem::reserveSeat() {
    current = new Passenger;
    cout << "Enter First Name: ";
    cin >> current->firstName;
    cout << "Enter Last Name: ";
    cin >> current->lastName;
    cout << "Enter ID: ";
    cin >> current->ID;
    cout << "Enter Phone Number: ";
    cin >> current->phone;

    int seatNum;
    do {
        cout << "Choose Seat Number (1-" << MAX_SEATS << "): ";
        cin >> seatNum;
        if (seatNum < 1 || seatNum > MAX_SEATS) {
            cout << "Invalid input. Try again.\n";
            continue;
        }
        if (seats[seatNum - 1] == -1)
            suggestSeats(seatNum);
        else
            is_seat_taken = false;

        seats[seatNum - 1] = -1;
        current->seatNumber = seatNum;
    } while (is_seat_taken);

    int foodOption;
    cout << "\nChoose Meal Preference:\n1. Veg\n2. Non-Veg\n3. No Food\nChoice: ";
    cin >> foodOption;
    while (foodOption < 1 || foodOption > 3) {
        cout << "Invalid choice. Choose again: ";
        cin >> foodOption;
    }
    current->mealPref = (foodOption == 1 ? "Veg" : foodOption == 2 ? "Non-Veg" : "No Food");

    current->reservationID = next_reservation_id++;
    current->next = nullptr;
    cout << "\nReservation Successful! Your reservation number: " << current->reservationID << endl;

    if (!head) head = current;
    else {
        Passenger* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = current;
    }
}

void AirlineSystem::cancelReservation() {
    int resID;
    cout << "Enter Reservation ID to cancel: ";
    cin >> resID;

    current = head;
    previous = head;

    while (current) {
        if (current->reservationID == resID) {
            if (current == head) {
                head = head->next;
                seats[current->seatNumber - 1] = 0;
            } else {
                previous->next = current->next;
                seats[current->seatNumber - 1] = 0;
            }
            delete current;
            cancelled_tickets++;
            cout << "Reservation Cancelled Successfully!\n";
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "Reservation ID not found.\n";
}

void AirlineSystem::updateSeat() {
    int currentSeat, newSeat;
    cout << "Enter Your Current Seat Number: ";
    cin >> currentSeat;

    current = head;
    while (current) {
        if (current->seatNumber == currentSeat) break;
        current = current->next;
    }

    cout << "Available seats:\n";
    for (int i = 0; i < MAX_SEATS; i++) {
        if (seats[i] == 0)
            cout << "|" << i + 1 << "| ";
        if ((i + 1) % 10 == 0) cout << endl;
    }
    cout << "Choose New Seat: ";
    cin >> newSeat;

    seats[current->seatNumber - 1] = 0;
    current->seatNumber = newSeat;
    seats[newSeat - 1] = -1;
    cout << "Seat Updated Successfully!\n";
}

void AirlineSystem::showPassenger() {
    int resID;
    cout << "Enter Reservation ID: ";
    cin >> resID;

    current = head;
    while (current) {
        if (current->reservationID == resID) {
            cout << "\n--- Passenger Details ---\n";
            cout << "Reservation ID: " << current->reservationID << "\n";
            cout << "Name: " << current->firstName << " " << current->lastName << "\n";
            cout << "ID: " << current->ID << "\nPhone: " << current->phone << "\n";
            cout << "Seat: " << current->seatNumber << "\nFood: " << current->mealPref << "\n";
            return;
        }
        current = current->next;
    }
    cout << "Reservation not found.\n";
}

void AirlineSystem::showAllBookings() {
    current = head;
    cout << "\n--- All Bookings ---\n";
    while (current) {
        cout << "Reservation ID: " << current->reservationID << ", Name: " << current->firstName << " " << current->lastName
             << ", Seat: " << current->seatNumber << ", Food: " << current->mealPref << endl;
        current = current->next;
    }
}

void displayMenu() {

    int choice;
    do {

        cout << "\n============================================\n";
        cout << "  Welcome to Indian Airline Booking System  \n";
        cout << "============================================\n";
        cout << "1. Book Ticket\n2. Cancel Ticket\n3. Change Seat\n4. View Passenger Details\n5. View All Bookings\n6. Exit\n";

        cout << "\nChoose an option: ";
        cin >> choice;
        system("CLS");
        switch (choice) {
            case 1: systemManager.reserveSeat(); break;
            case 2: systemManager.cancelReservation(); break;
            case 3: systemManager.updateSeat(); break;
            case 4: systemManager.showPassenger(); break;
            case 5: systemManager.showAllBookings(); break;
            case 6: exit(0);
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);
}

int main() {
    displayMenu();
    return 0;
}
