#include <iostream>
#include <exception>
#include"intArray.h"
using namespace std;


  

   IntArray::IntArray(int length) 
   {
       try
       {
           m_length = { length };

           if(length <= 0)
           throw std::runtime_error("underflow_error");

           if (length > 0)

               m_data = new int[length]{};
       }
       
       catch(std::runtime_error)
       {
           std::cout <<"length < 0"<< std::endl;
       }
   }


    IntArray::~IntArray()
    {
        delete[] m_data;
    }


    void IntArray::erase()
    {
        delete[] m_data;

        m_data = nullptr;
        m_length = 0;
    }

    int IntArray::getLength() const
    { 
        cout << m_length << endl;
        return m_length;
    }

    int& IntArray:: operator[](int i)
    {
        try
        {
            if (i <= 0)
            {
                throw std::invalid_argument("index out of range");
            }
             if(i > m_length)
             {
                 throw std::invalid_argument("index out of range");
             }
            cout << m_data[i]<<endl;
            return m_data[i];
            

            
            
            

        }
        catch(std::invalid_argument)
        {
            std::cout <<"index out of range"<<endl;
        }

    }

    void IntArray::reallocate(int newLength)
    {
        erase();
             if (newLength <= 0)
                   return;
              
        m_data = new int[newLength];
        m_length = newLength;
    }

    void IntArray::resize(int newLength)
    {
        if (newLength == m_length)
                       return;
                   
                    if (newLength <= 0)
                    {
                        erase();
                        return;
                    }

        int* data{ new int[newLength] };

        if (m_length > 0)
        {
            int elementsToCopy{ (newLength > m_length) ? m_length : newLength };

                      
            for (int index{ 0 }; index < elementsToCopy; ++index)
                            data[index] = m_data[index];
        }

                   
         delete[] m_data;

         m_data = data;
         m_length = newLength;
    }

    void IntArray:: insertBefore(int value, int i)
    {
        try
        {
            if (i <= 0)
                throw std::invalid_argument("index out of range");
            if(i >= m_length)
                throw std::invalid_argument("index out of range");




            int* data{ new int[m_length + 1] };

            for (int before{ 0 }; before < i; ++before)
                data[before] = m_data[before];

            data[i] = value;

            for (int after{ i }; after < m_length; ++after)
                data[after + 1] = m_data[after];


            delete[] m_data;
            m_data = data;
            ++m_length;
        }

        catch (const std::invalid_argument)
        {
            std::cout << "index out of range (insertBefore)" << endl;
        }        
    }

    void IntArray:: remove(int i)
    {
        try
        {
            if (i <= 0) 
                throw std::invalid_argument("index out of range");
            if (i > m_length)
                throw std::invalid_argument("index out of range");

            if (m_length == 1)
            {
                erase();
                return;
            }

            int* data{ new int[m_length - 1] };

            for (int before{ 0 }; before < i; ++before)
                data[before] = m_data[before];

            for (int after{ i + 1 }; after < m_length; ++after)
                data[after - 1] = m_data[after];

            delete[] m_data;
            m_data = data;
            --m_length;
        }

        catch (const std::invalid_argument)
        {
            std::cout << "index out of range (remove)" << endl;
        }
    }    
