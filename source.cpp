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

#ifdef PRE_RELEASE
    cout << "Running PreRelease code" << endl;
#else
    cout << "Running standard code" << endl;
#endif

    ifstream file("StudentData.txt");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        STUDENT_DATA s;
        getline(ss, s.firstName, ',');
        getline(ss, s.lastName);
        students.push_back(s);
    }

#ifdef PRE_RELEASE
    ifstream emailFile("StudentData_Emails.txt");
    size_t i = 0;
    while (getline(emailFile, line) && i < students.size()) {
        size_t pos = line.rfind(',');
        students[i].email = (pos == string::npos) ? line : line.substr(pos + 1);
        i++;
    }
#endif

#ifdef _DEBUG
    for (const auto& s : students) {
        cout << s.firstName << " " << s.lastName;
#ifdef PRE_RELEASE
        cout << " " << s.email;
#endif
        cout << endl;
    }
#endif

    cin.get();
    return 0;
}