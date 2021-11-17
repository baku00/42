#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "includes/libft/libft.h"
int  ft_printf(const char *s, ...);
void	ft_putunsigned_fd(unsigned long long int nb, int fd);
int	ft_intlen(long int nb);
void  ft_print_c(char c);
void  ft_print_d(int n);
void  ft_print_p(size_t p);
void  ft_print_s(char *s);
void  ft_print_u(unsigned int n);
void  ft_print_x(int n);
#endif
