#include<stdio.h>
#include<stdlib.h>

#define QUEUE_MAX_SIZE 10
typedef int element;

typedef struct Queuetype {
	element Queue[QUEUE_MAX_SIZE];
	int front, rear;
};

void init(Queuetype* q) {
	q->front = q->rear = 0;
	return;
}

bool is_full(Queuetype* q) {
	return ((q->rear + 1) % QUEUE_MAX_SIZE == q->front);
}

bool is_empty(Queuetype* q) {
	return q->front == q->rear;
}

void push(Queuetype* q, element item) {
	if (!is_full(q)) {
		q->rear = (q->rear + 1) % QUEUE_MAX_SIZE;
		q->Queue[q->rear] = item;
	}
	else {
		fprintf(stderr, "메모리가 가득찼습니다.\n");
		exit(1);
	}
	return;
}

element pop(Queuetype* q) {
	if (is_empty(q)) {
		fprintf(stderr, "메모리가 비어있습니다.\n");
		exit(1);
	}
	else {
		q->front = (q->front + 1) % QUEUE_MAX_SIZE;
		return q->Queue[q->front];
	}
}

int fibonachi(Queuetype* q, int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;

	for (int i = 2; i <= n; i++) {
		int d = pop(q);
		push(q, d + q->Queue[q->rear]);
	}
	return q->Queue[q->rear];
}

int main(void) {
	Queuetype q;
	init(&q);
	push(&q, 0);
	push(&q, 1);
	int n = 8;
	printf("%d", fibonachi(&q, n));
}