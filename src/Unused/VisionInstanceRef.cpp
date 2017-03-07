/*
 * VisionInstanceRef.cpp
 *
 *  Created on: Mar 3, 2017
 *      Author: logan
 */

#include "VisionInstanceRef.h"

namespace jcv
{

VisionInstanceRef::VisionInstanceRef()
{
	VisionInstanceRef::teamNumber = TEAMNUMBER;
	VisionInstanceRef::streamPort = STREAMPORT;

}

int VisionInstanceRef::setTeamNumber(int newTeamNumber, bool justReturn = false)
{
	int oldNumber = VisionInstanceRef::teamNumber;
	if (!justReturn)
	{
		VisionInstanceRef::teamNumber = newTeamNumber;
	}
	return oldNumber;

}

int VisionInstanceRef::setStreamPort(int newPort, bool justReturn = false)
{
	int oldPort = VisionInstanceRef::streamPort;
	if (!justReturn)
	{
		VisionInstanceRef::streamPort = newPort;
	}
	return oldPort;

}

VisionInstanceRef::~VisionInstanceRef()
{
	// TODO Auto-generated destructor stub
}

} /* namespace jcv */
