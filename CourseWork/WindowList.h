#include<iostream>
#include<vector>
#include<algorithm>
#include"Window.h"

class WindowList {
private:
	std::vector<Window> windows;
    bool cascadeMode;
public:
    //����������� �����������   
    WindowList(bool cascadeMode = true);

    // ����� ��� ��������� ������ ���� �� ������
    void addWindow(const Window& window);

    // ����� ��� ��������� ���� �� �����
    void arrangeWindows();

    // ����� ��� ��������� ������ ��� ���� �� ������ ������
    void maximizeAllWindows();

    // ����� ��� �������� ������ ��� ����
    void minimizeAllWindows();
};

WindowList::WindowList(bool cascadeMode = true) : cascadeMode(cascadeMode) {}

void WindowList::addWindow(const Window& window) {
    windows.push_back(window);
}
void WindowList::arrangeWindows() {
    if (cascadeMode) {
        // ��������� ���� ��������
        int startX = 0;
        int startY = 0;
        for (const auto& window : windows) {
            window.display(); // ���� ���������� ��� ����
            startX += 50; // ������� �� X
            startY += 20; // ������� �� Y
        }
    }
    else {
        // ��������� ���� �������
        int startX = 0;
        for (const auto& window : windows) {
            window.display(); // ���� ���������� ��� ����
            startX += window.getWidth() + 10; // ��������� startX ��� ���������� ����
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