#include <iostream>
#include <chrono>
#include <unistd.h>
 
int main()
{
    using namespace std::chrono;
 
    uint64_t ms = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    std::cout << ms << " milliseconds since the Epoch\n";
 
    uint64_t Ms = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    std::cout << Ms << " milliseconds since the Epoch\n";
 
    return 0;
}
