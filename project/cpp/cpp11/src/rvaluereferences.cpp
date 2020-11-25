#include <iostream>
#include<memory>
#include<vector>
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

//���
class HasPtrMem {
public:
	int *intptr;
public:
	HasPtrMem() :intptr(new int[100]) {
		for (int i = 0; i < 100; i++) { intptr[i] = i; }
	}
	HasPtrMem(const HasPtrMem& _right) :intptr(new int[100]()) {
		memcpy(intptr, _right.intptr,100);
	}
	~HasPtrMem() { 
		delete[] intptr;
	}
};

vector<int> getvector() {
	std::vector<int> v{ 1,2,3,4,5 };
	return std::move(v);
}
int main_rvaluereferences(){
	{
		HasPtrMem a;
		HasPtrMem b(a);

	}
	{
		std::vector<int> v{ 1,2,3,4,5 };
		std::vector<int> v2(std::move(v)); // ����ֵ���õ� v
		assert(v.empty());
	}

	{
		vector<vector<int>> v{ { 1,2,3,4,5 } ,{1,2,3},{4,5} };
		vector<vector<int>> v2(std::move(v)); // ����ֵ���õ� v
		assert(v.empty());
	}

	{
		std::vector<int> v{ 1,2,3,4,5 };
		std::vector<int>&& v3 = std::move(v);
		std::vector<int> v2(v3); 
		//assert(v.empty());
	}


	{
		std::vector<int> v2(getvector());
		//assert(v3.empty());
	}

	{
		std::vector<int>&& v3 = getvector();
		std::vector<int> v2(v3);
		//assert(v3.empty());
	}

	// {
	// 	std::vector<int>& v3 = getvector();
	// 	std::vector<int> v2 = v3;
	// 	//assert(v3.empty());

	// 	int i = 42;
	// 	int &l = i;
	// 	//int &&r = i;
	// 	//int &l2 = i+42;
	// }

	{
		const std::vector<int>&& v3 = getvector();
		std::vector<int> v2 = v3;
		//assert(v3.empty());
	}

}