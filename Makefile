NAME		=	domini_corner
CPP			=	g++ $(FLAGS)
RM			=	rm -f
FLAGS		=	-Wall -Wextra -Werror -g3 -std=c++14 -Iinclude/ -lglut -lGL -lGLU -lm
SRCS		=	$(addprefix srcs/, main.cpp MainWindow.cpp GameField.cpp GameCore.cpp\
				Player.cpp \
				)
OBJS		=	$(SRCS:.cpp=.o)
CYAN		=	\x1B[36m
MAGENTA		=	\x1B[35m
GREEN		=	\033[92m
ENDCOLOR	=	\x1B[0m

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CPP) $(OBJS) -o $(NAME)
			echo "${GREEN}"$(NAME)" is compiled${ENDCOLOR}"

clean:
			$(RM) $(OBJS)
			echo objs deleted

fclean:		clean
			$(RM) $(NAME)
			echo $(NAME) deleted

re:			fclean all

%.o:		%.cpp
			$(CPP) -c $< -o $@
			echo $@ compilled

run:		all
			./ircserv 1234 1234

.PHONY:		all clean fclean re so bonus norm

#.SILENT:
