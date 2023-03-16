//
//  HISTOGRAM.cpp
//  test_opencv
//
//  Created by Hieu's Macbook pro on 16/03/2023.
//

#include "HISTOGRAM.hpp"
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

void drawHistogram(Mat img, String windowName) {
    int histSize = 256;
    //so luong pixel cho moi gia tri pixel (0-255)
    float range[] = { 0, 255 };
    //Pham vi gia tri muon do
    const float* ranges[] = { range };
    // Tinh histogram MatND hist;
    MatND hist;
    calcHist(&img, 1, 0, Mat(), hist, 1, &histSize, ranges, true, false);
    int hist_w = 512;
    int hist_h = 400;
    int bin_w = cvRound((double)hist_w / histSize);
    // Truoc khi vẽ, chuẩn hóa kết quả về khoảng [0 , Hist.rows]
    Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(0, 0, 0));
    normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
    // Vẽ biểu đồ Hist
    for (int i = 1; i < histSize; i++) {
        line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(hist.at<float>(i - 1))),
            Point(bin_w * (i), hist_h - cvRound(hist.at<float>(i))),
            Scalar(255, 0, 0), 2, 8, 0);
    }
    imshow(windowName, histImage);
}

void Historgram(Mat grayscaleImg) {
    imshow("Image Before", grayscaleImg);
    drawHistogram(grayscaleImg, "Histogram Before");
    Mat equalizedImage(grayscaleImg.rows, grayscaleImg.cols, CV_8UC3);
    equalizeHist(grayscaleImg, equalizedImage);
    imshow("Image After", equalizedImage);
    drawHistogram(equalizedImage, "Histogram After");
}
