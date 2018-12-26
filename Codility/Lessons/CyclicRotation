// you can use includes, for example:
// #include <algorithm>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A, int K) {
	// write your code in C++14 (g++ 6.2.0)
	int num;
	if (!A.empty()) {
		std::vector<int>::iterator it = A.begin();
		for (int i = K; i>0; i--) {
			num = A[A.size() - 1];
			A.pop_back();
			A.insert(it, num);
		}
	}
	return A;
}
