/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:25:32 by linhnguy          #+#    #+#             */
/*   Updated: 2024/04/07 17:59:39 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

typedef struct sbonus_list
{
	void			*content;
	struct sbonus_list	*next;
}		t_b_list;

typedef struct s_get_list
{
	char				*str;
	struct s_get_list	*next;
}	t_list;

int					ft_isalpha(int n);
int					ft_isdigit(int n);
int					ft_isascii(int n);
int					ft_isalnum(int n);
int					ft_isprint(int n);
size_t				ft_strlen(const char *s);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *str1, const void *str2, size_t n);
char				*ft_strnstr(const char *h, const char *n, size_t len);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dsize);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_b_list			*ft_lstnew(void *content);
void				ft_lstadd_front(t_b_list **lst, t_b_list *new);
int					ft_lstsize(t_b_list *lst);
t_b_list			*ft_lstlast(t_b_list *lst);
void				ft_lstadd_back(t_b_list **lst, t_b_list *new);
void				ft_lstdelone(t_b_list *lst, void (*del)(void*));
void				ft_lstclear(t_b_list **lst, void (*del)(void*));
void				ft_lstiter(t_b_list *lst, void (*f)(void *));
t_b_list			*ft_lstmap(t_b_list *lst, void *(*f)(void *),
						void (*del)(void *));

int					ft_printf(int fd, const char *s, ...);
int					prints(int fd, char *s);
int					printc(int fd, char s);
int					printnbr(int fd, long n, int *c);
int					ft_speci(int fd, va_list *arg, char s);
int					printx(int fd, unsigned long n, char s, int *c);
int					printp(int fd, unsigned long n, int *c);

void				copy_str(t_list *list, char *full_line);
char				*get_next_line(int fd);
t_list				*last_node(t_list *list);
int					add_node(t_list **list, char *buf, int fd);
int					len_of_string(t_list *list);
void				clean_list(t_list **list, t_list *remainder_node);


#endif // LIBFT_H