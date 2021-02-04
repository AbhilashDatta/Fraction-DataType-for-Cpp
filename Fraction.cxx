#include "Fraction.hxx"

const Fraction Fraction::sc_fUnity = {1,1};
const Fraction Fraction::sc_fZero = {0,1};

Fraction::Fraction(int m = 1, int n = 1): p(abs(m)),q(abs(n)) {
    if(n==0) exit(1);
    if((n<0 && m>0)||(n>0 && m<0)){
        p = (-1)*p;
    }
    if(m==0) q = 1;
    normalize();
}

Fraction::Fraction(double d){
    p = (int)floor(d*precision());
    q = precision();
    normalize();
} 

Fraction::Fraction(const Fraction& f): p(f.p),q(f.q) {}

Fraction::~Fraction(){}

Fraction& Fraction::operator =(const Fraction& f){
    this->p = f.p;
    this->q = f.q;
    return *this;
}

Fraction Fraction::operator-(){
    Fraction temp(*this);
    temp.p = (-1)*temp.p;
    return temp;
}

Fraction& Fraction::operator+(){
    return *this;
}    

Fraction& Fraction::operator--(){
    p = p-q;
    return *this;
}

Fraction& Fraction::operator++(){
    p = p+q;
    return *this;
}

Fraction Fraction::operator--(int){
    Fraction temp = *this;
    p = p-q;
    return temp;
}

Fraction Fraction::operator++(int){
    Fraction temp = *this;
    p = p+q;
    return temp;
}

Fraction Fraction::operator!(){
    Fraction one;
    return one/(*this);
}

int Fraction::gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

Fraction operator+(const Fraction& f1, const Fraction& f2){
    Fraction sum(f1.p*f2.q+f1.q*f2.p, f1.q*f2.q);
    return sum;
}

Fraction operator-(const Fraction& f1, const Fraction& f2){
    Fraction diff(f1.p*f2.q-f1.q*f2.p, f1.q*f2.q);
    return diff;
}

Fraction operator*(const Fraction& f1, const Fraction& f2){
    Fraction prod(f1.p*f2.p, f1.q*f2.q);
    return prod;
}
 
Fraction operator/(const Fraction& f1, const Fraction& f2){
    try{
        unsigned int d= f1.q*f2.p;
        if(d==0) throw "Floating point exception";
        Fraction q(f1.p*f2.q,d);
        return q;
    }
    catch(...){
        cout<<"Division By Zero\n";
        return 0;
    }
}

Fraction operator%(const Fraction& f1, const Fraction& f2){
    try{
        if(f2.toDouble()==0) throw "Floating point exception";
        Fraction r(remainder(f1.toDouble(),f2.toDouble()));
        return r;
    }
    catch(...){
        cout<<"Division By Zero\n";
        return 0;
    }
}

bool operator==(const Fraction& f1, const Fraction& f2){
    if(abs((f1-f2).toDouble())<1e-5) return true;
    else return false;
}

bool operator!=(const Fraction& f1, const Fraction& f2){
    if(abs((f1-f2).toDouble())<1e-5) return false;
    else return true;
}

bool operator<(const Fraction& f1, const Fraction& f2){
    if((f2-f1).toDouble()>0) return true;
    else return false;
}

bool operator<=(const Fraction& f1, const Fraction& f2){
    if((f2-f1).toDouble()>=0) return true;
    else return false;
}

bool operator>(const Fraction& f1, const Fraction& f2){
    if((f1-f2).toDouble()>0) return true;
    else return false;
}

bool operator>=(const Fraction& f1, const Fraction& f2){
    if((f1-f2).toDouble()>=0) return true;
    else return false;
}

ostream& operator<<(ostream& os,const Fraction& f){
    if(f.toDouble()!=ceil(f.toDouble())) os<<f.p<<"/"<<f.q;
    else os<<f.p;
    return os;
}

istream& operator>>(istream& input,Fraction& f){
    int a,b;
    input>>a>>b;
    Fraction::normalize(a,b);
    if((a<0 && b>0)||(a>0 && b<0)){
        f.p = (-1)*abs(a);
        f.q = abs(b);
    }
    if(a==0){
        f.p = 0;
        f.q = 1;
    }
    if(b==0) exit(1);
    if((a>0 && b>0)||(a<0 && b<0)){
        f.p = abs(a);
        f.q = abs(b);
    }
    return input;
}