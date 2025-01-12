#ifndef CVD_FEATURES2D_UTILS_H
#define CVD_FEATURES2D_UTILS_H

#include "dartcv/features2d/features2d.h"
#include <opencv2/features2d.hpp>

inline cv::SimpleBlobDetector::Params SimpleBlobDetectorParams_c2cpp(SimpleBlobDetectorParams params)
{
  cv::SimpleBlobDetector::Params converted;

  converted.blobColor = params.blobColor;
  converted.filterByArea = params.filterByArea;
  converted.filterByCircularity = params.filterByCircularity;
  converted.filterByColor = params.filterByColor;
  converted.filterByConvexity = params.filterByConvexity;
  converted.filterByInertia = params.filterByInertia;
  converted.maxArea = params.maxArea;
  converted.maxCircularity = params.maxCircularity;
  converted.maxConvexity = params.maxConvexity;
  converted.maxInertiaRatio = params.maxInertiaRatio;
  converted.maxThreshold = params.maxThreshold;
  converted.minArea = params.minArea;
  converted.minCircularity = params.minCircularity;
  converted.minConvexity = params.minConvexity;
  converted.minDistBetweenBlobs = params.minDistBetweenBlobs;
  converted.minInertiaRatio = params.minInertiaRatio;
  converted.minRepeatability = params.minRepeatability;
  converted.minThreshold = params.minThreshold;
  converted.thresholdStep = params.thresholdStep;

  return converted;
}

inline SimpleBlobDetectorParams SimpleBlobDetectorParams_cpp2c(cv::SimpleBlobDetector::Params params)
{
  SimpleBlobDetectorParams converted;

  converted.blobColor = params.blobColor;
  converted.filterByArea = params.filterByArea;
  converted.filterByCircularity = params.filterByCircularity;
  converted.filterByColor = params.filterByColor;
  converted.filterByConvexity = params.filterByConvexity;
  converted.filterByInertia = params.filterByInertia;
  converted.maxArea = params.maxArea;
  converted.maxCircularity = params.maxCircularity;
  converted.maxConvexity = params.maxConvexity;
  converted.maxInertiaRatio = params.maxInertiaRatio;
  converted.maxThreshold = params.maxThreshold;
  converted.minArea = params.minArea;
  converted.minCircularity = params.minCircularity;
  converted.minConvexity = params.minConvexity;
  converted.minDistBetweenBlobs = params.minDistBetweenBlobs;
  converted.minInertiaRatio = params.minInertiaRatio;
  converted.minRepeatability = params.minRepeatability;
  converted.minThreshold = params.minThreshold;
  converted.thresholdStep = params.thresholdStep;

  return converted;
}

#endif // CVD_FEATURES2D_UTILS_H
