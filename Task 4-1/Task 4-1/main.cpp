#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <random>
#include <iomanip>

using namespace std;

/**
* \brief Заполнение массива случайными числами
* \param array Массив
* \param size Размер массива
* \param min Минимально возможное число
* \param max Максимально возможное число
**/
void RandomArray(int* array, const size_t size, const int min, const int max);

/**
* \brief Ввод массива с клавиатуры
* \param array Массив
* \param size Размер массива
**/
void UserArray(int* array, const size_t size);

/**
* \brief Сумма чётных отрицательных элементов
* \param array Массив
* \param size Размер массива
**/
int SumNumbers(int* array, const size_t size);

/**
* \brief Количество элементов, кратных 3 и 6
* \param array Массив
* \param size Размер массива
* \param A значение по условию
**/
void NumberElements(int* array, const size_t size);

/**
* \brief Новый массив(нули между минимумом и максимумом)
* \param array Массив
* \param second_array Обработанный массив
* \param size Размер массива
**/
void SecondArray(int* array, int* second_array, const size_t size);

enum class ArrayType
{
	RandomNumber = 1,
	UserNumber = 2
};

int main()
{
	setlocale(LC_ALL, "ru");

	cout.precision(3);
	cout << fixed;

	const int MIN = -1000, MAX = 1000;
	int sum;

	cout << "Please input array length: ";
	size_t size;
	cin >> size;
	const size_t size_array = size;

	int* array = new int[size_array];
	int* second_array = new int[size_array];

	cout << "\nChoose array:\n" << "1) Array with random number\n" << "2) Array with user number\n" << "1 or 2: ";
	int choice;
	cin >> choice;

	const auto arraytype = static_cast<ArrayType>(choice);

	switch (arraytype)
	{
	case ArrayType::RandomNumber:
	{
		RandomArray(array, size_array, MIN, MAX);
		break;
	}
	case ArrayType::UserNumber:
	{
		UserArray(array, size_array);
		break;
	}
	default:
		break;
	}

	cout << "Сумма чётных отрицательных элементов " << SumNumbers(array, size_array) << endl;

	cout << "Индексы элементов, значения которых кратны 3 и 6: \n";

	NumberElements(array, size_array);
	cout << endl;
	cout << "Новый массив, в котором элементы, находящиеся между максимальным и минимальным, заменяются нулями: " << endl; SecondArray(array, second_array, size_array);

	if (array != nullptr)
	{
		delete[] array;
		array = nullptr;
	}
	if (second_array != nullptr)
	{
		delete[] second_array;
		second_array = nullptr;
	}
}

void RandomArray(int* array, const size_t size, const int min, const int max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	const uniform_int_distribution<> uniformIntDistribution(min, max);

	for (size_t i = 0; i < size; ++i)
		array[i] = uniformIntDistribution(gen);
	for (size_t i = 0; i < size; ++i)
	{
		cout << "array[" << i << "] = " << array[i] << endl;
	}
}

void UserArray(int* array, const size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "array[" << i << "] = ";
		cin >> array[i];
	}
}

int SumNumbers(int* array, const size_t size)
{
	int sum = 0;
	for (size_t i = 0; i < size; ++i)
	{
		if (array[i] < 0 && array[i] % 2 == 0)
		{
			sum += array[i];
		}
	}
	return sum;
}

void NumberElements(int* array, const size_t size)
{
	bool check = false;
	for (size_t i = 0; i < size; i++) {
		if (array[i] % 6 == 0) {
			cout << "Номер элемента: " << i << endl;
			check = true;
		}
	}
	if (check == false) {
		cout << "Таких элементов нет ";
	}
}

void SecondArray(int* array, int* second_array, const size_t size)
{
	second_array = array;
	double null = 0;
	int max = INT_MIN;
	int min = INT_MAX;
	size_t max_index = size, min_index = 0;

	for (size_t i = 0; i < size; i++) {
		if (array[i] > max) {
			max_index = i;
			max = array[i];
		}
	}
	for (size_t i = 0; i < size; i++) {
		if (array[i] < min) {
			min_index = i;
			min = array[i];
		}
	}

	if (max_index < min_index) {
		for (size_t i = max_index + 1; i < min_index; i++)
			second_array[i] = null;
	}
	else {
		for (size_t i = min_index + 1; i < max_index; i++)
			second_array[i] = null;
	}

	for (size_t i = 0; i < size; i++)
		cout << second_array[i] << " ";
}