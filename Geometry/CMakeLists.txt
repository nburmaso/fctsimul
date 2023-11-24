add_library(Geometry SHARED
        src/DetectorFactory.cpp
        src/GeantDetector.cpp
        src/GeantDetectorConstruction.cpp)

target_include_directories(Geometry PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

target_link_libraries(Geometry PUBLIC
        ActsCore
        ${ActsExamplesFramework}
        ${ActsExamplesGeant4}
        ${ActsPluginGeant4})

install(TARGETS Geometry
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})