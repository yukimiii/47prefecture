#include <unistd.h>
#include <fcntl.h>
#define ONSEN __FILE__
#define SIZE 1

int	main()
{
	int		fd = open(ONSEN, O_RDONLY);
	char	spring[SIZE];

	if (fd < 0 || read(fd, spring, 0) < 0)
		return (1);
	for (ssize_t r = SIZE; 0 < (r = read(fd, spring, sizeof(spring))) && 0 < write(STDOUT_FILENO, spring, r);)
		;
	return (0);
}
