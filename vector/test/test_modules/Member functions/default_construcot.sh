FLAGS="-Wall -Werror -Wextra -std=c++98 -pedantic"
FT_OUT=ft_out
STD_OUT=std_out

c++ $FLAGS std_default_constructor.cpp -o $STD_OUT -DLEAKS
c++ $FLAGS ft_default_constructor.cpp -I ../../../ -o $FT_OUT -DLEAKS

COMPILE=$?

if [ $COMPILE -eq 1 ]
then
	echo -e "\033[1;31mDEFAULT CONSTRUCTOR FAILED TO COMPILE \033[0m"
	exit 1
else
	echo -e "\033[1;42mDEFAULT CONSTRUCTOR COMPILED\033[0m"
fi

FT_NODES=$(./$FT_OUT | grep -w "nodes malloced" | cut -d ' ' -f 3)
STD_NODES=$(./$STD_OUT | grep -w "nodes malloced" | cut -d ' ' -f 3)

if [ $FT_NODES -ne $STD_NODES ]
then
	echo -e "\033[1;31mNODES ALLOCED FT:$FT_NODES != STL:$STD_NODES\033[0m"
	exit 1
else
	echo -e "\033[1;42mNODES ALLOCED FT:$FT_NODES == STL:$STD_NODES\033[0m"
fi

c++ $FLAGS std_default_constructor.cpp -o $STD_OUT -DTIME
c++ $FLAGS ft_default_constructor.cpp -I ../../../ -o $FT_OUT -DTIME

FT_TIME=$(./$FT_OUT)
STD_TIME=$(./$STD_OUT)
echo $FT_TIME 
echo $STD_TIME
rm $FT_OUT $STD_OUT
