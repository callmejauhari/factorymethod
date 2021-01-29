#include <iostream>
#include <cstdint>

using namespace std;

class Button
{
public:
    Button()
    {
    }
};

class Dialog
{
public:
    virtual Button *createButton() = 0;
};

class WindowsButton : public Button
{
public:
    WindowsButton() : Button()
    {
        cout << "Windows Button" << endl;
    }
};

class LinuxButton : public Button
{
public:
    LinuxButton() : Button()
    {
        cout << "Linux Button" << endl;
    }
};

class WindowsDialog : public Dialog
{
public:
    Button *createButton() override
    {
        cout << "Windows Dialog" << endl;
        return new WindowsButton();
    }
};
class LinuxDialog : public Dialog
{
public:
    Button *createButton() override
    {
        cout << "Linux Dialog" << endl;
        return new LinuxButton();
    }
};

int main()
{
    Dialog *dialog = new WindowsDialog();
    Button *button = dialog->createButton();
    return 0;
}