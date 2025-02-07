#include <iostream>
#include <vector>

using namespace std;


template <typename T>
class MemoryCalculate {
private:
    T id;
    string name;

public:
    
    MemoryCalculate(T id, string name) : id(id), name(name) {}

    
    void display() const {
        cout << "ID: " << id << ", Name: " << name << endl;
    }

    
    T getId() const { return id; }
    string getName() const { return name; }
};


class StudentManagement {
private:
    vector<MemoryCalculate<int>> students; 
    
public:
   
    void addStudent(int id, string name) {
        students.push_back(MemoryCalculate<int>(id, name));
        cout << "Student Added Successfully!\n";
    }

   
    void displayAllStudents() {
        if (students.empty()) {
            cout << "No students available!\n";
            return;
        }
        cout << "Student List:\n";
        for (const auto &student : students) {
            student.display();
        }
    }

   
    void removeStudent(int id) {
        for (size_t i = 0; i < students.size(); i++) {
            if (students[i].getId() == id) {
                students.erase(students.begin() + i);
                cout << "Student with ID " << id << " removed successfully!\n";
                return;
            }
        }
        cout << "Student with ID " << id << " not found!\n";
    }

   
    void searchStudent(int id) {
        for (const auto &student : students) {
            if (student.getId() == id) {
                cout << "Student Found:\n";
                student.display();
                return;
            }
        }
        cout << "Student with ID " << id << " not found!\n";
    }
};


int main() {
    StudentManagement sm;
    int choice, id;
    string name;

    do {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Remove Student by ID\n";
        cout << "4. Search Student by ID\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Student ID: ";
                cin >> id;
                cout << "Enter Student Name: ";
                cin.ignore();
                getline(cin, name);
                sm.addStudent(id, name);
                break;

            case 2:
                sm.displayAllStudents();
                break;

            case 3:
                cout << "Enter Student ID to Remove: ";
                cin >> id;
                sm.removeStudent(id);
                break;

            case 4:
                cout << "Enter Student ID to Search: ";
                cin >> id;
                sm.searchStudent(id);
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}