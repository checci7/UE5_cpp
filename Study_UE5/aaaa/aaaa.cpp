#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <Windows.h>

int main()
{
    LARGE_INTEGER start;
    QueryPerformanceCounter(&start);
    srand(static_cast<unsigned int>(start.QuadPart));

    while (true)
    {
        int randomNumber = rand() % 11;  // 0부터 10까지의 숫자를 생성
        std::cout << randomNumber << std::endl;
        _getch();
    }

    return 0;
}
