#include<iostream>
#include"Matrix.h"

int main(int argc, char* argv[])
{
    Matrix matr1(3,3);
    for (int i = 0; i < matr1.getR(); ++i)
    {
        for (int j = 0; j < matr1.getC(); ++j)
        {
            matr1.set(i, j, 3 * i + j);
        }
    }
    Matrix matr2(3,1);
    for (int i = 0; i < matr2.getR(); ++i)
    {
        for (int j = 0; j < matr2.getC(); ++j)
        {
            matr2.set(i, j, 3 * i + j);
        }
    }
    Matrix matr3(3);
    for (int i = 0; i < matr3.getR(); ++i) {
      for (int j = 0; j < matr3.getC(); ++j){
        matr3.set(i, j, 3 * i + j);
      }
    }

    matr1.print(std::cout);
    matr2.print(std::cout);
    matr3.print(std::cout);
    Matrix res = mult(matr1, matr2);
    Matrix res1 = subtr(matr1, matr2);
    Matrix res2 = add(matr1, matr2);
    Matrix res3 = reverse(matr1);
    Matrix res4 = solve(matr1, matr2);
    Matrix res5 = transpose(matr1);
    res.print(std::cout);
    res1.print(std::cout);
    res2.print(std::cout);
    res4.print(std::cout);
    res5.print(std::cout);
    std::cout << matr3.det() << std::endl;
    res3.print(std::cout);
    matr1.transpose();
    matr2.addTo(matr2);
    matr3.multBy(3);
    matr1.print(std::cout);
    matr2.print(std::cout);
    matr3.print(std::cout);
    std::cout << matr1.getC() << "\n" << matr1.getR() << "\n";

    return 0;
}