# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: alkrusts <alkrusts@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2022/06/03 13:15:01 by alkrusts      #+#    #+#                  #
#    Updated: 2022/06/03 15:34:24 by alkrusts      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

all:
	c++ mini_tests/main.cpp -Wall -Werror -Wextra -pedantic -std=c++98 -I includes -I mini_tests
debug:
	c++ mini_tests/main.cpp -g -fsanitize=address -Wall -Werror -Wextra -pedantic -std=c++98 -I includes -I mini_tests
clean:
	rm a.out
