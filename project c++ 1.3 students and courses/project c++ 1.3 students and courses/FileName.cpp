#include <iostream>
#include <string>
using namespace std;

// √ﬁ’Ï ⁄œœ ··ÿ·«» Ê«·ﬂÊ—”« 
const int MAX_STUDENTS = 120;
const int MAX_COURSES = 12;
const int MAX_COURSES_PER_STUDENT = 5;

//  ⁄—Ì› ÂÌﬂ· «·ﬂÊ—”
struct Course {
    string name;
    string code;
    int creditHours;
};

//  ⁄—Ì› ÂÌﬂ· «·ÿ«·»
struct Student {
    string name;
    int id;
    int level;
    string group;
    float gpa;
    string courseCodes[MAX_COURSES_PER_STUDENT];
    float degrees[MAX_COURSES_PER_STUDENT];
};

// „’›Ê›«  «·ÿ·«» Ê«·ﬂÊ—”« 
Student students[MAX_STUDENTS];
Course courses[MAX_COURSES];
int studentCount = 0;
int courseCount = 0;

//  —Ã⁄ index «·ÿ«·» »‰«¡ ⁄·Ï «·‹ ID
int findStudentIndexById(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id)
            return i;
    }
    return -1;
}

//  —Ã⁄ index «·ﬂÊ—” »‰«¡ ⁄·Ï «·ﬂÊœ
int findCourseIndexByCode(string code) {
    for (int i = 0; i < courseCount; i++) {
        if (courses[i].code == code)
            return i;
    }
    return -1;
}

// ≈÷«›… ÿ«·» ÃœÌœ
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Student list is full!\n";
        return;
    }

    Student s;
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, s.name);

    cout << "Enter student ID: ";
    cin >> s.id;

    if (findStudentIndexById(s.id) != -1) {
        cout << "Student with this ID already exists.\n";
        return;
    }

    cout << "Enter level (1 to 4): ";
    cin >> s.level;

    cout << "Enter group: ";
    cin >> s.group;

    cout << "Enter GPA: ";
    cin >> s.gpa;

    for (int i = 0; i < MAX_COURSES_PER_STUDENT; i++) {
        s.courseCodes[i] = "";
        s.degrees[i] = 0;
    }

    students[studentCount++] = s;
    cout << "Student added successfully.\n";
}

//  ⁄œÌ· »Ì«‰«  ÿ«·»
void updateStudent() {
    int id;
    cout << "Enter student ID to update: ";
    cin >> id;

    int index = findStudentIndexById(id);
    if (index == -1) {
        cout << "Student not found.\n";
        return;
    }

    cout << "Enter new name: ";
    cin.ignore();
    getline(cin, students[index].name);

    cout << "Enter new level: ";
    cin >> students[index].level;

    cout << "Enter new group: ";
    cin >> students[index].group;

    cout << "Enter new GPA: ";
    cin >> students[index].gpa;

    cout << "Student updated successfully.\n";
}

// Õ–› ÿ«·»
void deleteStudent() {
    int id;
    cout << "Enter student ID to delete: ";
    cin >> id;

    int index = findStudentIndexById(id);
    if (index == -1) {
        cout << "Student not found.\n";
        return;
    }

    for (int i = index; i < studentCount - 1; i++) {
        students[i] = students[i + 1];
    }

    studentCount--;
    cout << "Student deleted successfully.\n";
}

// ≈÷«›… ﬂÊ—” ÃœÌœ
void addCourse() {
    if (courseCount >= MAX_COURSES) {
        cout << "Course list is full!\n";
        return;
    }

    Course c;
    cout << "Enter course name: ";
    cin.ignore();
    getline(cin, c.name);

    cout << "Enter course code: ";
    cin >> c.code;

    cout << "Enter credit hours: ";
    cin >> c.creditHours;

    courses[courseCount++] = c;
    cout << "Course added successfully.\n";
}

//  ⁄œÌ· »Ì«‰«  ﬂÊ—”
void updateCourse() {
    string code;
    cout << "Enter course code to update: ";
    cin >> code;

    int index = findCourseIndexByCode(code);
    if (index == -1) {
        cout << "Course not found.\n";
        return;
    }

    cout << "Enter new name: ";
    cin.ignore();
    getline(cin, courses[index].name);

    cout << "Enter new credit hours: ";
    cin >> courses[index].creditHours;

    cout << "Course updated successfully.\n";
}

// Õ–› ﬂÊ—”
void deleteCourse() {
    string code;
    cout << "Enter course code to delete: ";
    cin >> code;

    int index = findCourseIndexByCode(code);
    if (index == -1) {
        cout << "Course not found.\n";
        return;
    }

    for (int i = index; i < courseCount - 1; i++) {
        courses[i] = courses[i + 1];
    }

    courseCount--;
    cout << "Course deleted successfully.\n";
}

// ≈÷«›… ﬂÊ—” ·ÿ«·»
void assignCourseToStudent() {
    int id;
    cout << "Enter student ID: ";
    cin >> id;

    int sIndex = findStudentIndexById(id);
    if (sIndex == -1) {
        cout << "Student not found.\n";
        return;
    }

    string code;
    cout << "Enter course code: ";
    cin >> code;

    int cIndex = findCourseIndexByCode(code);
    if (cIndex == -1) {
        cout << "Course not found.\n";
        return;
    }

    float deg;
    cout << "Enter degree: ";
    cin >> deg;

    for (int i = 0; i < MAX_COURSES_PER_STUDENT; i++) {
        if (students[sIndex].courseCodes[i] == "") {
            students[sIndex].courseCodes[i] = code;
            students[sIndex].degrees[i] = deg;
            cout << "Course assigned successfully.\n";
            return;
        }
    }

    cout << "Student already has 5 courses.\n";
}

