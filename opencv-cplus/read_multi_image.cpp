#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;


int main(){
    vector<cv::String> fn;
    glob("/home/maicg/Documents/python-image-processing/code-edit-insightFace/data/nkt/*.jpg", fn, false);
    // Mat image = imread("/home/maicg/Documents/python-image-processing/code-edit-insightFace/data/nkt/img933.8416.jpg");
    // Mat image = imread("/home/maicg/Documents/python-image-processing/code-edit-insightFace/data/kt/img607.8203.jpg");
    size_t count = fn.size(); //number of png files in images folder
    for (size_t i=0; i<count; i++){
        Mat image = imread(fn[i]);
        // images.push_back(imread(fn[i]));

        int down_width = 300;
        int down_height = 200;
        Mat resized_down;
        //resize down
        resize(image, resized_down, Size(down_width, down_height), INTER_LINEAR);
        namedWindow("image");
        imshow("image", resized_down);
        waitKey(0);
    }

}