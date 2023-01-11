#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(){
    Mat img = imread("/home/maicg/cpp_test/2.png");
    imshow("window", img);
    waitKey(0);

    return 0;
}