#include <iostream>
using namespace std;

const int MAX_EVENTS = 50;
const int MAX_PARTICIPANTS = 100;

class Participant {
private:
    string name;
    string email;

public:
    Participant() {}

    Participant(string n, string e) {
        name = n;
        email = e;
    }

    void display() const {
        cout << "   Name  : " << name << "\n";
        cout << "   Email : " << email << "\n";
    }
};

class Event {
private:
    string title;
    string date;
    string venue;
    Participant participants[MAX_PARTICIPANTS];
    int participantCount;

public:
    Event() { participantCount = 0; }

    Event(string t, string d, string v) {
        title = t;
        date = d;
        venue = v;
        participantCount = 0;
    }

    void addParticipant(string name, string email) {
        if (participantCount >= MAX_PARTICIPANTS) {
            cout << "Maximum participants reached!\n";
            return;
        }

        participants[participantCount] = Participant(name, email);
        participantCount++;

        cout << "Participant added successfully!\n";
    }

    string getTitle() const {
        return title;
    }

    void displayEvent() const {
        cout << "\n======================\n";
        cout << "Event: " << title << "\n";
        cout << "Date : " << date << "\n";
        cout << "Venue: " << venue << "\n";
        cout << "Participants: "<<participantCount<<"\n";

        if (participantCount == 0) {
            cout << "   No participants registered  \n";
        } else {
            for (int i = 0; i < participantCount; i++) {
                participants[i].display();
                cout << "\n";
            }
        }
        cout << "======================\\n";
    }
};

class Club {
private:
    string clubName;
    Event events[MAX_EVENTS];
    int eventCount;

public:
    Club(string name) {
        clubName = name;
        eventCount = 0;
    }

    void addEvent() {
        if (eventCount >= MAX_EVENTS) {
            cout << "Maximum number of events reached!\n";
            return;
        }

        string t, d, v;
        cout << "Enter Event Title: ";
        getline(cin, t);
        cout << "Enter Event Date (DD-MM-YYYY): ";
        getline(cin, d);
        cout << "Enter Venue: ";
        getline(cin, v);

        events[eventCount] = Event(t, d, v);
        eventCount++;

        cout << "Event added successfully!\n";
    }

    void listEvents() const {
        if (eventCount == 0) {
            cout << "No events as of now! \n";
            return;
        }

        cout << "\n=== Events for " << clubName << " ===\n";
        for (int i = 0; i < eventCount; i++) {
            cout << i + 1 << ". " << events[i].getTitle() << "\n";
        }
    }

    void addParticipantToEvent() {
        if (eventCount == 0) {
            cout << "No events to register! \n";
            return;
        }

        listEvents();
        cout << "Choose event number: ";
        int num;
        cin >> num;
        cin.ignore();

        if (num < 1 || num > eventCount) {
            cout << "Invalid Event Option...Please select the correct number\n";
            return;
        }

        string name, email;
        cout << "Enter Participant Name: ";
        getline(cin, name);
        cout << "Enter Email: ";
        getline(cin, email);

        events[num - 1].addParticipant(name, email);
    }

    void viewEventDetails() const {
        if (eventCount == 0) {
            cout << "No events available!\n";
            return;
        }

        listEvents();
        cout << "Enter event number to view details: ";
        int num;
        cin >> num;
        cin.ignore();

        if (num < 1 || num > eventCount) {
            cout << "Invalid Number Option...Please select the correct number\n";
            return;
        }

        events[num - 1].displayEvent();
    }
};

class EventManager {
private:
    Club club;

public:
    EventManager(string clubName) : club(clubName) {}

    void menu() {
        int choice;

        do {
            cout << "\n========== EVENT MANAGEMENT SYSTEM ==========\n";
            cout << "1. Add Event\n";
            cout << "2. List Events\n";
            cout << "3. Register Participant\n";
            cout << "4. View Event Details\n";
            cout << "5. Exit\n";
            cout<<"\n";
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();

            switch (choice) {
            case 1:
                club.addEvent();
                break;

            case 2:
                club.listEvents();
                break;

            case 3:
                club.addParticipantToEvent();
                break;

            case 4:
                club.viewEventDetails();
                break;

            case 5:
                cout << "Exiting system...\n";
                cout << "Thanks for visiting!\n";
                break;

            default:
                cout << "Invalid choice! Please select the correct option! \n";
            }

        } while (choice != 5);
    }
};

int main() {
    EventManager manager(" AI/ML CLUB ");
    manager.menu();
    return 0;
}
