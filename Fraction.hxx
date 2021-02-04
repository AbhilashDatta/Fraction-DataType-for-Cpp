#ifndef FRACTION_HXX
#define FRACTION_HXX

#include<iostream>
#include<cmath>
using namespace std;

class Fraction{
private://Implementation
    //Data members: numerator and denominator
    //Numerator p is of type int as it can be positive or negative
    //Denominator q is of type unsigned int as it's always positive
    int p;
    unsigned int q;
    
    //Utility: Normalize: reducing to simplest fraction
    //Dividing numerator and denominator by their gcd reduces fraction to its simplest form
    void normalize(){
        int g = gcd(abs(p),q);
        p = p/g;
        q = q/g; 
    }
    //Parameterized normalization function for external use
    static void normalize(int& a,int& b){
        int g = gcd(abs(a),abs(b));
        a = a/g;
        b = b/g; 
    }

public://Interface
    //Constructors
    //Constructor 1: taking numerator and denominator of type int followed by normalization
    Fraction(int , int );
    
    //Constructor 2: taking double type parameter followed by normalization
    Fraction(double d);
    
    //Copy constructor
    //Parameters - constant reference of type Fraction 
    Fraction(const Fraction& f);

    //Destructor
    ~Fraction();

    //Copy Assignment Operator
    //Parameters: constant reference of type Fraction 
    //Return by reference as we don't want to assign to a copy but the original variable 
    Fraction& operator =(const Fraction& f);

    //Unary Arithmetic Operators
    //Unary minus operator
    //Return by value of type Fraction because it shouldn't change the original fraction
    Fraction operator-();

    //Unary plus operator
    //Return by reference of type Fraction 
    Fraction& operator+();

    //Prefix pre-decrement operator
    //Return by reference of type Fraction
    //Original fraction is being modified
    Fraction& operator--();

    //Prefix pre-increment operator
    //Return by reference of type Fraction
    //Original fraction is being modified
    Fraction& operator++();

    //Postfix post-decrement operator
    //Return by value of type Fraction as original value has to be modified but value prior to decrement has to be returned
    Fraction operator--(int);

    //Postfix post-increment operator
    //Return by value of type Fraction as original value has to be modified but value prior to decrement has to be returned
    Fraction operator++(int);

    //Binary Arithmetic Operators
    //Addition
    //Friend function to sustain the infix property  
    //Two parameters: constant references of type Fraction
    //Return by value of type Fraction as original values shouldn't be changed
    friend Fraction operator+(const Fraction&, const Fraction&);

    //Subtraction
    //Friend function to sustain the infix property  
    //Two parameters: constant references of type Fraction
    //Return by value of type Fraction as original values shouldn't be changed
    friend Fraction operator-(const Fraction&, const Fraction&);

    //Multiplication
    //Friend function to sustain the infix property  
    //Two parameters: constant references of type Fraction
    //Return by value of type Fraction as original values shouldn't be changed
    friend Fraction operator*(const Fraction&, const Fraction&);

    //Division
    //Friend function to sustain the infix property  
    //Two parameters: constant references of type Fraction
    //Return by value of type Fraction as original values shouldn't be changed
    //Division by zero exception handled
    friend Fraction operator/(const Fraction&, const Fraction&);

    //Remainder
    //Friend function to sustain the infix property  
    //Two parameters: constant references of type Fraction
    //Return by value of type Fraction as original values shouldn't be changed
    //Division by zero exception handled
    friend Fraction operator%(const Fraction&, const Fraction&);

    //Binary Relational Operators
    //Friend functions to sustain the infix property 
    //Two parameters: constant references of type Fraction
    //Return by value of type boolean
    //Equal
    friend bool operator==(const Fraction&, const Fraction&);

    //Unequal
    //Friend functions to sustain the infix property 
    //Two parameters: constant references of type Fraction
    //Return by value of type boolean
    friend bool operator!=(const Fraction&, const Fraction&);

    //Less than
    //Friend functions to sustain the infix property 
    //Two parameters: constant references of type Fraction
    //Return by value of type boolean
    friend bool operator<(const Fraction&, const Fraction&);

    //Less than equal to
    //Friend functions to sustain the infix property 
    //Two parameters: constant references of type Fraction
    //Return by value of type boolean
    friend bool operator<=(const Fraction&, const Fraction&);

    //More than
    //Friend functions to sustain the infix property 
    //Two parameters: constant references of type Fraction
    //Return by value of type boolean
    friend bool operator>(const Fraction&, const Fraction&);

    //More than equal to
    //Friend functions to sustain the infix property 
    //Two parameters: constant references of type Fraction
    //Return by value of type boolean
    friend bool operator>=(const Fraction&, const Fraction&);

    //Special Operators
    //Return by value of type Fraction as original value shouldn't be modified
    //Negation
    Fraction operator!();

    //I/O Operators
    //Friend functions to sustain the original syntax 
    //Two parameters: one i/o stream reference and one constant reference of type Fraction
    //Return by reference of type i/o stream
    //overloaded ostream operator
    friend ostream& operator<<(ostream&, const Fraction&);

    //overloaded ostream operator
    //Use of static normalize, all cases of fractions hard coded
    //Friend functions to sustain the original syntax 
    //Two parameters: one i/o stream reference and one constant reference of type Fraction
    //Return by reference of type i/o stream
    friend istream& operator>>(istream& ,Fraction&);

    //Static Constants
    static const Fraction sc_fUnity;
    static const Fraction sc_fZero;

    //Utility functions
    //GCD function: recursive method
    static int gcd(int a, int b);

    //LCM function
    //Inline function
    static int lcm(int a, int b);

    //Precision function
    //Inline Function
    static int precision();

    //Converts to double
    //Inline function
    double toDouble() const;
};


inline int Fraction::lcm(int a, int b){
    return a*b/gcd(a,b);
}

inline int Fraction::precision(){ return 1e3;}

inline double Fraction::toDouble() const{
    double f = (double)(p)/q;
    return f;
}

#endif 
