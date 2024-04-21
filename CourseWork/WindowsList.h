#pragma once
#include <iostream>
#include <stack>
#include "Window.h"

class WindowsList {
private:
    std::stack<Window*> windows;

public:
    WindowsList();                          // Constructor
    ~WindowsList();                         // Destructor
    void addWindow(Window* window);         // Method to add a window to the stack
    void addWindow_func();                  // Method to add multiple windows interactively
    void cascadeWindows();                  // Method to arrange windows in cascade mode
    void tileWindows();                     // Method to arrange windows in tile mode
    void displayAllWindowsInfo() const;     // Method to display information about all windows in the stack
    void minimizeAllWindows();              // Method to minimize all windows
    void maximizeAllWindows();              // Method to maximize all windows
    void executeMenu();                     // Method to execute menu for window management

    // Iterator class for WindowsList
    class Iterator {
    private:
        std::stack<Window*> stack_ptr;

    public:
        Iterator(std::stack<Window*> stack); // Constructor
        Iterator& operator++();              // Iterator increment operator
        bool operator!=(const Iterator& other) const; // Iterator inequality comparison
        Window& operator*() const;           // Dereference operator
    };

    Iterator begin();                       // Method to get iterator to the start of the stack
    Iterator end();                         // Method to get iterator to the end of the stack
};
