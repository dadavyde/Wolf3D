# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/17 12:09:18 by dadavyde          #+#    #+#              #
#    Updated: 2018/02/17 12:09:21 by dadavyde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
C_FLAGS = -c -Wall -Wextra -Werror -O3 -flto=thin -Ofast -march=native -mtune=native
WOLF_FLAGS = -F ~/Library/Frameworks/ -framework SDL2 -framework SDL2_mixer

SOURCES = src/main.c src/error_file.c src/validate.c src/save_map.c src/init.c \
		src/play_wolf3d.c src/events.c src/draw_scene.c src/find_intersection.c \
		src/draw_mini_map.c src/draw_line.c src/draw_texture_scene.c \
		src/draw_solid_scene.c src/recount_angle.c

HEADERS = includes/structs.h includes/wolf3d.h
INCLUDES = -I libft/
INCLUDES_SDL = -I ~/Library/Frameworks/SDL2.framework/Versions/A/Headers/\
				-I ~/Library/Frameworks/SDL2_mixer.framework/Versions/A/Headers/

OBJ = $(addprefix $(OBJDIR), $(notdir $(SOURCES:.c=.o)))
OBJDIR = obj/

LIBFT = libft/libft.a
NAME = wolf3d

C_RED = \033[31m
C_GREEN = \033[32m
C_MAGENTA = \033[35m
C_NONE = \033[0m

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ) $(LIBFT) 
	@$(CC) $(OBJ) $(WOLF_FLAGS) -o $@ $(LIBFT) 
	@printf "$(C_MAGENTA)wolf3d:   $(C_NONE) %-50s$(C_GREEN)[done]$(C_NONE)\n" $@

$(OBJDIR)%.o: src/%.c  $(HEADERS)
	@$(CC) $(C_FLAGS) $(INCLUDES_SDL)  $< -o  $@ $(INCLUDES)
	@printf "$(C_MAGENTA)wolf3d:   $(C_NONE) %-50s$(C_GREEN)[done]$(C_NONE)\n" $@

$(LIBFT):
	@make -C libft

$(OBJDIR): $(HEADERS) $(LIBFT)
	@mkdir -p $(OBJDIR)

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJDIR)
	@printf "$(C_MAGENTA)wolf3d:   $(C_NONE) %-50s$(C_RED)[done]$(C_NONE)\n" $@

fclean: clean
	@echo $(OBJ)
	@rm -f $(NAME)
	@printf "$(C_MAGENTA)wolf3d:   $(C_NONE) %-50s$(C_RED)[done]$(C_NONE)\n" $@

re: fclean all
