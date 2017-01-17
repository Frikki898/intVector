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
    capacity = INITIAL_CAPACITY;
    array = new int[capacity];

    for(int i = 0; i < size; i++)
    {
        array[i] = value;
        count++;
    }
    count = size;
}

IntVector::IntVector(const IntVector& vec)
    : capacity(vec.capacity), count(vec.count) {
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
    if(count == capacity)
    {
        resizeArrayCheck();
    }

    array[count] = elem;
    count++;
}

void IntVector::insert(int index, int elem) {
    resizeArrayCheck();
    for(int i = count; i > index; i--)
    {
        array[i] = array[i-1];
    }
    array[index] = elem;
    count++;
}

int IntVector::at(int index) const {
    if(index > count || index < 0)
    {
        //kasta error
    }
    else
    {
        return array[index];
    }
}

void IntVector::set_value_at(int index, int elem) {
    array[index] = elem;
}

int IntVector::size() const {
    return count;
}

bool IntVector::empty() const {
    if(capacity == 0)
    {
        return true;
    }
    return false;
}

void IntVector::remove_at(int index) {
    for(int i = index; i < count; i++)
    {
        cout << array[index] << " becomes " << array[index+1] << endl;
        array[i] = array[i+1];
    }

    array[count-1] = NULL;
    count--;
}

int IntVector::pop_back() {
    int popped = 0;

    popped = array[count-1];
    array[count-1] = NULL;

    count--;

    return popped;
}

void IntVector::clear() {
    for(int i = 0; i < count; i++)
    {
        array[i] = NULL;
    }
    count = 0;
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
    // TODO: Throw exception if index is out of range.
    return array[index];
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
