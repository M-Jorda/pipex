# *********************************** NAME *********************************** #

NAME	= pipex

# ****************************** SHELL COMMAND ******************************* #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f
PRINT		= echo
WAIT1		= sleep 1
WAIT0.3		= sleep 0.3
ERASE		= printf "\033[2K\r"

# ********************************** FILES *********************************** #

SRCS		= mandatory/pipex.c mandatory/utils.c mandatory/error.c			\
			mandatory/parse.c

BNS_SRC		= bonus/main_bonus.c bonus/pipex_bonus.c bonus/parse_bonus.c	\
			bonus/error_bonus.c

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

$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIB_DIR) -lft
	@$(PRINT) -n "$(Y)Creating executable $@ from objects ";$(WAIT0.3)
# @$(PRINT) -n ".";$(WAIT0.3)
# @$(PRINT) -n ".";$(WAIT0.3)
# @$(PRINT) -n ".";$(WAIT1);$(ERASE)
	@$(PRINT) "$(G)Executable $@ successfully created$(O)"
	@$(PRINT) "*****************************************"
	@$(PRINT) "*$(Y)   ______ _____ ______ _______ _    _  $(O)*"
	@$(PRINT) "*$(Y)  (_____ \_____)_____ \_______) \  / / $(O)*"
	@$(PRINT) "*$(Y)   _____) ) _   _____) )____   \ \/ /  $(O)*"
	@$(PRINT) "*$(Y)  |  ____/ | | |  ____/  ___)   )  (   $(O)*"
	@$(PRINT) "*$(Y)  | |     _| |_| |    | |_____ / /\ \  $(O)*"
	@$(PRINT) "*$(Y)  |_|    (_____)_|    |_______)_/  \_\ $(O)*"
	@$(PRINT) "*$(V) Made by : jjorda                      $(O)*"
	@$(PRINT) "*$(V) Started : 06/11/2024                  $(O)*"
	@$(PRINT) "*$(V) Finished : 30/11/2024                 $(O)*"
	@$(PRINT) "*****************************************"

$(OBJS_DIR):
			@mkdir -p $(OBJS_DIR)/mandatory

$(OBJS_DIR)/%.o:	%.c | $(OBJS_DIR)
				@$(CC) $(CFLAGS) -c $< -o $@

# ********************************** BONUS *********************************** #

bonus: $(LIB) $(NAME)_bns

$(NAME)_bns: $(BNS_OBJS)
	@$(CC) $(CFLAGS) -o $@ $(BNS_OBJS) -L$(LIB_DIR) -lft
	@$(PRINT) -n "$(Y)Creating executable $(NAME)_$@  from objects ";$(WAIT0.3)
# @$(PRINT) -n ".";$(WAIT0.3)
# @$(PRINT) -n ".";$(WAIT0.3)
# @$(PRINT) -n ".";$(WAIT1);$(ERASE)
	@$(PRINT) "$(G)Executable $(NAME)_$@ successfully created$(O)"
	@$(PRINT) "*****************************************"
	@$(PRINT) "*$(Y)   ______ _____ ______ _______ _    _  $(O)*"
	@$(PRINT) "*$(Y)  (_____ \_____)_____ \_______) \  / / $(O)*"
	@$(PRINT) "*$(Y)   _____) ) _   _____) )____   \ \/ /  $(O)*"
	@$(PRINT) "*$(Y)  |  ____/ | | |  ____/  ___)   )  (   $(O)*"
	@$(PRINT) "*$(Y)  | |     _| |_| |    | |_____ / /\ \  $(O)*"
	@$(PRINT) "*$(Y)  |_|    (_____)_|    |_______)_/  \_\ $(O)*"
	@$(PRINT) "*$(V) Made by : jjorda         $(P)+-+-+-+-+-+$   $(O)*"
	@$(PRINT) "*$(V) Started : 06/11/2024     $(P)|B|O|N|U|S|$   $(O)*"
	@$(PRINT) "*$(V) Finished : 30/11/2024    $(P)+-+-+-+-+-+$   $(O)*"
	@$(PRINT) "*****************************************"

$(BNS_OBJ_DIR):
			@mkdir -p $(BNS_OBJ_DIR)/bonus

$(BNS_OBJ_DIR)/%.o:	%.c | $(BNS_OBJ_DIR)
				@$(CC) $(CFLAGS) -c $< -o $@

# ********************************** DEBUG *********************************** #

debug: 	$(LIB) $(OBJS)
	@$(CC) -g -o $(NAME) $(SRCS) libft/libft.a 
	@$(PRINT) "*********************************************************"
	@$(PRINT) "*$(Y)                                                       $(O)*"
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

clean:	$(APP)
		@make clean -s -C $(LIB_DIR)
		@$(RM)r $(OBJS_DIR) $(BNS_OBJ_DIR)

# ********************************** FCLEAN ********************************** #

fclean:	clean 
		@make fclean -s -C $(LIB_DIR)
		@$(RM) $(NAME) $(NAME)_bns

# ************************************ RE ************************************ #

re:			fclean all

rebonus:	fclean bonus

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


info:
	@$(PRINT) "|---------------------------------------|"
	@$(PRINT) "|$(R)make, make all, make pipex:            $(O)|"
	@$(PRINT) "|$(B)Make the program pipex with libft      $(O)|"
	@$(PRINT) "|---------------------------------------|"
	@$(PRINT) "|$(R)make bonus:                            $(O)|"
	@$(PRINT) "|$(B)Make the program pipex_bns with libft  $(O)|"
	@$(PRINT) "|---------------------------------------|"
	@$(PRINT) "|$(R)make a.out                             $(O)|"
	@$(PRINT) "|$(B)Remove all the executable "a.out"        $(O)|"
	@$(PRINT) "|---------------------------------------|"
	@$(PRINT) "|$(R)make clean                             $(O)|"
	@$(PRINT) "|$(B)Remove all objects files and folders   $(O)|"
	@$(PRINT) "|---------------------------------------|"
	@$(PRINT) "|$(R)make fclean                            $(O)|"
	@$(PRINT) "|$(B)do clean and remove the executables    $(O)|"
	@$(PRINT) "|---------------------------------------|"
	@$(PRINT) "|$(R)make re                                $(O)|"
	@$(PRINT) "|$(B)do fclean and all                      $(O)|"
	@$(PRINT) "|---------------------------------------|"
	@$(PRINT) "|$(R)make rebonus                           $(O)|"
	@$(PRINT) "|$(B)do fclean and bonus                    $(O)|"
	@$(PRINT) "|---------------------------------------|"
	@$(PRINT) "|$(R)make party                             $(O)|"
	@$(PRINT) "|$(B)do a party :)                          $(O)|"
	@$(PRINT) "|---------------------------------------|"

# ********************************** PHONY *********************************** #

.PHONY:	all bonus debug a.out clean fclean re rebonus party info

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