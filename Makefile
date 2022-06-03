
FLAGS:=-Wall -Werror -Wextra -std=c++98 -pedantic

CC:= c++

SRC:=vector/vector.cpp \
	  main.cpp

HEADER:=-I vector/includes

ODIR:=.obj

OBJ:=$(addprefix $(ODIR)/, $(SRC:.cpp=.o))

all: creat_dir $(OBJ)
	$(CC) $(FLAGS) $(HEADER) $(OBJ) -o test

$(ODIR)/%.o: %.cpp
	$(CC) $(FLAGS) $(HEADER) -c $< -o $@

creat_dir:
	mkdir -p $(ODIR)/vector

fclean:
	rm -rf .obj

re: fclean all

test:
	make -C vector
	vector/a.out
	rm vector/a.out

dtest:
	make debug -C vector
	vector/a.out
	rm vector/a.out
