#include <iostream>
#include <string>


//Наследование (inheritance):

class Animal {
    public:
        void eat() const { std::cout << name << " eats" << std::endl; }
        void sleep() const { std::cout << name << "Animal sleeps" << std::endl; }
        void set_name(std::string name) {this -> name = name;}
    protected:
        std::string name;
        int id;
    private:
        static int curr_id;
};

class Dog : public Animal{
    public:
        void bark() {std::cout << name << " barks" << std::endl;} 
};

//Dog получил public методы и protected поля Animal 

//Агрегирование (Composition):

class Engine {
    public:
        void start() const { std::cout << "Engine started" << std::endl; }

};

class Car {
    public:
        void start_car() {
            zmz.start();
            std::cout << "Car is ready to go!" << std::endl; 
        }
    private:
        Engine zmz;
};

//Класс Car имеет объект класса Engine в качестве своего поля
//Внутри Car можно пользоваться методами Engine.

/*Типы наследования (public, protected, private)

1) Public:

    public -> public
    protected -> protected
    private -> недоступно в дочернем классе

2) Protected:

    public -> protected
    protected -> protected
    private -> недоступно в дочернем классе

2) Private:

    public -> private
    protected -> private
    private -> недоступно в дочернем классе

*/

//private - видно только внутри класса, 
//protected - внутри класса и дочерних. 

//Дружественные классы (friend) - доступ ко всем членам.

class Safe {
    friend class Collector;
    int money = 10000;
};

class Collector {
    public:

        void fill_bag(int money) {
            bag = money;
        }

        int empty_bag() {
            int temp = bag;
            bag = 0;
            return temp;
        }

        void get_money(Safe &s) {
            fill_bag(s.money);
            s.money = 0;
            std::cout << "Collector took " << bag << "dollars." << std::endl;    
        }

        void put_money(Safe &s) {
            s.money = empty_bag();
            std::cout << "Collector puted " << s.money << "dollars." << std::endl;
        }

    private:
        int bag;
};

int main() {
    Safe s;
    //s.money - ошибка!;
}

//Конструкторы и наследование:

class Dot {
    public:
        Dot(float x, float y, float z) : x(x), y(y), z(z) {}
        Dot() : x(0.0f), y(0.0f), z(0.0f) {}

        void set_z(float z) {
            this -> z = z;
        }

    protected:
        float x;
        float y;
        float z;
};

class Dot_2d : public Dot{
    public:
        Dot_2d(float x, float y) : Dot(x, y, 0.0f) {}

        void set_cords(float x, float y) {
            this -> x = x;
            this -> y = y;
        }
    private:
        void set_z() {} // Переопреедлили - теперь использование метода из родительского класса запрещено.
};

/*
    Если у родительского класса есть конструктор по умолчанию - constructor(),
    указывать родительский конструктор в списке инициализации не обязательно, т.е можно сделать так:
*/

class Dot_2d : public Dot{
    public:
        Dot_2d(float x, float y) : Dot(x, y, 0.0f) {}

        // и 

        Dot_2d() {}

        void set_cords(float x, float y) {
            this -> x = x;
            this -> y = y;
        }
};

// Инициализация константных (const) и ссылочных (&) полей:

class Example {
public:
    Example(int x, int y) : const_val(x), ref_val(y) {} // константные и ссылочные поля должны быть инициализированны до тела конструктора, т.е в списке инициализации.
private:
    const int const_val; // const объекты нельзя менять в теел конструктора, так что сразу инициализируем их числом в списке иниц.
    int& ref_val; // ссылка на int, должна быть инициализирована
};

// Полиморфизм (Polymorphism) - способность объектов вызывать один и тот же метод и по разному его выполнять.

// Полиморфизм требует виртуальную функцию, которая хранится в абстрактном классе (его объекты нельзя создавать):

#include <iostream>
#include <string>

class shape {
    public:
        shape(float x, float y, std::string name) : x(x), y(y), name(name) {}
        virtual float area() const = 0; //в классе вирт. функция - объект создать не получится (класс автоматически стал абстрактным)
        virtual ~shape() {}
    protected:
        float x, y;
        std::string name;
};

class rectangle : public shape {
    public:
        rectangle (float a, float b, float x, float y, std::string name)
        : shape(x, y, name) , a(a), b(b) {}

        float area() const override {
            return a*b;
        }

    private:
        float a, b;
};

class circle : public shape {
    public:
        circle (float radius, float x, float y, std::string name)
        : shape(x, y, name), radius(radius) {}

        float area() const override {
            return 3.14f * radius * radius;
        }
    private:
        float radius;
};

// Ромбовидное наследование (Diamond Problem):

/*                  
                      A
                     / \
                    B   C
                     \ /
                      D

            Откуда вызывать m() в D? 
*/

class A { public: void m() { std::cout << "A::m\n"; } };
class B : public A { };
class C : public A { };
class D : public B, public C { };

int main() {
    D d;
    // d.m(); // ОШИБКА: неоднозначность!
    d.B::m(); // OK: вызываем из B
    d.C::m(); // OK: вызываем из C
}

