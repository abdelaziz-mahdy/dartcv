#ifndef CVD_VEC_UTILS_H
#define CVD_VEC_UTILS_H

#include "dartcv/core/types.h"
#include <vector>

inline std::vector<cv::Point> vecpoint_c2cpp(VecPoint v) {
    std::vector<cv::Point> rv(v.length);
    for (int i = 0; i < v.length; i++) {
        CvPoint p = v.ptr[i];
        rv[i] = cv::Point(p.x, p.y);
    }
    return rv;
}

inline VecPoint vecpoint_cpp2c(std::vector<cv::Point> v) {
    auto* ptr = (CvPoint*)calloc(v.size(), sizeof(CvPoint));
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = CvPoint{v[i].x, v[i].y};
    }
    return VecPoint{.ptr = ptr, .length = v.size()};
}

inline VecPoint* vecpoint_cpp2c_p(std::vector<cv::Point> v) {
    auto* ptr = (CvPoint*)calloc(v.size(), sizeof(CvPoint));
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = CvPoint{v[i].x, v[i].y};
    }
    return new VecPoint{.ptr = ptr, .length = v.size()};
}

inline std::vector<cv::Point2f> vecpoint2f_c2cpp(VecPoint2f v) {
    std::vector<cv::Point2f> rv(v.length);
    for (int i = 0; i < v.length; i++) {
        CvPoint2f p = v.ptr[i];
        rv[i] = cv::Point2f(p.x, p.y);
    }
    return rv;
}

inline VecPoint2f vecpoint2f_cpp2c(std::vector<cv::Point2f> v) {
    auto* ptr = (CvPoint2f*)calloc(v.size(), sizeof(CvPoint2f));
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = CvPoint2f{v[i].x, v[i].y};
    }
    return VecPoint2f{.ptr = ptr, .length = v.size()};
}

inline void vecpoint2f_cpp2c(std::vector<cv::Point2f> v, VecPoint2f* vv) {
    if (vv->length != v.size()) {
        vv->ptr = (CvPoint2f*)realloc(vv->ptr, v.size() * sizeof(CvPoint2f));
        vv->length = v.size();
    }
    for (int i = 0; i < v.size(); i++) {
        vv->ptr[i] = CvPoint2f{v[i].x, v[i].y};
    }
}

inline VecPoint2f* vecpoint2f_cpp2c_p(std::vector<cv::Point2f> v) {
    auto* ptr = new CvPoint2f[v.size()];
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = CvPoint2f{v[i].x, v[i].y};
    }
    return new VecPoint2f{.ptr = ptr, .length = v.size()};
}

inline std::vector<cv::Point3f> vecpoint3f_c2cpp(VecPoint3f v) {
    std::vector<cv::Point3f> rv(v.length);
    for (int i = 0; i < v.length; i++) {
        CvPoint3f p = v.ptr[i];
        rv[i] = cv::Point3f(p.x, p.y, p.z);
    }
    return rv;
}

inline VecPoint3f vecpoint3f_cpp2c(std::vector<cv::Point3f> v) {
    auto* ptr = new CvPoint3f[v.size()];
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = CvPoint3f{v[i].x, v[i].y, v[i].z};
    }
    return VecPoint3f{.ptr = ptr, .length = v.size()};
}

inline VecPoint3f* vecpoint3f_cpp2c_p(std::vector<cv::Point3f> v) {
    auto* ptr = new CvPoint3f[v.size()];
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = CvPoint3f{v[i].x, v[i].y, v[i].z};
    }
    return new VecPoint3f{.ptr = ptr, .length = v.size()};
}

inline std::vector<cv::Point3i> vecpoint3i_c2cpp(VecPoint3i v) {
    std::vector<cv::Point3i> rv(v.length);
    for (int i = 0; i < v.length; i++) {
        CvPoint3i p = v.ptr[i];
        rv[i] = cv::Point3i(p.x, p.y, p.z);
    }
    return rv;
}

inline VecPoint3i vecpoint3i_cpp2c(std::vector<cv::Point3i> v) {
    auto* ptr = new CvPoint3i[v.size()];
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = CvPoint3i{v[i].x, v[i].y, v[i].z};
    }
    return VecPoint3i{.ptr = ptr, .length = v.size()};
}

