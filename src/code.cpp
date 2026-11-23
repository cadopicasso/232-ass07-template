// ============================================================
// CSCI 232 Assignment 07 – Shapes, Polymorphism and Insertion Sort
// Student Implementation
// ============================================================

#include "code.hpp"
#include <iostream>
#include <iterator>
#include <numbers>

// Uncomment the author block below and fill in your name:

std::string AUTHOR_NAME       = "Caden Johns";
std::string AUTHOR_AUTHORSHIP = "I acknowledge that I have worked on this "
"assignment independently, except where explicitly noted and referenced. "
"Any collaboration or use of external resources has been properly cited. "
"I am fully aware of the consequences of academic dishonesty and agree "
"to abide by the university's academic integrity policy.";

// ============================================================
// PART 1: Shape, Circle, Square, Rectangle
// ============================================================

/// True if THIS shape has a strictly smaller area() than other.
bool Shape::operator<(const Shape &other) const
{
    // TODO: compare area() of both shapes with <
    return area()<other.area();
}

/// Constructor with a member initializer list.
Circle::Circle(double newRadius)
{
    radius=newRadius;
}

/// pi * radius * radius, use std::numbers::pi
double Circle::area() const
{
    
    // TODO: implement
    return std::numbers::pi * radius * radius;
}

/// Return exactly "Circle".
std::string Circle::name() const
{
    // TODO: implement
    return "Circle";
}

Square::Square(double newSide)
{
    side=newSide;
}

/// side * side
double Square::area() const
{
    // TODO: implement
    return side*side;
}

/// Return exactly "Square".
std::string Square::name() const
{
    // TODO: implement
    return "Square";
}

Rectangle::Rectangle(double newWidth, double newHeight)
{
    width=newWidth;
    height=newHeight;
}

/// width * height
double Rectangle::area() const
{
    // TODO: implement
    return width*height;
}

/// Return exactly "Rectangle".
std::string Rectangle::name() const
{
    // TODO: implement
    return "Rectangle";
}

// ============================================================
// PART 2: ShapeList
// ============================================================

/// RAII: delete EVERY shape, then clear the list.
ShapeList::~ShapeList()
{
    for (auto s : data)
    {
        delete s;
    }
    
}

/// Append at the end. Return -1 if newShapePtr is nullptr, 0 on success.
int ShapeList::addShape(Shape *newShapePtr)
{
    if(newShapePtr==nullptr){
        return -1;
    }
    
    data.push_back(newShapePtr);

    return 0;
}

/// Delete the first shape and remove it from the list.
/// Return false if the list is empty, true otherwise.
bool ShapeList::removeFirst()
{
    if (data.size()==0){
        return false;
    }
    
    data.pop_front();
    return 0;
}

/// Number of shapes in the list.
int ShapeList::length() const
{
    return data.size();
}

/// Sum of area() of all shapes (0.0 if empty).
double ShapeList::totalArea() const
{
    double total=0;

    for (auto s: data){
        total+=s->area();
    }
    return total;
}

/// One line per shape: name, one space, area. Return the number of shapes.
int ShapeList::printList() const
{
    for (auto s: data){
        printf("%s %f\n",s->name().c_str(),s->area());
    }
    return data.size();
}

/// area() of the shape at index, or std::nullopt if index is out of range.
/// Hint: std::next(data.begin(), index)
std::optional<double> ShapeList::areaAt(int index) const
{

    auto result=std::next(data.begin(), index);
    if (result==data.end()){
        return std::nullopt;
    }
    return (*result)->area();
    
}

/// name() of the shape at index, or std::nullopt if index is out of range.
std::optional<std::string> ShapeList::nameAt(int index) const
{
    auto result=std::next(data.begin(), index);
    if (result==data.end()){
        return std::nullopt;
    }
    return (*result)->name();
}

/// Your own STABLE insertion sort, smallest area first.
/// Compare shapes with operator< (dereference the pointers!).
/// Hint: for every element, walk left while the previous shape is bigger,
/// then move the element there with data.splice(...).
void ShapeList::insertionSort()
{

    list<Shape*> sorted;
    list<Shape*> unsorted;

    for(auto s : data){
        unsorted.push_back(s);
    }

    Shape* checkShape;
    sorted.push_back(data.front());
    for (size_t i = 0; i < unsorted.size(); i++)
    {
        checkShape=unsorted.front();
        for (size_t i = 0; i < sorted.size(); i++)
        {
            if(*next(sorted.begin(),i)<checkShape){
                sorted.emplace(next(sorted.begin(),i), checkShape);
            }
        }
        
    }
    for(auto s: sorted){
        cout<<s->area()<<endl;
    }
    
}

/// True if no shape is smaller than the one before it.
bool ShapeList::isSorted() const
{
    // TODO: implement
    return false;
}
