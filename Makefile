# Compiler
CX = cc

# Compiler flags
CXFLAGS = -Wall -Wextra -Werror

NAME =		libftprintf.a
FILES = srcs/base_formatter.c \
		srcs/ft_printf.c \
		srcs/formatter.c \
		srcs/str_formatter.c \
		srcs/ptr_formatter.c

OBJS = ${FILES:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
	ar rcs ${NAME} ${OBJS}

.c.o:
	${CX} ${CXFLAGS} -I include -c $< -o $@

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re