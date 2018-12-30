// you can use includes, for example:
// #include <algorithm>
#include <vector>
#include <set>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    set<int> B;
    unsigned long long sum=0;
    for(std::vector<int>::size_type i=0; i<A.size(); i++){
        sum+=A[i];
        B.insert(A[i]);
    }
    if(sum==(A.size()*(A.size()+1))/2&&B.size()==A.size()){
        return 1;
    }
    else{
        return 0;
    }
}
