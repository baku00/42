#include <unistd.h>

int main(int argc, char **argv)
{
	char cs[255];
	char *s1, *s2;
	char c;
	int i = -1;
	int j = -1;
	if (argc == 3)
	{
		for (i = 0; i < 255; i++)
			cs[i] = 0;
		i = -1;
		s1 = argv[1];
		s2 = argv[2];
		while (s1[++i])
		{
			j = -1;
			while (s2[++j]) {
				if (s1[i] == s2[j] && !cs[(s1[i] + 0)])
				{
					cs[(s1[i] + 0)] = 1;
					c = s1[i];
					write(1, &c, 1);
				}
			}
		}

	}
	write(1, "\n", 1);
	return 0;
}
