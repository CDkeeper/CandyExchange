#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int N = 2e5 + 10;
int n;
int jishu[N], cnt, now_child;
int p[N], map[N];
int main() {
	scanf("%d", &n);
	memset(p, 0, sizeof(p));
	memset(map, 0, sizeof(p));
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	for (int i = 1; i <= n; i++) {
		if (map[i] == 0) {
			int child = i;
			now_child = p[child];
			cnt = 1;
			vector<int>q;
			q.push_back(child);
			while (now_child != child) {
				cnt++;
				q.push_back(now_child);
				now_child = p[now_child];
			}
			for (auto i : q) {
				jishu[i] = cnt;
				if (jishu[i] != 0)
					map[i] = 1;
			}
		}
	}
	printf("%d", jishu[1]);
	for (int i = 2; i <= n; i++) printf(" %d", jishu[i]);
	return 0;
}
