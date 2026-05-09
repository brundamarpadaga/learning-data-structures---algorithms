#include<iostream>

class rational{
    public:
    rational(int numerator, int denominator){
        this->numerator = numerator;
        this->denominator = denominator;
    }
    void print(){
        std::cout << numerator << "/" << denominator << std::endl;      
    }

    int getNumerator() const { // const member function, cannot modify member variables
        return numerator;
    }

    int getDenominator() const {
        return denominator;
    }

    void setNumerator(int numerator) {
        this->numerator = numerator;
    }

    void setDenominator(int denominator) {
        this->denominator = denominator;
    }

    rational operator+(const rational &rhs) const { 
        int newnumerator = numerator * rhs.getDenominator() + rhs.getNumerator() * denominator;
        int newdenominator = denominator * rhs.getDenominator();
        return rational(newnumerator, newdenominator);
    }

    rational operator-(const rational &rhs) const {
        int newnumerator = numerator * rhs.getDenominator() - rhs.getNumerator() * denominator;
        int newdenominator = denominator * rhs.getDenominator();
        return rational(newnumerator, newdenominator);
    }

    rational operator*(const rational &rhs) const {
        int newnumerator = numerator * rhs.getNumerator();
        int newdenominator = denominator * rhs.getDenominator();
        return rational(newnumerator, newdenominator);
    }

    rational operator/(const rational &rhs) const {
        int newnumerator = numerator * rhs.getDenominator();
        int newdenominator = denominator * rhs.getNumerator();
        return rational(newnumerator, newdenominator);
    }

    rational operator-() const { // unary minus operator
        return rational(-numerator, denominator);
    }


    private:
    int numerator;
    int denominator;
};


int main(){
    rational r1(1, 2);
    rational r2(1, 3);
    rational r3 = r1 + r2; // operator+ is called here
    r3.print(); // should print 5/6
    return 0;
}