inline VecPoint3i* vecpoint3i_cpp2c_p(std::vector<cv::Point3i> v) {
    auto* ptr = new CvPoint3i[v.size()];
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = CvPoint3i{v[i].x, v[i].y, v[i].z};
    }
    return new VecPoint3i{.ptr = ptr, .length = v.size()};
}

inline std::vector<std::vector<cv::Point>> vecvecpoint_c2cpp(VecVecPoint v) {
    std::vector<std::vector<cv::Point>> rv(v.length);
    for (int i = 0; i < v.length; i++) {
        VecPoint vp = v.ptr[i];
        std::vector<cv::Point> pts = vecpoint_c2cpp(vp);
        rv[i] = pts;
    }
    return rv;
}

inline VecVecPoint vecvecpoint_cpp2c(std::vector<std::vector<cv::Point>> v) {
    auto* ptr = new VecPoint[v.size()];
    for (int i = 0; i < v.size(); i++) {
        VecPoint vp = vecpoint_cpp2c(v[i]);
        ptr[i] = vp;
    }
    return VecVecPoint{.ptr = ptr, .length = v.size()};
}

inline VecVecPoint* vecvecpoint_cpp2c_p(std::vector<std::vector<cv::Point>> v) {
    auto* ptr = new VecPoint[v.size()];
    for (int i = 0; i < v.size(); i++) {
        VecPoint vp = vecpoint_cpp2c(v[i]);
        ptr[i] = vp;
    }
    return new VecVecPoint{.ptr = ptr, .length = v.size()};
}

inline std::vector<std::vector<cv::Point2f>> vecvecpoint2f_c2cpp(VecVecPoint2f v) {
    std::vector<std::vector<cv::Point2f>> rv(v.length);
    for (int i = 0; i < v.length; i++) {
        VecPoint2f vp = v.ptr[i];
        std::vector<cv::Point2f> pts = vecpoint2f_c2cpp(vp);
        rv[i] = pts;
    }
    return rv;
}

inline VecVecPoint2f vecvecpoint2f_cpp2c(std::vector<std::vector<cv::Point2f>> v) {
    auto* ptr = new VecPoint2f[v.size()];
    for (int i = 0; i < v.size(); i++) {
        VecPoint2f vp = vecpoint2f_cpp2c(v[i]);
        ptr[i] = vp;
    }
    return VecVecPoint2f{.ptr = ptr, .length = v.size()};
}

inline VecVecPoint2f* vecvecpoint2f_cpp2c_p(std::vector<std::vector<cv::Point2f>> v) {
    auto* ptr = new VecPoint2f[v.size()];
    for (int i = 0; i < v.size(); i++) {
        VecPoint2f vp = vecpoint2f_cpp2c(v[i]);
        ptr[i] = vp;
    }
    return new VecVecPoint2f{.ptr = ptr, .length = v.size()};
}

inline std::vector<std::vector<cv::Point3f>> vecvecpoint3f_c2cpp(VecVecPoint3f v) {
    std::vector<std::vector<cv::Point3f>> rv(v.length);
    for (int i = 0; i < v.length; i++) {
        VecPoint3f vp = v.ptr[i];
        std::vector<cv::Point3f> pts = vecpoint3f_c2cpp(vp);
        rv[i] = pts;
    }
    return rv;
}

inline VecVecPoint3f vecvecpoint3f_cpp2c(std::vector<std::vector<cv::Point3f>> v) {
    auto* ptr = new VecPoint3f[v.size()];
    for (int i = 0; i < v.size(); i++) {
        VecPoint3f vp = vecpoint3f_cpp2c(v[i]);
        ptr[i] = vp;
    }
    return VecVecPoint3f{.ptr = ptr, .length = v.size()};
}

inline VecVecPoint3f* vecvecpoint3f_cpp2c_p(std::vector<std::vector<cv::Point3f>> v) {
    auto* ptr = new VecPoint3f[v.size()];
    for (int i = 0; i < v.size(); i++) {
        VecPoint3f vp = vecpoint3f_cpp2c(v[i]);
        ptr[i] = vp;
    }
    return new VecVecPoint3f{.ptr = ptr, .length = v.size()};
}

