
cmake_minimum_required(VERSION 3.16.0)
project(CFE_IMU_APP C)

include_directories(fsw/mission_inc)
include_directories(fsw/platform_inc)

aux_source_directory(fsw/src APP_SRC_FILES)

# Create the app module
add_cfe_app(imu_app ${APP_SRC_FILES})