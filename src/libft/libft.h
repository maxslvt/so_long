/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolet-l <msolet-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:49:55 by msolet-l          #+#    #+#             */
/*   Updated: 2025/03/06 16:30:13 by msolet-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_printf(const char *txt, ...);
int					ft_ltoa_hexa_size(unsigned long long nb);
char				*ft_ltoa_hexa(unsigned long long n, char format);
int					ft_utoa_size(long nb);
char				*ft_utoa(unsigned int n);
char				*printf_s(const char *src);
char				*printf_p(long n);
void				ft_put_and_free(char *argc, int *len);
void				ft_putlen(const char *c, int i, int *len);
int					ft_putstr_fd2(char *s, int fd);
void				ft_printc(char c, int fd, int *len);
int					ft_putchar_fd2(char c, int fd);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t n);
char				*ft_strdup(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				**ft_split(char const *s, char c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_inset(char c, const char *set);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_atoi(const char *nptr);
int					ft_lstsize(t_list *lst);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				*ft_memset(void *s, int c, size_t n);
void				*ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
char				*get_next_line(int fd);
char				*ft_line_cleaner(t_list **s);
int					ft_strchr2(const t_list *s, int c);
t_list				*ft_lstlast(t_list *lst);
int					ft_strjoinlst(t_list **s1, char const *s2);

#endif