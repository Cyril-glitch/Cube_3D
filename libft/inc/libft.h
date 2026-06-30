/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:59:48 by cycolonn          #+#    #+#             */
/*   Updated: 2026/06/30 12:33:13 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

//# include <fcntl.h>
//# include <stdio.h>
//# include <string.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

# define RESET "\001\033[0m\002"
// bold blue
# define B_BLUE "\001\033[1;34m\002"
// bold light red
# define B_L_RED "\001\033[1;91m\002"
// vert menthe doux
# define MINT "\001\033[38;5;121m\002"
// Rouge Corail Doux (Coral)
# define CORAL "\001\033[38;5;203m\002"
// Un Bleu Acier
# define STEEL "\001\033[38;5;110m\002"
// lavande
# define LAVENDER "\001\033[38;5;147m\002"
// ice blue
# define ICE_BLUE "\001\033[38;5;117m\002"

// gestion de memoire
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_mempcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memrchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

// fonctions booleenes
int					ft_isspace(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_ischarset(char c, char set);
int					ft_isset(char c, const char *set);
int					ft_isfull_dig(char *s);

// allocation
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_freeiter(char **tab, int i);
void				ft_freedtab(void *t);

// manipulation des chaines de caracteres
int					ft_tolower(int c);
int					ft_toupper(int c);
size_t				ft_strlen(const char *s);
size_t				ft_dtablen(void *s);
void				ft_putstr(char *str);
char				*ft_strcpy(char *dst, const char *src);
int					ft_tablen(char **av);

char				*ft_strncpy(char *dst, const char *src, size_t dsize);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strncat(char *dst, const char *src, size_t ssize);
size_t				ft_strlcat(char *dst, const char *src, size_t dsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);

int					ft_str_append_str(char **s1, char *s2);
int					ft_str_append_mem(char **s1, char *s2, size_t size2);
char				*ft_strtrim(char const *s1, char const *set);
int					ft_countword(const char *s, char set);
int					ft_set_countword(char const *s, char *set);
char				**ft_split(char const *s, char c);
char				**ft_set_split(char const *s, char *set);
void				ft_sort(int size, char **tab);

// manipulation de chaines avec pointeur de fonctions
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

// manipulation de fichiers
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

// affichage des bases
int					ft_atoi(const char *nptr);
long				ft_atol(const char *nbr);
long long			ft_atoll(const char *nbr);
char				*ft_itoa(int n);
char				*ft_dtoa(double d, int precision);
void				ft_putnbr(int nbr);
void				ft_putdouble(double d_n, int precision);
void				ft_putnbr_base(int nbr, char *base);

// listes
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

#endif
