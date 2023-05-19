#include <iostream>

int ChCount(const char* const _string, char Ch)     // Ch와 같은 문자가 몇개들어있는지 세어서 리턴해주는 함수
{
    int ChCount = 0;
    while (_string[ChCount])
    {
        char Ch = _string[ChCount];

        ++ChCount;
    }

    int Count = 0;

    // for문을 돌리는건 당연한거야.

    return 0;
}

void TrimDelete(char* _string) //문자열의 공백을 삭제해주는 함수
{
    char Ch = 'a';
    ' ';

    //while ()
    //{
    if (Ch == ' ')
    {
        int a = 0;
    }
    //}
    return;
}


int DigitsCount(int _Number) // 문자열에 숫자가 몇 개 인지 세어주는 함수
{
    return 0;
}

void StrCopy(const char* const _Left, char* _Right) //ArrCopyText에 const char* const _Left("aaaa bbb ccc")를 복사해서 넣어주는 함수 
{
    return;
}

void NumberToString(int _Number, char* _Right) //숫자를 문자열("1")로 바꿔주는 함수
{
    return;
}


int main()
{
    // 4가 리턴되어야 합니다.
    // 문자열의 마지막에 들어가는 0은 글자로 치지 않습니다.
    {
        int Result = ChCount("ab aaa ccc ddd eee", 'w');
    }

    {
        char Arr[256] = "aa  b  c dd ee";

        TrimDelete(Arr);

        int a = 0;
    }

    {
        // 3이 리턴되게
        int Result = DigitsCount(100);

        int a = 0;
    }

    {
        char ArrCopyText[256] = {};

        StrCopy("aaaa bbb ccc", ArrCopyText);

        int a = 0;
    }

    {
        char Result[256] = {};

        // Result = "312312";

        NumberToString(312312, Result);

        char Ch = '0';

        int Value = 7;

        char ChConvert = Value + 48;

        int a = 0;
    }
}