# *********************************** NAME *********************************** #

NAME	= libft.a

# ****************************** SHELL COMMAND ******************************* #

RM			= rm
FINDBYNAME	= find -name
PRINT		= echo
WAIT1		= sleep 1
WAIT0.3		= sleep 0.3
ERASE		= printf "\033[2K\r"

# *********************************** REPO *********************************** #

OBJSDIR	= obj

# ********************************** FILES *********************************** #

SRCS	= $(SRC_CON) $(SRC_MEM) $(SRC_PRT) $(SRC_SCH) $(SRC_MAN) $(SRC_SEA) \
		$(SRC_LST) $(SRC_PF) $(SRC_PER) $(SRC_GNL)

SRC_CON	= convertion/ft_atoi.c convertion/ft_itoa.c convertion/ft_tolower.c \
		convertion/ft_toupper.c

SRC_MEM	= memory/ft_calloc.c memory/ft_mallocfailed.c						\
		memory/ft_split.c memory/ft_strdup.c memory/ft_strjoin.c			\
		memory/ft_strmapi.c memory/ft_strtrim.c memory/ft_substr.c			\
		memory/ft_leak.c memory/ft_split_arg.c

SRC_PRT	= print/ft_putchar_fd.c print/ft_putendl_fd.c print/ft_putnbr_fd.c	\
		print/ft_putstr_fd.c

SRC_SCH	= search/ft_isalnum.c search/ft_isalpha.c							\
		search/ft_isascii.c search/ft_isdigit.c search/ft_isprint.c			\
		search/ft_count_word.c search/ft_isesc.c search/ft_find_quotes.c

SRC_MAN	= manipulation/ft_bzero.c manipulation/ft_memcpy.c					\
		manipulation/ft_memmove.c manipulation/ft_memset.c					\
		manipulation/ft_striteri.c manipulation/ft_strlcat.c				\
		manipulation/ft_strlcpy.c manipulation/ft_strcat.c					\
		manipulation/ft_strcpy.c manipulation/ft_strncpy.c					\
		manipulation/ft_strcpy_esc.c

SRC_SEA	= str_search/ft_memchr.c str_search/ft_strcmp.c						\
		str_search/ft_memcmp.c str_search/ft_strchr.c						\
		str_search/ft_strlen.c str_search/ft_strncmp.c						\
		str_search/ft_strnstr.c str_search/ft_strrchr.c						\
		search/ft_isspace.c str_search/ft_strlen_esc.c

SRC_LST	= list/ft_lstnew.c list/ft_lstadd_back.c list/ft_lstclear.c			\
		list/ft_lstadd_front.c list/ft_lstdelone.c list/ft_lstsize.c		\
		list/ft_lstiter.c list/ft_lstlast.c list/ft_lstmap.c				\
		list/ft_lstfree.c list/ft_lstnew_mall.c list/ft_lst_freemall.c		\
		list/ft_lstn_2.c list/ft_lstn_3.c list/ft_nextlst.c

SRC_PF	= print/ft_printf/ft_printf.c print/ft_printf/ft_printf_utils.c

SRC_PER	= print/ft_printerr/ft_printerr.c print/ft_printerr/ft_printerr_utils.c

SRC_GNL	= file/gnl/get_next_line.c file/gnl/get_next_line_utils.c			\
		file/gnl/get_next_line_fd.c file/gnl/get_next_line_utils_fd.c

# ********************************* OBJECTS ********************************** #

OBJS	= $(patsubst %.c, $(OBJSDIR)/%.o, $(SRCS))

APP		= a.out

# ************************************ ALL *********************************** #

all:	$(NAME)

$(NAME):	$(OBJS)
			@ar rcs $@ $(OBJS)
			@$(PRINT) -n "$(Y)Creating library static $@ from objects ";$(WAIT0.3)
# @$(PRINT) -n ".";$(WAIT0.3)
# @$(PRINT) -n ".";$(WAIT0.3)
# @$(PRINT) -n ".";$(WAIT1);$(ERASE)
			@$(PRINT) "$(G)Library $@ successfully created$(O)"
			@$(PRINT) "*****************************************"
			@$(PRINT) "*$(Y)   _     __________  _______ _______   $(O)*"
			@$(PRINT) "*$(Y)  (_)   (_____)__  \(_______)_______)  $(O)*"
			@$(PRINT) "*$(Y)   _       _ ____)  )_____      _      $(O)*"
			@$(PRINT) "*$(Y)  | |     | |  __  (|  ___)    | |     $(O)*"
			@$(PRINT) "*$(Y)  | |_____| |_|__)  ) |        | |     $(O)*"
			@$(PRINT) "*$(Y)  |_______)___)____/|_|        |_|     $(O)*"
			@$(PRINT) "*$(V)  Made by : jjorda                     $(O)*"
			@$(PRINT) "*$(V)  Finished : 27/09/2024                $(O)*"
			@$(PRINT) "*$(V)  all a.out clean bonus fclean re      $(O)*"
			@$(PRINT) "*****************************************"

$(OBJSDIR)/%.o: %.c
				@mkdir -p $(dir $@)
				@cc -Wall -Wextra -Werror -c $< -o $@

# ********************************** A.OUT *********************************** #

$(APP):
		@$(PRINT) -n "$(R)Cleaning "a.out" files ";$(WAIT0.3)
# @$(PRINT) -n ".";$(WAIT0.3)
# @$(PRINT) -n ".";$(WAIT0.3)
# @$(PRINT) -n ".";$(WAIT1);$(ERASE)
		@$(FINDBYNAME) $(APP) -delete
		@$(PRINT) "$(G)'$(APP)' files removed"

# ********************************** CLEAN *********************************** #

clean:
		@$(PRINT) -n "$(R)Cleaning objects files ";$(WAIT0.3)
# @$(PRINT) -n ".";$(WAIT0.3)
# @$(PRINT) -n ".";$(WAIT0.3)
# @$(PRINT) -n ".";$(WAIT1);$(ERASE)
		@$(RM) -rf $(OBJSDIR)
		@$(FINDBYNAME) '*.o' -delete
		@$(PRINT) "$(G)object files removed"

# ********************************** FCLEAN ********************************** #

fclean:	clean 
		@$(PRINT) -n "$(R)Cleaning library ";$(WAIT0.3)
# @$(PRINT) -n ".";$(WAIT0.3)
# @$(PRINT) -n ".";$(WAIT0.3)
# @$(PRINT) -n ".";$(WAIT1);$(ERASE)
		@$(RM) -f $(NAME)
		@$(PRINT) "$(G)Library removed"

# ************************************ RE ************************************ #

re:	fclean all

# ********************************** PHONY *********************************** #

.PHONY:	all a.out clean bonus fclean re

# *********************************** COLOR ********************************** #

# BLACK
O	= \033[0m

#RED
R	= \033[0;31m
#GREEN
G	= \033[0;32m
#YELLOW
Y	= \033[0;33m
#VIOLET
V	= \033[0;34m
