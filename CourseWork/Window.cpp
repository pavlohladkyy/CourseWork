#include "Window.h"
#include <limits>

// Constructor definition
Window::Window(const std::pair<int, int>& tl, const std::pair<int, int>& br, const std::string& bg,
    const std::string& title, const std::vector<std::string>& menu)
    : Rectangle(tl, br, bg), title(title), menu(menu) {
}

// Input operator definition
std::istream& operator>>(std::istream& is, Window& window) {
    is >> static_cast<Rectangle&>(window); // Call the base class's input operator
    std::cout << "Enter window title: ";
    std::getline(is >> std::ws, window.title);
    if (window.title.empty()) {
        std::cout << "Empty title is not allowed. Please enter a valid title.\n";
        return is;
    }
    std::cout << "Enter menu items (type 'end' to finish):\n";
    std::string menuItem;
    while (std::getline(is >> std::ws, menuItem) && menuItem != "end") {
        window.menu.push_back(menuItem);
    }
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return is;
}

// Output operator definition
std::ostream& operator<<(std::ostream& os, const Window& window) {
    os << static_cast<const Rectangle&>(window); // Call the base class's output operator
    os << "\nTitle: " << window.title << "\n";
    os << "Menu:\n";
    for (const std::string& menuItem : window.menu) {
        os << menuItem << "\n";
    }
    return os;
}

// Get top-left window coordinates
std::pair<int, int> Window::getTopLeft() const {
    return top_left;
}

// Get bottom-right window coordinates
std::pair<int, int> Window::getBottomRight() const {
    return bottom_right;
}

// Override of the virtual method to get background information
std::string Window::getBackgroundInfo() const {
    return "Title: " + title + ", Menu items: " + std::to_string(menu.size());
}

// Set top-left window coordinates
void Window::setTopLeft(const std::pair<int, int>& newTopLeft) {
    top_left = newTopLeft;
}

// Set bottom-right window coordinates
void Window::setBottomRight(const std::pair<int, int>& newBottomRight) {
    bottom_right = newBottomRight;
}

// Set window title
void Window::setTitle(const std::string& newTitle) {
    title = newTitle;
}

// Get window title
const std::string& Window::getTitle() const {
    return title;
}

// Set menu items
void Window::setMenu(const std::vector<std::string>& newMenu) {
    menu = newMenu;
}

// Get menu items
const std::vector<std::string>& Window::getMenu() const {
    return menu;
}

// Set background color
void Window::setBackgroundColor(const std::string& bg) {
    background_color = bg;
}

// Get background color
const std::string& Window::getBackgroundColor() const {
    return background_color;
}

// Destructor definition
Window::~Window() {
    // Destructor implementation (if needed)
}
