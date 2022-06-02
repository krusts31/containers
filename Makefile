NAME=containers.a

FLAGS := -Wall -Werror -Wextra -std=c++98

CC := c++

SRC = vector/vector.cpp \
	  vector/main.cpp

HEADER= -I iterator_traits

ODIR := .obj

OBJ := $(addprefix $(ODIR)/, $(SRC:.cpp=.o))


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
	bash vector/test/test_modules/Member_functions/default_construcot.sh
