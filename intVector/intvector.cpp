#include <cmath>
#include "IntVector.h"

using namespace std;

// Constructors

IntVector::IntVector() {
    count = 0;
    capacity = INITIAL_CAPACITY;
    array = new int[capacity];
}

IntVector::IntVector(int size, int value) {
    count = 0;
    capacity = INITIAL_CAPACITY;
    array = new int[capacity];

    if(size >= 0)
    {
        for(int i = 0; i < size; i++)
        {
            resizeArrayCheck();
            array[i] = value;
            count++;
        }
    }
}

IntVector::IntVector(const IntVector& vec) : capacity(vec.capacity), count(vec.count) {
    array = new int[capacity];

    for(int i = 0; i < count; i++) {
        array[i] = vec.array[i];
    }
}

IntVector::~IntVector() {
    if(array != NULL)
    {
        delete[] array;
    }
    count = 0;
}

// Public member functions

void IntVector::push_back(int elem) {
    resizeArrayCheck();

    array[count] = elem;
    count++;
}

void IntVector::insert(int index, int elem) {

    if(index > count || index < 0)
    {
        throw IndexOutOfRangeException();
    }
    else
    {
        resizeArrayCheck();
        for(int i = count; i > index; i--)
        {
            array[i] = array[i-1];
        }
        array[index] = elem;
        count++;
    }

}

int IntVector::at(int index) const {
    if(index > count-1 || index < 0)
    {
        throw IndexOutOfRangeException();
    }
    else
    {
        return array[index];
    }
}

void IntVector::set_value_at(int index, int elem) {
    if(index >= count || index < 0)
    {
        throw IndexOutOfRangeException();
    }
    else
    {        
        array[index] = elem;
    }
}

int IntVector::size() const {
    return count;
}

bool IntVector::empty() const {
    if(count == 0)
    {
        return true;
    }
    return false;
}

void IntVector::remove_at(int index) {
    if(count == 0)
    {
        throw IndexOutOfRangeException();
    }
    else if(index >= count || index < 0)
    {
        throw IndexOutOfRangeException();
    }
    else
    {
        for(int i = index; i < count; i++)
        {
            array[i] = array[i + 1];
        }
        count--;
    }

}

int IntVector::pop_back() {
    if(count == 0)
    {
        throw EmptyException();
    }
    else
    {
        int popped = 0;

        popped = array[count-1];

        count--;

        return popped;

    }
}

void IntVector::clear() {
    int howManyInList = count;
    for(int i = 0; i < howManyInList; i++)
    {
        pop_back();
    }
}

// Overloaded operators

void IntVector::operator=(const IntVector& vec) {
    if(capacity < vec.capacity) {
        delete [] array;
        array = new int[vec.capacity];
    }

    capacity = vec.capacity;
    count = vec.count;

    for(int i = 0; i != count; i++) {
        array[i] = vec.array[i];
    }
}

int& IntVector::operator[] (int index) {
    if(index > count-1 || index < 0)
    {
        throw IndexOutOfRangeException();
    }
    else
    {
        return array[index];
    }


}

ostream& operator<< (ostream& out, const IntVector& rhs) {
    for(int i = 0; i < rhs.size(); i++) {
        if(i > 0) {
            out << " ";
        }
        out << rhs.at(i);
    }
    return out;
}

void IntVector::resizeArrayCheck()
{
    if(count == capacity)
    {
        capacity *= 2;

        int *tempArray = new int[capacity];

        for(int i = 0; i < count; i++)
        {
            tempArray[i] = array[i];
        }
        delete[] array;

        array = tempArray;
    }
}
