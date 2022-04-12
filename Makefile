NAME		=	domini_corner
CPP			=	g++ $(CFLAGS)
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -g3 -std=c++14 -Iinclude/ -lglut -lGL -lGLU -lm
COMM_PATH	=	commands/
COMM_SRCS	=

CHNL_PATH	=	
CHNL_SRCS	=
SRVR_PATH	=	
SRVR_SRCS	=
SRCS		=	$(addprefix srcs/, main.cpp GameField.cpp\
					$(addprefix $(COMM_PATH), $(COMM_SRCS)) \
					$(addprefix $(CHNL_PATH), $(CHNL_SRCS)) \
					$(addprefix $(SRVR_PATH), $(SRVR_SRCS)) \
				)
			
OBJS		=	$(SRCS:.cpp=.o)
HDRS		=	
CYAN		=	\x1B[36m
MAGENTA		=	\x1B[35m
GREEN		=	\033[92m
ENDCOLOR	=	\x1B[0m

all:		$(NAME)

$(NAME):	$(OBJS) include/main.h
			$(CPP) $(OBJS) -o $(NAME)
			echo "${GREEN}"$(NAME)" is compiled${ENDCOLOR}"

clean:
			$(RM) $(OBJS)
			echo objs deleted

fclean:		clean
			$(RM) $(NAME)
			echo $(NAME) deleted

re:			fclean all

%.o:		%.cpp $(HDRS)
			$(CPP) -c $< -o $@
			echo $@ compilled

run:		all
			./ircserv 1234 1234

.PHONY:		all clean fclean re so bonus norm

.SILENT:
