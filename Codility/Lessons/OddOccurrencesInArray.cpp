// you can use includes, for example:
// #include <algorithm>
#include <vector>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	vector<int> B;
	int cnt = 0;

	while (true) {
		B.clear();
		cnt = 0;
		if (A.size()>1) {
			for (std::vector<int>::size_type i = 1; i<A.size(); i++) {
				if (A[i] == A[0]) {
					cnt++;
				}
				else {
					B.push_back(A[i]);
				}
			}
			if ((cnt % 2) == 0) {
				return A[0];
			}
			A = B;
		}
		else {
			return A[0];
		}
	}
}
