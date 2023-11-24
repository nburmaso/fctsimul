add_library(Simulation SHARED
        src/GeantSimulator.cpp
        src/GeantActionInitialization.cpp
        src/GeantSimulationDataFormats.cpp
        src/GeantSimulationWorld.cpp
        src/GeantRunAction.cpp
        src/GeantEventAction.cpp
        src/GeantPrimaryGeneratorAction.cpp
        src/GeantTrack.cpp
        src/GeantMcPoint.cpp
        src/GeantHit.cpp
        src/GeantSteppingAction.cpp)

target_include_directories(Simulation PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

target_link_libraries(Simulation PUBLIC
        Geometry
        ActsCore
        ${ActsExamplesFramework}
        ${ActsExamplesGeant4}
        ${ActsPluginGeant4})

install(TARGETS Simulation
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})