# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 10:09:44 by umeneses          #+#    #+#              #
#    Updated: 2024/06/04 16:33:23 by umeneses         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#								COLORS										   #
# **************************************************************************** #

RED				:= \033[0;31m
GREEN			:= \033[0;32m
YELLOW			:= \033[0;33m
BLUE			:= \033[0;34m
PURPLE			:= \033[0;35m
CYAN			:= \033[0;36m
RESET			:= \033[0m

# **************************************************************************** #
#								PATHS										   #
# **************************************************************************** #

TEST_D				= ./test_files/
BUILD_D				= ./test_build/
PUSH_SWAP_D			= ../program_to_test/
LIBFT_D				= $(PUSH_SWAP_D)libs/libft/
HEADERS_ADDED		= $(PUSH_SWAP_D)headers/
HEADERS				= $(TEST_D) $(HEADERS_ADDED)

# **************************************************************************** #
#								FILES										   #
# **************************************************************************** #

PUSH_SWAP			= $(addprefix $(PUSH_SWAP_D), push_swap)
LIBS				= $(LIBFT_D)libft.a $(PUSH_SWAP_D)

NAME				= push_swap.tests

SRC_FILES			= test_main_miunit.c
#SRC_FILES			+= minunit_utils.c

SRC_FILES_ALL		= $(addprefix $(TEST_D), $(SRC_FILES))

OBJ_FILES			= $(addprefix $(BUILD_D), $(SRC_FILES_ALL:%.c=%.o))

# **************************************************************************** #
#								COMMANDS									   #
# **************************************************************************** #

RM					= rm -rf
MKDIR				= mkdir -p
MV_OBJS				= find . -type f \( -name '.o' -o -name '.a'\) -exec mv {} \

# **************************************************************************** #
#								COMPILATION									   #
# **************************************************************************** #

AUTHOR		= umeneses
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3
CPPFLAGS	= $(addprefix -I, $(HEADERS)) -MMD -MP
LDFLAGS		= $(addprefix -L, $(dir $(LIBS)))
LDLIBS		= -lft -ldl
COMP_OBJS	= $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
COMP_EXE	= $(CC) $(LDFLAGS) $(OBJ_FILES) $(LDLIBS) -o $(NAME)

# **************************************************************************** #
#								DEFINES										   #
# **************************************************************************** #

define		arguments
		42 1 1024
endef

define 		bonus
			@printf "$(YELLOW)"
			@echo ">>> Checking BONUS"
			@printf "$(CYAN)"
			@$(MAKE) -C $(PUSH_SWAP_D) bonus --no-print-directory
endef

# **************************************************************************** #
#								TARGETS										   #
# **************************************************************************** #

all: 				$(NAME)

$(BUILD_D)%.o:		%.c
					@$(MKDIR) $(dir $@)
					@$(COMP_OBJS)
					@echo "Compiling: $(notdir $<)"

$(NAME):			fclean push_swap $(OBJ_FILES)
					@$(COMP_EXE)
					@printf "$(PURPLE)"
					@echo ">>> Running PUSH_SWAP with default arguments:"
					@echo "$(call arguments)"
					@printf "$(CYAN)"
					$(PUSH_SWAP_D)./push_swap $(call arguments)
					@printf "$(GREEN)"
					@echo "$(NAME) Ready!"
					@printf "$(RESET)"
					@./$(NAME) 

push_swap:
					@printf "$(YELLOW)"
					@echo ">>> Checking PUSH_SWAP"
					@printf "$(CYAN)"
					@$(MAKE) -C $(PUSH_SWAP_D) --no-print-directory

bonus:
					$(call bonus)

clean:
					@printf "$(RED)"
					@echo ">>> Cleaning objects"
					@printf "$(PURPLE)"
					$(RM) $(OBJ_FILES)
					$(RM) $(BUILD_D)
					$(MAKE) -C $(PUSH_SWAP_D) fclean
					@printf "$(RESET)"

fclean:				clean
					@printf "$(RED)"
					@echo ">>> Cleaning executables"
					@printf "$(PURPLE)"
					$(RM) $(NAME)
					$(RM) $(NAME_BONUS)
					@printf "$(RESET)"

re:					fclean all

.PHONY:				all clean fclean re bonus