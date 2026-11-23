#ifndef CODE_HPP
#define CODE_HPP

#include <list>
#include <optional>
#include <string>


using namespace std;


// ============================================================
// PART 1: Abstract class Shape and its derived classes
// ============================================================

/// An abstract shape. It cannot be instantiated: area() and name() are
/// pure virtual, every derived class must provide them.
/// The destructor is virtual (given), so deleting a Circle through a
/// Shape* destroys the whole Circle.
///
/// YOUR TASK (in src/code.cpp):
/// - operator<: return true if THIS shape has a strictly smaller area() than
///   'other'. Use the virtual area() of both sides. Do NOT compare with <=:
///   two shapes with the same area are not "less" than each other.
class Shape
{
   public:  virtual ~Shape() = default;
   public:  virtual double      area() const = 0;
   public:  virtual std::string name() const = 0;

   public:  bool operator<(const Shape &other) const;
};

/// YOUR TASK (in src/code.cpp), for Circle, Square and Rectangle:
/// - Constructor: initialize the private fields with a member initializer list.
/// - area(): Circle: pi * radius * radius (use std::numbers::pi from <numbers>),
///           Square: side * side, Rectangle: width * height.
/// - name(): return exactly "Circle", "Square" or "Rectangle".
class Circle : public Shape
{
   private: double radius;

   public:  explicit Circle(double newRadius);
   public:  double      area() const override;
   public:  std::string name() const override;
};

class Square : public Shape
{
   private: double side;

   public:  explicit Square(double newSide);
   public:  double      area() const override;
   public:  std::string name() const override;
};

class Rectangle : public Shape
{
   private: double width;
   private: double height;

   public:  Rectangle(double newWidth, double newHeight);
   public:  double      area() const override;
   public:  std::string name() const override;
};

// ============================================================
// PART 2: Class ShapeList (a wrapper around std::list<Shape*>)
// ============================================================

/// A list of shapes that OWNS them. The caller creates a shape with 'new'
/// and hands the pointer over with addShape. From then on only ShapeList
/// may delete it.
///
/// ENCAPSULATION RULE: the implementation stays hidden. No public method
/// returns a Shape* or a std::list iterator: the outside world sees only
/// numbers, strings and counts.
///
/// YOUR TASK (in src/code.cpp): implement every method below.
///
///  ~ShapeList()   : Delete EVERY shape (RAII), then clear the list.
///  addShape       : Append the shape at the END of the list. Return -1 and
///                   change nothing if newShapePtr is nullptr, 0 on success.
///  removeFirst    : Delete the first shape and remove it from the list.
///                   Return false if the list is empty, true otherwise.
///  length         : Return the number of shapes.
///  totalArea      : Return the sum of area() of all shapes (0.0 if empty).
///  printList      : Print every shape on its own line to std::cout:
///                   its name(), one space, its area(). Return the number of
///                   printed shapes (0 for an empty list).
///  areaAt         : area() of the shape at the given 0-based index, or
///                   std::nullopt if the index is outside the list.
///                   (std::list has no operator[]: use std::next.)
///  nameAt         : name() of the shape at the given index, or std::nullopt.
///  insertionSort  : Sort the list in place, from the smallest to the largest
///                   area, with YOUR OWN insertion sort. Compare SHAPES with
///                   operator<, never pointers: a pointer comparison compares
///                   ADDRESSES. The sort must be STABLE: shapes with equal area
///                   keep their order. Do not copy the shapes. Hint: the
///                   std::list method splice moves one element in Θ(1).
///  isSorted       : Return true if no shape is smaller than the one before it.
///                   An empty list and a one-element list are sorted.
class ShapeList
{
   private: std::list<Shape *> data;

   public:  ShapeList() = default;
   public:  ~ShapeList();

   public:  int  addShape(Shape *newShapePtr);
   public:  bool removeFirst();
   public:  int  length() const;
   public:  double totalArea() const;
   public:  int  printList() const;

   public:  std::optional<double>      areaAt(int index) const;
   public:  std::optional<std::string> nameAt(int index) const;

   public:  void insertionSort();
   public:  bool isSorted() const;

   // given: copying a list would create two owners of the same shapes
   public:  ShapeList(const ShapeList &) = delete;
   public:  ShapeList &operator=(const ShapeList &) = delete;
};

#endif
