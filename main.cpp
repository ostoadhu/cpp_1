#include <iostream>

class T
{
    private :
        int m_data;

    public :
        T(int data = 0) : m_data{data} {}
        void changeData(T *t)
        {
            this = t;
        }

        void print()
        {
            std::cout << "data : " << m_data << std::endl;
        }
};

int main()
{
    T t;
    T *t_ptr = new T(10);
    
    t.changeData(t_ptr);
    t.print();

    return  0;
}