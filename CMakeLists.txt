cmake_minimum_required(VERSION 3.16)
project(fct_acts)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "-O0 -g")

# alice soft installation path
set(SW_DIR /home/nburmaso/alice/sw)
set(ARCH ubuntu2004_x86-64)

# add packages and libs
find_package(ROOT REQUIRED)
include(${ROOT_USE_FILE})

find_package(Geant4 REQUIRED)
include(${Geant4_USE_FILE})

find_package(Eigen3 REQUIRED
        HINTS "${SW_DIR}/${ARCH}/Eigen3/latest")

find_package(Acts REQUIRED)

find_library(ActsExamplesFramework "ActsExamplesFramework"
        PATH_SUFFIXES "lib"
        HINTS "${SW_DIR}/${ARCH}/acts/latest")

find_library(ActsExamplesGeant4 "ActsExamplesGeant4"
        PATH_SUFFIXES "lib"
        HINTS "${SW_DIR}/${ARCH}/acts/latest")

find_library(ActsPluginGeant4 "ActsPluginGeant4"
        PATH_SUFFIXES "lib"
        HINTS "${SW_DIR}/${ARCH}/acts/latest")

# make user libs

add_subdirectory(Logger)
add_subdirectory(Geometry)
add_subdirectory(Simulation)
#add_subdirectory(Reconstruction)


# main exec
add_executable(main main.cpp)

target_link_libraries(main PUBLIC
        plog
        Geometry
        Simulation
        ActsCore
        ${Geant4_LIBRARIES}
        ${ROOT_LIBRARIES})

# copy run macros
set(SCRIPTS Resources/run.mac)

foreach (_script ${SCRIPTS})
    configure_file(${PROJECT_SOURCE_DIR}/${_script}
            ${PROJECT_BINARY_DIR}/${_script}
            COPYONLY)
endforeach ()