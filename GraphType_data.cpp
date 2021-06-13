#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define TRUE 1
#define FALSE 0
#define INF 1000

typedef struct GraphType
{
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int time=0;
int distance[MAX_VERTICES];
int selected[MAX_VERTICES];

int get_min_vertex(int n)
{
	int v, i;
	for (i = 0; i < n; i++)
		if (!selected[i]) {
			v = i;
			break;
		}
	for (i = 0; i < n; i++)
		if (!selected[i] && (distance[i] < distance[v])) v = i;
	return (v);
}

void prim(GraphType* g, int s)
{
	int i, u, v;
	for (u = 0;u < g->n;u++)
		distance[u] = INF;
	distance[s] = 0;
	for (i = 0; i < g->n; i++) 
	{
		u = get_min_vertex(g->n);
		time =time+g->weight[u][i]; //시간 측정
		selected[u] = TRUE;
		if (distance[u] == INF) return;
		for (v = 0; v < g->n; v++)
			if (g->weight[u][v] != INF)
				if (!selected[v] && g->weight[u][v] < distance[v])
					distance[v] = g->weight[u][v];
	}
}

int main(void)
{
	GraphType g = {11,
		{{0,19,3,11,13,INF,INF,INF,INF,INF,INF},
		{19,0,4,5,INF,INF,INF,INF,INF,INF,INF},
		{3,4,0,8,21,INF,INF,INF,INF,INF,INF},
		{11,5,8,0,INF,7,INF,INF,INF,INF,15},
		{13,INF,21,INF,0,24,INF,INF,INF,6,INF},
		{INF,INF,INF,7,24,0,17,8,3,INF,INF},
		{INF,INF,INF,5,INF,17,0,INF,15,INF,12},
		{INF,INF,INF,INF,INF,8,INF,0,11,7,INF},
		{INF,INF,INF,INF,INF,3,15,8,0,INF,INF},
		{INF,INF,INF,INF,6,INF,INF,7,INF,0,INF},
		{INF,INF,INF,15,INF,INF,12,INF,INF,INF,0}}
		};
	prim(&g, 0);
	printf("A	걸리는 시간 : %d\n", time);
	prim(&g, 1);
	printf("B	걸리는 시간 : %d\n", time);
	prim(&g, 2);
	printf("C	걸리는 시간 : %d\n", time);
	prim(&g, 3);
	printf("D	걸리는 시간 : %d\n", time);
	prim(&g, 4);
	printf("E	걸리는 시간 : %d\n", time);
	prim(&g, 5);
	printf("F	걸리는 시간 : %d\n", time);
	prim(&g, 6);
	printf("G	걸리는 시간 : %d\n", time);
	prim(&g, 7);
	printf("H	걸리는 시간 : %d\n", time);
	prim(&g, 8);
	printf("I	걸리는 시간 : %d\n", time);
	prim(&g, 9);
	printf("J	걸리는 시간 : %d\n", time);
	prim(&g, 10);
	printf("K	걸리는 시간 : %d\n", time);
	return 0;
}