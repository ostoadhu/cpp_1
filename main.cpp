#include <iostream>

class T
{
    public :
        // Parameterised constructor - bc it has default value, param can be omitted
        T(int size = 0) : m_size{size}, m_buffer{nullptr}
        {
            std::cout << "Param Constructed" << std::endl;
        }

        // Copy constructor
        T(const T& other)
        {
            std::cout << "Copy Constructed" << std::endl;

            m_buffer = other.m_buffer;
            m_size = other.m_size;
        }

        // Assignment operator
        T operator=(const T& other)
        {
            std::cout << "Assignment operator called" << std::endl;

            m_size = other.m_size;
            m_buffer = other.m_buffer;

            return *this;
        }

        void details()
        {
            std::cout << "Pointer address : " << m_buffer << std::endl;
            std::cout << "Array size : " << m_size << std::endl;
        }

    private :
        int m_size;
        int *m_buffer;
};

int main()
{
    T t_1{10};
    T t_2{t_1};
    T t_3{};

    t_3 = t_2;

    t_1.details();
    t_2.details();
    
    
    return  0;
}