inline std::vector<std::vector<cv::Point3i>> vecvecpoint3i_c2cpp(VecVecPoint3i v) {
    std::vector<std::vector<cv::Point3i>> rv(v.length);
    for (int i = 0; i < v.length; i++) {
        VecPoint3i vp = v.ptr[i];
        std::vector<cv::Point3i> pts = vecpoint3i_c2cpp(vp);
        rv[i] = pts;
    }
    return rv;
}

inline VecVecPoint3i vecvecpoint3i_cpp2c(std::vector<std::vector<cv::Point3i>> v) {
    auto* ptr = new VecPoint3i[v.size()];
    for (int i = 0; i < v.size(); i++) {
        VecPoint3i vp = vecpoint3i_cpp2c(v[i]);
        ptr[i] = vp;
    }
    return VecVecPoint3i{.ptr = ptr, .length = v.size()};
}

inline VecVecPoint3i* vecvecpoint3i_cpp2c_p(std::vector<std::vector<cv::Point3i>> v) {
    auto* ptr = new VecPoint3i[v.size()];
    for (int i = 0; i < v.size(); i++) {
        VecPoint3i vp = vecpoint3i_cpp2c(v[i]);
        ptr[i] = vp;
    }
    return new VecVecPoint3i{.ptr = ptr, .length = v.size()};
}

inline std::vector<cv::Mat> vecmat_c2cpp(VecMat v) {
    std::vector<cv::Mat> rv(v.length);
    for (int i = 0; i < v.length; i++) {
        Mat m = v.ptr[i];
        rv[i] = *m.ptr;
    }
    return rv;
}

inline VecMat vecmat_cpp2c(std::vector<cv::Mat> v) {
    Mat* ptr = new Mat[v.size()];
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = {new cv::Mat(v[i])};
    }
    return VecMat{.ptr = ptr, .length = v.size()};
}

inline VecMat* vecmat_cpp2c_p(std::vector<cv::Mat> v) {
    Mat* ptr = new Mat[v.size()];
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = {new cv::Mat(v[i])};
    }
    return new VecMat{.ptr = ptr, .length = v.size()};
}

inline std::vector<char> vecchar_c2cpp(VecChar v) {
    std::vector<char> rv(v.length);
    for (int i = 0; i < v.length; i++) {
        rv[i] = v.ptr[i];
    }
    return rv;
}

inline std::string vecchar_c2cpp_s(VecChar v) {
    return std::string(v.ptr, v.length);
}

inline VecChar vecchar_cpp2c(std::vector<char> v) {
    char* ptr = new char[v.size()];
    std::copy(v.begin(), v.end(), ptr);
    // for (int i = 0; i < v.size(); i++) { ptr[i] = v[i]; }
    return VecChar{.ptr = ptr, .length = v.size()};
}

inline VecChar* vecchar_cpp2c_p(std::vector<char> v) {
    char* ptr = new char[v.size()];
    std::copy(v.begin(), v.end(), ptr);
    // for (int i = 0; i < v.size(); i++) { ptr[i] = v[i]; }
    return new VecChar{.ptr = ptr, .length = v.size()};
}

inline VecChar vecchar_cpp2c_s(std::string v) {
    char* ptr = new char[v.size()];
    std::copy(v.begin(), v.end(), ptr);
    // for (int i = 0; i < v.size(); i++) { ptr[i] = v[i]; }
    return VecChar{.ptr = ptr, .length = v.size()};
}

inline VecChar* vecchar_cpp2c_s_p(std::string v) {
    char* ptr = new char[v.size()];
    std::copy(v.begin(), v.end(), ptr);
    // for (int i = 0; i < v.size(); i++) { ptr[i] = v[i]; }
    return new VecChar{.ptr = ptr, .length = v.size()};
}

inline std::vector<uchar> vecuchar_c2cpp(VecUChar v) {
    std::vector<uchar> rv(v.length);
    for (int i = 0; i < v.length; i++) {
        rv[i] = v.ptr[i];
    }
    return rv;
}
inline VecUChar vecuchar_cpp2c(std::vector<uchar> v) {
    auto* ptr = new uchar[v.size()];
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = v[i];
    }
    return VecUChar{.ptr = ptr, .length = v.size()};
}

inline VecUChar* vecuchar_cpp2c_p(std::vector<uchar> v) {
    auto* ptr = new uchar[v.size()];
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = v[i];
    }
    return new VecUChar{.ptr = ptr, .length = v.size()};
}

