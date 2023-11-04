CC = cc

NAME = cub3D

CFLAGS =  -fsanitize=address -g -Wall -Werror -Wextra 

PARSER = parser/parser.c \
		 parser/check_file.c \
		 parser/parse_filler.c

ENGINE = engine/engine.c \
		 engine/keyhook.c \
		 engine/drawing.c \
		 engine/x_y_pos.c \
		 engine/ray_casting.c \
		 engine/render.c

CFILES = main.c \
		 $(ENGINE) \
		 $(PARSER)

INCLUDE = -Iinclude
OBJECTS = $(CFILES:.c=.o)

LIBFT = libft/libft.a

all : $(NAME)

$(NAME) : $(OBJECTS)
	make -C libft
	$(CC) -Iinclude MLX42/build/libmlx42.a  -lglfw -L"/Users/$(USER)/homebrew/opt/glfw/lib" -framework Cocoa -framework OpenGL -framework IOKit $(CFLAGS) $(LIBFT) $(OBJECTS) -o $(NAME)

%.o : %.c
	$(CC) -Ilibft $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	make clean -C libft
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re : fclean all
