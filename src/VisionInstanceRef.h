/*
 * VisionInstanceRef.h
 *
 *  Created on: Mar 3, 2017
 *      Author: logan
 */

#ifndef SRC_VISIONINSTANCEREF_H_
#define SRC_VISIONINSTANCEREF_H_

#include <opencv2/core/core.hpp>
#include <vector>
namespace jcv {

class VisionInstanceRef {
public: // Methods
	VisionInstanceRef();
	virtual ~VisionInstanceRef();
public: // Public Attributes
	int teamNumber;
	int streamPort;
	cs::MjpegServer* inputStreamServer;
	cs::MjpegServer* outputStreamServer;
	cs::MjpegServer* procOutputStreamServer;
	cs::UsbCamera* usbCamera;
	cs::VideoSink* usbCameraSink;
	cs::VideoSource* outputSource;
	cs::VideoSource* procOutputSource;




};

} /* namespace jcv */

#endif /* SRC_VISIONINSTANCEREF_H_ */
