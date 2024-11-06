#include <iostream>

class T
{
    private :
        int m_data_1;
        int m_data_2;

    public :
        T(int data_1 = 0, int data_2 = 0) : m_data_1{data_1}, m_data_2{data_2} 
        {
            std::cout << "Constructed" << std::endl;
        }

        ~T()
        {
            std::cout << "Destructed" << std::endl;
        }
        T setData_1(int data)
        {
            this->m_data_1 = data;
            return *this;
        }

        T setData_2(int data)
        {
            this->m_data_2 = data;
            return *this;
        }

        void print()
        {
            std::cout << " data_1 : " << m_data_1 << "\n data_2 : " << m_data_2 << std::endl;
        }
};

int main()
{
    T t;

    t.setData_1(10).setData_2(20);

    t.print();

    return  0;
}