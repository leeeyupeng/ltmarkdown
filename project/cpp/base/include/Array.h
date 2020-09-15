#include<iostream>
#include<vector>
using namespace std;

#define MAX 10
void test() {
	int a[MAX];
	for (int i = 0; i < MAX; i++) {
		a[i] = rand() % 100;
	}
	for (int i = 0; i < MAX; i++) {
		cout << "a[" << i << "]:" << a[i] << endl;
	}
	cout << "array length:" << sizeof(a) / sizeof(int) << endl;
}
void test2() {
	int* a;
	int n;
	cin >> n;
	a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100;
	}
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]:" << a[i] << endl;
	}
	cout << "array length:" << n << endl;
	cout << "a sizeof:" << sizeof(a) << endl;
	free(a);
	a = NULL;
}

void test3(vector<int> v) {
	int n = v.size();
	int * array;
	array = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		array[i] = v[i];
	}

	for (int i = 0; i < n; i++) {
		cout << "array[" << i << "]:" << array[i] << endl;
	}
	cout << "array length:" << n << endl;
	cout << "array sizeof:" << sizeof(array) << endl;
	free(array);
	array = NULL;
}
void test4(vector<int> v) {
	int n = v.size();
	int * array;
	array = (int*)malloc(sizeof(int) * n);
	memcpy(array,&v[0],sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		cout << "array[" << i << "]:" << array[i] << endl;
	}
	cout << "array length:" << n << endl;
	cout << "array sizeof:" << sizeof(array) << endl;
	free(array);
	array = NULL;
}