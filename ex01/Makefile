SRCS		= main.cpp\
				Contact.cpp\
				Phonebook.cpp
OBJS		= ${SRCS:.cpp=.o}
NAME		= phonebook
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

$(NAME):	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:		$(NAME)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} $(NAME)

re:			fclean all