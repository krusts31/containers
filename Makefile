
FLAGS:=-Wall -Werror -Wextra -std=c++98 -pedantic

CC:= c++

SRC:=vector/vector.cpp \
	  main.cpp

HEADER:=-I vector/includes

ODIR:=.obj

OBJ:=$(addprefix $(ODIR)/, $(SRC:.cpp=.o))

all: creat_dir $(OBJ)
	$(CC) $(FLAGS) $(HEADER) $(OBJ) -o containers

$(ODIR)/%.o: %.cpp
	$(CC) $(FLAGS) $(HEADER) -c $< -o $@

creat_dir:
	mkdir -p $(ODIR)/vector

fclean:
	rm -rf containers
	rm -rf .obj

re: fclean all

test:
	make -C mini_test
	mini_test/a.out
	rm mini_test/a.out

leaks:
	make -C mini_test leaks
	mini_test/a.out
	rm mini_test/a.out

dtest:
	make -C mini_test dtest
	mini_test/a.out
	rm mini_test/a.out
	rm -rf vector/a.out.dSYM
lldbtest:
	make -C mini_test dtest
	lldb mini_test/a.out
