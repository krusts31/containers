#include <vector>
#include <iostream>
#include <string>
int main ()
{
  std::vector<int> myvector (10);   // 10 zero-initialized ints

	myvector.at(1)=3;
   	myvector.at(2)=4;

	std::cout << myvector.at(2) - myvector.at(1) << std::endl;
  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector.at(i);
  std::cout << '\n';

  return 0;
}
