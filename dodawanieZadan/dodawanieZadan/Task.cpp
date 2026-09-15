#include "Task.h"

#include <iostream>

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

std::string Task::getName() const
{
    return name;
}

bool Task::isCompleted() const
{
    return completed;
}

int Task::getPriority() const
{
    return priority;
}

void Task::complete()
{
    completed = true;
}

void Task::display() const
{
    std::cout << "ID: " << id << "\n";
    std::cout << "Nazwa: " << name << "\n";
    std::cout << "Priorytet: " << priority << "\n";

    if (completed)
    {
        std::cout << "Status: Wykonane\n";
    }
    else
    {
        std::cout << "Status: Do wykonania\n";
    }

    std::cout << "----------------------\n";
}