#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	int n;

	int stack[100001];
	char oper[100];
	scanf("%d",&n);
	int top = -1;
	for (int i = 0; i < n; i++) {
		scanf("%s",oper);

		if (strcmp(oper, "push") == 0) {
			int x;
			scanf("%d",&x);
			stack[++top] = x;
		}
		else if (strcmp(oper, "pop") == 0) {
			if (top == -1) {
				printf("-1\n");
			}
			else {
				printf("%d\n",stack[top--]);
			}
		}
		else if (strcmp(oper, "size") == 0) {
			printf("%d\n",top+1);
		}
		else if (strcmp(oper, "empty") == 0) {
			if (top != -1) {
				printf("0\n");
			}
			else {
				printf("1\n");
			}
		}
		else if (strcmp(oper, "top") == 0) {
			if (top >= 0) {
				printf("%d\n",stack[top]);
			}
			else {
				printf("%d\n",top);
			}
		}
	}
}