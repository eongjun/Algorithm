/*using set*/
// you can use includes, for example:
// #include <algorithm>
#include <vector>
#include <set>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	set<int> B;
	std::set<int>::iterator it;


	if (A.size()>1) {
		for (std::vector<int>::size_type i = 0; i<A.size(); i++) {
			it = B.find(A[i]);
			if (it != B.end()) {
				B.erase(it);
			}
			else {
				B.insert(A[i]);
			}
		}
		it = B.begin();
		return *it;
	}
	else {
		return A[0];
	}

}

/*using XOR*/
// you can use includes, for example:
// #include <algorithm>
#include <vector>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
    int ans=0;
	for (std::vector<int>::size_type i = 0; i<A.size(); i++) {
	    ans ^= A[i];
	}
		
    return ans;
}
