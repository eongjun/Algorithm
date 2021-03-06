// you can use includes, for example:
// #include <algorithm>
#include <vector>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
	// write your code in C++14 (g++ 6.2.0)
	vector<int> binArr;
	while (N / 2.0 != 0) {
		binArr.push_back(N%2);
		N /= 2;
	}

	int ans = 0;
	int num = 0;
	for (std::vector<int>::size_type i = 0; i < binArr.size(); i++) {
		if (binArr[i] == 1) {
			for (std::vector<int>::size_type j = i + 1; j < binArr.size(); j++) {
				if (binArr[j] == 0) {
					num++;
				}
				else {
					if (ans<num) {
						ans = num;
					}
					i = j + 1;
					num = 0;
				}
			}
		}
	}
	return ans;
}
