#include <iostream>
#include <cmath>
using namespace std;

void backtrack(int &c){
	c--;
	if (c == -1) {
		exit(1);
	}
}

void print(int q[])
{
	static int count = 0;
	cout << "Solution #" << ++count << endl;
	cout << "  " << q[1] << " " << q[4] << endl;
	cout << q[0] << " " << q[2] << " " << q[5] << " " << q[7] << endl;
	cout << "  " << q[3] << " " << q[6] << endl;
}

bool ok(int a[8], int b, int c) {
	for (int i = 0; i<b; i++) {
		if (a[i] == a[b] || (abs(a[b] - a[c]) == 1)) return false;
	}
	return true;
}

int main() {
	int ans[8] = { 0 }, c = 0, i = 0;
	int a[8][5] = { { -1, -1, -1, -1, -1 },
	{ 0, -1, -1, -1, -1 },
	{ 0, 1, -1, -1, -1 },
	{ 0, 2, -1, -1, -1 },
	{ 1, 2, -1, -1, -1 },
	{ 1, 2, 3, 4, -1 },
	{ 2, 3, 5, -1, -1 },
	{ 4, 5, 6, -1, -1 } };
	while (true){
		while (c<8) {
			ans[c]++;
			if (ans[c]>8) {
				ans[c] = 0;
				backtrack(c);
				continue;
			}

			for (i = 0; i<5; i++) {
				if (a[c][i] == -1){
					c++;
					if (c == 8) {
						print(ans);
						backtrack(c);
					}
					break;
				}
				if (ok(ans, c, a[c][i]) == false)
					break;
			}
		}
	}
}