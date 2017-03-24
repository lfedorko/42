/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:57:08 by lfedorko          #+#    #+#             */
/*   Updated: 2017/01/31 15:57:09 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> //wchar_t
#include "libft/libft.h"

typedef struct format
{
	int flag;
	int plus;
	int minus : 2;
	int sharp : 2;
	int space : 2;
	int zero;
	int min;
	int p;
	char len[3];
	char conv;
	int null;
}    			t_struct;

int		ft_atoi(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
size_t		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strnew(size_t size);

int				ft_printf(const char *format, ... );
int				to_struct(va_list argp, char **s, int b);
int 			handle_output(va_list argp, t_struct *form);
char			*itoa_b(t_struct *form, void *num, int s);
char 			*itoa_d(t_struct *form, void *num);
char			*itoa_base(uintmax_t value, int base, char letter, int h);
void 			fill_array(int size,char *s,t_struct *form);
char 			*record1(char *s, int i, int size);
char			*myitoa(intmax_t n, t_struct *form);

int 			compare(int a, int b);
int 			find_letter(char *s, char c);
char 			*ft_realloc(char *s, int size);
char			*my_strcpy(char *dst, const char *src);
int				ft_isdigit(int c);
char 			*ft_char(t_struct *form);
char 			*ft_c(t_struct *form, int ch);
char 			*ft_s(t_struct *form, char *ch);
void			init_struct(t_struct *form);
void			ft_putchar0(char *str,t_struct *form);
size_t 			ft_pow(size_t n, int p);
char 			*print_bi(size_t val, t_struct *form);
char            *print_n(int *type,t_struct *form);
char 			*ft_widechar_s(wchar_t *s, t_struct *form);
char	        *ft_ws(t_struct *form, char *ch);


#endif
