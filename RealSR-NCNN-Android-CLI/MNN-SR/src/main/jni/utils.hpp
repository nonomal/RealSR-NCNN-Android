//
// Created by Yazii on 2025/3/30.
//
#ifndef REALSR_NCNN_ANDROID_CLI_UTILS_HPP
#define REALSR_NCNN_ANDROID_CLI_UTILS_HPP

#include <string>
#include "MNN/Tensor.hpp"
#include "MNN/Interpreter.hpp"
#include "MNN/ImageProcess.hpp"

using namespace MNN;

/**
 * 获取MNN后端类型的可读名称
 * @param backend_type MNNForwardType枚举值
 * @return 后端名称字符串（如"CPU"），未知类型返回数字字符串
 */
static std::string get_backend_name(MNNForwardType backend_type) {
    switch (backend_type) {
        case MNN_FORWARD_CPU:
            return "CPU";
        case MNN_FORWARD_CPU_EXTENSION:
            return "CPU Extension";
        case MNN_FORWARD_OPENCL:
            return "OpenCL";
        case MNN_FORWARD_OPENGL:
            return "OpenGL";
        case MNN_FORWARD_VULKAN:
            return "Vulkan";
        case MNN_FORWARD_METAL:
            return "Metal";
        case MNN_FORWARD_CUDA:
            return "CUDA";
        case MNN_FORWARD_NN:
            return "NN API";
        default:
            return std::to_string(static_cast<int>(backend_type));
    }
}


static std::string float2str(float f) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2);
    if (f >= 10000000000000000.0f) {
        oss << (f / 10000000000000000.0f) << " E";
    } else if (f >= 1000000000000000.0f) {
        oss << (f / 1000000000000000.0f) << " P";
    } else if (f >= 1000000000000.0f) {
        oss << (f / 1000000000000.0f) << " T";
    } else if (f >= 1000000000.0f) {
        oss << (f / 1000000000.0f) << " G";
    } else if (f >= 1000000.0f) {
        oss << (f / 1000000.0f) << " M";
    } else if (f >= 1000.0f) {
        oss << (f / 1000.0f) << " K";
    } else {
        oss << f;
    }

    return oss.str();
}


static std::string float2str(float v, int unit) {
    float f = v * pow(10, unit);
    return float2str(f);
}


typedef enum {
    UnSet = 0,
    RGB     = 1,
    BGR      = 2,
    RGBA      = 3,
    BGRA     = 4,
    YCbCr    = 5,
    YUV      = 6,
    GRAY = 10,
    Gray2YCbCr = 11,
    Gray2YUV = 12,
} ColorType;


inline const char* colorTypeToStr(ColorType type) {
    switch (type) {
        case RGB: return "RGB";
        case BGR: return "BGR";
        case RGBA: return "RGBA";
        case BGRA: return "BGRA";
        case YCbCr: return "YCbCr";
        case YUV: return "YUV";
        case GRAY: return "GRAY";
        case Gray2YCbCr: return "Gray2YCbCr";
        case Gray2YUV: return "Gray2YUV";
        default: return "UNKNOWN";
    }
}



#endif //REALSR_NCNN_ANDROID_CLI_UTILS_HPP