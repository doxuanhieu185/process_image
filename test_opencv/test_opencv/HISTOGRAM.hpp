//
//  HISTOGRAM.hpp
//  test_opencv
//
//  Created by Hieu's Macbook pro on 16/03/2023.
//

#ifndef HISTOGRAM_hpp
#define HISTOGRAM_hpp
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
void drawHistogram(Mat img, String windowName);
void Historgram(Mat grayscaleImg);
#endif /* HISTOGRAM_hpp */
