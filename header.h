#pragma once

#include <stdexcept>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Task {
	string name = "new task";
	string description = "no description";
	bool completed = false;
};

class ToDoList {
private:
	vector<Task> tasks;
public:
	void addTask(Task* actual);
	void renameTask(Task& actual, string newName);
	void switchTask(Task& actual);
	int getQuant();
};

void filePrint(fstream& file);
char choose();
void setName(Task* task);