// ⁄—÷ ﬂ· «·ÿ·«»
void displayAllStudents() {
    if (studentCount == 0) {
        cout << "No students found.\n";
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        cout << "\nStudent Name: " << students[i].name << " | ID: " << students[i].id << endl;
        cout << "Level: " << students[i].level << " | Group: " << students[i].group << " | GPA: " << students[i].gpa << endl;
        cout << "Courses: ";
        for (int j = 0; j < MAX_COURSES_PER_STUDENT; j++) {
            if (students[i].courseCodes[j] != "") {
                cout << students[i].courseCodes[j] << " (" << students[i].degrees[j] << ") ";
            }
        }
        cout << endl;
    }
}

// ⁄—÷ «·ÿ«·» «·√⁄·Ì œ—ÃÂ ›Ì ﬂ· ﬂÊ—”
void displayTopStudentInEachCourse() {
    for (int i = 0; i < courseCount; i++) {
        string courseCode = courses[i].code;
        float maxDegree = -1;
        string topStudentName = "";
        int topStudentId = -1;

        for (int j = 0; j < studentCount; j++) {
            for (int k = 0; k < MAX_COURSES_PER_STUDENT; k++) {
                if (students[j].courseCodes[k] == courseCode) {
                    if (students[j].degrees[k] > maxDegree) {
                        maxDegree = students[j].degrees[k];
                        topStudentName = students[j].name;
                        topStudentId = students[j].id;
                    }
                }
            }
        }

        if (topStudentName != "") {
            cout << "Top student in " << courseCode << " is " << topStudentName
                << " (ID: " << topStudentId << ") with " << maxDegree << " degrees.\n";
        }
        else {
            cout << "No students registered in course " << courseCode << ".\n";
        }
    }
}

// ⁄—÷ ÿ«·» »«·«”„ Ê «·‹ ID
void searchStudentByIdOrName() {
    cout << "Search by (1) ID or (2) Name: ";
    int option;
    cin >> option;

    if (option == 1) {
        int id;
        cout << "Enter student ID: ";
        cin >> id;

        int index = findStudentIndexById(id);
        if (index == -1) {
            cout << "Student not found.\n";
        }
        else {
            cout << "Name: " << students[index].name << " | Level: " << students[index].level
                << " | Group: " << students[index].group << " | GPA: " << students[index].gpa << endl;
        }

    }
    else if (option == 2) {
        string name;
        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, name);

        bool found = false;
        for (int i = 0; i < studentCount; i++) {
            if (students[i].name == name) {
                found = true;
                cout << "ID: " << students[i].id << " | Level: " << students[i].level
                    << " | Group: " << students[i].group << " | GPA: " << students[i].gpa << endl;
            }
        }

        if (!found) {
            cout << "Student not found.\n";
        }
    }
    else {
        cout << "Invalid option.\n";
    }
}

//«·»ÕÀ ⁄‰ «·ﬂÊ—” »«·«”„ «Ê «·‹ ID
void searchCourseByNameOrCode() {
    cout << "Search by (1) Code or (2) Name: ";
    int option;
    cin >> option;

    if (option == 1) {
        string code;
        cout << "Enter course code: ";
        cin >> code;

        int index = findCourseIndexByCode(code);
        if (index == -1) {
            cout << "Course not found.\n";
        }
        else {
            cout << "Course Name: " << courses[index].name << " | Credit Hours: " << courses[index].creditHours << endl;
        }

    }
    else if (option == 2) {
        string name;
        cout << "Enter course name: ";
        cin.ignore();
        getline(cin, name);

        bool found = false;
        for (int i = 0; i < courseCount; i++) {
            if (courses[i].name == name) {
                found = true;
                cout << "Course Code: " << courses[i].code << " | Credit Hours: " << courses[i].creditHours << endl;
            }
        }

        if (!found) {
            cout << "Course not found.\n";
        }
    }
    else {
        cout << "Invalid option.\n";
    }
}
//«⁄—÷ ﬂ· „” ÊÌ «·ÿ·«» «···Ì ›Ì ‰›” «·„” ÊÌ
void displayStudentsByLevel() {
    int level;
    cout << "Enter level (1 to 4): ";
    cin >> level;

    bool found = false;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].level == level) {
            found = true;
            cout << "Name: " << students[i].name << " | ID: " << students[i].id
                << " | Group: " << students[i].group << " | GPA: " << students[i].gpa << endl;
        }
    }

    if (!found)
        cout << "No students found in level " << level << ".\n";
}

// «·»—‰«„Ã «·—∆Ì”Ì
int main() {
    int choice;

    while (true) {
        cout << "\n=== Student Management System ===\n";
        cout << "1. Add Student\n";
        cout << "2. Update Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Add Course\n";
        cout << "5. Update Course\n";
        cout << "6. Delete Course\n";
        cout << "7. Assign Course and Degree to Student\n";
        cout << "8. Display All Students\n";
        cout << "9. Display Top Student in Each Course\n";
        cout << "10. Search Student by ID or Name\n";
        cout << "11. Search Course by Name or Code\n";
        cout << "12. Display Students by Level\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addStudent(); break;
        case 2: updateStudent(); break;
        case 3: deleteStudent(); break;
        case 4: addCourse(); break;
        case 5: updateCourse(); break;
        case 6: deleteCourse(); break;
        case 7: assignCourseToStudent(); break;
        case 8: displayAllStudents(); break;
        case 9: displayTopStudentInEachCourse(); break;
        case 10: searchStudentByIdOrName(); break;
        case 11: searchCourseByNameOrCode(); break;
        case 12: displayStudentsByLevel(); break;
        case 0:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
