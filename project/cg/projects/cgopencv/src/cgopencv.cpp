#include<iostream>
#include"opencv2/opencv.hpp"
using namespace cv;
using namespace std;
int main(){
	Mat image = imread("resources/icon512.png");
	imshow("cgopencv",image);
	waitKey(0);
	return 0;
}