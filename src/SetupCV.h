/* SetupCV.cpp
 * This file is a component of the Rockford Robotics Vision Processing System.
 * Copyright (c) 2017 Rockford Robotics, Inc.  All rights reserved.
 * THIS SOFTWARE HAS NOT YET BEEN RELEASED.
 *
 * Original Author: Logan Power, 2017, for 2017(Zuko).
 */

#ifndef SRC_SETUPCV_H_
#define SRC_SETUPCV_H_

// Workaround for working with GCC 5.4. Do not remove
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

// OpenCV Includes (with guards)
// NOTE: Not using the OpenCV library provided by WPI.  Using the builtin one for optimization purposes.
#ifndef __OPENCV_IMGPROC_HPP__
#include <opencv2/imgproc/imgproc.hpp>
#endif
#ifndef __OPENCV_CORE_HPP__
#include <opencv2/core/core.hpp>
#endif

// WPIlib Includes (with guards..?)
#ifndef NETWORKTABLE_H
#include "networktables/NetworkTable.h"
#endif
#ifndef ITABLE_H_
#include "tables/ITable.h"
#endif
#ifndef LLVM_ADT_STRINGREF_H
#include "llvm/StringRef.h"
#endif
// These are unlikely to be included anywhere else, so I will not guard them (for now)
#include "llvm/ArrayRef.h"
#include "cscore.h"

// Prototypes
cs::UsbCamera SetUsbCamera(int cameraId, cs::MjpegServer& server);
namespace jcv
{
int setupCV(int teamNumber, int streamPort);
}

#endif /* SRC_SETUPCV_H_ */