inline std::vector<std::vector<char>> vecvecchar_c2cpp(VecVecChar v) {
    std::vector<std::vector<char>> rv(v.length);
    for (int i = 0; i < v.length; i++) {
        VecChar vc = v.ptr[i];
        std::vector<char> pts = vecchar_c2cpp(vc);
        rv[i] = pts;
    }
    return rv;
}

inline std::vector<std::string> vecvecchar_c2cpp_s(VecVecChar v) {
    std::vector<std::string> rv(v.length);
    for (int i = 0; i < v.length; i++) {
        rv[i] = vecchar_c2cpp_s(v.ptr[i]);
    }
    return rv;
}

inline VecVecChar vecvecchar_cpp2c(std::vector<std::vector<char>> v) {
    auto* ptr = new VecChar[v.size()];
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = vecchar_cpp2c(v[i]);
    }
    return VecVecChar{.ptr = ptr, .length = v.size()};
}

inline VecVecChar* vecvecchar_cpp2c_p(std::vector<std::vector<char>> v) {
    auto* ptr = new VecChar[v.size()];
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = vecchar_cpp2c(v[i]);
    }
    return new VecVecChar{.ptr = ptr, .length = v.size()};
}

inline VecVecChar vecvecchar_cpp2c_s(std::vector<std::string> v) {
    auto* ptr = new VecChar[v.size()];
    for (size_t i = 0; i < v.size(); i++) {
        ptr[i] = vecchar_cpp2c_s(v[i]);
    }
    return VecVecChar{.ptr = ptr, .length = v.size()};
}

inline VecVecChar* vecvecchar_cpp2c_s_p(std::vector<std::string> v) {
    auto* ptr = new VecChar[v.size()];
    for (size_t i = 0; i < v.size(); i++) {
        ptr[i] = vecchar_cpp2c_s(v[i]);
    }
    return new VecVecChar{.ptr = ptr, .length = v.size()};
}

inline std::vector<int> vecint_c2cpp(VecI32 v) {
    std::vector<int> rv(v.length);
    for (int i = 0; i < v.length; i++) {
        rv[i] = v.ptr[i];
    }
    return rv;
}
inline VecI32 vecint_cpp2c(std::vector<int> v) {
    int* ptr = new int[v.size()];
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = v[i];
    }
    return VecI32{.ptr = ptr, .length = v.size()};
}

inline VecI32* vecint_cpp2c_p(std::vector<int> v) {
    int* ptr = new int[v.size()];
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = v[i];
    }
    return new VecI32{.ptr = ptr, .length = v.size()};
}

inline std::vector<float> vecfloat_c2cpp(VecF32 v) {
    std::vector<float> rv(v.length);
    for (int i = 0; i < v.length; i++) {
        rv[i] = v.ptr[i];
    }
    return rv;
}

inline VecF32 vecfloat_cpp2c(std::vector<float> v) {
    auto* ptr = new float[v.size()];
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = v[i];
    }
    return VecF32{.ptr = ptr, .length = v.size()};
}

inline VecF32* vecfloat_cpp2c_p(std::vector<float> v) {
    auto* ptr = new float[v.size()];
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = v[i];
    }
    return new VecF32{.ptr = ptr, .length = v.size()};
}

inline std::vector<double> vecdouble_c2cpp(VecF64 v) {
    std::vector<double> rv(v.length);
    for (int i = 0; i < v.length; i++) {
        rv[i] = v.ptr[i];
    }
    return rv;
}

inline VecF64 vecdouble_cpp2c(std::vector<double> v) {
    auto* ptr = new double[v.size()];
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = v[i];
    }
    return VecF64{.ptr = ptr, .length = v.size()};
}

inline void vecdouble_cpp2c(std::vector<double> v, VecF64* vv) {
    if (vv->length != v.size()) {
        vv->ptr = (double*)realloc(vv->ptr, v.size() * sizeof(double));
        vv->length = v.size();
    }
    for (int i = 0; i < v.size(); i++) {
        vv->ptr[i] = v[i];
    }
}

inline VecF64* vecdouble_cpp2c_p(std::vector<double> v) {
    auto* ptr = (double*)calloc(v.size(), sizeof(double));
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = v[i];
    }
    return new VecF64{.ptr = ptr, .length = v.size()};
}

