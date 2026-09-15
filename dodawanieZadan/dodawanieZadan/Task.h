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
    string getName() const;
    bool isCompleted() const;
    int getPriority() const;
    void setName(string newName);
    void setPriority(int newPriority);
    void complete();
    void display() const;
};