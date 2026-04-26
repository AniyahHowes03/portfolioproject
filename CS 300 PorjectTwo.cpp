#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// structure to hold course info
struct Course {
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;
};

// global storage
vector<Course> courseList;
bool dataLoaded = false;

// load data from file
void loadData() {

    ifstream file("Debug/ABCU.csv");

    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    courseList.clear();

    string line;
    while (getline(file, line)) {
        stringstream ss(line);

        Course course;
        string temp;

        getline(ss, course.courseNumber, ',');
        getline(ss, course.courseTitle, ',');

        // get prerequisites if any
        while (getline(ss, temp, ',')) {
            course.prerequisites.push_back(temp);
        }

        courseList.push_back(course);
    }

    file.close();

    // check if prerequisites exist
    for (int i = 0; i < courseList.size(); i++) {
        for (int j = 0; j < courseList[i].prerequisites.size(); j++) {
            bool found = false;

            for (int k = 0; k < courseList.size(); k++) {
                if (courseList[k].courseNumber == courseList[i].prerequisites[j]) {
                    found = true;
                }
            }

            if (!found) {
                cout << "Warning: prerequisite "
                     << courseList[i].prerequisites[j]
                     << " not found." << endl;
            }
        }
    }

    dataLoaded = true;
    cout << "Data loaded." << endl;
}

// simple sort (by course number)
void sortCourses() {
    for (int i = 0; i < courseList.size(); i++) {
        for (int j = i + 1; j < courseList.size(); j++) {
            if (courseList[j].courseNumber < courseList[i].courseNumber) {
                swap(courseList[i], courseList[j]);
            }
        }
    }
}

// print all courses
void printCourseList() {
    if (!dataLoaded) {
        cout << "Please load data first." << endl;
        return;
    }

    sortCourses();

    for (int i = 0; i < courseList.size(); i++) {
        cout << courseList[i].courseNumber << ", "
             << courseList[i].courseTitle << endl;
    }
}

// print one course
void printCourse() {
    if (!dataLoaded) {
        cout << "Please load data first." << endl;
        return;
    }

    string courseNum;
    cout << "Enter course number: ";
    cin >> courseNum;

    for (int i = 0; i < courseList.size(); i++) {
        if (courseList[i].courseNumber == courseNum) {
            cout << courseList[i].courseNumber << ", "
                 << courseList[i].courseTitle << endl;

            cout << "Prerequisites: ";
            for (int j = 0; j < courseList[i].prerequisites.size(); j++) {
                cout << courseList[i].prerequisites[j] << " ";
            }
            cout << endl;
            return;
        }
    }

    cout << "Course not found." << endl;
}

int main() {
    int choice = 0;

    cout << "Welcome to the course planner." << endl;

    while (choice != 9) {
        cout << "1. Load Data Structure" << endl;
        cout << "2. Print Course List" << endl;
        cout << "3. Print Course" << endl;
        cout << "9. Exit" << endl;

        cout << "What would you like to do? ";
        cin >> choice;

        if (choice == 1) {
            loadData();
        }
        else if (choice == 2) {
            printCourseList();
        }
        else if (choice == 3) {
            printCourse();
        }
        else if (choice == 9) {
            cout << "Thank you for using the course planner!" << endl;
        }
        else {
            cout << "Invalid option." << endl;
        }
    }

    return 0;
}
