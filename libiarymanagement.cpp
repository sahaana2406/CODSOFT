#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};


void addTask(std::vector<Task>& tasks) {
    std::string taskDescription;
    std::cout << "Enter the task description: ";
    std::cin.ignore();  
    std::getline(std::cin, taskDescription);

    tasks.push_back({taskDescription, false});
    std::cout << "Task added successfully!" << std::endl;
}
void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to show." << std::endl;
    } else {
        std::cout << "To-Do List:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].description
                      << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]" << std::endl;
        }
    }
}


void completeTask(std::vector<Task>& tasks) {
    int taskNumber;
    std::cout << "Enter the task number to mark as completed: ";
    std::cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].completed = true;
        std::cout << "Task marked as completed!" << std::endl;
    } else {
        std::cout << "Invalid task number!" << std::endl;
    }
}


void removeTask(std::vector<Task>& tasks) {
    int taskNumber;
    std::cout << "Enter the task number to remove: ";
    std::cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        std::cout << "Task removed successfully!" << std::endl;
    } else {
        std::cout << "Invalid task number!" << std::endl;
    }
}

int main() {
    std::vector<Task> tasks;
    int choice;

    do {
        std::cout << "\nTo-Do List Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                completeTask(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                std::cout << "Exiting the program..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}
