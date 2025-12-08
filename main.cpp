#include "Header.h"
#include <clocale>
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	ifstream file;
	file.open("tasks.txt", ifstream::in);
	try {
		filePrint(file);
	}
	catch(const runtime_error& e) {
		cout << e.what() << endl;
	}
			
	file.close();

	char dec = choose();

	if (dec == '1') {
		Task* newTask = new Task;
		setName(newTask);
	}
    
    if (
	
	return 1;
}
//
