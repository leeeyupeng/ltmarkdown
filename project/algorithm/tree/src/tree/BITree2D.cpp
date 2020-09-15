#include <iostream>
#include<memory.h>
#include<limits.h>
using namespace std;
#include "tree/BITree2D.h"
lt::tree::BITree2D::BITree2D() {
}
lt::tree::BITree2D::~BITree2D(){
	free(_arr);
}
void lt::tree::BITree2D::init(int _n,int _m) {
	n = _n;
	m = _m;
	_arr = (int*)malloc(sizeof(int) * ((n+1) *( m + 1)));
	memset(_arr, 0, sizeof(int) * ((n+1) * (m + 1)));
}
void lt::tree::BITree2D::updateBITree(int x,int y, int val) {
	x++,y++;
	for (int i = x; i <= n; i += (i&(-i))) {
		for (int j = y; j <= m; j += (j&(-j))) {
			_arr[i * (m + 1) + j] += val;
		}
	}
}
int lt::tree::BITree2D::getSum(int x,int y) {
	int result = 0;
	x++, y++;
	for (int i = x; i > 0; i -= (i&(-i))) {
		for (int j = y; j > 0; j -= (j&(-j))) {
			result += _arr[i * (m + 1) + j];
		}
	}
	return result;
}