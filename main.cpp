#include <bits/stdc++.h>

#define endl "\n";
using namespace std;
int maxQueue = 10;
const int specializations_Number = 5;
string specializations_Names[specializations_Number] = {"Internal medicine", "General surgery", "Orthopedics",
                                                        "Emergency medicine",
                                                        "Radiology"};
vector<deque<string>> specialization_queue(6);
vector<pair<string, string>> Archive;

int menu() {
    int type = 0;
    while (!type) {
        cout << "\t\t\t\t\t" << "Enter Number Of Operation You Want To Do" << endl;
        cout << "\t\t\t" << "1) Add new patient" << endl;
        cout << "\t\t\t" << "2) Print all rows" << endl;
        cout << "\t\t\t" << "3) Get next patient" << endl;
        cout << "\t\t\t" << "4) print all old patients" << endl;
        cout << "\t\t\t" << "5) edit row capacity" << endl;
        cout << "\t\t\t" << "6) Exit" << endl;
        cin >> type;
        if (type < 1 || type > 6) {
            cout << "\t\t\t\t\tInvalid, Please Try Again" << endl;
            type = 0;
        }
    }
    return type;
}

void addPatient() {
    int target = 0;
    while (target < 1 || target > 5) {
        cout << "\t\t\t\t\t" << "Enter Number Of Specializations You Want" << endl;
        for (int i = 1; i <= specializations_Number; i++) {
            cout << "\t\t\t" << i << ") " << specializations_Names[i - 1] << endl;
        }
        cin >> target;
        if (target < 1 || target > 5) {
            cout << "\t\t\t\t\tInvalid, Please Try Again" << endl;
        }
    }
    cout << "\t\t\t\t\tEnter Patient Name" << endl;
    string name;
    cin >> name;
    int state = 0;
    while (state < 1 || state > 2) {
        cout << "\t\t\t\t\tIs it  a critical condition?" << endl;
        cout << "\t\t\t" << "1) Yes" << endl;
        cout << "\t\t\t" << "2) No" << endl;
        cin >> state;
        if (state < 1 || state > 5) {
            cout << "\t\t\t\t\tInvalid, Please Try Again" << endl;
        }
    }
    state %= 2;
    if (state) {
        specialization_queue[target].push_front(name);
    } else {
        specialization_queue[target].push_back(name);
    }

    cout << "\t\t\t\t\t" << "Patient Added Successfully" << endl;
}

void printRows() {
    for (int i = 1; i <= specializations_Number; i++) {
        cout << "\t\t\t\t\t" << i << ") " << specializations_Names[i - 1];
        cout << "\t\t" << (specialization_queue[i].size() * 100) / specializations_Number << "%" << endl;
        cout << "\t\t\t";
        for (auto j: specialization_queue[i])
            cout << j << " , ";
        cout << endl;
    }
}

void getNextPatient() {
    int target = 0;
    while (target < 1 || target > 5) {
        cout << "\t\t\t\t\t" << "Enter Number Of Specializations You Want" << endl;
        for (int i = 1; i <= specializations_Number; i++) {
            cout << "\t\t\t" << i << ") " << specializations_Names[i - 1] << endl;
        }
        cin >> target;
        if (target < 1 || target > 5) {
            cout << "\t\t\t\t\tInvalid, Please Try Again" << endl;
        }
    }
    if (specialization_queue[target].empty()) {
        cout << "\t\t\t\t\t" << "No patients at the moment. Have rest, DR" << endl;
        return;
    }
    string name = specialization_queue[target].front();
    cout << "\t\t\t" << name << "\tPlease Go To Your Specialization DR" << endl;
    specialization_queue[target].pop_front();
    Archive.push_back({name, specializations_Names[target - 1]});
}

void printArchive() {
    cout << "\t\t\t\t\t" << "Hospital Archive" << endl;
    for (int i = 0; i < Archive.size(); i++) {
        cout << "\t\t\t" << i + 1 << ") Name: " << Archive[i].first << " , specialization: " << Archive[i].second
             << endl;
    }
}

void addNewRooms() {
    int Count = 0;
    cout << "\t\t\t\t\t" << "Enter Number Of Rooms You Want To Add" << endl;
    cin >> Count;
    maxQueue += Count;
    cout << "\t\t\t\t\t" << "Rooms Added Successfully" << endl;
}

int main() {
    cout << "\t\t\t\t\tWelcome To Our Hospital System" << endl;
    bool running = true;
    while (running) {
        int choice = menu();
        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                printRows();
                break;
            case 3:
                getNextPatient();
                break;
            case 4:
                printArchive();
                break;
            case 5:
                addNewRooms();
                break;
            case 6:
                running = false;
                break;
            default:
                break;
        }
    }

    system("pause");
    return 0;
}
