//
//  RGB_separation.cpp
//  test_opencv
//
//  Created by Hieu's Macbook pro on 16/03/2023.
//

#include "RGB_separation.hpp"
#include <stdio.h>
#include<iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include<opencv2/img_hash.hpp>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void splitRGB(cv::Mat img) {
    Mat rgb[3];
    split(img, rgb);
    imshow("Original", img);
    imshow("blue", rgb[0]);
    imshow("green", rgb[1]); imshow("red", rgb[2]);
    // Ghi lại thông tin
    imwrite("blue.jpg", rgb[0]);
    imwrite("green.jpg", rgb[1]);
    imwrite("red.jpg", rgb[2]);
}
