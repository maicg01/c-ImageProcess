#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;


int main(){
    Mat image = imread("/home/maicg/Documents/python-image-processing/code-edit-insightFace/data/nkt/img933.8416.jpg");
    // Mat image = imread("/home/maicg/Documents/python-image-processing/code-edit-insightFace/data/kt/img607.8203.jpg");
    int down_width = 300;
    int down_height = 200;
    Mat resized_down;
    //resize down
    resize(image, resized_down, Size(down_width, down_height), INTER_LINEAR);
    namedWindow("image");
    imshow("image", resized_down);
    waitKey(0);

    Mat outputImage;
    inRange(resized_down, Scalar(0,40,0), Scalar(179,255,255), outputImage);

    namedWindow("output");
    imshow("output", outputImage);
    waitKey(0);
}