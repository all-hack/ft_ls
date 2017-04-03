# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelange <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/25 11:25:58 by obelange          #+#    #+#              #
#    Updated: 2016/10/22 17:26:22 by obelange         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

S_PATH = src/
B_PATH = build/
H_PATH = include/
LIBFT_PATH = libft
PRINTF_PATH = ft_printf

FILES = main

FILES += t_context_infa t_context_helper

FILES += t_clip_infa t_clip_infa_helper t_clip_engine t_clip_parse_helper \
t_clip_apply_sflags t_clip_apply_lflags t_clip_helper

FILES += ls_engine ls_longprint ls_longprint_permission
# ls_shortprint ls_argument_handling \
#  ls_argument_handling_files

FILES += algo_filesort algo_strsort
# FILES += algo_filesort_time 

FILES += file_helper

FILES += filelist_infa

# FILES += ft_strsearch_ov  

FILES += ft_strlist_print ft_strlist_len ft_strlist_build ft_strlist_add \
ft_strlist_del ft_strlist_minus ft_strlist_remove ft_strlist_findindex \
ft_fstrlist_add

FILES += ft_strtrim_c ft_strmcatf ft_strsearch_ov ls_arguments ft_fstrmcatf

OBJ = $(addprefix $(B_PATH), $(addsuffix .o, $(FILES)))

LIB_COMP = -L$(LIBFT_PATH) -lft -I$(LIBFT_PATH) -L$(PRINTF_PATH) -lftprintf -I$(PRINTF_PATH)

FLAGS = -Wall -Werror -Wextra
DEVF = $(FLAGS) -fsanitize=address
LEAKF = $(FLAGS) $(HOME)/Desktop/offence/tools/alloc_wrap.c -ldl

ifdef ALLOCWRAP
	C_FLAGS += $(HOME)/Desktop/offence/tools/alloc_wrap.c -ldl
endif 

.PHONY: all fclean clean libft.a libftprintf.a run leak

all : $(NAME)

$(NAME) : build $(OBJ) libft.a libftprintf.a
	@echo ""
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB_COMP)

run : fclean build $(OBJ) libft.a libftprintf.a
	@echo "\x1b[31mrun is turned on\x1b[36m"
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB_COMP) && printf "\x1b[37m" && ./$(NAME)

dev : fclean build $(OBJ) libft.a libftprintf.a
	gcc $(DEVF) -o $(NAME) $(OBJ) $(LIB_COMP)

leak : fclean build $(OBJ) libft.a  libftprintf.a
	@echo "\x1b[31malloc wrap is turned on\x1b[36m"
	gcc $(LEAKF) -o $(NAME) $(OBJ) $(LIB_COMP)

libft.a : 
	@printf "\x1b[32m \ncompiling libft.... \x1b[36m"
	@$(MAKE) -C $(LIBFT_PATH) all

libftprintf.a :
	@printf "\x1b[32m \ncompiling printf.... \x1b[36m"
	@$(MAKE) -C $(PRINTF_PATH) all

build :
	@printf "\x1b[32m \nbuilding objects.....\n\x1b[33m"
	@mkdir $(B_PATH)

$(B_PATH)%.o : $(S_PATH)%.c
	gcc -c $< -o $@ -I ./$(LIBFT_PATH)/$(H_PATH) -I ./$(H_PATH) -I ./$(PRINTF_PATH)/$(H_PATH)
	
clean : 
	@rm -rf build
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(PRINTF_PATH) clean

fclean : clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(PRINTF_PATH) fclean

re : fclean all


