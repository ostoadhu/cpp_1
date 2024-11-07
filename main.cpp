#include <iostream>

class T
{
    public :
        ~T()
        {
            std::cout << "Destructed" << std::endl;

            delete[] m_buffer;
        }

        // Parameterised constructor - bc it has default value, param can be omitted
        T(int size = 0) : m_size{size}, m_buffer{nullptr}
        {
            std::cout << "Param Constructed" << std::endl;

            if ( m_size > 0)
            {
                m_buffer = new int[m_size];
            }
        }

        // Copy constructor
        T(const T& other)
        {
            std::cout << "Copy Constructed" << std::endl;

            if (this != &other)
            {
                m_size = other.m_size;

                if (m_size > 0)
                {
                    m_buffer = new int[m_size];
                }

                for (int index = 0; index < m_size; index++)
                {
                    m_buffer[index] = other.m_buffer[index];
                }
            }
            else
            {
                std::cout << "Tried to Copy Construct itself" << std::endl;
            }
        }

        // Assignment operator
        T operator=(const T& other)
        {
            if (this != &other)
            {
                std::cout << "Assignment operator called" << std::endl;

                // rease memory content of previous object
                if (m_buffer != nullptr) 
                {
                    delete[] m_buffer;
                }

                m_size = other.m_size;

                if (m_size > 0)
                {
                    m_buffer = new int[m_size];
                }

                for (int index = 0; index < m_size; index++)
                {
                    m_buffer[index] = other.m_buffer[index];
                }
            }
            else
            {
                std::cout << "Tried to Assign itself" << std::endl;
            }

            return *this;
        }

        void details()
        {
            std::cout << "Pointer address : " << m_buffer << std::endl;
            if ( m_buffer != nullptr )
            {
                for(int index = 0; index < m_size; index++)
                {
                    std::cout << m_buffer[index] << " ";
                }
                std::cout << std::endl;
            }

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

    t_3 = t_2; // t_3{t_2}; bc return type is NOT T&

    t_1.details();
    t_2.details();
    t_3.details();
    
    return  0;
}