#include <iostream>
#include <vector>
using namespace std;
bool vectorMultiplyTest(vector<int> a, vector<int> b){
    bool j;
    int i = 0;
    vector<int> c;
        while( j == false && i < a.size() ){
                for(int q = 0; q < b.size(); ++q){
                    if( (a[i]*b[q])%2 == 1){
                    j = true;
                    ++i;
                    }
                    else{
                        ++i;
                    }
                }
            }
    return j;
}

int main()
{
    vector<int> a{ 2, 2, 4};
    vector<int> b{ 3, 4, 2};
    for (int x : a)
        cout << x << " ";
    cout << endl;
    for (int x : b)
        cout << x << " ";
    cout << endl;
    
    cout << vectorMultiplyTest(a,b) << endl;
        
}