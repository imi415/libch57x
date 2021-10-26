cmake_minimum_required(VERSION 3.10)

project(libch57x)

if(NOT DEFINED LIBCH57X_DEVICE)
    message(FATAL_ERROR "Error: LIBCH57X_DEVICE not defined.")
endif()

set(LIBCH57X_SOURCES
    "lib/CMSIS_Vendor/WCH/CH57x/Source/system_ch57x.c"
)

set(LIBCH57X_INCLUDES
    "include"
    "lib/CMSIS/CMSIS/Core/Include"
    "lib/CMSIS_Vendor/WCH/CH57x/Include"
)

set(LIBCH57X_DEFINES
    "-DDEVICE_${LIBCH57X_DEVICE}"
)

add_library(${PROJECT_NAME} ${LIBCH57X_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${LIBCH57X_INCLUDES})
target_compile_definitions(${PROJECT_NAME} PUBLIC ${LIBCH57X_DEFINES})