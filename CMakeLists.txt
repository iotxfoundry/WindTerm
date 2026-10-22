cmake_minimum_required(VERSION 3.16)

project(WindTermGuiSkeleton LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

# 确定性双 Qt 探测：NAMES 习惯写法在双 Qt 共存系统上会被 Qt6 抢先，改为显式次序
find_package(Qt5 QUIET COMPONENTS Widgets)
if(Qt5_FOUND)
  set(QT_VERSION_MAJOR 5)
else()
  find_package(Qt6 QUIET COMPONENTS Widgets)
  set(QT_VERSION_MAJOR 6)
endif()
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE PROJECT_HEADERS CONFIGURE_DEPENDS src/*.h)

add_executable(WindTermGuiSkeleton ${PROJECT_SOURCES} ${PROJECT_HEADERS})
set_target_properties(WindTermGuiSkeleton PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
target_include_directories(WindTermGuiSkeleton PRIVATE src)
target_link_libraries(WindTermGuiSkeleton PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
