#include <iostream>

int ChCount(const char* const _string, char Ch)
{
    int ChCount = 0;
    int Count = 0;
    
    while (_string[ChCount] != '\0')
    {
        if (_string[ChCount] == Ch) {
            ++Count;
        }
        ++ChCount;
    }
    return Count;
}

void TrimDelete(char* _string)
{
    char Ch = ' ';
    int ChCount = 0;

    while (_string[ChCount] != '\0')
    {
        if (_string[ChCount] == Ch)
        {
            int i = ChCount;
            while (_string[i] != '\0')
            {
                _string[i] = _string[i + 1];
                ++i;
            }
        }

        else
        {
            ++ChCount;
        }
    }
}


int DigitsCount(int _Number) 
{
    int count = 0;

    while (_Number != '\0')
    {
        int digit = _Number % 10; 
        if (digit >= 0 && digit <= 9) { 
            ++count; 
        }
        _Number /= 10;
    }
    return count;
}

void StrCopy(const char* const _Left, char* _Right) 
{
    int i = 0;
    while (_Left[i] != '\0') {
        _Right[i] = _Left[i];
        ++i;
    }
    _Right[i] = '\0';
}

void NumberToString(int _Number, char* _Right)
{
    return;
}


int main()
{
    {
        int Result = ChCount("ab aaa ccc ddd eee", 'a');
        std::cout << Result << std::endl;
    }

    {
        char Arr[256] = "aa  b  c dd ee";
        TrimDelete(Arr);
        std::cout << Arr << std::endl;
    }

    {
        int Result = DigitsCount(100);
        std::cout << Result << std::endl;
    }

    {
        char ArrCopyText[256] = {};
        StrCopy("aaaa bbb ccc", ArrCopyText);
        std::cout << ArrCopyText << std::endl;
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