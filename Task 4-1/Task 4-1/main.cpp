#include <iostream>
#include <string>
#include <random>

using namespace std;

/**
 * \brief Заполнение массива случайными числами.
 * \param size размер массива.
 * \param minValue минимальное значение элементов массива.
 * \param maxValue максимальное значение элементов массива.
 * \return заполненный массив.
 */
int* FillRandomArray(size_t size, int minValue, int maxValue);

/**
 * \brief Создание нового массива, путем копирования исходного массива
 * и замены второго элемента на максимальный отрицательный элемент (если такой имеется)
 * \param array исходный массив.
 * \param size размер массива.
 * \return новый измененный массив.
 */
int* MaxMinElementChanged(const int* array, const size_t size);

/**
 * \brief Вывод массива на консоль.
 * \param array массив.
 * \param size размер массива.
 * \param message претворяющая печать надпись.
 */
int ArrayPrint(const int* array, size_t size, const string& message = "");

/**
 * \brief
 */
enum class ArrayInputWay
{
    random,
    keyboard
};

/**
 * \brief Нахождение суммы четных отрицательных значений элементов массива.
 * \param array массив.
 * \param size размер массива.
 * \return сумма четных отрицательных значений элементов массива.
 * Если массива не существует, то сумма = 42.
 */
int SumOddValues(const int* array, size_t size);

/**
 * \brief Метод, возвращающий заполненный пользователем массив.
 * \param size размер массива.
 * \param minValue минимальное значение элементов массива.
 * \param maxValue максимальное значение элементов массива.
 * \param message надпись для пользователя.
 * \return заполненный массив.
 */
int* FillUserArray(size_t size, const string& message = "");

/**
 * \brief Вывод на консоль всех индексов, элементы которых кратны 3 и 6.
 * \param size размер массива.
 * \param number заданный индекс.
 */
int PrintIndexesAboveConst(int* array, const size_t size);

/**
 * \brief Ввод целого числа.
 * \param message претворяющая печать надпись.
 * \return целое число, введенное пользователем.
 */
int IntInput(const string& message);

/**
 * \brief Определяет, четное и отрицательное ли число?
 * \param element число.
 * \return если четное отрицательное, то true. Если нечетное - false
 */
bool IsOdd(int element);

/*
* \brief Поиск максимального элемента
* \return Максимальный элемент
*/
int GetMaxElem(const int* array, const size_t size);

/*
* \brief Кратность шести
*/
bool IsOddSix(const int element);

/*
* \brief Крастность трём
*/
bool IsOddThree(const int element);

/*
* \brief Поиск минмиального элемента
* \return Минимальный элемент
*/
int GetMinElem(const int* array, const size_t size);

/**
 * \brief Метод, изменяющий неправильный диапазон.
 * \param min минимальное значение.
 * Будет изменено, если ошибочно было больше максимального.
 * Результатом станет -10.
 * \param max максимальное значение.
 * Будет изменено, если ошибочно было меньше минимального.
 * Результатом станет 10.
 */
void ChangeWrongRange(int& min, int& max);

/**
 * \brief Копирование исходного массива.
 * \param array исходный массив.
 * \param size размер массива.
 * \return новый массив со скопированными элементами.
 */
int* ArrayCopy(const int* array, size_t size);

int main()
{
    cout << "Input array size = ";
    size_t size;
    cin >> size;
    cout << "Which way of array filling are you prefer?\n"
        << static_cast<int>(ArrayInputWay::random) << " - random,\n"
        << static_cast<int>(ArrayInputWay::keyboard) << " - keyboard.\n"
        << "Your choice is ";
    int choice;
    std::cin >> choice;

    try
    {
        const auto chosen = static_cast<ArrayInputWay>(choice);
        int* myArray = nullptr;

        switch (chosen)
        {
        case ArrayInputWay::random:
        {
            auto minValue = IntInput("Input min value of array = ");
            auto maxValue = IntInput("Input max value of array = ");
            if (maxValue <= minValue)
            {
                ChangeWrongRange(minValue, maxValue);
            }
            myArray = FillRandomArray(size, minValue, maxValue);
            break;
        }
        case ArrayInputWay::keyboard:
        {
            myArray = FillUserArray(size, "Input elements of the array");
            break;
        }
        default:
            cout << "You entered wrong choice!\n";
            return 1;
        }

        ArrayPrint(myArray, size, "\nThe array is:\n");

        const auto sum = SumOddValues(myArray, size);
        cout << "Sum of elements odd value = " << sum << "\n";

        PrintIndexesAboveConst(myArray, size);

        const auto changedArray = MaxMinElementChanged(myArray, size);
        ArrayPrint(changedArray, size, "\nThe changed array is:\n");

        delete[] myArray;
        delete[] changedArray;

        cout << endl;
        return 0;
    }
    catch (out_of_range&)
    {
        cout << "You entered wrong choice!";
        return 1;
    }

}

