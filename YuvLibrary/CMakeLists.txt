cmake_minimum_required(VERSION 3.4.1)

PROJECT(YuvLibrary)

#SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../app/src/main/jniLibs/${ANDROID_ABI})

SET(SRC_LIST
                    src/main/cpp/source/compare.cc
                    src/main/cpp/source/compare_common.cc
                    src/main/cpp/source/compare_neon64.cc
                    src/main/cpp/source/compare_gcc.cc
                    src/main/cpp/source/convert.cc
                    src/main/cpp/source/convert_argb.cc
                    src/main/cpp/source/convert_from.cc
                    src/main/cpp/source/convert_from_argb.cc
                    src/main/cpp/source/convert_to_argb.cc
                    src/main/cpp/source/convert_to_i420.cc
                    src/main/cpp/source/cpu_id.cc
                    src/main/cpp/source/planar_functions.cc
                    src/main/cpp/source/rotate.cc
                    src/main/cpp/source/rotate_any.cc
                    src/main/cpp/source/rotate_argb.cc
                    src/main/cpp/source/rotate_common.cc
                    src/main/cpp/source/rotate_mips.cc
                    src/main/cpp/source/rotate_neon64.cc
                    src/main/cpp/source/rotate_gcc.cc
                    src/main/cpp/source/row_any.cc
                    src/main/cpp/source/row_common.cc
                    src/main/cpp/source/row_mips.cc
                    src/main/cpp/source/row_neon64.cc
                    src/main/cpp/source/row_gcc.cc
                    src/main/cpp/source/scale.cc
                    src/main/cpp/source/scale_any.cc
                    src/main/cpp/source/scale_argb.cc
                    src/main/cpp/source/scale_common.cc
                    src/main/cpp/source/scale_mips.cc
                    src/main/cpp/source/scale_neon64.cc
                    src/main/cpp/source/scale_gcc.cc
                    src/main/cpp/source/video_common.cc
    )


IF(${ANDROID_ABI} MATCHES "armeabi-v7a")
    MESSAGE("building armeabi-v7a        ------------------------")
    SET(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -DLIBYUV_NEON")
    SET(SRC_LIST
                ${SRC_LIST}
                src/main/cpp/source/compare_neon.cc
                src/main/cpp/source/rotate_neon.cc
                src/main/cpp/source/row_neon.cc
                src/main/cpp/source/scale_neon.cc
    )
ELSE(${ANDROID_ABI} MATCHES "arm64-v8a")
        MESSAGE("building arm64-v8a        ------------------------")
        SET(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -DLIBYUV_NEON")
        SET(SRC_LIST
                    ${SRC_LIST}
                    src/main/cpp/source/compare_neon64.cc
                    src/main/cpp/source/rotate_neon64.cc
                    src/main/cpp/source/row_neon64.cc
                    src/main/cpp/source/scale_neon64.cc
        )
ELSE(${ANDROID_ABI} MATCHES "x86" OR ${ANDROID_ABI} MATCHES "x86_64")
        MESSAGE("building x86 or  x86_64   ------------------------")
        SET(SRC_LIST
                    ${SRC_LIST}
                    src/main/cpp/source/compare_gcc.cc
                    src/main/cpp/source/rotate_gcc.cc
                    src/main/cpp/source/row_gcc.cc
                    src/main/cpp/source/scale_gcc.cc
        )
ENDIF()

find_library(log-lib log)

ADD_LIBRARY(yuv SHARED ${SRC_LIST} src/main/cpp/libyuv.cpp)


TARGET_LINK_LIBRARIES(yuv ${log-lib})

