#pragma once

#include <string>

class Task
{
private:
    int id;
    std::string name;
    bool completed;
    int priority;

public:
    Task(int taskId, std::string taskName, int taskPriority);

    int getId() const;
    std::string getName() const;
    bool isCompleted() const;
    int getPriority() const;

    void complete();
    void display() const;
};