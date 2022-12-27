#include <iostream>
#include <vector>



using namespace std;

typedef enum { kWhite, kBlack } Color;

struct Coordinate {
	bool operator==(const Coordinate& that) const {
		return x == that.x && y == that.y;
	}

	int x, y;
};

bool SearchMazeHelper(const Coordinate& cur, const Coordinate& e,
	vector<vector<Color>>* maze_ptr,
	vector<Coordinate>* path_ptr) {
	auto& maze = *maze_ptr;

	if (cur.x < 0 || cur.x >= maze.size() || cur.y < 0 ||
		cur.y >= maze[cur.x].size() || maze[cur.x][cur.y] != kWhite) {
		return false;
	}

	auto& path = *path_ptr;
	path.emplace_back(cur);
	maze[cur.x][cur.y] = kBlack;
	if (cur == e) {
		return true;
	}

	for (const Coordinate& next_move : // Coordinate array를 두고 for loop 돌리기
		{ Coordinate{cur.x, cur.y + 1}, Coordinate{cur.x, cur.y - 1},
		Coordinate{cur.x + 1, cur.y}, Coordinate{cur.x - 1, cur.y} }) {
		if (SearchMazeHelper(next_move, e, maze_ptr, path_ptr)) {
			return true;
		}
	}

	path.pop_back();
	return false;
}

vector<Coordinate> SearchMaze(vector<vector<Color>> maze, const Coordinate& s,
	const Coordinate& e) {
	vector<Coordinate> path;
	SearchMazeHelper(s, e, &maze, &path);
	return path;
}

int main()
{
	return 0;
}
