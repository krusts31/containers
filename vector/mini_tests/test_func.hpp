#include "vector.hpp"

#include <string>

bool	test_3(void)
{
	ft::vector<int>	ft_int_vec;
	return (true);
}

bool	is_default_construct_vec_int_empty(void)
{
	ft::vector<int>			ft_int_vec;

	if (ft_int_vec.empty())
		return (true);
	else
		return (false);
}

bool	is_default_construct_vec_char_empty(void)
{
	ft::vector<char>			ft_char_vec;

	if (ft_char_vec.empty())
		return (true);
	else
		return (false);
}

bool	is_default_construct_vec_string_empty(void)
{
	ft::vector<std::string>		string_vec;

	/*
	if (string_vec.empty())
		return (true);
	else
	*/
	return (false);
}

bool	is_default_construct_vec_float_empty(void)
{
	ft::vector<float>			ft_float_vec;

	if (ft_float_vec.empty())
		return (true);
	else
		return (false);
}
