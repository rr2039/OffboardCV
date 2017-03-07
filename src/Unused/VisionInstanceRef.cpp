/*
 * VisionInstanceRef.cpp
 *
 *  Created on: Mar 3, 2017
 *      Author: logan
 */

#include "VisionInstanceRef.h"

namespace jcv
{

#ifdef JCV_TEAM_NUMBER
VisionInstanceRef::VisionInstanceRef(int team, int port)
{
	VisionInstanceRef::teamNumber = TEAMNUMBER;
	VisionInstanceRef::streamPort = STREAMPORT;

}
#else
VisionInstanceRef::VisionInstanceRef(int team, int port)
{
	VisionInstanceRef::teamNumber = team;
	VisionInstanceRef::streamPort = port;
}
#endif /* JCV_TEAM_NUMBER */

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

} /* namespace jcv */
