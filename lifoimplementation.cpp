// LIFO Stack Implementation using template
#include <iostream>
#include <string>
#include <exception>

using namespace std;

// Simple exception class
class ExceptionClass : public std::exception
{
    const char *errMsg;
    ExceptionClass(){};
public:
    explicit ExceptionClass(const char * s) throw() : errMsg(s) { }
    const char *what() const throw() { return errMsg; }
};

// Simple fixed-size LIFO stack template
template <typename T>
class LifoStack
{
private:
    static const int defaultSize = 10;
    static const int maxSize = 1000;
    int m_size;
    int m_top;
    T *m_stackPtr;
public:
    explicit LifoStack(int s = defaultSize);
    ~LifoStack() {
        delete[] m_stackPtr;
    }
    
    T &push(const T&);
    T &pop();
    
    bool isempty() const {
        return m_top < 0;
    }
    
    bool isfull() const {
        return m_top >= m_size - 1;
    }
    
    int top() const { 
        return m_top;
    }

    int size() const {
        return m_size;
    }
};

// Stack<T> Constructor.
template <typename T>
LifoStack<T>::LifoStack(int s){
    if (s > maxSize || s < 1) throw ExceptionClass("Invalid Stack Size");
    else m_size = s;
    m_stackPtr = new T[m_size];
    m_top = -1;
}

template <typename T>
T & LifoStack<T>::push (const T &val)
{
    if (isfull()) throw ExceptionClass("Stack Full");
    return m_stackPtr[++m_top] = val;
}

template <typename T>
T & LifoStack<T>::pop()
{
    if (isempty()) throw ExceptionClass("Stack Empty");
    return m_stackPtr[m_top--];
}

int main(int argc, char **argv)
{
    // Stack of int.
    try
    {
        LifoStack<int> stacki(5);
        cout << "stacki size: " << stacki.size() << endl;
        cout << "stacki top: " << stacki.top() << endl;
        for (int k : {1, 2, 3, 4, 5})
        {
            stacki.push(k);
        }
        cout << "stacki top after pushes: " << stacki.top() << endl;
        cout << "stacki is " << (stacki.isfull() ? "" : "not") << "full" << endl;
        while (!stacki.isempty()){
            cout << "popped " << stacki.pop() << endl;
        }
    }
    catch(ExceptionClass &ex)
    {
        cout << "Stack error: " << ex.what() << endl;
    }

    // String stacking
    try
    {
        LifoStack<string> str(5);
        cout << "str size: " << str.size() << endl;
        for (const char *s : {"one", "two", "three", "four", "five"}){
            str.push(s);
        }
        cout << "str top after pushes: " << str.top() << endl;
        cout << "str is " << (str.isfull() ? "" : "not ") << "full" << endl;
        while (!str.isempty())
        {
            cout << "popped " << str.pop() << endl;
        }
    }
    catch(ExceptionClass & ex)
    {
        cout << "Stack error: " << ex.what() << endl;
    }
    
    return 0;
}