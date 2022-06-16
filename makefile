

TIME=$$(date +'%Y-%m-%d %H:%M:%S')

SRCS = ft_atoi.c functions.c ft_strcat.c get_next_line.c list_func.c read_dict.c main.c

FLAGS = -Wall -Wextra -Werror -fsanitize=address -fmax-errors=1 -g3
TESTER = 
TEST_PATH = 

run:
	gcc $(FLAGS) $(SRCS)
	@./a.out 12345

test: $(TESTER)
	cd $(TESTER) && make && make fclean

$(TESTER):
	git clone $(TEST_PATH)

clean:
	rm -rf ./a.out
fclean: clean
	rm -rf $(TESTER)
push: fclean
	git add .
	git commit -m "$(TIME)"
	git push