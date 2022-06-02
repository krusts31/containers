#ifndef UNIT_TEST
# define UNIT_TEST
# include <criterion/criterion.h>

#endif
void	tester(double x, double y, double expected);
double ft_pow(double x, double y)
{
	return (x * y);
}
Test(Example_Tests, should_pass_all_tests_provided)
{
	tester(1.0, 1.0, 1.0);
}

void	tester(double x, double y, double expected)
{
	double submitted;
	submitted = ft_pow(x, y);
	cr_assert(ft_pow(x, y) == expected,
		"Submitted:\t%f for %f to the power of %f\nExpected:\t%f\n",
		submitted, x, y, expected
		);
}
