// 1. SHAPE CLASS HIERARCHY
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

class Shape {
public:
    virtual double area() const = 0;
    virtual void draw() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return M_PI * radius * radius; }
    void draw() const override { std::cout << "Drawing Circle\n"; }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override { return width * height; }
    void draw() const override { std::cout << "Drawing Rectangle\n"; }
};

class Triangle : public Shape {
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() const override { return 0.5 * base * height; }
    void draw() const override { std::cout << "Drawing Triangle\n"; }
};

void testShapes() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.emplace_back(std::make_unique<Circle>(5));
    shapes.emplace_back(std::make_unique<Rectangle>(4, 6));
    shapes.emplace_back(std::make_unique<Triangle>(3, 7));

    for (const auto& shape : shapes) {
        shape->draw();
        std::cout << "Area: " << shape->area() << "\n";
    }
}

// 2. ZOO MANAGEMENT SYSTEM
class Animal {
public:
    virtual void makeSound() const = 0;
    virtual ~Animal() {}
};

class Lion : public Animal {
public:
    void makeSound() const override {
        std::cout << "Roar!\n";
    }
};

class Elephant : public Animal {
public:
    void makeSound() const override {
        std::cout << "Trumpet!\n";
    }
};

void zoo() {
    std::vector<std::unique_ptr<Animal>> animals;
    animals.emplace_back(std::make_unique<Lion>());
    animals.emplace_back(std::make_unique<Elephant>());

    for (const auto& animal : animals) {
        animal->makeSound();
    }
}

// 3. SIMPLE MEMORY MANAGER (RAII)
class Resource {
    int* data;
public:
    Resource(size_t size) {
        data = new int[size];
        std::cout << "Resource allocated\n";
    }
    ~Resource() {
        delete[] data;
        std::cout << "Resource deallocated\n";
    }
};

void useResource() {
    Resource r(10);
    // do something with r
}

// 4. SIMPLIFIED SMART POINTER
template<typename T>
class MyUniquePtr {
    T* ptr;
public:
    explicit MyUniquePtr(T* p = nullptr) : ptr(p) {}
    ~MyUniquePtr() { delete ptr; }

    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }

    // Disable copy
    MyUniquePtr(const MyUniquePtr&) = delete;
    MyUniquePtr& operator=(const MyUniquePtr&) = delete;

    // Move support
    MyUniquePtr(MyUniquePtr&& other) noexcept : ptr(other.ptr) { other.ptr = nullptr; }
    MyUniquePtr& operator=(MyUniquePtr&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }
};

void testSmartPointer() {
    MyUniquePtr<int> p(new int(42));
    std::cout << *p << "\n";
}

// 5. PLUGIN MANAGER
class Plugin {
public:
    virtual void execute() const = 0;
    virtual ~Plugin() {}
};

class PluginA : public Plugin {
public:
    void execute() const override {
        std::cout << "Plugin A executed\n";
    }
};

class PluginB : public Plugin {
public:
    void execute() const override {
        std::cout << "Plugin B executed\n";
    }
};

void runPlugins() {
    std::vector<std::unique_ptr<Plugin>> plugins;
    plugins.emplace_back(std::make_unique<PluginA>());
    plugins.emplace_back(std::make_unique<PluginB>());

    for (const auto& plugin : plugins) {
        plugin->execute();
    }
}

int main() {
    testShapes();
    std::cout << "---\n";
    zoo();
    std::cout << "---\n";
    useResource();
    std::cout << "---\n";
    testSmartPointer();
    std::cout << "---\n";
    runPlugins();
    return 0;
}
