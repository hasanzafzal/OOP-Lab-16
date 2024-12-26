#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string name;
public:
    Animal(string name) : name(name) {}
    virtual string makeSound() = 0;
};

class Dog : public Animal {
public:
    Dog(string name) : Animal(name) {}
    string makeSound() override {
        cout << name << " the dog is with the ";
        return "Woof!";
    }
};

class cat : public Animal {
public:
    cat(string name) : Animal(name) {}
    string makeSound() override {
        cout << name << " the cat is with the ";
        return "Meow!";
    }
};

class Person {
protected:
    string name;
    int age;
public:
    Person(string name, int age) : name(name), age(age) {}
};

class worker {
protected:
    string jobTitle;
public:
    worker(string jobTitle) : jobTitle(jobTitle) {}
};

class Veterinarian : public Person, worker {
public:
    Veterinarian(string name, int age, string jobTitle) : Person(name, age), worker(jobTitle) {}
    void work(Animal* animal) {
        cout << jobTitle << " : " << name << " is taking care of..." << animal->makeSound() << endl;
    }
};

class Caretaker : public Person, worker {
public:
    Caretaker(string name, int age, string jobTitle) : Person(name, age), worker(jobTitle) {}
    void work(Animal* animal) {
        cout << jobTitle << " : " << name << " is taking care of..." << animal->makeSound() << endl;
    }
};

int main() {
    Animal* animals[2];
    animals[0] = new Dog("Spike");
    animals[1] = new cat("Tom");
    Veterinarian vet("Dr.Hashir", 20, "Veterinarian");
    Caretaker caretaker("Waleed", 22, "Caretaker");
    vet.work(animals[0]);
	caretaker.work(animals[1]);
    return 0;
}