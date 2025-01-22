#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int ROW, COL, CUR = 0;
vector<vector<int>> map;

vector<vector<int>> fileload(string filepath) {
	ifstream openFile(filepath);

	if (openFile.is_open()) {
		openFile >> ROW >> COL;

		vector<vector<int>> result(ROW, vector<int>(COL));

		for (int i = 0; i < ROW; ++i) {
			for (int j = 0; j < COL; ++j) {
				openFile >> result[i][j];
			}
		}

		return result;
	}

	return vector<vector<int>>();
}

int main() {
	pair<int, int> start, goal;
	string filePath = "MAP1.txt";

	map = fileload(filePath);
	if (map.empty()) return -1;


	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			if (map[i][j] == 2) {
				start = { i, j };
				map[i][j] = 0;
			}
			if (map[i][j] == 3) {
				goal = { i, j };
				map[i][j] = 0;
			}
		}
	}

	//cout << start.first << start.second << goal.first << goal.second;

	return 0;
}