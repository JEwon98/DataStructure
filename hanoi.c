#include <stdio.h>
#pragma warning (disable:4996)

void Hanoi(int N, int src, int des, int temp);
int main() {

	int N;

	scanf("%d", &N);
	Hanoi(N, 1, 3, 2);

}
void Hanoi(int N, int src, int des, int temp) {

	if (N == 1) {
		printf("%d to %d\n", src, des);
		return;
	}
	Hanoi(N - 1, src, temp, des);
	Hanoi(1, src, des, temp);
	Hanoi(N - 1, temp, des, src);


}