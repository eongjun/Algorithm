//2048 (Easy)

#include <iostream>

using namespace std;


int n, ret;

class BOARD {
public:
	int map[20][20];

	void rotate() {		//90도 회전 함수
		int temp[20][20];

		for (int y = 0; y < n; ++y) {			//90도 돌린 보드를 temp에 저장
			for (int x = 0; x < n; ++x) {
				temp[y][x] = map[n - x - 1][y];
			}
		}

		for (int y = 0; y < n; ++y) {			//temp에 저장된 값을 보드로 옮김
			for (int x = 0; x < n; ++x) {
				map[y][x] = temp[y][x];
			}
		}
	}

	int getMax() {		//최댓값 구하기
		int ret = 0;

		for (int y = 0; y < n; ++y) {			
			for (int x = 0; x < n; ++x) {
				if (ret < map[y][x]) {
					ret = map[y][x];
				}
			}
		}

		return ret;
	}

	void up() {
		int temp[20][20];

		for (int x = 0; x < n; ++x) {
			int flag = 0, target = -1;
			for (int y = 0; y < n; ++y) {
				if (map[y][x] == 0) {			//칸이 비어있으면 다음 칸으로 넘어감
					continue;
				}

				if (flag == 1 && map[y][x] == temp[target][x]) {	//flag가 1이고 현재 칸의 숫자와 이전에 넣은 숫자가 같다면
					temp[target][x] *= 2, flag = 0;					//두 숫자를 합친 값으로 바꾸고 flag를 0으로 설정
				}
				else {
					temp[++target][x] = map[y][x], flag = 1;		//같은 숫자가 겹치지 않는다면 아래칸에 숫자를 넣고 flag를 1로 설정
				}
			}
			for (++target; target < n; ++target) {					//밀기 동작을 수행한 후 생기는 빈 공간을 0으로 초기화
				temp[target][x] = 0;
			}
		}
		for (int y = 0; y < n; ++y) {			//temp에 저장된 값을 보드로 옮김
			for (int x = 0; x < n; ++x) {
				map[y][x] = temp[y][x];
			}
		}
	}
};

void dfs(BOARD cur, int count) {
	if (count == 5) {
		int candi = cur.getMax();
		if (ret < candi) {
			ret = candi;
		}
		return;
	}

	for (int dir = 0; dir < 4; ++dir) {
		BOARD next = cur;
		next.up();
		dfs(next, count + 1);
		cur.rotate();
	}
}

int main() 
{
	BOARD board;
	cin >> n;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			cin >> board.map[y][x];
		}
	}

	ret = 0;
	dfs(board, 0);
	cout << ret;
	
	return 0;
}
