#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Class for storing patient information
class Patient {
public:
    string name;
    int age;
    string disease;

    Patient(string n, int a, string d) {
        name = n;
        age = a;
        disease = d;
    }

    void displayPatientInfo() {
        cout << "Patient Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Disease: " << disease << "\n";
    }
};

// Class for storing doctor information
class Doctor {
public:
    string name;
    string specialization;

    Doctor(string n, string s) {
        name = n;
        specialization = s;
    }

    void displayDoctorInfo() {
        cout << "Doctor Name: " << name << "\n";
        cout << "Specialization: " << specialization << "\n";
    }
};

// Hospital Management System Class
class HospitalManagementSystem {
private:
    vector<Patient> patients;
    vector<Doctor> doctors;

public:
    void addPatient(string name, int age, string disease) {
        patients.push_back(Patient(name, age, disease));
        cout << "Patient added successfully!\n";
    }

    void addDoctor(string name, string specialization) {
        doctors.push_back(Doctor(name, specialization));
        cout << "Doctor added successfully!\n";
    }

    void displayPatients() {
        cout << "\nList of Patients:\n";
        for (int i = 0; i < patients.size(); i++) {
            cout << "\nPatient " << i + 1 << ":\n";
            patients[i].displayPatientInfo();
        }
    }

    void displayDoctors() {
        cout << "\nList of Doctors:\n";
        for (int i = 0; i < doctors.size(); i++) {
            cout << "\nDoctor " << i + 1 << ":\n";
            doctors[i].displayDoctorInfo();
        }
    }

    void assignDoctorToPatient(int patientIndex, int doctorIndex) {
        if (patientIndex < patients.size() && doctorIndex < doctors.size()) {
            cout << "\nDoctor " << doctors[doctorIndex].name 
                 << " is assigned to Patient " << patients[patientIndex].name << "\n";
        } else {
            cout << "Invalid Patient or Doctor index!\n";
        }
    }
};

int main() {
    HospitalManagementSystem hms;
    int choice;

    do {
        cout << "\n--- Hospital Management System Menu ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Add Doctor\n";
        cout << "3. Display Patients\n";
        cout << "4. Display Doctors\n";
        cout << "5. Assign Doctor to Patient\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name, disease;
            int age;
            cout << "Enter patient name: ";
            cin >> name;
            cout << "Enter patient age: ";
            cin >> age;
            cout << "Enter patient disease: ";
            cin >> disease;
            hms.addPatient(name, age, disease);
            break;
        }
        case 2: {
            string name, specialization;
            cout << "Enter doctor name: ";
            cin >> name;
            cout << "Enter doctor specialization: ";
            cin >> specialization;
            hms.addDoctor(name, specialization);
            break;
        }
        case 3:
            hms.displayPatients();
            break;
        case 4:
            hms.displayDoctors();
            break;
        case 5: {
            int patientIndex, doctorIndex;
            hms.displayPatients();
            cout << "Select patient by index: ";
            cin >> patientIndex;
            hms.displayDoctors();
            cout << "Select doctor by index: ";
            cin >> doctorIndex;
            hms.assignDoctorToPatient(patientIndex - 1, doctorIndex - 1);
            break;
        }
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
