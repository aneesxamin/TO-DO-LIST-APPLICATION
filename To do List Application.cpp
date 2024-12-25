#include <iostream>
#include <vector>
#include <string>

// Structure to hold task information
struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

// Function declarations
void displayMenu();
void addTask(std::vector<Task>& tasks);
void markTaskCompleted(std::vector<Task>& tasks);
void viewTasks(const std::vector<Task>& tasks);

int main() {
    std::vector<Task> tasks;
    int choice;

    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                markTaskCompleted(tasks);
                break;
            case 3:
                viewTasks(tasks);
                break;
            case 4:
                std::cout << "Exiting the application. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}

// Function to display the menu
void displayMenu() {
    std::cout << "\nTo-Do List Application\n";
    std::cout << "1. Add a Task\n";
    std::cout << "2. Mark Task as Completed\n";
    std::cout << "3. View Tasks\n";
    std::cout << "4. Exit\n";
}

// Function to add a task
void addTask(std::vector<Task>& tasks) {
    std::cin.ignore(); // Clear input buffer
    std::string description;
    std::cout << "Enter task description: ";
    std::getline(std::cin, description);

    tasks.push_back(Task(description)); // Use push_back instead of emplace_back
    std::cout << "Task added successfully.\n";
}

// Function to mark a task as completed
void markTaskCompleted(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available to mark as completed.\n";
        return;
    }

    viewTasks(tasks);
    int taskNumber;
    std::cout << "Enter the task number to mark as completed: ";
    std::cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].completed = true;
        std::cout << "Task marked as completed.\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}

// Function to view tasks
void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to display.\n";
        return;
    }

    std::cout << "\nCurrent Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i].description;
        if (tasks[i].completed) {
            std::cout << " [Completed]";
        }
        std::cout << "\n";
    }
}

