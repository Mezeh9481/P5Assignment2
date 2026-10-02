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
#ifdef _DEBUG
    for (const auto& s : students) {
        cout << s.firstName << " " << s.lastName << endl;
    }
#endif
    cin.get();

    return 1;
}