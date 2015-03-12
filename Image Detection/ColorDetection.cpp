#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define ORANGE_HUE 56
#define ORANGE_SAT 120
#define ORANGE_B 255

#define BLUE_HUE 255
#define BLUE_SAT 0
#define BLUE_B 0

#define GREEN_HUE 0
#define GREEN_SAT 255
#define GREEN_B 0

#define YELLOW_HUE 0
#define YELLOW_SAT 255
#define YELLOW_B 255

#define RED_HUE 0
#define RED_SAT 0
#define RED_B 255

#define WHITE_HUE 255
#define WHITE_SAT 255
#define WHITE_B 255

#define WHITE 0
#define YELLOW 1
#define ORANGE 2
#define RED 3
#define GREEN 4
#define BLUE 5

using namespace cv;
using namespace std;
#define CORNER_SIZE 40
#define SIZE 110
#define SPACE 40
#define X_OFF 100
#define Y_OFF 100


Mat src; Mat src_HSV, src_modified;	//Stores the image from Video and a HSV converted image

Vec3b Orange, Red, White, Blue, Green, Yellow;

/*Function Prototypes*/
void getHSV();
Vec3b printColor(unsigned long H, unsigned long S, unsigned long V);
void initializeColors();


int main(int argc, char** argv)
{
	VideoCapture cap(1); // open the default camera
	if (!cap.isOpened())  // check if we succeeded
		return -1;

	for (;;)
	{
		/* Get the image from video*/
		cap >> src;

		initializeColors();
		/* Create an HSV of the image*/
		cvtColor(src, src_HSV, CV_BGR2HSV);

		/* Draw rectangles*/
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				rectangle(src, Point2f(i*SIZE + X_OFF +SPACE, j*SIZE+ Y_OFF + SPACE), 
					Point2f((i + 1)*SIZE + X_OFF -SPACE, Y_OFF+ (j + 1)*SIZE - SPACE), 
					Scalar(0,0,255), 2);
			}
		}
		getHSV();
		/* Display the video on a screen*/
		char* source_window = "Source";
		namedWindow(source_window, CV_WINDOW_AUTOSIZE);
		imshow(source_window, src);
	//	cvtColor(src_HSV, src_modified, CV_HSV2BGR);
		//char* source_window1 = "Source_HSV";
		//namedWindow(source_window1, CV_WINDOW_AUTOSIZE);
		//imshow(source_window1, src_modified);

		if (waitKey(30) >= 0)
		//	getHSV();
		//if (waitKey(30) == 0x20)
			break;


	}
}



void getHSV()
{
	/* Gets the HSV Averages of the H, S, and V values of each rectangle in the image*/
	unsigned long H, S, V;
	

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//For every Rectangle
			H = S = V = 0;
			for (int x = i*SIZE + X_OFF + SPACE; x < (i + 1)*SIZE + X_OFF - SPACE; x++)
			{
				for (int y = j*SIZE + Y_OFF + SPACE; y < Y_OFF + (j + 1)*SIZE - SPACE; y++)
				{

					//Get the sum of HSV Values
					Vec3b hsv = src_HSV.at<Vec3b>(x, y);
					H += hsv.val[0];
					S += hsv.val[1];
					V += hsv.val[2];
				}
			}

			//Get the average
			H = H / ((SIZE - 2 * SPACE)*(SIZE - 2 * SPACE));
			S = S / ((SIZE - 2 * SPACE)*(SIZE - 2 * SPACE));
			V = V / ((SIZE - 2 * SPACE)*(SIZE - 2 * SPACE));
			//Check which color it is
			
			//cout << " ";
			//cout << i << "," << j << endl;
			// Write the color in the corner
			Vec3b copy = printColor(H, S, V);
			for (int x = i*CORNER_SIZE; x < (i + 1)*CORNER_SIZE; x++)
			{
				for (int y = j*CORNER_SIZE; y < (j + 1) * CORNER_SIZE; y++)
				{
					src.at<Vec3b>(x, y) = copy;
				}
			}
		}
		//cout << endl;
	}


	return;
}


Vec3b printColor(unsigned long H, unsigned long S, unsigned long V)
{
	//cout << "H = " << H << " S =" << S << " V= " << V << endl;
	if (H > 30 && H < 40)
		return Yellow;
	else if (H > 20 && H < 30 && S < 70)
		return White;
	else if (H > 55 && H < 80)
		return Green;
	else if (H > 95 && H < 125)
		return Blue;
	else if (H < 3)
		return Red;
	else if (H >= 3 && H < 10)
		return Orange;
	else
		return Vec3b(255, 0, 157);

}


void initializeColors()
{
	Orange.val[0] = ORANGE_HUE;
	Orange.val[1] = ORANGE_SAT;
	Orange.val[2] = ORANGE_B;

	Yellow.val[0] = YELLOW_HUE;
	Yellow.val[1] = YELLOW_SAT;
	Yellow.val[2] = YELLOW_B;

	White.val[0] = WHITE_HUE;
	White.val[1] = WHITE_SAT;
	White.val[2] = WHITE_B;

	Blue.val[0] = BLUE_HUE;
	Blue.val[1] = BLUE_SAT;
	Blue.val[2] = BLUE_B;

	Green.val[0] = GREEN_HUE;
	Green.val[1] = GREEN_SAT;
	Green.val[2] = GREEN_B;

	Red.val[0] = RED_HUE;
	Red.val[1] = RED_SAT;
	Red.val[2] = RED_B;
}