#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct STUDENT_DATA {
    string firstName;
    string lastName;
    string email;
};

int main() {
    vector<STUDENT_DATA> students;
    ifstream file("StudentData.txt");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        STUDENT_DATA s;
        getline(ss, s.firstName, ',');
        getline(ss, s.lastName);
        students.push_back(s);
    }

    cin.get();
    return 0;
}