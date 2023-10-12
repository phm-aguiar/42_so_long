/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:11:54 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/12 18:17:41 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_libft
{
	void			*content;
	struct s_libft	*next;
}					t_list;

typedef struct s_gnl
{
	char			data;
	struct s_gnl	*next;
}					t_gnl;

typedef struct s_itoa_base
{
	char			*str;
	size_t			len;
	int				len_base;
}					t_variables;

int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
size_t				ft_strlen(const char *msg);
void				*ft_memset(void *array, int value, size_t num);
void				ft_bzero(void *array, size_t num);
void				*ft_memcpy(void *array, const void *src, size_t num);
void				*ft_memmove(void *array, const void *src, size_t num);
int					ft_atoi(const char *nptr);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
void				*ft_calloc(size_t num_elements, size_t element_size);
char				*ft_strdup(char *src);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_itoa(int n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *newnode);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *newnode);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
size_t				ft_nbrlen(long int nbr);
char				*ft_strnew(int counter);
char				*ft_itoa_base(long int nbr, char *base);
int					ft_putstr(const char *s);
size_t				ft_putnbr(long int n);
size_t				ft_putnbr_base(long int nbr, char *base);
void				ft_putendl(char *s);
int					ft_putchar(char c);
void				ft_strrev(char *ptr);
int					ft_putptr(size_t number, char *base);
size_t				ft_nbrlen_base(long int nbr, int len_base);
char				*ft_itoa_unsigned(unsigned int n);
int					ft_isnonzero_digit(int c);
int					ft_sizelst(t_gnl **list_of_char);
int					ft_read_error(t_gnl **main_list, char *current);
void				ft_start_gnl(t_gnl **caracter, char c);
void				ft_wipe_list(t_gnl **list_of_char, int counter);
char				*get_next_line(int fd);
int					ft_read_the_file(int fd, t_gnl **main_list);
int					ft_split_char(const char *c, t_gnl **main_list);
void				ft_add_caracter(t_gnl **main_list, char character);
void				ft_extract_line(t_gnl **list_of_char, char **line,
						int counter);

#endif
