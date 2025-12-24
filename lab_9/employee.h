#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
public:
    // Конструктор по умолчанию
    Employee() : position(0), fullName(""), gender(' '), birthDate(""), hireDate(""), education(""), jobTitle(""), maritalStatus(""), department("") {}

    // Конструктор с параметрами
    Employee(int pos, const std::string& name, char gen, const std::string& birth, const std::string& hire, const std::string& edu, const std::string& job, const std::string& status, const std::string& dept) :
        position(pos), fullName(name), gender(gen), birthDate(birth), hireDate(hire), education(edu), jobTitle(job), maritalStatus(status), department(dept) {}

    // Методы доступа (геттеры)
    int getPosition() const { return position; }
    std::string getFullName() const { return fullName; }
    char getGender() const { return gender; }
    std::string getBirthDate() const { return birthDate; }
    std::string getHireDate() const { return hireDate; }
    std::string getEducation() const { return education; }
    std::string getJobTitle() const { return jobTitle; }
    std::string getMaritalStatus() const { return maritalStatus; }
    std::string getDepartment() const { return department; }

private:
    int position;
    std::string fullName;
    char gender;
    std::string birthDate;
    std::string hireDate;
    std::string education;
    std::string jobTitle;
    std::string maritalStatus;
    std::string department;
};

#endif
