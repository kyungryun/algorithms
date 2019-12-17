#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;
char input[100001];
char oper, c;
int n;
stack<char> l_stack, r_stack;

int main() {
	scanf("%s",input);
	for (int i = 0; input[i] != 0; i++) {
		l_stack.push(input[i]);
	}

	scanf("%d",&n);
	

	for (int i = 0; i < n; i++) {
		scanf(" %c",&oper);
		if (oper == 'L' && l_stack.size() != 0) {
			r_stack.push(l_stack.top());
			l_stack.pop();
		}
		if (oper == 'D' && r_stack.size() != 0) {
			l_stack.push(r_stack.top());
			r_stack.pop();
		}
		if (oper == 'B' && l_stack.size() != 0) {
			l_stack.pop();
		}
		if (oper == 'P') {
			scanf(" %c",&c);
			l_stack.push(c);
		}
	}

	while (!l_stack.empty()) {
		r_stack.push(l_stack.top());
		l_stack.pop();
	}
	while (!r_stack.empty()) {
        printf("%c",r_stack.top());
		r_stack.pop();
	}
	printf("\n");

	return 0;
}
