#include<iostream>
#include<vector>
#include<algorithm>
#include"Window.h"

class WindowList {
private:
	std::vector<Window> windows;
    bool cascadeMode;
public:
    //конструктор ініціалізації   
    WindowList(bool cascadeMode = true);

    // Метод для додавання нового вікна до списку
    void addWindow(const Window& window);

    // Метод для розміщення вікон на екрані
    void arrangeWindows();

    // Метод для збільшення розміру всіх вікон до розміру екрана
    void maximizeAllWindows();

    // Метод для мінімізації розмірів всіх вікон
    void minimizeAllWindows();
};

WindowList::WindowList(bool cascadeMode = true) : cascadeMode(cascadeMode) {}

void WindowList::addWindow(const Window& window) {
    windows.push_back(window);
}
void WindowList::arrangeWindows() {
    if (cascadeMode) {
        // Розміщення вікон каскадом
        int startX = 0;
        int startY = 0;
        for (const auto& window : windows) {
            window.display(); // Вивід інформації про вікно
            startX += 50; // Зміщення по X
            startY += 20; // Зміщення по Y
        }
    }
    else {
        // Розміщення вікон плиткою
        int startX = 0;
        for (const auto& window : windows) {
            window.display(); // Вивід інформації про вікно
            startX += window.getWidth() + 10; // Збільшення startX для наступного вікна
        }
    }
}
void WindowList::maximizeAllWindows() {
    for (auto& window : windows) {
        window.maximizeToScreen();
    }
}

void WindowList::minimizeAllWindows() {
    for (auto& window : windows) {
        window.minimize();
    }
}