#include <iostream>
using namespace std;

const int MAX_SPECIALIZATION = 20;
const int MAX_QUEUE = 5;
string Names[MAX_SPECIALIZATION + 1][MAX_QUEUE + 1];
int Status[MAX_SPECIALIZATION + 1][MAX_QUEUE + 1];
int queue_length[MAX_SPECIALIZATION + 1];

int menu() {
    int choice = -1;
    while (choice == -1) {
        cout << "\nEnter your choice:\n";
        cout << "1) Add new patient\n";
        cout << "2) Print all patients\n";
        cout << "3) Get next patient\n";
        cout << "4) Exit\n";

        cin >> choice;

        if (!(1 <= choice && choice <= 4)) {
            cout << "Invalid choice. Try again\n";
            choice = -1;	// loop keep working
        }
    }
    return choice;
}

void shift_left(int specialization, string names_specialization[], int status_specialization[]) {
    int length = queue_length[specialization];
    for (int i = 0; i < length; i++) {
        names_specialization[i - 1] = Names[specialization][i];
        status_specialization[i - 1] = Status[specialization][i];
    }
    queue_length[specialization]--;
}

void shift_right(int specialization, string names_specialization[], int status_specialization[]) {
    int length = queue_length[specialization];
    for (int i = length - 1; i >= 0; --i) {
        names_specialization[i + 1] = names_specialization[i];
        status_specialization[i + 1] = status_specialization[i];
    }
    queue_length[specialization]++;
}

bool add_patient() {
    int specialization;
    string name;
    int status;

    cout<<"Enter specialization, name, status: ";
    cin>>specialization>>name>>status;

    int pos = queue_length[specialization];
    if (pos >= MAX_QUEUE) {
        cout<<"Sorry we can't add more patients for this specialization\n";
        return false;
    }

    if (status == 0) {
        Names[specialization][pos] = name;
        Status[specialization][pos] = status;
        queue_length[specialization]++;
    }
    else {
        shift_right(specialization, Names[specialization], Status[specialization]);
        Names[specialization][0] = name;
        Status[specialization][0] = status;
    }

    return true;
}

void print_patient(int specialization, string names_specialization[], int status_specialization[]) {
    int length = queue_length[specialization];
    if (length == 0) {
        return;
    }

    cout<<"There are "<<length<<" patients in specialization "<<specialization<<"\n";
    for (int i = 0; i < length; ++i) {
        cout<<names_specialization[i]<<"\t";
        if (status_specialization[i]) {
            cout<<"Urgent\n";
        }else {
            cout<<"Regular\n";
        }
    }
    cout<<"\n";
}

void print_patients() {
    cout<<"***************************\n";
    for (int specialization = 0; specialization < MAX_SPECIALIZATION; ++specialization) {
        print_patient(specialization, Names[specialization], Status[specialization]);
    }
}

void get_next_patients() {
    int specialization;
    cout<<"Enter specialization: ";
    cin>>specialization;

    int length = queue_length[specialization];
    if (length == 0) {
        cout<<"No patients at the moment, Have rest, Dr\n";
        return;
    }

    cout<<Names[specialization][0]<<" Please go with the Dr\n";
    shift_left(specialization, Names[specialization], Status[specialization]);
}

void hospital_system() {
    while (true) {
        int choice = menu();
        if (choice == 1) {
            add_patient();
        }else if (choice == 2) {
            print_patients();
        }else if (choice == 3) {
            get_next_patients();
        }else {
            break;
        }
    }
}

int main() {
    hospital_system();
    return 0;
}