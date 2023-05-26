#include <iostream>
#include <conio.h>
#include <Windows.h>


// 1. 파일 정리
// 2. 10개의 장애물 배치 class Wall
//    Player 
//    Wall 
//    같은 클래스를 상속받아서 만들어져야 한다.
// 
// 3. 장애물을 통과 못하게 하기.

// 4. 플레이어가 어떠한 키를 누르면 플레이어 위치에서
//    총알 1발이 발사되게 만드세요.

// 5. 그 총알 1발에 벽이 닿으면 벽이 없어지게 만드세요.

// 숙제 플레이어가 화면 바깥으로 나가지 못하게 해라.

const int XLine = 20;  //최대값
const int YLine = 10;


class int4 // 이녀석은 캡슐화된 클래스라기 보다는 기본자료형
{
public:
    int X = 0;
    int Y = 0;
    int Z = 0;
    int W = 0;

    void operator=(const int4& _Other)
    {
        X = _Other.X;
        Y = _Other.Y;
        Z = _Other.Z;
        W = _Other.W;
    }

    void operator+=(const int4& _Other)
    {
        X += _Other.X;
        Y += _Other.Y;
        Z += _Other.Z;
        W += _Other.W;
    }

    int4 operator+(const int4& _Other) const
    {
        int4 Return;
        Return.X = X + _Other.X;
        Return.Y = Y + _Other.Y;
        Return.Z = Z + _Other.Z;
        Return.W = W + _Other.W;
        return Return;
    }

};
const int4 Left = { -1, 0 };
const int4 Right = { 1, 0 };
const int4 Up = { 0, -1 };
const int4 Down = { 0, 1 };

class ConsoleScreen
{
public:
    void Init(char _BaseCh) //필드생성
    {
        BaseCh = _BaseCh;
        Clear();
    }

    void SetPixel(const int4& _Pos, char _Ch)
    {
        ArrScreen[_Pos.Y][_Pos.X] = _Ch;
    }

    void Clear()
    {
        system("cls"); //화면지우는 함수
        for (size_t y = 0; y < YLine; y++)
        {
            for (size_t x = 0; x < XLine; x++)
            {
                ArrScreen[y][x] = BaseCh;
            }
            ArrScreen[y][XLine] = 0;
        }
    }

    bool IsScreenOut(const int4& _Pos) const
    {
        if (0 > _Pos.X)
        {
            return true;
        }

        if (0 > _Pos.Y)
        {
            return true;
        }

        if (XLine <= _Pos.X)
        {
            return true;
        }

        if (YLine <= _Pos.Y)
        {
            return true;
        }

        return false;
    }

    void Print() const
    {
        for (size_t y = 0; y < YLine; y++)
        {
            printf_s(ArrScreen[y]);
            printf_s("\n");
        }
    }

private:
    char BaseCh = ' ';
    char ArrScreen[YLine][XLine + 1] = {};
};

class Player
{
public:
    int4 GetPos() const
    {
        return Pos;
    }

    void AddPos(const int4& _Pos)
    {
        Pos += _Pos;
    }


    void SetPos(const int4& _Pos)
    {
        Pos = _Pos;
    }

    Player()
        : Pos()
    {
    }
    
    Player(const Player&) = delete;

    void Input(ConsoleScreen* _Sreen)
    {
        char Select = (char)_getch();  //키입력받는함수

        int4 MovePos = { 0, 0 };

        switch (Select)
        {
        case 'a':
            MovePos = Left;
            break;
        case 'd':
            MovePos = Right;
            break;
        case 'w':
            MovePos = Up;
            break;
        case 's':
            MovePos = Down;
        case ' ': //총알발사
            Shot();
            break;
        default:
            break;
        }

        if (false == _Sreen->IsScreenOut(GetPos() + MovePos))
        {
            AddPos(MovePos);
        }

    }
    int4 Pos;
};

void Shot() {

}

int main()
{
    ConsoleScreen Screen;
    Screen.Init('*'); //화면채우기

    Player MainPlayer; 
    MainPlayer.SetPos({ 10, 5 }); //시작위치

    //Wall ArrWall[10];
    while (true)
    {
        Screen.Clear(); //화면지우기
        Screen.SetPixel(MainPlayer.GetPos(), 'a'); //플레이어 a 생성
        Screen.Print(); //화면그리기
        MainPlayer.Input(&Screen);//키입력받는함수

        int Count = 0;
        for (size_t i = 0; i < 5; i++)
        {
            //int4 WallPos = ArrWall[i].GetPos();
            int4 WallPos = { 5 + Count, i };
            Screen.SetPixel(WallPos, '0');
        }
        ++Count;

        if (0 != _kbhit()) //시간흐름
        {
            MainPlayer.Input(&Screen);
        }
        Sleep(200);
    }
}

//헤더랑 클래스 정리
// ::의 의미?
//순환참조? A가B를알고 B가 A를 아는것?
//전역함수의 선언과 구현?
//extern = C스타일의 문법을 분리해주는 것
//클래스?,객채지향? = 모든것을 표현할 수 있다.
//다른사람의코드를 이용.이해해야한다
//
//클래스의 상속문법? 클래스상속 퍼블릭상속? 프로텍트상속? <- 쓸 곳이 있나?