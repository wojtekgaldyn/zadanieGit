#include "Task.h"
#include <iostream>
using namespace std;

Task::Task(int taskId, std::string taskName, int taskPriority)
{
    id = taskId;
    name = taskName;
    priority = taskPriority;
    completed = false;
}

int Task::getId() const
{
    return id;
}
int Task::getPriority() const
{
    return priority;
}
string Task::getName() const
{
    return name;
}
bool Task::isCompleted() const
{
    return completed;
}


void Task::complete()
{
    completed = true;
}

void Task::setName(string newName) {
    name = newName;
}

void Task::setPriority(int newPriority) {
    priority = newPriority;
}

void Task::display() const
{
    cout << "ID: " << id << "\n";
    cout << "Nazwa: " << name << "\n";
    cout << "Priorytet: " << priority << "\n";

    if (completed)
    {
        cout << "Status: Wykonane\n";
    }
    else
    {
        cout << "Status: Do wykonania\n";
    }

    cout << "----------------------\n";
}