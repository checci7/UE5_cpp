#include <iostream>

int StringCount(char* _Arr)
{
    int ChCount = 0;

    while (_Arr[ChCount])
    {
        ++ChCount;
    }
    return ChCount;
}

void ChangeCh(char* _Arr, char _PrevCh, char _NextCh)
{
    // 1. 들어온 글자를 전부 '1'로 채워봐라.
    //  1-1. 함수 내부에서 하지 말고
    // for while도 생각하지 말고
    //


    return;
}

int main()
{
    {
        char Arr[100] = "2222";

        int Result = StringCount(Arr);

        std::cout << Result << std::endl;

    }

    {
        char Arr[100] = "aaa bbb ccc";

        Arr[0] = '1';

        // Arr[100] = "1111111111111";

        // 3이 나와야 합니다.
        // "aaa bbb ccc"; => "aaa bbb ddd";
        ChangeCh(Arr, 'c', 'd');
    }
}