#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "RGB_separation.hpp"
#include "YUV.hpp"
#include "HISTOGRAM.hpp"
#include "Median_filter.hpp"
#include "mean_filter.hpp"
#include "DCT.hpp"
#include "Gaussian_filter.hpp"
#include "UnsharpMask.hpp"
#include "Secmentation.hpp"
using namespace cv;
using namespace std;

int main()
{
//    Mat img = imread("gai.jpg");
//    if (!img.data)
//     {
//         printf("Khong the mo/tim duoc anh\n");
//     return -1;
//     }
//    USM(img, 5,5 , 5);
    Segmentation(); 
    waitKey(0);
    return 0;
}