inline std::vector<cv::Rect> vecrect_c2cpp(VecRect v) {
    std::vector<cv::Rect> rv(v.length);
    for (int i = 0; i < v.length; i++) {
        CvRect p = v.ptr[i];
        rv[i] = cv::Rect(p.x, p.y, p.width, p.height);
    }
    return rv;
}
inline VecRect vecrect_cpp2c(std::vector<cv::Rect> v) {
    auto* ptr = (CvRect*)calloc(v.size(), sizeof(CvRect));
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = {v[i].x, v[i].y, v[i].width, v[i].height};
    }
    return VecRect{.ptr = ptr, .length = v.size()};
}

inline void vecrect_cpp2c(std::vector<cv::Rect> v, VecRect* vv) {
    if (vv->length != v.size()) {
        vv->ptr = (CvRect*)realloc(vv->ptr, v.size() * sizeof(CvRect));
        vv->length = v.size();
    }
    for (int i = 0; i < v.size(); i++) {
        vv->ptr[i] = {v[i].x, v[i].y, v[i].width, v[i].height};
    }
}

inline VecRect* vecrect_cpp2c_p(std::vector<cv::Rect> v) {
    auto* ptr = new CvRect[v.size()];
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = {v[i].x, v[i].y, v[i].width, v[i].height};
    }
    return new VecRect{.ptr = ptr, .length = v.size()};
}

inline std::vector<cv::Rect2f> vecrect2f_c2cpp(VecRect2f v) {
    std::vector<cv::Rect2f> rv(v.length);
    for (int i = 0; i < v.length; i++) {
        CvRect2f p = v.ptr[i];
        rv[i] = cv::Rect2f(p.x, p.y, p.width, p.height);
    }
    return rv;
}
inline VecRect2f vecrect2f_cpp2c(std::vector<cv::Rect2f> v) {
    auto* ptr = (CvRect2f*)calloc(v.size(), sizeof(CvRect2f));
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = {v[i].x, v[i].y, v[i].width, v[i].height};
    }
    return VecRect2f{.ptr = ptr, .length = v.size()};
}

inline void vecrect2f_cpp2c(std::vector<cv::Rect2f> v, VecRect2f* vv) {
    if (vv->length != v.size()) {
        vv->ptr = (CvRect2f*)realloc(vv->ptr, v.size() * sizeof(CvRect2f));
        vv->length = v.size();
    }
    for (int i = 0; i < v.size(); i++) {
        vv->ptr[i] = {v[i].x, v[i].y, v[i].width, v[i].height};
    }
}

inline VecRect2f* vecrect2f_cpp2c_p(std::vector<cv::Rect2f> v) {
    auto ptr = new CvRect2f[v.size()];
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = {v[i].x, v[i].y, v[i].width, v[i].height};
    }
    return new VecRect2f{.ptr = ptr, .length = v.size()};
}

inline std::vector<cv::KeyPoint> veckeypoint_c2cpp(VecKeyPoint v) {
    std::vector<cv::KeyPoint> rv(v.length);
    for (int i = 0; i < v.length; i++) {
        KeyPoint p = v.ptr[i];
        rv[i] = cv::KeyPoint(p.x, p.y, p.size, p.angle, p.response, p.octave, p.classID);
    }
    return rv;
}
inline VecKeyPoint veckeypoint_cpp2c(std::vector<cv::KeyPoint> v) {
    auto* ptr = (KeyPoint*)calloc(v.size(), sizeof(KeyPoint));
    for (int i = 0; i < v.size(); i++) {
        auto kp = v[i];
        KeyPoint ckp = {kp.pt.x, kp.pt.y, kp.size, kp.angle, kp.response, kp.octave, kp.class_id};
        ptr[i] = ckp;
    }
    return VecKeyPoint{.ptr = ptr, .length = v.size()};
}

inline VecKeyPoint* veckeypoint_cpp2c_p(std::vector<cv::KeyPoint> v) {
    auto* ptr = new KeyPoint[v.size()];
    for (int i = 0; i < v.size(); i++) {
        auto kp = v[i];
        KeyPoint ckp = {kp.pt.x, kp.pt.y, kp.size, kp.angle, kp.response, kp.octave, kp.class_id};
        ptr[i] = ckp;
    }
    return new VecKeyPoint{.ptr = ptr, .length = v.size()};
}

