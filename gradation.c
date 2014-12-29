#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *file;
char mh[1000][10000];
int mr[1000][1000];
int mg[1000][1000];
int mb[1000][1000];
int gs[1000][1000];
int bw[1000][1000];
int g,h,i,j; // длина, высота, для счета

void countstr(); //считывание строк
void color(); //присвоение цветов в массивы
void gradation(); //создание массива градиента серого
void binar(); //бинаризация серого массива
void show(); //вывод бинаризированного массива для записи в файл

int main(int argc, char *argv[])
{
	file = fopen(argv[1], "r");
	if (file==NULL){
		printf("Введите в аргументах путь к изображению");
		exit(1);
		}
	countstr();
	color();
	gradation();
	binar();
	show();
}

void countstr()
{
	h=1;
	while (fgets(mh[h], 1000, file))
	{
		h++;
	}
}

void color()
{
	char *buf;
	int d=1;
	g=1;
	i=1;

	for(j=1;j<h;j++)
	{
		buf = strtok(mh[j], " ");
		while (buf != NULL)
		{
			if (d==1) {
				mr[j][i] = atoi(buf);
				d++;
				}
			else if (d==2) {
				mg[j][i] = atoi(buf);
				d++;
				}
			else if (d==3) {
				mb[j][i] = atoi(buf);
				d=1;
				i++;
				}
			if (g<i) g=i;
			buf=strtok(NULL," ");
		}
		d=1;
		i=1;
	}
}

void gradation()
{
	for(j=4;j<h;j++)
		for(i=1;i<g;i++)
			gs[j][i]=(mr[j][i]+mg[j][i]+mb[j][i])/3;
}

void binar()
{
	for(j=4;j<h;j++)
		for(i=1;i<g;i++)
		{
			if (gs[j][i]>atoi(mh[3])/3)
				bw[j-3][i]=0;
			else bw[j-3][i]=1;
		}
}

void show()
{
	printf("P1\n");
	printf("%d %d\n", h-4, g-1);
	for(j=1;j<h-3;j++){
		for(i=1;i<g;i++)
		{
			printf("%d ",bw[j][i]);
		}
	printf("\n");
	}
}
