#include "Window.h" 
#include "Rectangle.h"
#include "WindowsList.h"
#include <fstream> 
#include <iostream>

int main() {

    // Creating a window object and inputting its properties
    Window myWindow(std::make_pair(0, 0), std::make_pair(0, 0), "", "", {});
    std::cin >> myWindow; // Input data for the myWindow object from console
    Rectangle* pointer = &myWindow; // Pointer to a Window object pointing to the base class Rectangle
    // Calling a virtual method via the derived class
    std::cout << "Window background info: " << pointer->getBackgroundInfo() << std::endl;
    // Outputting information about the window
    std::cout << myWindow << std::endl;


    // Creating an object of the Rectangle class, initializing properties via copy constructor
    Rectangle myRectangle2(myWindow);
    std::cin >> myRectangle2; // Input data for the myRectangle2 object from console
    myRectangle2.modifyWindow(myRectangle2); // Call the modifyWindow method
    std::cout << myRectangle2 << std::endl; // Output information about the rectangle
    Rectangle* pointer_rect = &myRectangle2; // Pointer to a Rectangle object pointing to the base class Rectangle
    // Calling a virtual method via the base class
    std::cout << "Rectangle background info: " << pointer_rect->getBackgroundInfo() << std::endl;


    // Creating an object of the Rectangle class, initializing properties via move constructor and using assignment (=) to assign to the object
    Rectangle myRectangle3 = std::move(myWindow);
    myRectangle3.set();
    myRectangle3.show();
    myRectangle3.modifyWindow(myRectangle3);
    myRectangle3.show();


    WindowsList myWindows; // Creating an object of the WindowsList class
    myWindows.addWindow_func(); // Adding a window to the windows list
    // Iterate through windows using the iterator
    for (auto it = myWindows.begin(); it != myWindows.end(); ++it) {
        std::cout << "Window: " << (*it).getTitle() << std::endl;
        std::cout << "Top Left: (" << (*it).getTopLeft().first << ", " << (*it).getTopLeft().second << ")" << std::endl;
        std::cout << "Bottom Right: (" << (*it).getBottomRight().first << ", " << (*it).getBottomRight().second << ")" << std::endl;
        std::cout << std::endl;}
    // Execute menu for window management
    myWindows.executeMenu();


    // Open a file for writing
    std::ofstream outputFile("ÑourceWork.txt");
    if (outputFile.is_open()) {
        // Output the obtained info string to the file
        outputFile << myWindow << std::endl;
        outputFile.close();
        std::cout << "Data successfully written to the file ÑourceWork.txt " << std::endl;}
    else { std::cout << "Error opening a file for writing" << std::endl;} std::cout << std::endl;
    return 0;
}