inline std::vector<cv::DMatch> vecdmatch_c2cpp(VecDMatch v) {
    std::vector<cv::DMatch> rv(v.length);
    for (int i = 0; i < v.length; i++) {
        DMatch p = v.ptr[i];
        rv[i] = cv::DMatch(p.queryIdx, p.trainIdx, p.imgIdx, p.distance);
    }
    return rv;
}

inline VecDMatch vecdmatch_cpp2c(std::vector<cv::DMatch> v) {
    auto* ptr = new DMatch[v.size()];
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = {v[i].queryIdx, v[i].trainIdx, v[i].imgIdx, v[i].distance};
    }
    return VecDMatch{.ptr = ptr, .length = v.size()};
}

inline VecDMatch* vecdmatch_cpp2c_p(std::vector<cv::DMatch> v) {
    auto* ptr = new DMatch[v.size()];
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = {v[i].queryIdx, v[i].trainIdx, v[i].imgIdx, v[i].distance};
    }
    return new VecDMatch{.ptr = ptr, .length = v.size()};
}

inline std::vector<std::vector<cv::DMatch>> vecvecdmatch_c2cpp(VecVecDMatch v) {
    std::vector<std::vector<cv::DMatch>> rv(v.length);
    for (int i = 0; i < v.length; i++) {
        VecDMatch p = v.ptr[i];
        rv[i] = vecdmatch_c2cpp(p);
    }
    return rv;
}

inline VecVecDMatch vecvecdmatch_cpp2c(std::vector<std::vector<cv::DMatch>> v) {
    auto* ptr = new VecDMatch[v.size()];
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = vecdmatch_cpp2c(v[i]);
    }
    return VecVecDMatch{.ptr = ptr, .length = v.size()};
}

inline VecVecDMatch* vecvecdmatch_cpp2c_p(std::vector<std::vector<cv::DMatch>> v) {
    auto* ptr = new VecDMatch[v.size()];
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = vecdmatch_cpp2c(v[i]);
    }
    return new VecVecDMatch{.ptr = ptr, .length = v.size()};
}

inline std::vector<cv::Point2f> vecPointToVecPoint2f(VecPoint src) {
    std::vector<cv::Point2f> v(src.length);
    for (int i = 0; i < src.length; i++) {
        v[i] = cv::Point2f((float)src.ptr[i].x, (float)src.ptr[i].y);
    }
    return v;
}

inline std::vector<cv::Vec4f> vec_vec4f_c2cpp(VecVec4f v) {
    std::vector<cv::Vec4f> rv(v.length);
    for (int i = 0; i < v.length; i++) {
        Vec4f p = v.ptr[i];
        rv[i] = cv::Vec4f(p.val1, p.val2, p.val3, p.val4);
    }
    return rv;
}

inline VecVec4f vec_vec4f_cpp2c(std::vector<cv::Vec4f> v) {
    auto* ptr = new Vec4f[v.size()];
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = {v[i].val[0], v[i].val[1], v[i].val[2], v[i].val[3]};
    }
    return VecVec4f{.ptr = ptr, .length = v.size()};
}

inline VecVec4f* vec_vec4f_cpp2c_p(std::vector<cv::Vec4f> v) {
    auto* ptr = new Vec4f[v.size()];
    for (int i = 0; i < v.size(); i++) {
        ptr[i] = {v[i].val[0], v[i].val[1], v[i].val[2], v[i].val[3]};
    }
    return new VecVec4f{.ptr = ptr, .length = v.size()};
}

inline std::vector<cv::Vec6f> vec_vec6f_c2cpp(VecVec6f v) {
    std::vector<cv::Vec6f> rv(v.length);
    for (int i = 0; i < v.length; i++) {
        Vec6f p = v.ptr[i];
        rv[i] = cv::Vec6f(p.val1, p.val2, p.val3, p.val4, p.val5, p.val6);
    }
    return rv;
}

inline VecVec6f* vec_vec6f_cpp2c_p(std::vector<cv::Vec6f> v) {
    auto* ptr = new Vec6f[v.size()];
    for (int i = 0; i < v.size(); i++) {
        cv::Vec6f vec = v[i];
        ptr[i] = {vec.val[0], vec.val[1], vec.val[2], vec.val[3], vec.val[4], vec.val[5]};
    }
    return new VecVec6f{.ptr = ptr, .length = v.size()};
}

#endif  // CVD_VEC_UTILS_H
