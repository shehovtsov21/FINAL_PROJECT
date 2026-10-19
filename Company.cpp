#include "Company.h"

Employee::Employee(std::string name, int experience, std::string position)
    : name(name), experience(experience), position(position) {}

std::string Employee::getName() const {
    return name;
}

void Employee::printInfo() const {
    std::cout << name << " | " << position << " | Experience: "
              << experience << " years | Salary: " << calculateSalary() << '\n';
}

Programmer::Programmer(std::string name, int experience, std::string language,
                       int codeLines, double pricePerLine)
    : Employee(name, experience, "Programmer"), language(language),
      codeLines(codeLines), pricePerLine(pricePerLine) {}

void Programmer::work() const {
    std::cout << name << " writes code in " << language << ".\n";
}

double Programmer::calculateSalary() const {
    return codeLines * pricePerLine;
}

Tester::Tester(std::string name, int experience, int bugsFound, double pricePerBug)
    : Employee(name, experience, "Tester"), bugsFound(bugsFound),
      pricePerBug(pricePerBug) {}

void Tester::work() const {
    std::cout << name << " tests the system and finds bugs.\n";
}

double Tester::calculateSalary() const {
    return bugsFound * pricePerBug;
}

ProjectManager::ProjectManager(std::string name, int experience, double fixedSalary,
                               int completedTasks, double bonusPerTask)
    : Employee(name, experience, "ProjectManager"), fixedSalary(fixedSalary),
      completedTasks(completedTasks), bonusPerTask(bonusPerTask) {}

void ProjectManager::work() const {
    std::cout << name << " organizes the team and checks deadlines.\n";
}

double ProjectManager::calculateSalary() const {
    return fixedSalary + completedTasks * bonusPerTask;
}

TeamLead::TeamLead(std::string name, int experience, std::string language,
                   int codeLines, double pricePerLine, int teamSize,
                   double bonusPerEmployee)
    : Programmer(name, experience, language, codeLines, pricePerLine),
      teamSize(teamSize), bonusPerEmployee(bonusPerEmployee) {
    position = "TeamLead";
}

void TeamLead::work() const {
    std::cout << name << " writes code in " << language
              << " and leads " << teamSize << " developers.\n";
}

double TeamLead::calculateSalary() const {
    return Programmer::calculateSalary() + teamSize * bonusPerEmployee;
}

Project::Project(std::string title, double budget) : title(title), budget(budget) {}

void Project::addEmployee(Employee* employee) {
    if (employee == nullptr) return;
    for (Employee* current : employees) {
        if (current == employee) return;
    }
    employees.push_back(employee);
}

void Project::removeEmployee(Employee* employee) {
    for (std::size_t i = 0; i < employees.size(); i++) {
        if (employees[i] == employee) {
            employees.erase(employees.begin() + i);
            return;
        }
    }
}

void Project::printParticipants() const {
    if (employees.empty()) std::cout << "No participants.\n";
    for (Employee* employee : employees) {
        employee->printInfo();
    }
}

double Project::totalSalary() const {
    double total = 0;
    for (Employee* employee : employees) {
        total += employee->calculateSalary();
    }
    return total;
}

void Project::startWork() const {
    for (Employee* employee : employees) {
        employee->work();
    }
}

Employee* Project::findHighestPaid() const {
    if (employees.empty()) return nullptr;
    Employee* best = employees[0];
    for (Employee* employee : employees) {
        if (employee->calculateSalary() > best->calculateSalary()) {
            best = employee;
        }
    }
    return best;
}

void Project::printInfo() const {
    std::cout << "\nProject: " << title << "\nBudget: " << budget
              << "\nParticipants:\n";
    printParticipants();
    std::cout << "Total salary: " << totalSalary() << '\n';
    Employee* best = findHighestPaid();
    if (best != nullptr) {
        std::cout << "Highest paid: " << best->getName()
                  << " (" << best->calculateSalary() << ")\n";
    }
    std::cout << "Work:\n";
    startWork();
}
