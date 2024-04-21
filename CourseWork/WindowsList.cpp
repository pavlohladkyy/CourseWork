#include "WindowsList.h"

// Iterator constructor
WindowsList::Iterator::Iterator(std::stack<Window*> stack) : stack_ptr(stack) {}

// Iterator increment operator
WindowsList::Iterator& WindowsList::Iterator::operator++() {
    stack_ptr.pop();
    return *this;
}

// Iterator inequality comparison
bool WindowsList::Iterator::operator!=(const Iterator& other) const {
    return stack_ptr != other.stack_ptr;
}

// Dereference operator
Window& WindowsList::Iterator::operator*() const {
    return *stack_ptr.top();
}

// Constructor definition
WindowsList::WindowsList() {}

// Destructor definition
WindowsList::~WindowsList() {
    while (!windows.empty()) {
        delete windows.top();
        windows.pop();
    }
}

// Method to add a window to the stack
void WindowsList::addWindow(Window* window) {
    windows.push(window);
}

// Method to add multiple windows interactively
void WindowsList::addWindow_func() {
    int numWindows;
    std::cout << "\nEnter the number of windows: ";
    std::cin >> numWindows;

    for (int i = 0; i < numWindows; ++i) {
        Window* window = new Window(std::make_pair(0, 0), std::make_pair(0, 0), "", "", {});
        std::cout << "Enter details for Window " << i + 1 << ":\n";
        std::cin >> *window;
        addWindow(window);
    }
}

// Method to arrange windows in cascade mode
void WindowsList::cascadeWindows() {
    std::stack<Window*> tempStack = windows;
    int x = 0, y = 0;

    while (!tempStack.empty()) {
        Window* current = tempStack.top();
        std::pair<int, int> topLeft = { x, y };
        std::pair<int, int> bottomRight = { x + current->getWidth(), y - current->getHeight() };

        x += 10;
        y -= 10;

        std::cout << "Cascade Placement:\n";
        std::cout << *current << "\n";
        tempStack.pop();
    }
}

// Method to arrange windows in tile mode
void WindowsList::tileWindows() {
    std::stack<Window*> tempStack = windows;
    int x = 0, y = 0;

    while (!tempStack.empty()) {
        Window* current = tempStack.top();
        current->setTopLeft({ x, y });
        current->setBottomRight({ x + current->getWidth(), y - current->getHeight() });

        std::cout << "Tile Placement:\n";
        std::cout << *current << "\n";

        tempStack.pop();
    }
}

// Method to display information about all windows in the stack
void WindowsList::displayAllWindowsInfo() const {
    std::stack<Window*> tempStack = windows;
    while (!tempStack.empty()) {
        tempStack.top()->getBackgroundInfo();
        tempStack.pop();
    }
}

// Method to minimize all windows
void WindowsList::minimizeAllWindows() {
    std::stack<Window*> tempStack = windows;
    while (!tempStack.empty()) {
        Window* current = tempStack.top();
        current->minimize(); // Assuming minimize is a method in Window
        tempStack.pop();
    }
}

// Method to maximize all windows
void WindowsList::maximizeAllWindows() {
    std::stack<Window*> tempStack = windows;
    while (!tempStack.empty()) {
        Window* current = tempStack.top();
        current->maximize(); // Assuming maximize is a method in Window
        tempStack.pop();
    }
}

// Method to execute menu for window management
void WindowsList::executeMenu() {
    int choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Cascade windows\n";
        std::cout << "2. Tile windows\n";
        std::cout << "3. Minimize all windows\n";
        std::cout << "4. Maximize all windows\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            cascadeWindows();
            break;
        case 2:
            tileWindows();
            break;
        case 3:
            minimizeAllWindows();
            break;
        case 4:
            maximizeAllWindows();
            break;
        case 5:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);
}

// Method to get iterator to the start of the stack
WindowsList::Iterator WindowsList::begin() {
    return Iterator(windows);
}

// Method to get iterator to the end of the stack
WindowsList::Iterator WindowsList::end() {
    return Iterator(std::stack<Window*>()); // Empty stack for end iterator
}
