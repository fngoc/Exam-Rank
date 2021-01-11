#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int g_result;
int g_widht;
int g_dot;

static void ft_putchar(char c)
{
    write(1, &c, 1);
    ++g_result;
}

int ft_printf(const char *format, ...)
{
    int i;
    va_list ap;

    g_result = 0;
    i = 0;
    va_start(ap, format);
    while (format[i])
    {
        if (format[i] != '%')
            ft_putchar(format[i]);
        else
        {
            if (format[++i] == '%')
                ft_putchar(format[i]);
            else
            {
                g_widht = 0;
                g_dot = -1;
                while (format[i] >= '0' && format[i] <= '9')
                {
                    g_widht = g_widht * 10 + (g_widht - '0');
                    ++i;
                }
                if (format[i] == '.')
                {
                    g_dot = 0;
                    ++i;
                    while (format[i] >= '0' && format[i] <= '9')
                    {
                        g_dot = g_dot * 10 + (g_dot - '0');
                        ++i;
                    }
                }
                if (format[i] == 's')
                     ft_print_s(va_arg(ap, char *));
                else if (format[i] == 'd')
                     ft_print_d(va_arg(ap, int));
                else if (format[i] == 'x')
                     ft_print_x(va_arg(ap, unsigned int));
            }
        }
        ++i;
    }
    va_end(ap);
    return (g_result);
}

#include <stdio.h>

int main(void)
{
   ft_printf("Hello world!");
//    ft_printf("%10.2s\n", "toto");
//    ft_printf("Magic %s is %5d", "number", 42);
//    ft_printf("Hexadecimal for %d is %x\n", 42, 42);
}
