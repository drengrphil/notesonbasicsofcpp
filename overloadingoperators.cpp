// Overloading Operators
// Using member funcrtion for operator overloading
// Separate non-member function for operator overloading
// Providing special meaning for operators, to be used on user defined classes or types.
// For examp,e overload an operator "+" in a class like String so that
//   string concatenation can be performed using +.
#include <iostream>
#include <cstdio>
using namespace std;

/*
 * Operator overloading using member function
 * ComplexExample contains operator overloading for +
 * to add two different objects.
 */
class ComplexExample
{
private:
    int m_real, m_imag;
public:
    ComplexExample(int r = 0, int i = 0) {m_real = r; m_imag = i;}
    // + Operator overloading.
    ComplexExample operator + (ComplexExample const &obj){
        ComplexExample res;
        res.m_real = m_real + obj.m_real;
        res.m_imag = m_imag + obj.m_imag;
        return res;
    }

    void printStuffs(){
        cout << m_real << " + i" << m_imag << endl;
    }
};

class Rational
{
private:
    int m_numerator = 0;
    int m_denominator = 1;
public:
    Rational(int numerator = 0, int denominator = 1) 
    : m_numerator(numerator), 
    m_denominator(denominator)
    {
        puts("Rational Default Constructor");
    }

    // Copy Constructor
    Rational(const Rational &rhs) :
    m_numerator(rhs.m_numerator),
    m_denominator(rhs.m_denominator)
    {
        puts("Copy Constructor");
    }

    // Destructor
    ~Rational();
    inline int numerator() const {return m_numerator;}
    inline int denominator() const {return m_denominator;}

    // Operators overloading methods
    Rational &operator = (const Rational &);
    Rational operator + (const Rational &) const;
    Rational operator - (const Rational &) const;
    Rational operator * (const Rational &) const;
    Rational operator / (const Rational &) const;
};

Rational::~Rational(){
    m_numerator = 0; m_denominator = 1;
    puts("Destructor called");
}

Rational & Rational::operator = (const Rational &rhs)
{
    if (this != &rhs){
        m_numerator = rhs.numerator();
        m_denominator = rhs.denominator();
    }
    return *this;
}

Rational Rational::operator + (const Rational &rhs) const {
    return Rational((m_numerator * rhs.m_denominator) + (m_denominator * rhs.m_numerator),
                    m_denominator * rhs.m_denominator);
}

Rational Rational::operator - (const Rational &rhs) const {
    return Rational((m_numerator * rhs.m_denominator) + (m_denominator * rhs.m_numerator),
                    m_denominator * rhs.m_denominator);
}

Rational Rational::operator * (const Rational &rhs) const {
    return Rational((m_numerator * rhs.m_numerator),
                    m_denominator * rhs.m_denominator);
}

Rational Rational::operator / (const Rational &rhs) const {
    return Rational(m_numerator * rhs.m_denominator, m_denominator * rhs.m_numerator);
}

// Useful for std::cout
// Non-member function operator overloading for cout (<<)
ostream &operator << (ostream & o, const Rational &r){
    if (r.denominator() == 1){
        return o << r.numerator();
    }
    else{
        return o << r.numerator() << '/' << r.denominator();
    }
}

int main()
{
    ComplexExample comE1(10, 5), comE2(2,4);
    ComplexExample comE3 = comE1 + comE2; // Uses operator overloading +
    comE3.printStuffs();

    Rational rational1 = 7; // 7/1
    cout << "rational1 is: " << rational1 << endl;
    Rational rational2(5, 2); // 5/2
    cout << "rational2 is: " << rational2 << endl;
    // Use copy constructor
    Rational rational3 = rational2;
    cout << "rational3 is: " << rational3 << endl;
    // Default constructor
    Rational rational4; 
    cout << "rational4 is: " << rational4 << endl;
    // Assignment operator =
    rational4 = rational3;
    cout << "rational4 is now: " << rational4 << endl;
}
