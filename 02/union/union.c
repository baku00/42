#include <unistd.h>

int main(int argc, char **argv)
{
	char cs[255] = {0};
	char *s1, *s2;
	char c;
	int i = -1;
	if (argc == 3)
	{
		s1 = argv[1];
		s2 = argv[2];
		while (s1[++i]) {
			if (!cs[(s1[i] + 0)])
			{
				cs[(s1[i] + 0)] = 1;
				c = s1[i];
				write(1, &c, 1);
			}
		}
		i = -1;
		while (s2[++i]) {
			if (!cs[(s2[i] + 0)])
			{
				cs[(s2[i] + 0)] = 1;
				c = s2[i];
				write(1, &c, 1);
			}
		}
	}
	write(1, "\n", 1);
	return 0;
}
