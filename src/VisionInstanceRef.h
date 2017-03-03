/*
 * VisionInstanceRef.h
 *
 *  Created on: Mar 3, 2017
 *      Author: logan
 */

#ifndef SRC_VISIONINSTANCEREF_H_
#define SRC_VISIONINSTANCEREF_H_

#ifdef JCV_TEAM_NUMBER
const int TEAMNUMBER = JCV_TEAM_NUMBER;
#else
const int TEAMNUMBER = 0000;
#endif /* ifdef JCV_TEAM_NUMBER */

#ifdef JCV_STREAM_PORT
const int STREAMPORT = JCV_STREAM_PORT;
#else
const int STREAMPORT = 1185;
#endif /* ifdef JCV_STREAM_PORT */

#include <opencv2/core/core.hpp>
namespace jcv
{
/* VisionInstanceRef:
 * A container class for references to various
 */
class VisionInstanceRef
{
public:
	// Methods
	VisionInstanceRef();
	int setTeamNumber(int, bool);
	int setStreamPort(int, bool);
	virtual ~VisionInstanceRef();
public:
	// Public Attributes
	cs::MjpegServer* inputStreamServer;
	cs::MjpegServer* outputStreamServer;
	cs::MjpegServer* procOutputStreamServer;
	cs::UsbCamera* usbCamera;
	cs::VideoSink* usbCameraSink;
	cs::VideoSource* outputSource;
	cs::VideoSource* procOutputSource;
protected:
	// Protected Attributes
	static int teamNumber;
	int streamPort;

};

} /* namespace jcv */

#endif /* SRC_VISIONINSTANCEREF_H_ */
