#ifndef UNITY_H
#define UNITY_H
#include "unity.h"
#endif

#include "code.hpp"
#include <cmath>
#include <iostream>
#include <numbers>

// ============================================================
// PART 1 Tests: Shapes
// ============================================================

/// Create Circle(1), Square(2), Rectangle(2, 3).
/// Verify area() is pi, 4 and 6 (compare doubles with std::fabs(a - b) < 1e-9).
void test_shape_areas(void)
{

    Circle* c= new Circle(1);
    Square* s= new Square(2);
    Rectangle* r= new Rectangle(2,3);
    TEST_ASSERT_TRUE_MESSAGE(c->area()==std::numbers::pi, "test_shape_areas FAIL 1");
    TEST_ASSERT_TRUE_MESSAGE(s->area()==4, "test_shape_areas FAIL 2");
    TEST_ASSERT_TRUE_MESSAGE(r->area()==6, "test_shape_areas FAIL 3");
    delete c;
    delete s;
    delete r;
}

/// Create an array of three Shape* (a Circle, a Square, a Rectangle) with new.
/// Verify name() through the BASE pointer gives "Circle", "Square", "Rectangle".
/// Delete the shapes through the base pointers.
void test_shape_names_through_base_pointer(void)
{
    Shape* shapes[3];
    shapes[0]= new Circle(1);
    shapes[1]= new Square(2);
    shapes[2]= new Rectangle(2,3);
    TEST_ASSERT_TRUE_MESSAGE(shapes[0]->name()=="Circle", "test_shape_names_through_base_pointer FAIL 1");
    TEST_ASSERT_TRUE_MESSAGE(shapes[1]->name()=="Square", "test_shape_names_through_base_pointer FAIL 1");
    TEST_ASSERT_TRUE_MESSAGE(shapes[2]->name()=="Rectangle", "test_shape_names_through_base_pointer FAIL 1");

    for (size_t i = 0; i < 3; i++)
    {
        delete shapes[i];
    }
    
}

/// Create Square(1) and Square(2). Take two const Shape& to them.
/// Verify small < big is true, big < small is false, small < small is false.
void test_shape_operator_less(void)
{
    Square s1=Square(1);
    Square s2=Square(2);
    TEST_ASSERT_TRUE_MESSAGE(s1<s2, "test_shape_operator_less FAIL 1");
    TEST_ASSERT_TRUE_MESSAGE(!(s2<s1), "test_shape_operator_less FAIL 2");
}

/// Create Square(2) and Rectangle(1, 4): both have area 4.
/// Verify that NEITHER a < b NOR b < a is true.
void test_shape_equal_area_not_less(void)
{
    Square s=Square(2);
    Rectangle r=Rectangle(1,4);
    TEST_ASSERT_TRUE_MESSAGE(!(s<r), "test_shape_equal_area_not_less FAIL 1");
    TEST_ASSERT_TRUE_MESSAGE(!(r<s), "test_shape_equal_area_not_less FAIL 2");
}

// ============================================================
// PART 2 Tests: ShapeList
// ============================================================

/// Create a ShapeList. Add new Circle(1) and new Square(2) with addShape.
/// Verify both calls return 0 and length() is 2.
/// (Do NOT delete the shapes yourself: the list owns them.)
void test_list_add_and_length(void)
{
    ShapeList shapes=ShapeList();

    TEST_ASSERT_TRUE_MESSAGE(shapes.addShape(new Circle(1))==0, "test_list_add_and_length FAIL 1");
    TEST_ASSERT_TRUE_MESSAGE(shapes.addShape(new Square(2))==0, "test_list_add_and_length FAIL 2");
    TEST_ASSERT_TRUE_MESSAGE(shapes.length()==2, "test_list_add_and_length FAIL 3");
}

/// Create a ShapeList. Call addShape(nullptr).
/// Verify it returns -1 and length() stays 0.
void test_list_add_null_guard(void)
{
    ShapeList shapes=ShapeList();
    
    TEST_ASSERT_TRUE_MESSAGE(shapes.addShape(nullptr)==-1, "test_list_add_null_guard FAIL 1");
    TEST_ASSERT_TRUE_MESSAGE(shapes.length()==0, "test_list_add_null_guard FAIL 2");
}

/// Add Rectangle(2, 5) (area 10), Circle(1) (area 3.14), Square(2) (area 4).
/// Call insertionSort(). Verify nameAt(0), nameAt(1), nameAt(2) are
/// "Circle", "Square", "Rectangle" and isSorted() is true.
void test_insertionSort_orders_by_area(void)
{
    ShapeList shapes=ShapeList();
    shapes.addShape(new Rectangle(2, 5));
    shapes.addShape(new Circle(1));
    shapes.addShape(new Square(2));

    shapes.insertionSort();
    TEST_ASSERT_TRUE_MESSAGE(0, "TODO: Implement this test");
}

/// Call insertionSort() on an EMPTY list: no crash, length() is 0.
/// Then add ONE shape and sort again: length() is 1 and nameAt(0) is unchanged.
void test_insertionSort_empty_and_single(void)
{
    TEST_ASSERT_TRUE_MESSAGE(0, "TODO: Implement this test");
}
