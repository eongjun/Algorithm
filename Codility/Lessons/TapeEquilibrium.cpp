// you can use includes, for example:
// #include <algorithm>
#include <cmath>
#include <vector>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int sum=0;
    int sub=0;
    int ans;
    for(std::vector<int>::size_type i=0; i<A.size(); i++){
        sum+=A[i];
    }
    for(std::vector<int>::size_type i=0; i<A.size()-1; i++){
        sub+=A[i];
        if(i==0){
            ans=abs(sum-2*sub);
        }
        else if(ans>abs(sum-2*sub)){
            ans=abs(sum-2*sub);
        }
    }
    return ans;
}
