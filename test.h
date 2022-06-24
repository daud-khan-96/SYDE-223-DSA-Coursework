#ifndef A1_TESTS_HPP
#define A1_TESTS_HPP

#include "doubly-linked-list.h"
#include "sequential-list.h"
#include "polynomial.h"

#define ASSERT_TRUE(T) \
    if (!(T))          \
        return false;
#define ASSERT_FALSE(T) \
    if ((T))            \
        return false;


class PolynomialTest
{
public:
    void test1()
    {
        int a[] = {1, 0, 0, -2, 3, 5};
        int size = 6;
        Polynomial poly(a, size);
        poly.print();
    }
    void test2()
    {
        int a[] = {0, 0, -3, 0, 0};
        int size = 5;
        Polynomial poly(a, size);
        poly.print();
    }

};

#endif
