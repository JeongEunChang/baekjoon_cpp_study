#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)


void push(int x, int* cnt, int* stack);
void pop(int* cnt, int* stack);
void size(int cnt);
void empty(int cnt);
void top(int cnt, int* stack);

int main(void)
{
	int* stack;
	int stack_size = 10;
	int cnt = 0;
	char* order[6];   // 문자 배열 사용  ---> 4ms,   char* order[6]; 사용시 0ms 나왔습니다.
	int num;
	int i;
	int x;

	stack = (int*)malloc(stack_size * sizeof(int));

	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		scanf("%s", order);
		if (strcmp(order, "push") == 0)
		{
			scanf("%d", &x);           // 어떻게 이것만 공백을 기준으로 나눌 지 몰라서
			push(x, &cnt, stack);      // 버퍼에 남게된다는 것을 이용했습니다.
		}
		else if (strcmp(order, "pop") == 0) pop(&cnt, stack);
		else if (strcmp(order, "size") == 0) size(cnt);
		else if (strcmp(order, "empty") == 0) empty(cnt);
		else if (strcmp(order, "top") == 0) top(cnt, stack);

		if (cnt == stack_size)
		{
			stack_size += 10;
			stack = (int*)realloc(stack, stack_size * sizeof(int));
		}
	}

	free(stack);
}

void push(int x, int* cnt, int* stack)
{
	stack[*cnt] = x;
	*cnt += 1;
}

void pop(int* cnt, int* stack)
{
	if (*cnt == 0) printf("%d\n", -1);
	else
	{
		printf("%d\n", stack[*cnt - 1]);
		*cnt -= 1;
	}
}

void size(int cnt)
{
	printf("%d\n", cnt);
}

void empty(int cnt)
{
	if (cnt == 0) printf("%d\n", 1);
	else printf("%d\n", 0);
}

void top(int cnt, int* stack)
{
	if (cnt == 0) printf("%d\n", -1);
	else printf("%d\n", stack[cnt - 1]);
}