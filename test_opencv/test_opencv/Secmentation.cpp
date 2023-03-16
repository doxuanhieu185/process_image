//
//  Secmentation.cpp
//  test_opencv
//
//  Created by Hieu's Macbook pro on 16/03/2023.
//

#include "Secmentation.hpp"
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

void Segmentation()
{
    Mat image;
    image = imread("color.jpg");
    int down_width = 300;
    int down_height = 200;
    resize(image, image, Size(down_width, down_height), INTER_LINEAR);
    Mat image_gray(image.rows, image.cols, CV_8UC1);
    cvtColor(image, image_gray, COLOR_BGR2GRAY);
    Mat binary(image.rows, image.cols, CV_8UC1);
    threshold(image_gray, binary, 40, 255, THRESH_BINARY | THRESH_OTSU);
    Mat fg;
    erode(binary, fg, Mat(), Point(-1, -1), 2);
    Mat bg;
    dilate(binary, bg, Mat(), Point(-1, -1), 3);
    threshold(bg, bg, 1, 128, THRESH_BINARY_INV);
    Mat markers(binary.size(), CV_8U, Scalar(0));
    markers = fg + bg;
    markers.convertTo(markers, CV_32S);
    watershed(image, markers);
    markers.convertTo(markers, CV_8U);
    threshold(markers, markers, 40, 255, THRESH_BINARY |
        THRESH_OTSU);
    imshow("Org", image);
    imshow("Sau Segmentation", markers);
}
