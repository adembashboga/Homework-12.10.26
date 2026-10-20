#include <iostream>
using namespace std;

template <typename T>
class Array {
private:
    T* data;
    int size;
    int grow;

public:
    Array() : data(nullptr), size(0), grow(1) {}

    ~Array() { delete[] data; }

    int GetSize() const { return size; }

    void SetSize(int newSize, int newGrow = 1) 
    {
        grow = newGrow;
        if (newSize == size) return;

        T* newData = newSize > 0 ? new T[newSize] : nullptr;
        int copySize = (newSize < size) ? newSize : size;

        for (int i = 0; i < copySize; ++i)
            newData[i] = data[i];

        delete[] data;
        data = newData;
        size = newSize;
    }

    int GetUpperBound() const { return size - 1; }

    bool IsEmpty() const { return size == 0; }

    void FreeExtra() {}

    void RemoveAll() { SetSize(0); }

    T GetAt(int index) const { return data[index]; }

    void SetAt(int index, T value) { data[index] = value; }

    T& operator[](int index) { return data[index]; }

    void Add(T value) 
    {
        SetSize(size + 1, grow);
        data[size - 1] = value;
    }

    void Append(const Array& other) 
    {
        int oldSize = size;
        SetSize(size + other.size);
        for (int i = 0; i < other.size; ++i)
            data[oldSize + i] = other.data[i];
    }

    T* GetData() { return data; }

    void InsertAt(int index, T value) 
    {
        SetSize(size + 1);
        for (int i = size - 1; i > index; --i)
            data[i] = data[i - 1];
        data[index] = value;
    }

    void RemoveAt(int index) 
    {
        for (int i = index; i < size - 1; ++i)
            data[i] = data[i + 1];
        SetSize(size - 1);
    }
};