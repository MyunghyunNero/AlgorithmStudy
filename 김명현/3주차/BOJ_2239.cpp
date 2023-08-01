#include <iostream>
using namespace std;
bool check;
int map[10][10];
bool row[10][10] = { false, };
bool col[10][10] = { false, };
bool square[10][10] = { false, };

void print() {
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++)
			cout << map[i][j];
		cout << '\n';
	}
}

void go(int idx) {
    if(check) return;
	if (idx >= 81) {
		print();
        check=true;
		return;
	}
	int x = idx / 9;
	int y = idx % 9;
	int square_num = x / 3 * 3 + y / 3;
	if (map[x][y] == 0) {
		for(int i = 1; i <=9; i++) {
			if (row[x][i] == false && col[y][i] == false && square[square_num][i] == false) {
				map[x][y] = i;
				row[x][i] = true;
				col[y][i] = true;
				square[square_num][i] = true;
				go(idx + 1);
				map[x][y] = 0;
				row[x][i] = false;
				col[y][i] = false;
				square[square_num][i] = false;
			}
		}
	}
	else
		go(idx + 1);
}

int main() {
	
    for (int i = 0; i < 9; i++)
    {
        string Inp;
        cin >> Inp;
        for (int j = 0; j < Inp.length(); j++)
        {
            map[i][j] = Inp[j] - '0';
            if (map[i][j] != 0)
            {
                row[i][map[i][j]] = true;
                col[j][map[i][j]] = true;
                square[(i / 3) * 3 + (j / 3)][map[i][j]] = true;
            }
        }
    }
	go(0);
	return 0;
}