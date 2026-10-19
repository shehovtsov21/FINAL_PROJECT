#include "Company.h"

int main() {
    Programmer programmer("Ivan", 3, "C++", 1200, 10);
    Tester tester("Olena", 2, 35, 300);
    ProjectManager manager("Andrii", 5, 20000, 10, 500);
    TeamLead lead("Maksym", 7, "C++", 1500, 12, 4, 2000);

    std::vector<Employee*> employees = {&programmer, &tester, &manager, &lead};
    std::cout << "Company employees:\n";
    for (Employee* employee : employees) {
        employee->printInfo();
        employee->work();
    }

    Project website("Website", 150000);
    website.addEmployee(&programmer);
    website.addEmployee(&tester);
    website.addEmployee(&manager);
    website.addEmployee(&lead);

    Project mobileApp("Mobile app", 200000);
    mobileApp.addEmployee(&programmer);
    mobileApp.addEmployee(&manager);
    mobileApp.addEmployee(&lead);

    std::vector<Project> projects = {website, mobileApp};
    for (const Project& project : projects) {
        project.printInfo();
    }

    std::cout << "\nRemoving Ivan from Website:\n";
    projects[0].removeEmployee(&programmer);
    projects[0].printInfo();
    std::cout << "\nIvan still exists and participates in Mobile app:\n";
    programmer.printInfo();
    projects[1].printInfo();

    return 0;
}
