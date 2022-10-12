#include <iostream>
#include"intArray.h"

using namespace std;


int main()
{
    IntArray a(10);
    /*IntArray a1(-10);*/
    a.reallocate(9);
    a.insertBefore(11, 1);
    /*a.operator[](-12);*/
    a.operator[](1);
    /*a.insertBefore(12, -1);*/
    a.getLength(); 
    a.remove(5);
    /*a.remove(-6);*/
      
    return 0;
