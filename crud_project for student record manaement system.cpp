#include<iostream>
#include<fstream>
using namespace std;

class Student {

public:

    int id;
    string name;
    float marks;

    void input() {

        while(true) {

            cout << "\nEnter ID: ";
            cin >> id;

            if(cin.fail()) {

                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Enter integer type ID only\n";
            }
            else {
                break;
            }
        }

        cin.ignore();

        while(true) {

            cout << "Enter Name: ";
            getline(cin, name);

            bool valid = true;

            for(int j = 0; j < name.length(); j++) {

                if(!(isalpha(name[j]) || name[j] == ' ')) {

                    valid = false;
                    break;
                }
            }

            if(valid) break;
            else cout << "Name should contain letters only\n";
        }

        while(true) {

            cout << "Enter Marks: ";
            cin >> marks;

            if(cin.fail()) {

                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Enter numeric marks only\n";
            }
            else {
                break;
            }
        }
    }

    void display() {

        cout << "\nID: " << id;
        cout << "\nName: " << name;
        cout << "\nMarks: " << marks << endl;
    }

    void saveToFile() {

        ofstream file("students.txtt", ios::app);
        file << id << " " << name << " " << marks << endl;
        file.close();
    }
};

int main() {

    Student s[100];
    int count = 0;

    // ? LOAD DATA FROM FILE
    ifstream file("students.txtt");

    while(file >> s[count].id >> s[count].name >> s[count].marks) {
        count++;
    }

    file.close();

    while(true) {

        int choice;

        cout << "\n\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Update Student\n";
        cout << "4. Search Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        // ADD
        if(choice == 1) {

            cout << "Enter Student Data\n";

            s[count].input();
            s[count].saveToFile();

            count++;
        }

        // DISPLAY
        else if(choice == 2) {

            for(int i = 0; i < count; i++) {
                s[i].display();
            }
        }

        // UPDATE
        else if(choice == 3) {

            int updateId;
            bool found = false;

            cout << "Enter Student ID to Update: ";
            cin >> updateId;

            for(int i = 0; i < count; i++) {

                if(s[i].id == updateId) {

                    found = true;
                    cin.ignore();

                    while(true) {

                        cout << "Enter New Name: ";
                        getline(cin, s[i].name);

                        bool valid = true;

                        for(int j = 0; j < s[i].name.length(); j++) {

                            if(!(isalpha(s[i].name[j]) || s[i].name[j] == ' ')) {
                                valid = false;
                                break;
                            }
                        }

                        if(valid) break;
                        else cout << "Name should contain letters only\n";
                    }

                    while(true) {

                        cout << "Enter New Marks: ";
                        cin >> s[i].marks;

                        if(cin.fail()) {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            cout << "Enter numeric marks only\n";
                        }
                        else break;
                    }

                    cout << "Student Updated Successfully\n";
                    break;
                }
            }

            if(!found) cout << "Student Not Found\n";
        }

        // SEARCH
        else if(choice == 4) {

            int searchid;
            bool found = false;

            cout << "Enter ID to Search Record: ";
            cin >> searchid;

            for(int i = 0; i < count; i++) {

                if(s[i].id == searchid) {

                    cout << "\nRecord Found\n";
                    s[i].display();
                    found = true;
                    break;
                }
            }

            if(!found) cout << "Record Not Found\n";
        }

        // DELETE
        else if(choice == 5) {

            int deleteid;
            bool found = false;

            cout << "Enter ID to delete record: ";
            cin >> deleteid;

            for(int i = 0; i < count; i++) {

                if(s[i].id == deleteid) {

                    for(int j = i; j < count - 1; j++) {
                        s[j] = s[j + 1];
                    }

                    count--;
                    found = true;

                    cout << "Record Deleted Successfully\n";
                    break;
                }
            }

            if(!found) cout << "Record Not Found\n";
        }

        // EXIT
        else if(choice == 6) {

            cout << "Thanks for using our services\n";
            break;
        }

        else {
            cout << "Invalid Choice";
        }
    }

    return 0;
}
