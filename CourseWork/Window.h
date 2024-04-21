#pragma once

#include "Rectangle.h"  // Include the declaration of Rectangle class
#include <iostream>
#include <vector>
#include <string>

// Class representing a window derived from Rectangle
class Window : public Rectangle {
private:
    std::string title;              // Window title
    std::vector<std::string> menu;  // Menu items
protected:
    std::string background_color;    // Background color
public:
    // Initialization constructor
    Window(const std::pair<int, int>& tl, const std::pair<int, int>& br, const std::string& bg,
        const std::string& title, const std::vector<std::string>& menu);

    // Methods to set and get window coordinates
    void setTopLeft(const std::pair<int, int>& newTopLeft);
    void setBottomRight(const std::pair<int, int>& newBottomRight);
    std::pair<int, int> getTopLeft() const;
    std::pair<int, int> getBottomRight() const;

    // Override of the virtual method from the base class
    std::string getBackgroundInfo() const override;

    // Methods to set and get title
    void setTitle(const std::string& newTitle);
    const std::string& getTitle() const;

    // Methods to set and get menu items
    void setMenu(const std::vector<std::string>& newMenu);
    const std::vector<std::string>& getMenu() const;

    // Methods to set and get background color
    void setBackgroundColor(const std::string& bg);
    const std::string& getBackgroundColor() const;

    // Friend functions for input and output operations
    friend std::istream& operator>>(std::istream& is, Window& window);
    friend std::ostream& operator<<(std::ostream& os, const Window& window);

    // Destructor
    ~Window();
};
