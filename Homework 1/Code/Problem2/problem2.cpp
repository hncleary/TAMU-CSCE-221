#include <iostream>
#include <vector>
using namespace std;
vector<double> vectorMultiply(vector<double> a, vector<double> b){
    vector<double> c;
    if(a.size()==b.size()){
        for(int i = 0; i < a.size(); ++i){
        c.push_back(a[i]*b[i]);
        }
    }
    else{
        c.push_back(0);
        cout << "invalid vector sizes" << endl;
    }
    return c;
}

int main()
{
    vector<double> a{ 10, 20, 35};
    vector<double> b{ 15, 35, 35};
    for (int x : a)
        cout << x << " ";
    cout << endl;
    for (int x : b)
        cout << x << " ";
    cout << endl;
    
    for( int y : vectorMultiply(a,b))
        cout << y << " ";
        
}