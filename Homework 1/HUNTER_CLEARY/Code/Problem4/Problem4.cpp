#include<iostream> 
#include<vector>
using namespace std;
template<typename T>
int BinarySearch(T x, vector<T> v){
    int p;
    int midpoint = (v.size() / 2);
    bool j = false;
    int end = v.size();
    int start = 0;
    int temp;
    while ( j == false){
        if( v[midpoint] == x ){
            j = true;
            p = midpoint;
        }
        else if( v[midpoint+1] == x ){
            j = true;
            p = midpoint+1;
        }
        else if( v[midpoint-1] == x ){
            j = true;
            p = midpoint-1;
        }
        else if(v[midpoint] > x){
            temp = midpoint;
            midpoint = (end-midpoint)/2;
            start = temp;
        }
        else if((v[midpoint] < x)){
            temp = midpoint;
            midpoint = (start-midpoint);
            end = temp;
        }
    }
    return p;
}
    /*
    for(int i = 0; i < v.size();++i){
        if(x == v[i]){
        p = i;
        }
    }
    return p;
    */


int main(){
vector<int> v1{1,2,3,5,7,9,11,15};

cout << "The value is located at: " << BinarySearch(9, v1) << " ";
    
}