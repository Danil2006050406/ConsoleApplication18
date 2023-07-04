// ConsoleApplication18.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class CheckersPiece {
public:
    virtual bool isValidMove(int fromRow, int fromCol, int toRow, int toCol) const = 0;
};


class NormalPiece : public CheckersPiece {
public:
    bool isValidMove(int fromRow, int fromCol, int toRow, int toCol) const override {
        
        int rowDiff = toRow - fromRow;
        int colDiff = toCol - fromCol;
        return (rowDiff == 1 && (colDiff == 1 || colDiff == -1));
    }
};


class KingPiece : public CheckersPiece {
public:
    bool isValidMove(int fromRow, int fromCol, int toRow, int toCol) const override {
        
        int rowDiff = toRow - fromRow;
        int colDiff = toCol - fromCol;
        return (abs(rowDiff) == abs(colDiff));
    }
};

int main() {
    CheckersPiece* normalPiece = new NormalPiece();
    CheckersPiece* kingPiece = new KingPiece();

    
    bool isValidMoveNormal = normalPiece->isValidMove(1, 2, 2, 3);
    cout << boolalpha << isValidMoveNormal << endl;  

    
    bool isValidMoveKing = kingPiece->isValidMove(1, 2, 3, 4);
    cout << boolalpha << isValidMoveKing << endl;  
   
    bool isValidMoveNormal2 = normalPiece->isValidMove(1, 2, 3, 3);
    cout << boolalpha << isValidMoveNormal2 << endl;  

    delete normalPiece;
    delete kingPiece;

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
