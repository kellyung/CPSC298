/// @file Project_Inheritance.cpp
/// @brief Implementation file for Shape class
/// @author kelung@chapman.edu
/// CPSC 298-6 Colloquium: Programming in C++

#include <iostream>
#include <cmath>

class Shape
{
public:
    Shape() : m_dHeight(0.0), m_dWidth(0.0) {
//        std::cout << "Shape constructor 1 is called" << std::endl;
    }
    Shape(double dHeight, double dWidth) : m_dHeight(dHeight), m_dWidth(dWidth) {
//        std::cout << "Shape constructor is called" << std::endl;
        m_dHeight = dHeight;
        m_dWidth = dWidth;
        m_strType = "Shape";
    }

    virtual ~Shape() {
//        std::cout << "Shape destructor is called" << std::endl;
    }
    virtual void scale(double dScaleFactor) = 0;
    virtual double area() = 0;
    virtual double perimeter() = 0;

    virtual void displayProperties() {
        std::cout << "Shape Type: " << m_strType << ", height: " << m_dHeight << " width: " << m_dWidth << std::endl;
    }

protected:
    double m_dHeight;
    double m_dWidth;
    std::string m_strType;
};

class Rectangle : public Shape
{
public:
    Rectangle() {
//        std::cout << "Rectangle constructor 1 is called" << std::endl;
    }
    Rectangle(double dHeight, double dWidth) {
//        std::cout << "Rectangle constructor is called" << std::endl;
        m_dHeight = dHeight;
        m_dWidth = dWidth;
        m_strType = "Rectangle";
    }
    virtual ~Rectangle() {
//        std::cout << "Rectangle destructor is called" << std::endl;
    }
    void scale(double dScaleFactor) {
        m_dHeight = m_dHeight * dScaleFactor;
        m_dWidth = m_dWidth * dScaleFactor;
    }

    double area() {
        return m_dHeight * m_dWidth;
    }

    double perimeter() {
        return (2 * m_dHeight) + (2 * m_dWidth);
    }
};

class Circle : public Shape
{
public:
    Circle() {
//        std::cout << "Circle constructor 1 is called" << std::endl;
    }
    Circle(double dHeight, double dWidth) {
//            std::cout << "Circle constructor is called" << std::endl;
        m_dHeight = dHeight;
        m_dWidth = dWidth;
        m_strType = "Circle";
        }
    virtual ~Circle() {
//        std::cout << "Circle destructor is called" << std::endl;
    }
    void scale(double dScaleFactor) {
        m_dHeight = m_dHeight * dScaleFactor;
        m_dWidth = m_dWidth * dScaleFactor;
    }

    double area() {
        return (1.0/4.0) * M_PI * m_dWidth * m_dWidth;
    }
    double perimeter() {
        return M_PI * m_dWidth;
    }
};


int main() {
    Rectangle* p_shapeRectangle = new Rectangle(2.0, 3.0);
    Circle* p_shapeCircle = new Circle(2.0, 2.0);

    Shape* p_shapes[2];

    p_shapes[0] = p_shapeCircle;
    p_shapes[1] = p_shapeRectangle;

    for (int i = 0; i < 2; i++) {
        p_shapes[i]->displayProperties();
        std::cout << "Area: " << p_shapes[i]->area() << ", Perimeter: " << p_shapes[i]->perimeter() << std::endl;
        p_shapes[i]->scale(2);
        p_shapes[i]->displayProperties();
        std::cout << "Area: " << p_shapes[i]->area() << ", Perimeter: " << p_shapes[i]->perimeter() << std::endl;
    }

    delete p_shapeRectangle;
    delete p_shapeCircle;

    return 0;
}

