cmake_minimum_required(VERSION 3.0.0)
project(mp4-to-ascii VERSION 0.1.0)

include(CTest)
enable_testing()

AUX_SOURCE_DIRECTORY(src SOURCE_DIR) 

find_package( OpenCV REQUIRED )
add_executable(mp4-to-ascii ${SOURCE_DIR})

target_link_libraries(mp4-to-ascii ${OpenCV_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
