// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// =============================================================================

// =============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;


// -----------------------------------------------------------------------------
// FEATURE 1 — Add a Task
// -----------------------------------------------------------------------------

void addTask(vector<string>& tasks) {

    string task;

    cout << "Enter task: ";
    cin.ignore();
    getline(cin, task);


    tasks.push_back(task);

    cout << "Task added: \"" << task << "\"" << endl;
}


// -----------------------------------------------------------------------------
// FEATURE 2 — View All Tasks
// -----------------------------------------------------------------------------

void viewTasks(const vector<string>& tasks) {

    if (tasks.empty()) {

        cout << "Your task list is empty." << endl;
        return;

    }


    cout << "Your Tasks:" << endl;


    for (int i = 0; i < tasks.size(); i++) {

        cout << i + 1 << ". " << tasks[i] << endl;

    }
}


// -----------------------------------------------------------------------------
// FEATURE 3 — Delete a Task
// -----------------------------------------------------------------------------

void deleteTask(vector<string>& tasks) {

    if (tasks.empty()) {

        cout << "No tasks available to delete." << endl;
        return;

    }


    viewTasks(tasks);


    int taskNumber;

    cout << "Enter task number to delete: ";
    cin >> taskNumber;


    if (taskNumber < 1 || taskNumber > tasks.size()) {

        cout << "Error: Invalid task number." << endl;

        return;

    }


    string removedTask = tasks[taskNumber - 1];


    tasks.erase(tasks.begin() + (taskNumber - 1));


    cout << "Task \"" << removedTask << "\" has been removed." << endl;
}


// -----------------------------------------------------------------------------
// MAIN FUNCTION
// -----------------------------------------------------------------------------

int main() {

    vector<string> tasks;

    int choice;


    do {

        cout << endl;
        cout << "============================" << endl;
        cout << "     TO-DO LIST MENU" << endl;
        cout << "============================" << endl;
        cout << "1. Add task" << endl;
        cout << "2. View tasks" << endl;
        cout << "3. Delete task" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";

        cin >> choice;



        switch(choice) {


            case 1:

                addTask(tasks);

                break;



            case 2:

                viewTasks(tasks);

                break;



            case 3:

                deleteTask(tasks);

                break;



            case 4:

                cout << "Goodbye!" << endl;

                break;



            default:

                cout << "Error: Invalid choice. Please select between 1 and 4."
                     << endl;

        }


    } while (choice != 4);



    return 0;
}