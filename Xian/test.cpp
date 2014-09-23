#include<iostream>
#include<cstdio>
#include<queue>
#include<map>
using namespace std;
struct node {
	int top, bottom, left, right, front, back, step;
	bool operator < (const node &x) const {
		if (top != x.top) {
			return top < x.top;
		}
		if (bottom != x.bottom) {
			return bottom < x.bottom;
		}
		if (left != x.left) {
			return left < x.left;
		}
		if (right != x.right) {
			return right < x.right;
		}
		if (front != x.front) {
			return front < x.front;
		}
		return back < x.back;
	}
	bool operator == (const node &x) const {
		return top == x.top && bottom == x.bottom && left == x.left && right == x.right && front == x.front && back == x.back;
	}
};
node lr(const node &x) {
	node y;
	y = x;
	y.step = x.step;
	y.bottom = x.left;
	y.left = x.top;
	y.top = x.right;
	y.right = x.bottom;
	return y;
}
node rr(const node &x) {
	node y;
	y = x;
	y.step = x.step;
	y.bottom = x.right;
	y.right = x.top;
	y.top = x.left;
	y.left = x.bottom;
	return y;
}
node fr(const node &x) {
	node y;
	y = x;
	y.step = x.step;
	y.bottom = x.front;
	y.front = x.top;
	y.top = x.back;
	y.back = x.bottom;
	return y;
}
node br(const node &x) {
	node y;
	y = x;
	y.step = x.step;
	y.bottom = x.back;
	y.back = x.top;
	y.top = x.front;
	y.front = x.bottom;
	return y;
}
int bfs(node st, node ed) {
	map<node, bool> vis; node now, next;
	queue<node> q;
	if (st == ed) {
		return 0;
	}
	st.step = 0;
	q.push(st);
	vis[st] = true;
	while (!q.empty()) {
		now = q.front(); q.pop();
		next = lr(now);
		if (!vis[next]) {
			if (next == ed) {
				return now.step+1;
			}
			vis[next] = true;
			next.step = now.step+1;
			q.push(next);
		}
		next = rr(now);
		if (!vis[next]) {
			if (next == ed) {
				return now.step+1;
			}
			vis[next] = true;
			next.step = now.step+1;
			q.push(next);
		}
		next = fr(now);
		if (!vis[next]) {
			if (next == ed) {
				return now.step+1;
			}
			vis[next] = true;
			next.step = now.step+1;
			q.push(next);
		}
		next = br(now);
		if (!vis[next]) {
			if (next == ed) {
				return now.step+1;
			}
			vis[next] = true;
			next.step = now.step+1;
			q.push(next);
		}
	}
	return -1;
}
int main() {
	node st, ed;
	st.step = 0;
	while (scanf("%d", &st.top) == 1) {
		scanf("%d", &st.bottom);
		scanf("%d", &st.left);
		scanf("%d", &st.right);
		scanf("%d", &st.front);
		scanf("%d", &st.back);
		scanf("%d", &ed.top);
		scanf("%d", &ed.bottom);
		scanf("%d", &ed.left);
		scanf("%d", &ed.right);
		scanf("%d", &ed.front);
		scanf("%d", &ed.back);
		printf("%d\n", bfs(st, ed));
	}
	return 0;
}
