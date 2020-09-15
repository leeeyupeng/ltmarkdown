#include <iostream>
using namespace std;
int main() {
	int* a = (int*)malloc(sizeof(int) * 101);

	cout << "a[99]:" << a[99] << endl;
	cout << "a[100]:" << a[100] << endl;
	cout << "a[101]:" << a[101] << endl;
	a[100] = 0x0;
	cout << "a[100]:" << a[100] << endl;
	cout << "a[101]:" << a[101] << endl;
	a[101] = -33686019;
	cout << "a[100]:" << a[100] << endl;
	//a[10000] = 10;
	//cout << "a[10000]:" << a[10000] << endl;

	cout << "(a-1):" << *(a - 10000) << endl;
	free(a);

	int *arr[100000];
	for (int i = 0; i < 100000; i++) {
		arr[i] = (int*)malloc(sizeof(int) * 1000001);
		if (arr[i] == NULL) {
			cout << "arr[i] == NULL" << endl;
		}
	}

	int bb = 0;
	//for (int i = 0; i < 1000; i++) {
	//	free(arr[i]);
	//}

	int cc = 5;
	int arrint[10000];
	int arrint2[10000];
	int arrint3[10000];
	int arrint4[10000];
	system("pause");
	return 0;
}