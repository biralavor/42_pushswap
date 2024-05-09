# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 17:59:28 by umeneses          #+#    #+#              #
#    Updated: 2024/05/09 18:46:02 by umeneses         ###   ########.fr        #
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

SRC_D					= ./src/
BONUS_D					= ./bonus/
BUILD_D					= ./build/
LIBS_D					= ./libs/
LIBFT_D					= $(LIBS_D)libft/
HEADERS_ADDED			= $(LIBFT_D)includes/
HEADERS_ADDED			+= $(BONUS_D)headers/
HEADERS					= ./headers/ $(HEADERS_ADDED)

# **************************************************************************** #
#								FILES										   #
# **************************************************************************** #

LIBFT					= $(addprefix $(LIBFT_D), libft.a)
LIBS					= $(LIBFT_D)libft.a

NAME					= push_swap

SRC_FILES				= main.c

SRC_FILES_ALL			= $(addprefix $(SRC_D), $(SRC_FILES))

OBJS_FILES				= $(addprefix $(BUILD_D), $(SRC_FILES_ALL:%.c=%.o))
OBJS_ALL				= $(OBJS_FILES)

# **************************** #
#			BONUS			   #
# **************************** #

NAME_BONUS				= push_swap_bonus

SRC_FILES_BONUS			= main_bonus.c

SRC_BONUS_ALL			= $(addprefix $(SRC_SV_BONUS_D), $(SRC_FILES_BONUS))

OBJS_FILES_BONUS		= $(addprefix $(BUILD_D), $(SRC_BONUS_ALL:%.c=%.o))
OBJS_ALL_BONUS			= $(OBJS_FILES_BONUS)

# **************************************************************************** #
#								COMMANDS									   #
# **************************************************************************** #

RM					= rm -rf
MKDIR				= mkdir -p
MV_OBJS				= find . -type f \( -name '.o' -o -name '.a'\) -exec mv {} \

# **************************************************************************** #
#								DEFINES										   #
# **************************************************************************** #

define	project_title
		@printf "$(CYAN)"
		@echo "                                                                    "
		@echo "#########################    WELCOME TO    #########################"
		@echo "                      ______                                        "
		@echo "____________  ___________  /_     __________      _______ ________  "
		@echo "___  __ \  / / /_  ___/_  __ \    __  ___/_ | /| / /  __  /__  __ \ "
		@echo "__  /_/ / /_/ /_(__  )_  / / /    _(__  )__ |/ |/ // /_/ /__  /_/ / "
		@echo "_  .___/\__,_/ /____/ /_/ /_/     /____/ ____/|__/ \__,_/ _  .___/  "
		@echo "/_/                                                       /_/       "
		@echo "                                                                    "
		@echo "#############                                         ##############"
		@echo "                                                                    "
		@printf "$(RESET)"
endef

define	project_title_bonus
		@printf "$(CYAN)"
		@echo "                                                                    "
		@echo "#########################    WELCOME TO    #########################"
		@echo "                      ______                                        "
		@echo "____________  ___________  /_     __________      _______ ________  "
		@echo "___  __ \  / / /_  ___/_  __ \    __  ___/_ | /| / /  __  /__  __ \ "
		@echo "__  /_/ / /_/ /_(__  )_  / / /    _(__  )__ |/ |/ // /_/ /__  /_/ / "
		@echo "_  .___/\__,_/ /____/ /_/ /_/     /____/ ____/|__/ \__,_/ _  .___/  "
		@echo "/_/                                                       /_/       "
		@echo "                                                                    "
		@echo "#############                  BONUS                  ##############"
		@echo "                                                                    "
		@printf "$(RESET)"
endef

define					instructions
						@echo "TODO: add instructions here"

endef

define					instructions_bonus
						@echo "TODO: add bonus instructions here"
endef

ifdef					WITH_BONUS
	NAME				= $(NAME_BONUS)
	OBJS_FILES			= $(OBJS_FILES_BONUS)
	OBJS_ALL			= $(OBJS_ALL_BONUS)
	project_title		= $(project_title_bonus)
	instructions		= $(instructions_bonus)
endif

define					bonus
						$(MAKE) WITH_BONUS=TRUE --no-print-directory
endef

# **************************************************************************** #
#								COMPILATION									   #
# **************************************************************************** #

AUTHOR			= umeneses
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g3
CPPFLAGS		= $(addprefix -I, $(HEADERS)) -MMD -MP
LDFLAGS			= $(addprefix -L, $(dir $(LIBS)))
LDLIBS			= -lft -ldl
COMP_OBJS		= $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
COMP_EXE		= $(CC) $(LDFLAGS) $(OBJS_FILES) $(LDLIBS) -o $(NAME)

# **************************************************************************** #
#								TARGETS										   #
# **************************************************************************** #

all: 				$(NAME)

$(BUILD_D)%.o:		%.c
					@$(MKDIR) $(dir $@)
					@$(COMP_OBJS)
					@echo "Compiling: $(notdir $<)"

$(NAME):			libft_lib $(OBJS_FILES)
					@$(COMP_EXE)
					@printf "$(GREEN)"
					@echo "$(NAME) Ready!"
					$(call header)
					@printf "$(YELLOW)"
					$(call instructions)
					@printf "$(RESET)"

libft_lib:
					@printf "$(YELLOW)"
					@echo ">>> Checking LIBFT"
					@printf "$(CYAN)"
					@$(MAKE) -C $(LIBFT_D) --no-print-directory
					@printf "$(YELLOW)"
					@echo "Next target >>> $(NAME)..."
					@printf "$(RESET)"

bonus:
					$(call bonus)

clean:
					@printf "$(RED)"
					@echo ">>> Cleaning objects"
					@printf "$(PURPLE)"
					$(RM) $(OBJS_ALL)
					$(RM) $(BUILD_D)
					$(MAKE) -C $(LIBFT_D) fclean
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