# *********************************** NAME *********************************** #

NAME	= pipex

# ****************************** SHELL COMMAND ******************************* #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
PRINT		= echo
WAIT1		= sleep 1
WAIT0.3		= sleep 0.3
ERASE		= printf "\033[2K\r"

# ********************************** FILES *********************************** #

SRCS		= mandatory/main.c mandatory/pipex.c mandatory/utils.c			\
			mandatory/error.c mandatory/parse.c

BNS_SRC		= bonus/pipex_bonus.c

LIB			= libft.a
LIB_DIR		= ./libft

APP			= a.out

# ********************************* OBJECTS ********************************** #

OBJS_DIR	= obj
OBJS		= $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))

BNS_OBJ_DIR	= bonus_obj
BNS_OBJS	= $(patsubst %.c, $(BNS_OBJ_DIR)/%.o, $(BNS_SRC))

# ************************************ ALL *********************************** #

all:	$(LIB) $(NAME)

$(LIB):		
		@make -s -C $(LIB_DIR);

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIB_DIR) -lft
	@$(PRINT) -n "$(Y)Creating executable $@ from objects ";$(WAIT0.3)
	@$(PRINT) -n ".";$(WAIT0.3)
	@$(PRINT) -n ".";$(WAIT0.3)
	@$(PRINT) -n ".";$(WAIT1);$(ERASE)
	@$(PRINT) "$(G)Executable $@ successfully created$(O)"
	@$(PRINT) "*********************************************************"
	@$(PRINT) "*$(Y)    ___   _   ___   ____            __      __         $(O)*"
	@$(PRINT) "*$(Y)   |   \ (_) |   \ |  __|/\  /\    /  |    /  \        $(O)*"
	@$(PRINT) "*$(Y)   | |> ) _  | |> )| |_  \ \/ /   /_| |   | /\ |       $(O)*"
	@$(PRINT) "*$(Y)   |  _/ | | |  _/ |  _|  |  |      | |   |(  )|       $(O)*"
	@$(PRINT) "*$(Y)   | |   | | | |   | |__ / /\ \     | | _ | \/ |       $(O)*"
	@$(PRINT) "*$(Y)   |_|   |_| |_|   |____|\/  \/     |_|(_) \__/        $(O)*"
	@$(PRINT) "*		                                        $(O)*"
	@$(PRINT) "*$(V)     Made by : jjorda                                  $(O)*"
	@$(PRINT) "*$(V)     Started : 06/11/2024                              $(O)*"
	@$(PRINT) "*$(V)                                                       $(O)*"
	@$(PRINT) "*********************************************************"

$(OBJS_DIR):
			@mkdir -p $(OBJS_DIR)/mandatory

$(OBJS_DIR)/%.o:	%.c | $(OBJS_DIR)
				@$(CC) $(CFLAGS) -c $< -o $@

# ********************************** BONUS *********************************** #

bonus: $(LIB) $(BNS_OBJ_DIR)
	@$(PRINT) -n "$(Y)Creating executable $(NAME)_$@  from objects ";$(WAIT0.3)
	@$(PRINT) -n ".";$(WAIT0.3)
	@$(PRINT) -n ".";$(WAIT0.3)
	@$(PRINT) -n ".";$(WAIT1);$(ERASE)
	@$(PRINT) "$(G)Executable $(NAME)_$@ successfully created$(O)"
	@$(PRINT) "*********************************************************"
	@$(PRINT) "*$(Y)                                                       $(O)*"
	@$(PRINT) "*$(Y)  ░       ░░░░      ░░░   ░░░  ░░  ░░░░  ░░░      ░░   $(O)*"
	@$(PRINT) "*$(Y)  ▒  ▒▒▒▒  ▒▒  ▒▒▒▒  ▒▒    ▒▒  ▒▒  ▒▒▒▒  ▒▒  ▒▒▒▒▒▒▒   $(O)*"
	@$(PRINT) "*$(Y)  ▓       ▓▓▓  ▓▓▓▓  ▓▓  ▓  ▓  ▓▓  ▓▓▓▓  ▓▓▓      ▓▓   $(O)*"
	@$(PRINT) "*$(Y)  █  ████  ██  ████  ██  ██    ██  ████  ████████  █   $(O)*"
	@$(PRINT) "*$(Y)  █       ████      ███  ███   ███      ████      ██   $(O)*"
	@$(PRINT) "*		                                        $(O)*"
	@$(PRINT) "*$(V)     Made by : jjorda                                  $(O)*"
	@$(PRINT) "*$(V)     Started : 06/11/2024                              $(O)*"
	@$(PRINT) "*$(V)                                                       $(O)*"
	@$(PRINT) "*********************************************************"


$(BNS_OBJ_DIR):
			@mkdir -p $(BNS_OBJ_DIR)/bonus

$(BNS_OBJ_DIR)/%.o:	%.c | $(BNS_OBJ_DIR)
				@$(CC) $(CFLAGS) -c $< -o $@

# ********************************** DEBUG *********************************** #

debug: $(LIB) $(OBJS)
	@$(CC) -g -o $(NAME) $(SRCS) libft/libft.a 
	@$(PRINT) "*********************************************************"
	@$(PRINT) "*$(Y)                                                       $(O)*"
	@$(PRINT) "*$(Y)     ██████  ███████ ██████  ██    ██  ██████          $(O)*"
	@$(PRINT) "*$(Y)     ██   ██ ██      ██   ██ ██    ██ ██               $(O)*"
	@$(PRINT) "*$(Y)     ██   ██ █████   ██████  ██    ██ ██   ███         $(O)*"
	@$(PRINT) "*$(Y)     ██   ██ ██      ██   ██ ██    ██ ██    ██         $(O)*"
	@$(PRINT) "*$(Y)     ██████  ███████ ██████   ██████   ██████          $(O)*"
	@$(PRINT) "*                                                       $(O)*"
	@$(PRINT) "*$(V)     Made by : jjorda                                  $(O)*"
	@$(PRINT) "*$(V)     Started : 06/11/2024                              $(O)*"
	@$(PRINT) "*$(V)                                                       $(O)*"
	@$(PRINT) "*********************************************************"

# ********************************** A.OUT *********************************** #

$(APP):	
	@find -name $(APP) -delete
	@make $(APP) -s -C $(LIB_DIR)


# ********************************** CLEAN *********************************** #

clean:	
	@make clean -s -C $(LIB_DIR)
	@$(RM)r $(OBJS_DIR)

# ********************************** FCLEAN ********************************** #

fclean:	clean 
	@make fclean -s -C $(LIB_DIR)
	@$(RM) $(NAME)

# ************************************ RE ************************************ #

re:	fclean all

party:
	@printf "\033c"
	@echo "\n\$(P)♪┏(・o･)┛♪"
	@sleep 1
	@printf "\033c"
	@echo "$(Y)♪┗(・o･)┓♪"
	@sleep 1
	@printf "\033c"
	@echo "\n$(B)♪┏(・o･)┛♪"
	@sleep 1
	@printf "\033c"
	@echo "$(V)♪┗(・o･)┓♪\n"

# ********************************** PHONY *********************************** #

.PHONY:	all bonus debug a.out clean fclean re party

# *********************************** COLOR ********************************** #

# BLACK
O	= \033[0m

#RED
R	= \033[31m
#GREEN
G	= \033[32m
#YELLOW
Y	= \033[33m
#VIOLET
V	= \033[34m
#PINK
P	= \033[35m
#BLUE
B	= \033[36m