_RED	=	\033[31m
_GREAN	=	\033[32m
_YELLOW	=	\033[33m
_BLUE	=	\033[34m
_END	=	\033[0m

NAME	=	miniRT
SRCS	=	srcs/main.c srcs/bmp.c srcs/ft_check_filename.c srcs/ft_error1.c srcs/ft_event.c \
			srcs/ft_input_test1.c srcs/ft_input_test2.c  srcs/output_teset.c\
			srcs/read_rtfile1.c srcs/read_rtfile2.c srcs/read_rtfile3.c srcs/read_rtfile4.c srcs/read_rtfile5.c\
			srcs/ft_make_cylinder.c srcs/ft_make_plane.c srcs/ft_make_ray.c srcs/ft_make_screan.c srcs/ft_make_sphere.c srcs/ft_make_square.c srcs/ft_make_triangle.c\
			srcs/ft_mlx_use.c srcs/ft_prepare_lc.c srcs/ft_prepare_obj.c \
			srcs/ft_print_objs.c srcs/ft_showimage.c \
			srcs/light1.c srcs/light2.c srcs/light_cross1.c srcs/light_cross2.c\
			srcs/ft_quadratic_func.c \
			srcs/ft_windowsize.c\
			srcs/libft1.c srcs/libft2.c srcs/libft3.c srcs/libft4.c\
			srcs/ft_vector_utli1.c srcs/ft_vector_utli2.c \
			srcs/ft_calcu_progress.c

OBJS = $(SRCS:.c=.o)

CC	= gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L./minilibx-linux -lmlx_Linux -lXext -lX11 -lm
	@echo "\nFINISH Compiling $(NAME)!"
	@echo "$(_YELLOW)Try \"./$(NAME)  rt_files/*.rt\" to use$(_END)"


clean:
	@echo "Removing object files...."
	@rm -rf $(OBJS)

fclean:
	@echo "$(_RED)Removing object files and program....$(_END)"
	@rm -rf $(NAME) $(OBJS)

re: fclean all

%.o: %.c
	@$(CC) -c $(CFLAGS) -L./minilibx_linux -lmlx_Linux -lXext -lX11 -lm -o $@ $<
	@printf "$(_GREAN)>$(_END)"

PHONY: all clean fclean re