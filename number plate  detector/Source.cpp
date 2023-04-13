#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;


//  PROJECT -> NUMBER PLATE DETECTION


void main() {

	VideoCapture cap(0);
	Mat img;
	CascadeClassifier PlateCascade;
	PlateCascade.load("Resources/haarcascade_russian_plate_number.xml");

	if (PlateCascade.empty()) { cout << "XML file not loaded" << endl; }

	vector<Rect> plates;

	while (true) {
		cap.read(img);
	vector<Rect> plates;
		PlateCascade.detectMultiScale(img, plates, 1.1, 10);

		for (int i = 0; i < plates.size(); i++)
		{
			Mat imgCrop = img(plates[i]);
			// to detect number plate and crop it in new window
			imshow(to_string(i), imgCrop);
			// to save the number plate 
			imwrite("Resources/Plates/" + to_string(i) +".png", imgCrop);
			rectangle(img, plates[i].tl(), plates[i].br(), Scalar(255, 0, 255), 3);
		}

		imshow("Image", img);
		waitKey(1);
	}
}