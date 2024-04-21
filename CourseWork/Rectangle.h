#pragma once
#include<iostream>

// Class representing a rectangle
class Rectangle {
protected:
    std::pair<int, int> top_left;          // Coordinates of the top-left corner
    std::pair<int, int> bottom_right;      // Coordinates of the bottom-right corner
    std::string background_color;          // Background color



    

public:
    // Initialization constructor
    Rectangle(const std::pair<int, int>& tl, const std::pair<int, int>& br, const std::string& bg);
    // Copy constructor
    Rectangle(const Rectangle& other);
    // Move constructor
    Rectangle(Rectangle&& other) noexcept;



    // Operators ++ and -- to increase or decrease the window
    Rectangle& operator++(); // Prefix ++
    Rectangle operator++(int); // Postfix ++
    Rectangle& operator--(); // Prefix --
    Rectangle operator--(int); // Postfix --



    // Operator * for moving the window
    Rectangle& operator*(const std::pair<int, int>& displacement);
    // Assignment operator =
    Rectangle& operator=(Rectangle&& other);



    // Input operator
    friend std::istream& operator>>(std::istream& is, Rectangle& rect);
    // Output operator
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& rect);



    // Set coordinates and background color of the rectangle from console
    void set();
    // Display coordinates and background color of the rectangle on screen
    void show() const;
    // Modify the rectangle based on user choice
    void modifyWindow(Rectangle& rect);
    virtual std::string getBackgroundInfo() const {return background_color;}



    // Method to calculate width of the rectangle
    int getWidth() const;
    // Method to calculate height of the rectangle
    int getHeight() const;



    //Method to minimize window in class WindowLists
    void minimize();
    //Method to maximize window in class WindowLists
    void maximize();

    virtual ~Rectangle() = default; // Virtual destructor
};