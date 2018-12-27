// you can use includes, for example:
// #include <algorithm>
#include <vector>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int sum=0;
    int sum2=0;
    for(std::vector<int>::size_type i=0; i<A.size(); i++){
        sum+=A[i];
        sum2+=i+1;
    }
    if(sum==sum2){
        return A.size()+1;
    }
    else{
        return A.size()+1+sum2-sum;
    }
    
}
