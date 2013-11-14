#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5000
#define INF 1e8



int dist[MAX_SIZE][MAX_SIZE];
int n;


void floyd_warshall() {
	int i, j, k;

	for (k = 0; k < n; ++k) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

void doPrint() {
	int i, j, k;

	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			printf("%d ", dist[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int i, j;

	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			scanf("%d", &dist[i][j]);
			if (dist[i][j] == -1) dist[i][j] = INF;
		}
	}

	floyd_warshall();
	//doPrint();
}





