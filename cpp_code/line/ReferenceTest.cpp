/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <string>
#include <iostream>
using namespace std;

class Home {
private:
    string address;

public:
    Home(string address) {
        this->address = address;
    }
    string toString() {
        return "Home{ address=" + this->address + "}";
    }
};

class Person {
private:
    string name;
    int age;
    Home* home;

public:
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }

    void setHome(Home* home) {
        this->home = home;
    }

    string toString() {
        return "Person{ name=" + name +
            ", age=" + to_string(age) +
            ", home=" + home->toString() + "}";
    }
};

int main() {
    Person person("jeffy", 12);
    Home* home = new Home("杭州");
    person.setHome(home);

    cout << person.toString() << endl;
    return 0;
}