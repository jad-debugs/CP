#include <bits/stdc++.h>
using namespace std;
/*
6
E 3 5
N 5 3
E 4 6
E 10 4
N 11 2
N 8 1
*/

int n;

int minOfArray(int arr[]) {
	int ans = 1e9;
	for(int i = 0; i < n; i++) {
		if(arr[i] < ans)
			ans = arr[i];
	}
	return ans;
}

int main()
{

	cin >> n;

	char dir[n];
	int y[n], x[n];

	for(int i = 0; i < n; i++) {
		cin >> dir[i] >> x[i] >> y[i];
	}

	int d = min(minOfArray(y), minOfArray(x));
	
	for(int i = 0; i < n; i++) {
		y[i] -= d; x[i] -= d;
	}

	set<pair<int,int>> coordinates;

	set<int> cowsDone;

	int ans[n];

	for(int i = 0; i < n; i++) {
		ans[i] = 0; // was 9, trying something else
	}

	while(true) {
		if(cowsDone.size() == n)
			break;
		vector<pair<int, int>> curCoor;
		for(int i = 0; i < n; i++) {
			if(cowsDone.count(i) == 0) {
				if(coordinates.count(make_pair(x[i], y[i])) == 0) {

					if(dir[i] == 'E') {
						if(x[i] <= 1e4) {
							curCoor.push_back(make_pair(x[i], y[i]));
							x[i]++; ans[i]++;
						}
						else {
							ans[i] = -1;
							cowsDone.insert(i);
						}
					}
					else if(dir[i] == 'N') {
						if(y[i] <= 1e4) {
							curCoor.push_back(make_pair(x[i], y[i]));
							y[i]++; ans[i]++;
						}
						else {
							ans[i] = -1;
							cowsDone.insert(i);
						}
					}
				}
				else {
					cowsDone.insert(i);
					continue;
				}
			}
			else
				continue;
		}

		for(auto x : curCoor) {
			coordinates.insert(x);
		}
	}

	for(int i = 0; i < n; i++) {
		if(ans[i] == -1)
			cout << "Infinity";
		else
			cout << ans[i];
		cout << "\n";
	}

	return 0;
}