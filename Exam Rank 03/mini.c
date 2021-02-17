#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

typedef struct s_zone
{
    int widh;
    int height;
    char background;
}               t_zone;

typedef struct s_list
{
    char	type;
    float	x;
    float	y;
    float	radius;
    char	color;
}               t_list;

int ft_strlen(char *s)
{
    int i = 0;
    if (!s)
		return (i);
    while (s[i] != '\0')
        ++i;
    return (i);
}

int fail(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

int free_all(FILE *file, char *str)
{
	fclose(file);
	if (str)
		free(str);
	return (1);
}

char *get_zone(FILE *file, t_zone *zone)
{
    int i;
    char *array;

    if ((i = fscanf(file, "%d %d %c\n", &zone->widh, &zone->height, &zone->background)) != 3)
        return (NULL);
    if (zone->widh <= 0 || zone->widh > 300 || zone->height <= 0 || zone->height > 300)
        return (NULL);
    if (!(array = (char *)malloc(sizeof(char) * (zone->widh * zone->height))))
        return (NULL);
    i = -1;
    while (++i < (zone->widh * zone->height))
        array[i] = zone->background;
    return (array);
}

int is_rad(int x, int y, t_list *tmp)
{
	float dist;

	dist = sqrtf((x - tmp->x) * (x - tmp->x) + (y - tmp->y) * (y - tmp->y));
	if (dist <= tmp->radius)
	{
		if ((tmp->radius - dist) < 1.00000000)
			return (2);
		return (1);
	}
	return (0);
}

void get_draw(t_list *tmp, t_zone *zone, char *draw)
{
	int x, y, rad;

	y = 0;
	while (y < zone->height)
	{
		x = 0;
		while (x < zone->widh)
		{
			rad = is_rad((float)x, (float)y, tmp);
			if ((rad == 2 && tmp->type == 'c') || (rad && tmp->type == 'C'))
                draw[(y * zone->widh) + x] = tmp->color;
            x++;
		}
		++y;
	}
}

int drawing(FILE *file, t_zone *zone, char *draw)
{
	t_list tmp;
	int count;

	while ((count = fscanf(file, "%c %f %f %f %c\n", &tmp.type, &tmp.x, &tmp.y, &tmp.radius, &tmp.color)) == 5)
	{
		if (tmp.radius <= 0.00000000 && (tmp.type != 'c' || tmp.type != 'C'))
			return (0);
		get_draw(&tmp, zone, draw);
	}
	if (count != -1)
		return (0);
	return (1);
}

void print_draw(char *draw, t_zone *zone)
{
	int i = 0;

	while (i < zone->height)
	{
		write(1, draw + (i * zone->widh), zone->widh);
		write(1, "\n", 1);
		++i;
	}
}

int main(int argc, char **argv)
{
	t_zone zone;
	char *draw;
	FILE *file;

	if (argc != 2)
		return (fail("Error: argument\n"));
	if (!(file = fopen(argv[1], "r")))
		return (fail("Error: Operation file corrupted\n"));
	if (!(draw = get_zone(file, &zone)))
		return (free_all(file, NULL) && fail("Error: Operation file corrupted\n"));
	if (!(drawing(file, &zone, draw)))
		return (free_all(file, draw) && fail("Error: Operation file corrupted\n"));
	print_draw(draw, &zone);
	free_all(file, draw);
	return (0);
}
