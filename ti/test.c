#include <cv.h>
#include <highgui.h>
#include <stdio.h>
using namespace cv;
int main(int argc, char** argv)
{
    CvCapture* capture = cvCaptureFromCAM(0);
		IplImage* image = 0;
		cvSet(image, CV_RGB(255,255,255), NULL);
		image = cvQueryFrame(capture);



		cvNamedWindow("this is HAZYBOT !!!!", CV_WINDOW_AUTOSIZE);

		puts("Initialization complete !!");

		puts("Data of the image :");
		printf("image->height = %i\n", image->height);
		printf("image->width = %i\n", image->width);
		printf("image->nChannels = %i\n", image->nChannels);
		cvShowImage("this is HAZYBOT !!!!", image);
		while(cvWaitKey(30) == -1){
		}
    return 0;
}
