#ifndef COMPANY_H
#define COMPANY_H

#include <iostream>
#include <string>
#include <vector>

class Employee {
protected:
    std::string name;
    int experience;
    std::string position;
public:
    Employee(std::string name, int experience, std::string position);
    virtual ~Employee() = default;
    std::string getName() const;
    void printInfo() const;
    virtual void work() const = 0;
    virtual double calculateSalary() const = 0;
};

class Programmer : public Employee {
protected:
    std::string language;
    int codeLines;
    double pricePerLine;
public:
    Programmer(std::string name, int experience, std::string language,
               int codeLines, double pricePerLine);
    void work() const override;
    double calculateSalary() const override;
};

class Tester : public Employee {
    int bugsFound;
    double pricePerBug;
public:
    Tester(std::string name, int experience, int bugsFound, double pricePerBug);
    void work() const override;
    double calculateSalary() const override;
};

class ProjectManager : public Employee {
    double fixedSalary;
    int completedTasks;
    double bonusPerTask;
public:
    ProjectManager(std::string name, int experience, double fixedSalary,
                   int completedTasks, double bonusPerTask);
    void work() const override;
    double calculateSalary() const override;
};

class TeamLead : public Programmer {
    int teamSize;
    double bonusPerEmployee;
public:
    TeamLead(std::string name, int experience, std::string language,
             int codeLines, double pricePerLine, int teamSize,
             double bonusPerEmployee);
    void work() const override;
    double calculateSalary() const override;
};

class Project {
    std::string title;
    double budget;
    std::vector<Employee*> employees;
public:
    Project(std::string title, double budget);
    void addEmployee(Employee* employee);
    void removeEmployee(Employee* employee);
    void printParticipants() const;
    double totalSalary() const;
    void startWork() const;
    Employee* findHighestPaid() const;
    void printInfo() const;
};

#endif
