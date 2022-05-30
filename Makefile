NAME=containers.a

FLAGS := -Wall -Werror -Wextra -std=c++98

CC := c++

SRC = vector/vector.cpp 

ODIR := .obj

OBJ := $(addprefix $(ODIR)/, $(SRC:.cpp=.o))

all: creat_dir $(OBJ)

$(ODIR)/%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

creat_dir:
	mkdir -p $(ODIR)/vector

fclean:
	rm -rf .obj
