#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int mass[10000][10000];
int x,y,h,g,i,j;
char *args[1000];

int main(int argc, char *argv[]){
	int k;

	for (k=1;k<argc-1;k++)
		args[k]=argv[k];

    	setlocale(LC_ALL,"Russian");
	mist(argc);
	init_var();
	dr_tab();
	for (k=5;k<argc;k++)
		check_tab(k-4,atoi(argv[k]));
	show_tab();
}

int mist(int argc){
	if (argc == 1) {
		printf("Введите последовательно значения следующих параметров: (ширина ячейки) (высота ячейки) (количество вариантов ответа) (количество вопросов) (ответы)\n\n");
		exit(1);
	}
	else if (atoi(args[4]) != argc-5) {
		printf("Количество вопросов не сповпадает с количеством ответов\n\n",atoi(args[4]),argc-5);
		exit(1);
	}
	for (i=5;i<argc-1;i++)
		if (atoi(args[3]) < atoi(args[i]) || atoi(args[i]) < 1){
			printf("Вы ввели вариант ответа, который отстутсвует в предложенных вариантах\n\n",atoi(args[3]),atoi(args[i]));
			exit(1);
		}
	if (atoi(args[1]) < 3 || atoi(args[2]) < 3) {
		printf("Размер ячейки должен быть больше 2-х\n\n");
		exit(1);
	}
}

int init_var(){
	h=atoi(args[1]);
	g=atoi(args[2]);
	x=(atoi(args[1])+1)*atoi(args[3])+1;
	y=(atoi(args[2])+1)*atoi(args[4])+1;
}

int dr_tab(){
	for (i=1;i<y+1;i=i+g+1)
		for (j=1;j<x+1;j++)
			mass[i][j]=1;

	for (j=1;j<x+1;j=j+h+1)
		for (i=1;i<y+1;i++)
			mass[i][j]=1;
}

int check_tab(int vpr, int otv){
	int m,n;
	m=3+((h+1)*(otv-1));
	n=3+((g+1)*(vpr-1));
	for (i=0;i<g-2;i++)
		for (j=0;j<h-2;j++)
			mass[n+i][m+j]=1;
}

int show_tab(){
	printf("P1\n");
	printf("%d %d\n",x,y);
	for (i=1;i<y+1;i++){
		for (j=1;j<x+1;j++){
			printf("%d",mass[i][j]);
		}
		printf("\n");
	}
}