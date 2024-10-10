/*
    This file is originally from gocv project
    Licensed: Apache 2.0 license. Copyright (c) 2017-2021 The Hybrid Group.

    Modified by Rainyl.
    Licensed: Apache 2.0 license. Copyright (c) 2024 Rainyl.
*/
#ifndef _OPENCV3_VERSION_H_
#define _OPENCV3_VERSION_H_

#ifdef __cplusplus
#include <opencv2/core.hpp>
extern "C" {
#endif

#include "core.h"

CvStatus *openCVVersion(const char **rval);
CvStatus *openCVVersion_Async(CvCallback_1 callback);

CvStatus *getBuildInfo(const char **rval);
CvStatus *getBuildInfo_Async(CvCallback_1 callback);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_VERSION_H_
