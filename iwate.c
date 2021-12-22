#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av)
{
	srand(atoi(av[ac != 1]));
	int i = 0, g = 0, r = rand() % 94 + 33;
	while (read(1, &g, 1) && g != r && ++i)
		write(1, "soba ", 5);
	printf("\n[%c] %d\n", r, i);
	return 0;
}
