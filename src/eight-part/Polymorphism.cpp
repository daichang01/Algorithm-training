#include <iostream>
using namespace std;


// 基类 Person
class Person {
public:
    virtual void introduce() const { // 虚函数
        cout << "我是一个人。" << endl;
    }

    // 重载（Overload）
// 重载是指在同一个类中有多个同名函数，它们的参数列表不同。
// 在Person类中添加重载示例
        // 重载函数 introduce，增加一个年龄参数
    virtual void introduce(int age) const {
        cout << "我是一个" << age << "岁的人。" << endl;
    }
};

// 覆盖（Override）
// 覆盖是面向对象编程中的一个概念，子类重新定义父类中有相同名称和参数列表的虚函数。
// 子类 Student
class Student : public Person {
public:
    void introduce() const override { // 覆盖父类的虚函数
        cout << "我是一个学生。" << endl;
    }
};

// 子类 Athlete
class Athlete : public Person {
public:
    void introduce() const override { // 覆盖父类的虚函数
        cout << "我是一个运动员。" << endl;
    }
};

void introducePerson(const Person& person) {
    person.introduce();
}




int main() {
    Person person;
    Student student;
    Athlete athlete;

    // 通过父类引用调用介绍方法，展示覆盖（多态性）
    introducePerson(person);  // 输出: 我是一个人。
    introducePerson(student); // 输出: 我是一个学生。
    introducePerson(athlete); // 输出: 我是一个运动员。

    // 直接调用重载方法
    person.introduce(30); // 输出: 我是一个30岁的人。

    return 0;
}


