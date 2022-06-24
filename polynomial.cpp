#include "polynomial.h"
#include <iostream>
#include <string>
using namespace std;
Polynomial::Polynomial(int A[], int size) {
    for (int i = 0; i < size; i++)
    {
        coefficients.insert_back(A[i]);
    }
    size_ = size;
}
Polynomial* Polynomial::add(Polynomial* rhs) {
    int arr[size_];
    int max_size = max(size_, rhs -> size_);
    for (int i = 0; i < max_size; i++)
    {
        if(i + 1 > size_)
        {
            arr[i] = rhs -> coefficients.select(i);
        }
        else if (i + 1 > rhs -> size_)
        {
            arr[i] = coefficients.select(i);
        }
        else
        {
            arr[i] = coefficients.select(i) + rhs -> coefficients.select(i);
        }
    }
    Polynomial* result_pointer = new Polynomial(arr, size_);
    return result_pointer;
}
Polynomial* Polynomial::sub(Polynomial* rhs) {
    int arr[size_];
    int max_size = max(size_, rhs -> size_);
    for (int i = 0; i < max_size; i++)
    {
        if(i + 1 > size_)
        {
            arr[i] = -1 * rhs -> coefficients.select(i);
        }
        else if (i + 1 > rhs -> size_)
        {
            arr[i] = coefficients.select(i);
        }
        else
        {
            arr[i] = coefficients.select(i) - rhs -> coefficients.select(i);
        }
    }
    Polynomial* result_pointer = new Polynomial(arr, size_);
    return result_pointer;
}
Polynomial* Polynomial::mul(Polynomial* rhs) {
    int max_size = size_ + rhs -> size_ - 1;
    int products[max_size];
    for (int i = 0; i < max_size; i++)
    {
        products[i] = 0;
    }
    for (int j = 0; j < size_; j++)
    {
        for (int k = 0; k < rhs -> size_; k++)
        {
            products[j+k] += (coefficients.select(j)*rhs -> coefficients.select(k));
        }
    }
    Polynomial* result_pointer = new Polynomial(products, max_size);
    return result_pointer;
}
void Polynomial::print() {
    int final_index;
    for (int i = 0; i < size_; i++)
    {
        if (coefficients.select(i) != 0)
        {
            final_index = i;
            break;
        }
    }
    for (int i = size_; i > 0; i--)
    {
        if (coefficients.select(i - 1) > 0)
        {
            cout << coefficients.select(i - 1) << "x^" << i - 1 << (i != final_index + 1 ? " + " : "");
        }
        else if (coefficients.select(i - 1) < 0)
        {
            cout << "(" << coefficients.select(i - 1) << ")" << "x^" << i - 1 << (i != final_index + 1 ? " + " : "");
        }
    }
    cout << endl;
}
