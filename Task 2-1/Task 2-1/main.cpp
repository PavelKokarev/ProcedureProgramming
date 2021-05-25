#define _USE_MATH_DEFINES // for C++

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/**
 * \brief Расчет увеличения в N раз.
 * \param а переменная А.
 * \param n переменная N.
 * \return Параметр А, увеличенный в N раз.
 */
double GetAforN(double a, double n);

/**
 * \brief Расчет увеличения в 2N раз.
 * \param а переменная А.
 * \param n переменная N.
 * \return Параметр А, увеличенный в 2N раз.
 */
double GetAfor2N(double a, double n);

/**
 * \brief Расчет увеличения в 3N раз.
 * \param а переменная А.
 * \param n переменная N.
 * \return Параметр А, увеличенный в 3N раз.
 */
double GetAfor3N(double a, double n);

/**
 * \brief Пользовательский выбор увеличения А в N раз (0),
 * 2N раз (1) и 3N раз (2).
 */
enum class ActionChoice { N, doubleN, tripleN };

/**
 * \brief Точка входа в программу.
 * \return Код ошибки (0 - успех).
 */
int main()
{
    cout << "Input A = ";
    double a;
    cin >> a;

    cout << "Input N = ";
    double n;
    cin >> n;

    cout << "Input what do you want: increase А for N times (0), for 2N times (1), for 3N times (2) " << "\n";
    int input;
    cin >> input;

    const auto choice = static_cast<ActionChoice>(input);

    switch (choice)
    {
    case ActionChoice::N:
    {
        const auto N = GetAforN(a, n);
        cout << "A, increase for N times = " << N;
        break;
    }
    case ActionChoice::doubleN:
    {
        const auto doubleN = GetAfor2N(a, n);
        cout << "A, increase for 2N times = " << doubleN;
        break;
    }
    case ActionChoice::tripleN:
    {
        const auto tripleN = GetAfor3N(a, n);
        cout << "A, increase for 3N times = " << tripleN;
        break;
    }
    }
    cout << endl;
    return 0;
}

double GetAforN(double a, double n)
{
    return a * n;
}

double GetAfor2N(double a, double n)
{
    return a * 2 * n;
}

double GetAfor3N(double a, double n)
{
    return a * 3 * n;
}