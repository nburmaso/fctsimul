add_library(Reconstruction SHARED
        src/RecCKFTracks.cpp)

target_include_directories(Reconstruction PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

target_link_libraries(Reconstruction PUBLIC
        ActsCore
        ${ActsExamplesFramework}
        ${ActsExamplesCommon}
        ${ActsExamplesUtilities}
        ${ActsExamplesMagneticField}
        ${ActsExamplesIoPerformance})

install(TARGETS Reconstruction
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})