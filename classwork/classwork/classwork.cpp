#include <iostream>

template<typename T>
void printArray(T* arr, size_t len) {
	for (int i = 0; i < len; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

void test1() {
	int a = 2, b = 5;
	std::cout << "Before:" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "After:" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
}

void test2() {
	std::cout << "Enter length of array:" << std::endl;
	size_t n = 0;
	std::cin >> n;
	int* arr = new int[n];
	for (size_t i = 0; i < n; ++i) {
		arr[i] = i;
	}

	std::cout << "Before:" << std::endl;
	printArray(arr, n);

	int* pa = arr;
	int* pla = arr + n - 1;
	int temp = *pa;
	*pa = *pla;
	*pla = temp;

	std::cout << "After:" << std::endl;
	printArray(arr, n);
	delete[] arr;
}


void test3() {
	double** p = 0;
	p = new double*;
	*p = new double;
	**p = 2;
	std::cout << **p << std::endl;
	delete *p;
	delete p;
}

template<typename T>
int insertionSort(T* arr, int listLength) {
	int swap_count = 0;
	for (int i = 1; i < listLength; i++) {
		int j = i - 1; // previous element
		while (j >= 0 && arr[j] < arr[j + 1]) { // compare previous and next element, if the next one element is bigger than the previous, then
			swap(arr[j], arr[j + 1]); // swap them
			j--;
			swap_count++;
		}
	}
	return swap_count;
}

void test4() {
	double arr[12] = { 3, 65, 8, 0, 23, 14, 12, -30, 2.8, -4, 6, 0.3 };
	std::cout << "Before:" << std::endl;
	printArray(arr, 12);
	int swap_count = insertionSort(arr, 12);
	std::cout << "After sort:" << std::endl;
	printArray(arr, 12);
    std::cout << swap_count << std::endl;
}



template<typename T> 
int halfSwap(T* arr, size_t n) {
	int swap_count = 0;
	for (size_t i = 0; i < n/2; ++i) {
		swap(arr[i], arr[i + n / 2]);
		swap_count++;
	}
	return swap_count;
}

void test6() {
	double arr[14] = { 3, 65, 8, 0, 23, 14, 12, -30, 2.8, -4, 6, 0.3, -1.111, 1};
	std::cout << "Before:" << std::endl;
	printArray(arr, 14);
	int swap_count = halfSwap(arr, 14);
	std::cout << "After:" << std::endl;
	printArray(arr, 14);
}


template<typename T>
int countLocalMins(T* arr, int n) {
	int localMinCount = 0;
	for (size_t i = 1; i < n - 1; ++i) { 
		if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {   // сравниваем элемент массива с предыдущим и последующим, если меньше, то
			localMinCount++; // в счетчике count прибавляется +1
		}
	}
	return localMinCount; // возвращаем значение счетчика
}

void test7() {
	double arr[14] = { 3, 65, 8, 0, 23, 14, 12, -30, 2.8, -4, 6, 0.3, -1.111, 1 };
	std::cout << "Array:" << std::endl;
	printArray(arr, 14);
	std::cout << countLocalMins(arr, 14) << std::endl;
}



int main()
{
	std::cout << "Task 1" << std::endl;
	test1();


	std::cout << "Task 2" << std::endl;
	test2();
	

	std::cout << "Task 3" << std::endl;
	test3();

	std::cout << "Task 4" << std::endl;
	test4();

	std::cout << "Task 6" << std::endl;
	test6();
	
	std::cout << "Task 7" << std::endl;
	test7();
}

