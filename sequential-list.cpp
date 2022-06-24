#include <iostream>
#include "sequential-list.h"
using namespace  std;

SequentialList::SequentialList(unsigned int cap)
{
    size_ = 0;
    data_ = new DataType[cap];
    capacity_ = cap;
}

SequentialList::~SequentialList()
{
    delete data_;
    data_ = NULL;
}

unsigned int SequentialList::size() const
{
    return size_;
}

unsigned int SequentialList::capacity() const
{
    return capacity_;
}

bool SequentialList::empty() const
{
    return size_ == 0;
}

bool SequentialList::full() const
{
    return size_ == capacity_;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
    if (size_ == 0)
    {
        return data_[size_];
    }
    else if (index < size_)
    {
        return data_[index];
    }
    else
    {
        return data_[size_ - 1];
    }
}

unsigned int SequentialList::search(DataType val) const
{
    for (int i = 0; i < size_; i++)
    {
        if (data_[i] == val)
        {
            return i;
        }
    }
    return size_;
}

void SequentialList::print() const
{
    if (size_ > 0)
    {
        for (int i = 0; i < size_; i++) {
            cout << data_[i] << " ";
        }
        cout << endl;
    }
}

bool SequentialList::insert(DataType val, unsigned int index)
{
    if (index == 0)
    {
        insert_front(val);
        return true;
    }
    else if (index == size_)
    {
        insert_back(val);
        return true;
    }
    else if (index < size_ && not full())
    {
        for (unsigned int i = size_  - 1; i >= index; i--)
        {
            data_[i + 1] = data_[i];
        }
        data_[index] = val;
        size_++;
        return true;
    }
    else
    {
        return false;
    }
}

bool SequentialList::insert_front(DataType val)
{
    if (not full())
    {
        if (empty())
        {
            data_[0] = val;
            size_++;
            return true;
        }
        else
        {
            for (int i = size_ - 1; i >= 0; i--) {
                data_[i + 1] = data_[i];
            }
            data_[0] = val;
            size_++;
            return true;
        }
    }
    else
    {
        return false;
    }
}

bool SequentialList::insert_back(DataType val)
{
    if (not full())
    {
        data_[size_++] = val;
        return true;
    }
    else
    {
        return false;
    }
}

bool SequentialList::remove(unsigned int index)
{
    if (index + 1 == size_)
    {
        size_ -=  1;
        return true;
    }
    else if (index + 1 < size_)
    {
        for (unsigned int i = index; i < size_; i++)
        {
            data_[i] = data_[i + 1];
        }
        size_--;
        return true;
    }
    else
    {
        return false;
    }
}

bool SequentialList::remove_front()
{
    if (not empty())
    {
        for (int i = 1; i < size_; i++)
        {
            data_[i-1] = data_[i];
        }
        size_--;
        return true;
    }
    else
    {
        return false;
    }
}

bool SequentialList::remove_back()
{
    if (size_ != 0)
    {
        size_--;
        return true;
    }
    else
    {
        return false;
    }
}

bool SequentialList::replace(unsigned int index, DataType val)
{
    if (index + 1 <= size_)
    {
        data_[index] = val;
        return true;
    }
    return false;
}

