// you can use includes, for example:
// #include <algorithm>
#include <vector>
#include <set>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    set<int> B;
    for(std::vector<int>::size_type i=0;i<A.size();i++){
        B.insert(A[i]);
        if(B.size()==X){
            return i;
        }
    }
    return -1;
}
