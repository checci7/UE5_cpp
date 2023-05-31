#include <iostream>
#include <vector>

// stl은 템플릿만 사용했다면 다 stl
// 자료구조템플릿 != stl 
// stl중 자료구조 stl이라고 합니다.
// C++을 만든

// stl에 포함된 자료구조형 템플릿 클래스들을 배우는 겁니다.

// std 자료구조가 할수 있다면
// 나도 똑같은 짓을 하고 똑같은 결과를 내는 클래스를 만들어 보는게.

// 숙제0 => HVector의 leck을 없애와라
//         대입연산자를 사용하면 터지는걸 정상으로 돌려놔라.
//         이미 보여준 코드 이미 array에서 해결은 한거에요.

// 숙제1 => 템플릿으로 바꾸세요.

template<typename DataType>

class HVector
{
public:
    HVector()
    {
        sizeValue = 0;
        capacityValue = 0;
        ArrPtr = nullptr;
    }

    DataType& operator[](size_t _Index)
    {
        return ArrPtr[_Index];
    }

    size_t size() const
    {
        return sizeValue;
    }

    size_t capacity() const
    {
        return capacityValue;
    }

    void push_back(const DataType& _Data)
    {
        if (sizeValue + 1 > capacityValue)
        {
            reserve(static_cast<size_t>((capacityValue * 1.5) + 1));
        }

        ArrPtr[sizeValue] = _Data;
        sizeValue += 1;
    }

    void reserve(size_t _capacity)
    {
        DataType* PrevPtr = ArrPtr;
        ArrPtr = new DataType[_capacity];

        if (nullptr != PrevPtr)
        {
            for (size_t i = 0; i < sizeValue; i++)
            {
                ArrPtr[i] = PrevPtr[i];
            }

            delete[] PrevPtr;
        }

        capacityValue = _capacity;
    }

    HVector& operator=(const HVector& other)
    {
        if (this != &other)
        {
            delete[] ArrPtr;
            sizeValue = other.sizeValue;
            capacityValue = other.capacityValue;
            ArrPtr = new DataType[capacityValue];

            for (size_t i = 0; i < sizeValue; i++)
            {
                ArrPtr[i] = other.ArrPtr[i];
            }
        }

        return *this;
    }

    ~HVector()
    {
        delete[] ArrPtr;
    }

private:
    size_t sizeValue;
    size_t capacityValue;
    DataType* ArrPtr;
};

int main()
{
    {
        HVector<int> Arr;
        for (size_t i = 0; i < 10; i++)
        {
            Arr.push_back(i);
        }

        for (size_t i = 0; i < Arr.size(); i++)
        {
            std::cout << Arr[i] << std::endl;
        }

        HVector<int> Arr0;
        Arr0 = Arr;

        for (size_t i = 0; i < Arr0.size(); i++)
        {
            std::cout << Arr0[i] << std::endl;
        }
    }
    return 0;
}