int* FillRandomArray(const size_t size, const int minValue, const int maxValue)
{
    //Will be used to obtain a seed for the random number engine
    std::random_device rd;

    //Standard mersenne_twister_engine seeded with rd()
    std::mt19937 gen(rd());

    const std::uniform_int_distribution<> uniformIntDistribution(minValue, maxValue);

    auto* array = new int[size];
    for (size_t index = 0; index < size; index++)
    {
        array[index] = uniformIntDistribution(gen);
    }

    return array;
}

int* FillUserArray(const size_t size, const string& message)
{
    auto* array = new int[size];
    cout << message << "\n";
    for (size_t index = 0; index < size; index++)
    {
        cin >> array[index];
    }
    return array;
}

int ArrayPrint(const int* array, const size_t size, const string& message)
{
    if (array == nullptr)
    {
        cout << "The array doesn't exist";
        return 0;
    }

    cout << message;
    for (size_t index = 0; index < size; index++)
    {
        cout << array[index] << " ";
    }
    cout << "\n";
}

void ChangeWrongRange(int& min, int& max)
{
    min = -1000;
    max = 1000;
    cout << "\nYou input wrong range. Right range is ["
        << min << ","
        << max << "]\n";
}

int IntInput(const string& message)
{
    cout << message;
    int temp;
    cin >> temp;
    return temp;
}

int PrintIndexesAboveConst(int* array, const size_t size)
{
    for (size_t i = 0; i < size; i++)
        if (IsOddSix(array[i]))
            return i;
}

int SumOddValues(const int* array, const size_t size)
{
    if (array == nullptr)
        return 42;

    auto sum = 0;
    for (size_t index = 0; index < size; index++)
    {
        if (IsOdd(array[index]) && array[index] < 0)
            sum += array[index];
    }
    return sum;
}

bool IsOdd(const int element)
{
    return element % 2 != 1;
}

bool IsOddSix(const int element)
{
    return element % 6 != 0;
}

bool IsOddThree(const int element)
{
    return element % 3 != 0;
}

int* MaxMinElementChanged(const int* array, const size_t size)
{
    if (array == nullptr)
        return nullptr;

    const auto null = 0;
    const auto newArray = ArrayCopy(array, size);
    const auto maxElem = GetMaxElem(array, size);
    const auto minElem = GetMinElem(array, size);

    for (size_t i = 0; i < size; i++)
        if (array[i] == minElem)
        {
            size_t indexFirst = i;
            for (size_t index = indexFirst + 1; index < size; index++)
            {
                do {
                    newArray[index] = null;
                } while (array[index] < maxElem);
            }
        }
        else if (array[i] == maxElem)
        {
            size_t indexFirst = i;
            for (size_t index = indexFirst + 1; index < size; index++)
            {
                do {
                    newArray[index] = null;
                } while (array[index] > minElem);
            }
        }
}

int GetMaxElem(const int* array, const size_t size)
{
    auto maximum = -1001;
    for (unsigned int i = 0; i < size; i++)
    {
        if (array[i] > maximum)
            maximum = array[i];
    }
    return maximum;
}

int GetMinElem(const int* array, const size_t size)
{
    auto minimum = 1001;
    for (unsigned int i = 0; i < size; i++)
    {
        if (array[i] < minimum)
            minimum = array[i];
    }
    return minimum;
}

int* ArrayCopy(const int* array, const size_t size)
{
    if (array == nullptr)
        return nullptr;

    const auto target = new int[size];
    for (size_t index = 0; index < size; index++)
    {
        target[index] = array[index];
    }
    return target;
}