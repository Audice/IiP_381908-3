#include "Matrix.h"

int main() {
    double res, tmp;
    int n, d;
    setlocale(LC_ALL, "rus");
    cout << "Мерность вектора: ";
    do {
        cin >> n;
    } while (n < 3); cout << endl;
    Vector v1(n), v2(n), sum(n), resVec(n), cos;
    Vector* arr = new Vector[n];
    Matrix m1(n, n), m2(n, n), m3(n, n), ResM(n, n);
    v1.Random();
    v2.Random();
    arr[1] = v1;
    arr[2] = v2;
    cout << "Генерация случайных векторов" << endl << endl;
    cout << v1 << v2;
    cout << endl << "Расстояние между векторами: " << v1.lenghtbwnvec(v2) << endl << endl;
    cout << "Скалярная сумма: " << v1 + v2 << endl;
    cout << "Скалярная разность: " << v1 - v2 << endl;
    cout << "Скалярная произведение: " << v1 * v2 << endl;
    cout << "Косинус угла между векторами: " << v1.Cos(v2);
    for (int i = 3; i < n; i++) {
        v2.Random();
        arr[i] = v2;
    }
    cout << endl << "Генерация векторов" << endl << endl;;
    for (int i = 1; i < n; i++) {
        cout << arr[i];
    }
    cout << endl << "Векторное произведение: " << v1.vectorProizv(arr);
    for (int i = 0; i < n; i++) {
        v1.Random();
        m1.Set(v1, i);
        v1.Random();
        m2.Set(v1, i);
    }
    cout << endl;
    cout << "Генерация матриц" << endl << endl;
    m1.PrintM();
    cout << endl;
    m2.PrintM();
    cout << endl;
    cout << "Транспонирование 2 матрицы" << endl << endl;
    m3 = m2.T();
    m3.PrintM();
    cout << endl;
    cout << "Сложение матриц" << endl << endl;
    ResM = m1 + m2;
    ResM.PrintM();
    cout << endl;
    cout << "Разность матриц" << endl << endl;
    ResM = m1 - m2;
    ResM.PrintM();
    cout << endl;
    cout << "Произведение матрицы на 10" << endl << endl;
    ResM = ResM * 10;
    ResM.PrintM();
    cout << endl;
    cout << "Умножение матриц" << endl << endl;
    ResM = m1 * m2;
    ResM.PrintM();
    cout << endl;
    cout << "Детерминант матрицы: ";
    d = m2.D();
    cout << d << endl << endl;
    cout << "Обратная 2 матрица" << endl << endl;
    ResM = m2.T();
    ResM = ResM / d;
    ResM.PrintM();
    cout << "Деление матриц" << endl << endl;
    ResM = m1 / m2;
    ResM.PrintM();
    cout << endl;
    cout << "Первая матрица в 2 степени" << endl << endl;
    ResM = m1 ^ 2;
    ResM.PrintM();
    cout << endl;
}
