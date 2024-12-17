// Implement a class Complex which represents the Complex Number data type. Implement the following
//  1. Constructor (including a default constructor which creates the complex number 0+0i).
//  2. Overloadoperator+ to add two complex numbers.
//  3. Overload operator* to multiply two complex numbers.
//  4. Overload operators << and >> to print and read Complex Numbers

#include <iostream> 
using namespace std; 
 
class complex { 
private: 
    int real; 
    int imag; 
 
public: 
    // Default constructor 
    complex() {}; 
 
    // Member functions 
    void setvalue(int, int); 
    void display(); 
     
    // Operator overloading 
    complex operator* (complex &c); 
    complex operator+ (complex &d); 
 
    // Friend functions 
    friend void operator <<(ostream &output, complex &s); 
    friend void operator >>(istream &input, complex &q); 
}; 
 
// Member function definitions 
void complex::setvalue(int c, int d) { 
    real = c; 
    imag = d; 
} 
 
void complex::display() { 
    cout << real << "+" << imag << "i" << "\n"; 
} 
 
// Friend function definitions 
void operator<<(ostream &output, complex &s) { 
    output << s.real << "+" << s.imag << "i"; 
} 
 
void operator>>(istream &input, complex &q) { 
    input >> q.real >> q.imag; 
} 
 
// Operator overloading definitions 
complex complex::operator*(complex &c) { 
    complex t; 
    t.real =  real * c.real - imag * c.imag;
    t.imag =  real * c.imag + imag * c.real;
    return t; 
} 
 
complex complex::operator+(complex &d) { 
    complex temp; 
    temp.real = real + d.real; 
    temp.imag = imag + d.imag; 
    return temp; 
} 
 
int main() { 
    complex c1, c2, c3, c4; 
 
    // Input first complex number 
    cout << "Enter the real & imaginary parts of the First Complex Number: "; 
    cin >> c3; 
    cout << "Complex Object of first is:" << c3; 
 
    // Input second complex number 
    cout << "\n\nEnter the real & imaginary parts of the Second Complex Number: "; 
    cin >> c4; 
    cout << "Complex Object of second is:" << c4; 
 
    // Perform addition and multiplication 
    c1 = c3 + c4; 
    c2 = c3 * c4; 
 
    // Output results 
    cout << "\n\n Results are: \n Addition is: " << c1; 
    cout << "\n Multiplication is: " << c2; 
 
    return 0; 
}
