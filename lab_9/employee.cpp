#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


using namespace std;


// Структура для хранения информации о сотруднике
struct Employee {
    int position;
    string fullName;
    char gender;
    string birthDate;
    string hireDate;
    string education;
    string jobTitle;
    string maritalStatus;
    string department;

    Employee(int position, string fullName, char gender, string birthDate, string hireDate, string education, string jobTitle, string maritalStatus, string department) :
        position(position), fullName(fullName), gender(gender), birthDate(birthDate), hireDate(hireDate), education(education), jobTitle(jobTitle), maritalStatus(maritalStatus), department(department) {}

    // Геттеры для доступа к полям структуры
    int getPosition() const { return position; }
    string getFullName() const { return fullName; }
    char getGender() const { return gender; }
    string getBirthDate() const { return birthDate; }
    string getHireDate() const { return hireDate; }
    string getEducation() const { return education; }
    string getJobTitle() const { return jobTitle; }
    string getMaritalStatus() const { return maritalStatus; }
    string getDepartment() const { return department; }
};

void processDatabase() {
    // Имя файла
    string filename = "baza.txt";

    // Открываем файл с данными
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл " << filename << endl;
        return;
    }

    vector<Employee> employees;
    string line;

    // Читаем данные из файла
    while (getline(file, line)) {
        stringstream ss(line);
        Employee employee(0, "", ' ', "", "", "", "", "", "");

        int position;
        string fullName;
        char gender;
        string birthDate;
        string hireDate;
        string education;
        string jobTitle;
        string maritalStatus;
        string department;
        string temp;

        ss >> position;
        ss >> fullName;
        ss >> gender;
        ss >> birthDate;
        ss >> hireDate;
        ss >> education;

        // Читает название должности до двойного пробела
        jobTitle = "";
        while (ss >> temp) {
            if (temp.find("  ") != string::npos) {
                jobTitle += temp.substr(0, temp.find("  "));
                break;
            } else {
                jobTitle += temp + " ";
            }
        }
        // Удаляет пробел в конце, если название должности не является пустым
        if (!jobTitle.empty()) {
            jobTitle.pop_back();
        }

        ss >> maritalStatus;
        getline(ss >> ws, department);

        //Создает объект Employee и добавляет его в вектор
        employee = Employee(position, fullName, gender, birthDate, hireDate, education, jobTitle, maritalStatus, department);
        employees.push_back(employee);
    }

    // Закрыть файл
    file.close();

    // Вывод результатов

    cout << "Не женатых мужчин {" << endl;
    for (const auto& employee : employees) {
        if (employee.getGender() == 'm' && employee.getMaritalStatus() == "Не женат") {
            cout << "  " << employee.getFullName() << " (" << employee.getJobTitle() << ")" << endl;
        }
    }
    cout << "}" << endl << endl;

    cout << "Не женатых мужчин с В/О {" << endl;
    for (const auto& employee : employees) {
        if (employee.getGender() == 'm' && employee.getMaritalStatus() == "Не женат" && employee.getEducation() == "В/О") {
            cout << "  " << employee.getFullName() << " (" << employee.getJobTitle() << ")" << endl;
        }
    }
    cout << "}" << endl << endl;

    cout << "Конкуренток (не замужних женщин) {" << endl;
    for (const auto& employee : employees) {
        if (employee.getGender() == 'w' && employee.getMaritalStatus() == "Не замужем") {
            cout << "  " << employee.getFullName() << " (" << employee.getJobTitle() << ")" << endl;
        }
    }
    cout << "}" << endl;
}
