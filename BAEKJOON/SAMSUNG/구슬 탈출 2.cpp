//구슬 탈출 2
#include <iostream>
#include <queue>
using namespace std;

class INFO {
public:
	int rx, ry, bx, by, count;
};

INFO start;
//char** map;
//char map[10][10];

int bfs(char ** &map) {
	const int dx[] = { 0,0,-1,1 };			//우로 이동
	const int dy[] = { -1,1,0,0 };			//하로 이동
	int visited[10][10][10][10] = { 0, };	//방문 체크
	queue<INFO> q;							//구슬 위치 정보와 움직인 횟수 큐
	q.push(start);							//큐에 시작 정보 저장
	visited[start.rx][start.ry][start.bx][start.by] = 1; // 시작 지점 방문

	int ret = -1; //ret값 -1로 초기화
	while (!q.empty()) {
		INFO cur = q.front(); q.pop();		//cur에 큐 제일 앞에 있는 원소를 반환하고 삭제
		if (cur.count > 10) break;			//10번 초과로 움직였다면 중지
		if (map[cur.rx][cur.ry] == 'O'&& map[cur.bx][cur.by] != 'O') {	//목표 달성 시
			ret = cur.count;	//움직인 횟수를 반환하고
			break;				//종료
		}
		for (int dir = 0; dir < 4; ++dir) {	//BFS
			//현재 구슬 위치 기억
				int next_rx = cur.rx;
			int next_ry = cur.ry;
			int next_bx = cur.bx;
			int next_by = cur.by;
			
			while (true) {
				if (map[next_rx][next_ry] != '#' && map[next_rx][next_ry] != 'O') {	//빨간 구슬이 벽에 닿지 않았고 구멍에 빠지지 않았다면
					next_rx += dx[dir];	//이동
					next_ry += dy[dir];	//이동
				}
				else {
					if (map[next_rx][next_ry] == '#') {								//빨간 구슬이 벽에 닿았다면
						next_rx -= dx[dir];	//바로 전으로 되돌아감
						next_ry -= dy[dir];	//바로 전으로 되돌아감
					}
					break;	//벽에 닿기 전까지 반복 후 중지
				}
			}

			while (true) {	//파란 구슬도 마찬가지로 이동
				if (map[next_bx][next_by] != '#' && map[next_bx][next_by] != 'O') {
					next_bx += dx[dir];
					next_by += dy[dir];
				}
				else {
					if (map[next_bx][next_by] == '#') {
						next_bx -= dx[dir];
						next_by -= dy[dir];
					}
					break;
				}
			}

			if (next_rx == next_bx && next_ry == next_by) { //파란 구슬과 빨간 구슬이 겹치게 되는 것 예외처리
				if (map[next_rx][next_ry] != 'O') {			//빨간 구슬이 구멍에 빠진게 아니라면
					int red_dist = abs(next_rx - cur.rx) + abs(next_ry - cur.ry);	//빨간 구슬의 이동 거리
					int blue_dist = abs(next_bx - cur.bx) + abs(next_by - cur.by);	//파란 구슬의 이동 거리
					if (red_dist > blue_dist) {		//빨간 구슬이 더 많이 움직였다면
						next_rx -= dx[dir];
						next_ry -= dy[dir];			//빨간 구슬을 한 칸 전으로 이동
					}
					else {							//파란 구슬이 더 많이 움직였다면
						next_bx -= dx[dir];
						next_by -= dy[dir];			//파란 구슬을 한 칸 전으로 이동
					}
				}
			}

			if (visited[next_rx][next_ry][next_bx][next_by] == 0) {
				visited[next_rx][next_ry][next_bx][next_by] = 1;	//구슬이 방문한 지역을 표시
				INFO next;
				next.rx = next_rx;
				next.ry = next_ry;
				next.bx = next_bx;
				next.by = next_by;
				next.count = cur.count + 1;
				q.push(next);										//next를 큐에 삽입
			}
		}


	}

	return ret;
}

int main() {
	int n, m;
	cin >> n >> m;
	char** map = new char*[n];
	for (int i = 0; i < n; ++i) {
		map[i] = new char[m];
	}

	for (int i = 0; i < n; ++i) {
		cin >> map[i];
	}

	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			if (map[x][y] == 'R') {
				start.rx = x;
				start.ry = y;
			}
			if (map[x][y] == 'B') {
				start.bx = x;
				start.by = y;
			}
		}
	}

	start.count = 0;

	int ret = bfs(map);
	cout << ret;

	for (int i = 0; i < n; ++i) {
		delete[] map[i];
	}
	delete[] map;


	return 0;
}
