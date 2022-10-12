#pragma once
#include <cassert>

class IntArray
{
private:
    int m_length{};
    int* m_data{};
public:

    IntArray() = default;

    IntArray(int);//создать контенер
    ~IntArray();
    void erase();

    int getLength() const;

    int& operator[](int);//получить доступ к элементу массива

    void reallocate(int newLength);

    void resize(int newLength);//изменить размер контенера

    void insertBefore(int value, int i);// вставить перед
    
    void remove(int i);// удаление
           
};
