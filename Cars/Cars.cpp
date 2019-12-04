#include <iostream>
#include <string>
using namespace std;

class Human
{
public:
    Human(string Name, int Age)
    {
        this->Name = Name;
        this->Age = Age;
    }

    void SayHello()
    {
        cout << "Привет, меня зовут " << GetName() << endl;
    }

    string GetName()
    {
        return Name;
    }

private:
    string Name;
    int Age;
};

class Vehicle
{
public:
    Vehicle(string Model, string Color)
    {
        this->Model = Model;
        this->Color = Color;
    }

    void GetIn(Human &p)
    {
        cout << "Я "<< GetModel() << ", в меня сел " << p.GetName() << "!" << endl;
    }

    void StartTheCar()
    {
        cout << "ВРУМ! ВРУМ! ВРУМ!, я завёлся!" << endl;
    }

    void Drive()
    {
        cout << "Я " << GetModel() << ", я еду!" << endl;
    }

    virtual void Brake()
    {

    }

    void GetOut(Human& p)
    {
        
        cout << "Я " << GetModel() << ", из меня вышел " << p.GetName() << "!" << endl;
    }

    string GetModel()
    {
        return Model;
    }
private:
    string Model;
    string Color;
};

class Car : public Vehicle
{
public:
    Car(string Model, string Color):Vehicle(Model, Color)
    {

    }

    void Brake() override
    {
        cout << "Я АВТОМОБИЛЬ " << GetModel() << ", я торможу БЫСТРО!" << endl;
    }
};

class Truck : public Vehicle
{
public:
    Truck(string Model, string Color):Vehicle(Model, Color)
    {

    }

    void Brake() override
    {
        cout << "Я ГРУЗОВИК " << GetModel() << ", я торможу МЕДЛЕННО!" << endl;
    }
};


int main()
{
    setlocale(LC_ALL, "Ru");

    Human p1("Петр", 36);
    p1.SayHello();

    Car c1("lada granta", "зеленый");
    c1.GetIn(p1);
    c1.Drive();
    c1.Brake();
    c1.GetOut(p1);

    Truck t1("Газель", "серый");
    t1.GetIn(p1);
    t1.Drive();
    t1.Brake();
    t1.GetOut(p1);

    return 0;

}