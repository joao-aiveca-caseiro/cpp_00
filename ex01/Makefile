SRCS		= main.cpp\
				Contact.cpp\
				PhoneBook.cpp
INCS		= Contact.hpp\
				PhoneBook.hpp
OBJS		= ${SRCS:.cpp=.o}
NAME		= phonebook
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

$(NAME):	${OBJS} ${INCS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:		$(NAME)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} $(NAME)

re:			fclean all