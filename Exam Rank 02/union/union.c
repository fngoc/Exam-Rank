#include <unistd.h>

static void ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	int buf[127] = { 0 };
	int i;

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i] != '\0')
		{
			if (buf[(int)argv[1][i]] == 0)
			{
				buf[(int)argv[1][i]] = 1;
				ft_putchar(argv[1][i]);
			}
			++i;
		}
		i = 0;
		while (argv[2][i] != '\0')
		{
			if (buf[(int)argv[2][i]] == 0)
			{
				buf[(int)argv[2][i]] = 1;
				ft_putchar(argv[2][i]);
			}
			++i;
		}
	}
	ft_putchar('\n');
	return (0);
}
