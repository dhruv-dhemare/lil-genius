#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string Name;
    string Class;
    string Division;
    string DOB;
    string blood_grp;
    string address;
    string Mob_Number;
    string Driving_License;
    static int counter;

public:
    int Roll_No;
    Student() {
        this->counter++;
        this->Roll_No = this->counter;
    }

    Student(const Student &s1) {
        this->Name = s1.Name;
        this->Roll_No = ++counter;
        this->Class = s1.Class;
        this->Division = s1.Division;
        this->DOB = s1.DOB;
        this->blood_grp = s1.blood_grp;
        this->address = s1.address;
        this->Mob_Number = s1.Mob_Number;
        this->Driving_License = s1.Driving_License;
    }

    ~Student() {
        cout << "Student object " << this->Name << " destructed" << endl;
        this->counter--;
    }

    static int total_ppl() {
        return counter;
    }

    static Student* createStudent() {
        Student* NewStudent = new Student;
        cout << "Enter Student Name: ";
        cin >> NewStudent->Name;

        cout << "Enter Student Class: ";
        cin >> NewStudent->Class;

        cout << "Enter Student Division: ";
        cin >> NewStudent->Division;

        cout << "Enter Student DOB: ";
        cin >> NewStudent->DOB;

        cout << "Enter Student Blood Group: ";
        cin >> NewStudent->blood_grp;

        cout << "Enter Student Address: ";
        cin >> NewStudent->address;

        cout << "Enter Student Mobile Number: ";
        cin >> NewStudent->Mob_Number;

        cout << "Enter Student Driving License: ";
        cin >> NewStudent->Driving_License;

        return NewStudent;
    }

    static void deleteStudent(Student* deleteStudent) {
        delete deleteStudent;
    }

    void updateName(string NewName) {
        this->Name = NewName;
    }

    friend class Database;
};

int Student::counter = 0;

class Database {
    Student* database[100];
    int count;

public:
    Database() : count(0) {}

    void add_student(Student* student) {
        if (count < 100) {
            database[count++] = student;
        } else {
            cout << "Database is full." << endl;
        }
    }

    void delete_student(int index) {
        if (index >= 0 && index < count) {
            delete database[index];
            for (int i = index; i < count - 1; ++i) {
                database[i] = database[i + 1];
            }
            count--;
        } else {
            cout << "Invalid index." << endl;
        }
    }

    Student* get_student(int index) {
        if (index >= 0 && index < count) {
            return database[index];
        }
        return nullptr;
    }

    void updateName(Student* student, string NewName) {
        student->updateName(NewName);
    }

    void print() {
        cout << "----------------------------------" << endl;
        for (int i = 0; i < count; ++i) {
            Student* student = database[i];
            cout << "Name: " << student->Name << endl;
            cout << "Roll No: " << student->Roll_No << endl;
            cout << "Class: " << student->Class << endl;
            cout << "Division: " << student->Division << endl;
            cout << "DOB: " << student->DOB << endl;
            cout << "Blood Group: " << student->blood_grp << endl;
            cout << "Address: " << student->address << endl;
            cout << "Mobile Number: " << student->Mob_Number << endl;
            cout << "Driving License: " << student->Driving_License << endl;
            cout << "==================================="<<endl;
        }
        cout << "-----------------------------------" << endl;
    }

    int size() const {
        return count;
    }
};

void Menu() {
    Database database;
    while (true) {
        cout << "Choose an Operation:" << endl;
        cout << "Press 1 for Entering Student Data" << endl;
        cout << "Press 2 for Deleting Student Data" << endl;
        cout << "Press 3 for Updating Student Data" << endl;
        cout << "Press 4 to Print All Students" << endl;
        cout << "Press 0 to exit" << endl;
        int n;
        cin >> n;
        if (n == 1) {
            database.add_student(Student::createStudent());
            database.print();
        } else if (n == 2) {
            cout << "Enter the Roll number to delete: ";
            int rollNo;
            cin >> rollNo;
            bool found = false;
            for (int i = 0; i < database.size(); ++i) {
                if (database.get_student(i)->Roll_No == rollNo) {
                    database.delete_student(i);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Student with Roll Number " << rollNo << " not found." << endl;
            }
            database.print();
        } else if (n == 3) {
            cout << "Enter the Roll number to update: ";
            int rollNo;
            cin >> rollNo;
            bool found = false;
            for (int i = 0; i < database.size(); ++i) {
                if (database.get_student(i)->Roll_No == rollNo) {
                    cout << "Enter new name: ";
                    string newName;
                    cin >> newName;
                    database.updateName(database.get_student(i), newName);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Student with Roll Number " << rollNo << " not found." << endl;
            }
            database.print();
        } else if (n == 4) {
            database.print();
        } else if (n == 0) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

int main() {
    Menu();
    return 0;
}