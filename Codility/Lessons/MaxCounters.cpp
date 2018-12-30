// you can use includes, for example:
// #include <algorithm>
#include <vector>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> B(N);
    int max=0;
    int tmp=0;
    for(std::vector<int>::size_type i=0; i<A.size(); i++){
        if(A[i]>N){
         max=tmp;    
        }
        else{
            if(B[A[i]-1]<max){
                B[A[i]-1]=max;
            }
            B[A[i]-1]++;
            if(tmp< B[A[i]-1]){
                tmp=B[A[i]-1];
            }
        }
    }
    
    for(int i=0; i<B.size(); i++){
        if(B[i]<max){
            B[i]=max;
        }
    }
    return B;
}
