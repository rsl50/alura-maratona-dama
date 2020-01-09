#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define LINE_SIZE	100
//SOLUÇÃO DE https://github.com/alura-cursos/maratonaprogramacao/blob/aula1-exc/DAMA.cpp

bool igual(int a, int b, int aa, int bb){
	return (a == aa && b == bb);
}

bool mesma_linha(int x, int y, int xx, int yy){
	return (x == xx || y == yy);
}
 
bool mesma_diagonal(int x, int y, int xx, int yy){
	return (x - y == xx - yy || x + y == xx + yy);
}

int main () {
	FILE *fp;
	fp = freopen("input1.txt", "r", stdin);
	
	char buf[LINE_SIZE];
	memset(buf, 0, LINE_SIZE);
	
	if (fp == NULL) {
		printf("Erro ao abrir arquivo");
		return (-1);
	} else {
		
		while (fgets(buf, LINE_SIZE, fp) != NULL) {
			int x1, x2, y1, y2;
			sscanf(buf, "%d %d %d %d", &x1, &y1, &x2, &y2);
						
			if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0) break;
			
			if (igual(x1, y1, x2, y2)) printf("0\n");
			else if (mesma_linha(x1, y1, x2, y2) || mesma_diagonal(x1, y1, x2, y2)) printf("1\n");
			else printf("2\n");
		}
	}
	
	fclose(fp);

    return (0);
}
