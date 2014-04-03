//
//  main.cpp
//  Rotation of a video
//
//  Created by Simarpreet Singh Chawla on 03/04/14.
//  Copyright (c) 2014 Simarpreet Singh Chawla. All rights reserved.
//

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, const char * argv[])
{
    VideoCapture cap("/Users/Sam/Desktop/1.mp4");
    if ( !cap.isOpened() )
    {
        cout << "Cannot open the video file" << endl;
        return -1;
    }
    int iAngle = 180;
    namedWindow( "Image", CV_WINDOW_AUTOSIZE );
    createTrackbar("Angle", "Image", &iAngle, 360);
    while (true)
    {
        Mat matOriginalFrame;
        bool bSuccess = cap.read(matOriginalFrame);
        if (!bSuccess)
        {
            cout << "Cannot read the frame from video file" << endl;
            break;
        }
        imshow("Image", matOriginalFrame);
        int iImageHeight = matOriginalFrame.rows / 2;
        int iImageWidth = matOriginalFrame.cols / 2;
        Mat matRotation = getRotationMatrix2D( Point(iImageWidth, iImageHeight), (iAngle - 180), 1 );
        Mat matRotatedFrame;
        warpAffine( matOriginalFrame, matRotatedFrame, matRotation, matOriginalFrame.size() );
        imshow( "Image", matRotatedFrame);
        if (waitKey(30) == 27)
        {
            cout << "esc key is pressed by user" << endl;
            break;
        }
    }
    return 0;
}

