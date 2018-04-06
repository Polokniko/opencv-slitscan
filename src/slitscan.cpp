#include <iostream> // for cout to print to console
#include <chrono> // for chrono::steady_clock::now() to get time and calculate fps
#include <vector> // for vector, for the images vector to store images

#include <opencv2/opencv.hpp> // for VideoCapture and Mat, to get the video stream and matrix manipulation

int main()
{
	// i just use std::endl and "\n" pretty much interchangeably, don't think it really matters

	// initializes video capture stream
	cv::VideoCapture cap;
	std::cout << "video capture initialized\n";

	// checks if video capture exists or something. also can't set resolution without this line? not sure why
	if (!cap.open(0)) {std::cout << "video capture nonexistent\n"; return 0;}
	std::cout << "video capture found\n";

	// setting width and height, this line has to be after the `if (!cap.open(0)` no idea why
	int width = 640;
	int height = 360;

	 cap.set(CV_CAP_PROP_FRAME_WIDTH, width);
	 cap.set(CV_CAP_PROP_FRAME_HEIGHT, height);

	// copys video stream image into matrix frame
	cv::Mat frame;
	cap >> frame;

	std::cout << "video capture resolution set to " << frame.cols << " by " << frame.rows << std::endl;

	// initialize images
	// copys the current image into vector (basically a list) with a size of the number of rows in the image
	std::vector<cv::Mat> images(frame.rows);
	std::cout << "image vector initialized\n";
	for (int i=0; i<frame.rows; i++) {
		images[i] = frame;
		std::cout << "image saved to vector index " << i << std::endl;;
	}

	std::cout << "initialization complete, starting main loop\n";

	// loop variables

	// initializes and fills matrix, finished_image, with size of (frame.rows, frame.cols), with zeros
	// the datatype format: CV_[The number of bits per item][Signed or Unsigned][Type Prefix]C[The channel number]
	//                              x size      y size      datatype
	cv::Mat result = cv::Mat::zeros(frame.rows, frame.cols, CV_8UC3);

	// buffer to shift the images
	std::vector<cv::Mat> imagesbuffer(frame.rows);

	// initialization complete, starting main loop
	while (true) {
		// if you see chrono, it's just for time
		// doesn't affect performance too much?
		auto start = std::chrono::steady_clock::now();

		// copys video stream image into frame matrix
		cv::Mat frame;
		cap >> frame;

		// shift images in the vector, images, to the right(?) and overwrites the last image
		imagesbuffer = images;
		for (int i=1; i<frame.rows-1; i++) {
			images[i] = imagesbuffer[i-1];
		}

		// add current frame to start of images after shifting of images
		images[0] = frame;

		// creating slit scanned image (is that what it's called?), result
		for (int i=0; i<frame.rows; i++) {
			images[i].row(i).copyTo(result.row(i));
		}

		// displays the result
		cv::imshow("result", result);
		// comment to hide live video capture, improves speed by a tiny bit
		cv::imshow("frame", frame);

		// checks if any keys are pressed, if so, exit
		// you need this for the images to show, no idea why
		if (cv::waitKey(20) > 0) break;

		// outputs delay in seconds, calculates delay in nanoseconds then divides it by 10^9
//		std::cout << (std::chrono::duration <double, std::nano> (std::chrono::steady_clock::now() - start).count())/1000000000 << std::endl;
		// prints the frames per second, calculated by dividing the time it took in seconds by the number of frames in that time (numofframes/delay)
		std::cout << 1/((std::chrono::duration <double, std::nano> (std::chrono::steady_clock::now() - start).count())/1000000000) << " frames per second\n";
	}
	cap.release();
	// pretty sure this isn't even required, but whatever
	return 0;
}
