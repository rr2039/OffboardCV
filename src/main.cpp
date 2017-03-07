/*
 * main.cpp
 *
 *  Created on: Mar 6, 2017
 *      Author: logan
 */

// Workaround for working with GCC 5.4. It was FIRST's idea.
#define _GLIBCXX_USE_CXX11_ABI 0

// Standard Includes (with guards)
#ifndef _GLIBCXX_THREAD
#include <thread>
#endif //_GLIBCXX_THREAD
#ifndef _GLIBCXX_STRING
#include <string>
#endif // _GLIBCXX_STRING
#ifndef _GLIBCXX_CHRONO
#include <chrono>
#endif // _GLIBCXX_CHRONO
#ifndef _STDIO_H
#include <stdio.h>
#endif // _STDIO_H

// OpenCV Includes (with guards)
// NOTE: Not using the OpenCV library provided by WPI.  Using the builtin one for optimization purposes.
#ifndef __OPENCV_IMGPROC_HPP__
#include <opencv2/imgproc/imgproc.hpp>
#endif
// imgproc.hpp already includes core.  This is only left here for posterity.
#ifndef __OPENCV_CORE_HPP__
#include <opencv2/core/core.hpp>
#endif

// WPIlib Includes (with guards..?)
#ifndef NETWORKTABLE_H
#include "networktables/NetworkTable.h"
#endif
// These are also already included by Networktable.h  Again, for posterity.
#ifndef ITABLE_H_
#include "tables/ITable.h"
#endif
#ifndef LLVM_ADT_STRINGREF_H
#include "llvm/StringRef.h"
#endif
// These are unlikely to be included anywhere else, so I will not guard them (for now)
#include "llvm/ArrayRef.h"
#include "cscore.h"

// Forward Declarations:
cs::UsbCamera SetUsbCamera(int cameraId, cs::MjpegServer& server);

// Some constants you might want to set differently later:
const int USBCAM_RES_WIDTH = 640;
const int USBCAM_RES_HEIGHT = 480;
const int USBCAM_FPS = 30;
const int USBCAM_ID = 0;

int main(int argc, char **argv) /* Look!  POSIX argument interfaces! */
{
	int teamNumber;
	int port;
	/* Allow me to specify a different team number, if I want. */
	try {
		if (argc > 1)
			sscanf(argv[1], "%d", &teamNumber);
		else
			teamNumber = 2039;
		/* Also, allow me to specify a different port if I want to too. */
		if (argc > 2)
			sscanf(argv[2], "%d", &port);
		else
			port = 1185;
	} catch (...) {
	}

	/* Set Up NetworkTables */
	NetworkTable::SetClientMode();
	NetworkTable::SetTeam(teamNumber);
	NetworkTable::Initialize();

	/* Set Up MJPEG Servers, Sinks, Etc. */
	cs::MjpegServer inputStream("Input MJPEG Server", port);
	cs::MjpegServer unprocessedOutputStream("Unprocessed Output MJPEG Server",
			port + 1);
	cs::MjpegServer overlaidOutputStream("Overlaid Output MJPEG Server",
			port + 2);
	cs::CvSink usbCameraSink("USB Camera Sink");
	cs::CvSource unprocessedSource("Unprocessed Source",
			cs::VideoMode::PixelFormat::kMJPEG, USBCAM_RES_WIDTH,
			USBCAM_RES_HEIGHT, USBCAM_FPS);
	cs::CvSource processedSource("Processed Source",
			cs::VideoMode::PixelFormat::kMJPEG, USBCAM_RES_WIDTH,
			USBCAM_RES_HEIGHT, USBCAM_FPS);
	cs::CvSource overlaidSource("Overlaid Source",
			cs::VideoMode::PixelFormat::kMJPEG, USBCAM_RES_WIDTH,
			USBCAM_RES_HEIGHT, USBCAM_FPS);

	/* Set up USB camera */
	cs::UsbCamera camera = SetUsbCamera(USBCAM_ID, inputStream);
	camera.SetResolution(USBCAM_RES_WIDTH, USBCAM_RES_HEIGHT);

	/* Attach sources to sinks, etc. */
	usbCameraSink.SetSource(camera);
	unprocessedOutputStream.SetSource(unprocessedSource);
	overlaidOutputStream.SetSource(overlaidSource);

	/* I suppose I'll follow FIRST's advice and not instantiate cv mats inside the loop.
	 * I could static them, but oh well. */
	cv::Mat inputImage, processedImage, overlaidImage;

	/* And now, we infinitely process the image.  */
	while (true)
	{
		auto frameTime = usbCameraSink.GrabFrame(inputImage);
		if (frameTime == 0) continue;
		// TODO: process the image.
		processedSource.PutFrame(processedImage);
		// TODO: Overlay the image.
		overlaidSource.PutFrame(overlaidImage);


	}
}

