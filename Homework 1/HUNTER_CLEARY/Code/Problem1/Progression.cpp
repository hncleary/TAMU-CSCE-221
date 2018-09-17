#include<iostream>
#include<math.h> //power function for geometric progression

using namespace std;

class Progression{
    public:
    virtual int getnext() = 0;
    virtual int sum() = 0;
    
    void setCurrenVal(int a){
        currentVal = a;
    }
    void setIncrement(int d){
        increment = d;
    }
    
    void setRatio(int r){
        ratio = r;
    }
    void setFirstValue(int f){
        firstValue = f;
    }
    void setElementNumber(int n){
        elementNumber = n;
    }
    protected:
    int currentVal;
    int elementNumber = 0;
    int increment;
    int ratio;
    int firstValue;
};

class ArithmeticProgression : public Progression{
    public:
    int getnext(){
        currentVal = (currentVal + (increment*elementNumber));
        ++elementNumber;
        return currentVal;
    }
    //adds up values until provided element number
    int sum(int s){
        int total;
        for(int i = 1; i < s; ++i){
            total = currentVal + getnext(i);
        }
    }
};
class GeometricProgression : public Progression{
    public:
    int getnext(){
        currentVal = (firstValue * (pow(ratio,(elementNumber+1))));
        ++elementNumber;
        return currentVal;
    }
    //adds up values until provided element number
    int sum(int s){
        int total;
        for(int i = 1; i < s; ++i){
            total = currentVal + getnext(i);
        }
    }
};
int main(void){
    ArithmeticProgression linear;
    linear.setCurrenVal(0);
    linear.setIncrement(2);
    lineear.setFirstValue(1);
    cout << linear.getnext() << endl;
    cout << linear.sum() << endl;
    
    GeometricProgression ratio;
    ratio.setCurrenVal(0);
    ratio.setRatio(2);
    ratio.setFirstValue(2);
    cout << ratio.getnext() << endl;
    cout << ratio.sum() << endl;
    return 0;
}