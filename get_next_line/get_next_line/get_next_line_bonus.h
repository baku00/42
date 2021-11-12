#ifndef BUFFER_SIZE
# define BUFFER_SIZE
#endif

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>

char	*ft_strdup(const char *str);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
char  *get_next_line(int fd);
int get_state();
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif
