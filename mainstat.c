#include <stdio.h>
#include <string.h>
#include "stat.h"

int main()
{
    int x=nbobserver("stats.txt");
    if(x!=0)
        printf("Le nombre des observateurs est %d \n",x);
    else
	printf("Pas d'observateurs \n");

    trier("stats.txt");
    trier("gagnants.txt");

    return 0;
}
