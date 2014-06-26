/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 15:47:42 by aemebiku          #+#    #+#             */
/*   Updated: 2014/06/26 15:47:43 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include "libft_struct.h"

# define BUFF_SIZE 100

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
void	*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void	*ft_memmove(void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strndup(const char *s1, size_t len);
char	*ft_strcpy(char *s1, const char *s2);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
float	ft_atof(const char *str);
int		ft_toupper(int c);
int		ft_tolower(int c);

void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
char	*ft_strtrim_carac(char const *s, char c);
char	**ft_strsplit(char const *s, char c);
char	**ft_strsplit_esc(char const *s, char c);
char	**ft_strsplit_mult(char const *s, char *c);
char	*ft_itoa_base(long int n, int base);
char	*ft_itoa(long int n);
int		get_next_line(int const fd, char **line);
void	ft_free_tab(char **tab);

int		ft_putint(int c);
ssize_t	ft_putchar(char c);
ssize_t	ft_putchar_fd(char c, int fd);
ssize_t	ft_putstr(char const *s);
ssize_t	ft_putendl(char const *s);
ssize_t	ft_putstr_fd(char const *s, int fd);
ssize_t	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_base_fd(long int n, int base, int fd);
void	ft_putnbr_base(long int n, int base);
void	ft_putnbr(long int n);
void	ft_putnbr_fd(long int n, int fd);
void	ft_putnbrf(float n);
void	ft_putnbrf_fd(float n, int fd);
void	ft_puttab(char **cmd);

float	ft_power(float nb, int power);
int		ft_facto(int nb);
float	ft_rsqrt(float nb);
float	ft_cos(float angle);
float	ft_sin(float angle);
float	ft_tan(float angle);
float	ft_check_angle(float angle);

t_dlist	*ft_dlst_init(void);
t_dnew	*ft_dcreate_elem(void *data);
void	ft_dlstpush_head(t_dlist *list, void *data);
void	ft_dlstpush_tail(t_dlist *list, void *data);
void	ft_dlst_push(t_dlist *list, void *data, size_t pos);
void	ft_dlstdel_head(t_dlist *list, void (*p_fct)(void **));
void	ft_dlst_del(t_dlist *list, size_t pos, void (*p_fct)(void **));
void	ft_dlstdel_tail(t_dlist *list, void (*p_fct)(void **));
void	ft_dlstdel_all(t_dlist *list, void (*p_fct)(void **));
void	ft_dlstdel_elem(t_dlist *list, void (*p_fct)(void **));
t_dnew	*ft_dget_elem(t_dlist *list, size_t pos);
void	ft_dlst_swap(t_dlist *list, size_t pos1, size_t pos2);
size_t	ft_list_data_len(t_dlist *list);
char	*ft_dlst_to_array(t_dlist *list);
int		ft_get_pos(t_dlist *list, t_dnew *elem);
void	ft_delem_print(t_dnew *elem);
void	ft_dlst_print(t_dlist *list);
void	ft_dlst_print_sp(t_dlist *list);
void	ft_dlst_print_fd(t_dlist *list, int fd);
void	ft_dlst_rprint(t_dlist *list);
void	ft_dlst_print_tab(t_dlist *list);

#endif
