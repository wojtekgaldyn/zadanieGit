#pragma once

#include <string>

using namespace std;

class Task
{
private:
    int id;
    string name;
    bool completed;
    int priority;

public:
    Task(int taskId, string taskName, int taskPriority);

    int getId() const;
    bool isCompleted() const;

    void complete();
    void setName(string newName);
    void setPriority(int newPriority);

    void display() const;
};