#include"Rectangle.h"

// Initialization constructor
Rectangle::Rectangle(const std::pair<int, int>& tl, const std::pair<int, int>& br, const std::string& bg)
    : top_left(tl), bottom_right(br), background_color(bg) {
    std::cout << "Initialization constructor\n";
}


// Copy constructor
Rectangle::Rectangle(const Rectangle& other)
    : top_left(other.top_left), bottom_right(other.bottom_right), background_color(other.background_color) {
    std::cout << "\n\nCopy constructor\n";
}


// Move constructor
Rectangle::Rectangle(Rectangle&& other) noexcept
    : top_left(std::move(other.top_left)), bottom_right(std::move(other.bottom_right)), background_color(std::move(other.background_color)) {
    std::cout << "\n\nMove constructor\n";
}


// Operator ++ for increasing rectangle coordinates
Rectangle& Rectangle::operator++() {
    --top_left.first;
    ++top_left.second;
    ++bottom_right.first;
    --bottom_right.second;
    return *this;
}


// Operator ++ for increasing rectangle coordinates (postfix)
Rectangle Rectangle::operator++(int) {
    Rectangle temp = *this;
    ++(*this);
    return temp;
}


// Operator -- for decreasing rectangle coordinates
Rectangle& Rectangle::operator--() {
    ++top_left.first;
    --top_left.second;
    --bottom_right.first;
    ++bottom_right.second;
    return *this;
}


// Operator -- for decreasing rectangle coordinates (postfix)
Rectangle Rectangle::operator--(int) {
    Rectangle temp = *this;
    --(*this);
    return temp;
}


// Operator * for moving the window
Rectangle& Rectangle::operator*(const std::pair<int, int>& displacement) {
    top_left.first += displacement.first;
    top_left.second += displacement.second;
    bottom_right.first += displacement.first;
    bottom_right.second += displacement.second;
    return *this;
}


// Assignment operator =
Rectangle& Rectangle::operator=(Rectangle&& other) {
    if (this != &other) {
        top_left = std::move(other.top_left);
        bottom_right = std::move(other.bottom_right);
        background_color = std::move(other.background_color);
    }
    return *this;
}


// Input operator
std::istream& operator>>(std::istream& is, Rectangle& rect) {
    using std::cin, std::cout;
    std::cout << "Enter the coordinates of the top left corner (x): ";
    is >> rect.top_left.first;
    std::cout << "Enter the coordinates of the top left corner (y): ";
    is >> rect.top_left.second;
    std::cout << "Enter the coordinates of the bottom right corner (x): ";
    is >> rect.bottom_right.first;
    // Check for valid input of bottom right corner (x)
    if (rect.top_left.first >= rect.bottom_right.first) {
        cout << "\aInvalid bottom right corner (x); it should be greater than: " << rect.top_left.first << "\n";
        while (rect.bottom_right.first <= rect.top_left.first) {
            cout << "\aTry again; enter the coordinates of the bottom right corner (x):";
            cin >> rect.bottom_right.first;
        }
    }
    std::cout << "Enter the coordinates of the bottom right corner (y): ";
    is >> rect.bottom_right.second;

    // Check for valid input of bottom right corner (y)
    if (rect.bottom_right.second >= rect.top_left.second) {
        cout << "\aInvalid bottom right corner (y); it should be less than: " << rect.top_left.second << " \n";
        while (rect.bottom_right.second >= rect.top_left.second) {
            cout << "\aTry again; enter the coordinates of the bottom right corner (y):";
            cin >> rect.bottom_right.second;
        }
    }
    std::cout << "Enter the background color: ";
    is >> rect.background_color;
    return is;
}


// Output operator
std::ostream& operator<<(std::ostream& os, const Rectangle& rect) {
    os << "Top left corner coordinates (" << rect.top_left.first << ";" << rect.top_left.second << ")\n";
    os << "Bottom right corner coordinates (" << rect.bottom_right.first << ";" << rect.bottom_right.second << ")\n";
    os << "Background color: " << rect.background_color;
    return os;
}


// Set coordinates and background color of the rectangle from console
void Rectangle::set() {
    using std::cout, std::cin;
    cout << "Enter the coordinates of the top left corner (x):";
    cin >> top_left.first;
    cout << "Enter the coordinates of the top left corner (y):";
    cin >> top_left.second;
    cout << "Enter the coordinates of the bottom right corner (x):";
    cin >> bottom_right.first;
    // Check for valid input of bottom right corner (x)
    if (bottom_right.first <= top_left.first) {
        cout << "\aInvalid bottom right corner (x); it should be greater than: " << top_left.first << "\n";
        while (bottom_right.first <= top_left.first) {
            cout << "\aTry again; enter the coordinates of the bottom right corner (x):";
            cin >> bottom_right.first;
        }
    }
    cout << "Enter the coordinates of the bottom right corner (y):";
    cin >> bottom_right.second;
    // Check for valid input of bottom right corner (y)
    if (bottom_right.second >= top_left.second) {
        cout << "\aInvalid bottom right corner (y); it should be less than: " << top_left.second << " \n";
        while (bottom_right.second >= top_left.second) {
            cout << "\aTry again; enter the coordinates of the bottom right corner (y):";
            cin >> bottom_right.second;
        }
    }
    cout << "Enter the background color:";
    cin >> background_color;
}


// Display coordinates and background color of the rectangle on screen
void Rectangle::show() const {
    using std::cout;
    cout << "Top left corner coordinates (" << top_left.first << ";" << top_left.second << ")\n";
    cout << "Bottom right corner coordinates (" << bottom_right.first << ";" << bottom_right.second << ")\n";
    cout << "Background color: " << background_color;
}


// Modify the rectangle based on user choice
void Rectangle::modifyWindow(Rectangle& rect) {
    char choice;
    std::cout << "\nDo you want to increase (++), decrease (--), or move (*) the window?\n Enter '+' for increase, '-' for decrease, or '*' for move, 'x' to stop changing coordinates: ";
    std::cin >> choice;
    std::pair<int, int> displacement;

    switch (choice) {
    case '+':
        ++rect;
        break;
    case '-':
        --rect;
        break;
    case '*':
        std::cout << "Enter the displacement coordinates (x y): ";
        std::cin >> displacement.first >> displacement.second;
        rect* displacement;
        break;

    case'x':
        break;
    default:

        break;
    }
}


// Method to calculate width of the rectangle
int Rectangle::getWidth() const {
    return bottom_right.first - top_left.first;
}


// Method to calculate height of the rectangle
int Rectangle::getHeight() const {
    return top_left.second - bottom_right.second;
}


//Method to minimize window in class WindowLists
void Rectangle::minimize() {
    top_left = { 0, 0 };
    bottom_right = { 0, 0 };
    std::cout << "Window minimized. Coordinates: (" << top_left.first << ", " << top_left.second << ") to ("
        << bottom_right.first << ", " << bottom_right.second << ")\n";
}



//Method to maximize window in class WindowLists
void Rectangle::maximize() {
    top_left = { 0, 0 }; // Assuming top-left corner at (0, 0) for maximization
    bottom_right = { getWidth(), -getHeight() }; // Calculate bottom-right corner
    std::cout << "Window maximized. Coordinates: (" << top_left.first << ", " << top_left.second << ") to ("
        << bottom_right.first << ", " << bottom_right.second << ")\n";
}