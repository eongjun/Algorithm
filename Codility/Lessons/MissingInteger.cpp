// you can use includes, for example:
// #include <algorithm>
#include <vector>
#include <set>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    set<int> B;
    for(std::vector<int>::size_type i=0;i<A.size();i++){
        if(A[i]>0){
            B.insert(A[i]);
        }
    }    
    if(B.size()==0){
        return 1;
    }
    else{
        for(std::set<int>::size_type i=1;i<=B.size();i++){
            if(B.find(i)==B.end()){
                return i;
            }
        }
        return B.size()+1;
    }
}
