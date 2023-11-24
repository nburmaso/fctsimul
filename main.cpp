#include "Acts/Definitions/Units.hpp"
#include "Acts/MagneticField/BFieldMapUtils.hpp"
#include "Acts/MagneticField/ConstantBField.hpp"
#include "Acts/MagneticField/MagneticFieldProvider.hpp"
#include "GeantDetectorConstruction.hpp"
#include "GeantSimulationWorld.hpp"
#include "GeantSimulator.hpp"

#include "plog/Appenders/ColorConsoleAppender.h"
#include "plog/Formatters/TxtFormatter.h"
#include "plog/Init.h"
#include "plog/Log.h"

using namespace Acts::UnitLiterals;
using namespace FCTGeometry;

int main(int argc, char* argv[])
{
  static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
  plog::init(plog::verbose, &consoleAppender);

  Simulation::DetectorPars::nLayers = 9;

  Simulation::DetectorPars::layersZ = {-442.0, -444.0, -446.0, -448.0, -450.0,
                                       -460.0, -470.0, -480.0, -490.0};
  Simulation::DetectorPars::layersInR = {6.0, 6.0, 6.0, 6.0, 6.1,
                                         6.2, 6.3, 6.5, 6.6};
  Simulation::DetectorPars::layersOutR = {44.1, 44.3, 44.5, 44.7, 44.9,
                                          45.9, 46.9, 47.9, 48.9};

  Simulation::GeantSimulator::runSimulation(argc, argv);

  // auto* detConstruction = new GeantDetectorConstruction();
  // detConstruction->layersZ = &Simulation::DetectorPars::layersZ;
  // detConstruction->layersInR = &Simulation::DetectorPars::layersInR;
  // detConstruction->layersOutR = &Simulation::DetectorPars::layersOutR;
  // auto* physWorld = detConstruction->Construct();
  //
  // GeantDetector::Config cfg{};
  // cfg.name = "FCT";
  // cfg.g4World = physWorld;
  // cfg.g4SurfaceOptions.sensitiveSurfaceSelector =
  //   std::make_shared<Acts::Geant4PhysicalVolumeSelectors::AllSelector>();
  //
  // auto logger =
  //   Acts::getDefaultLogger("log", Acts::Logging::Level::INFO, &std::cout);
  //
  // GeantDetector det{};
  // auto [trackingGeometryPtr, contextDecorators, detectorElements] =
  //   det.constructTrackingGeometry(cfg, *logger);
  //
  // Acts::Vector3 field(0.0 * Acts::UnitConstants::T,
  //                     0.5 * Acts::UnitConstants::T,
  //                     0.0 * Acts::UnitConstants::T);
  // auto constMagField = std::make_shared<Acts::ConstantBField>(field);

  // setup the fitter
  // const double reverseFilteringMomThreshold = 0.0;
  // TrackFittingAlgorithm::Config fitter;
  // fitter.inputMeasurements = digiCfg.outputMeasurements;
  // fitter.inputSourceLinks = digiCfg.outputSourceLinks;
  // fitter.inputProtoTracks = trackFinderCfg.outputProtoTracks;
  // if (dirNav) {
  //   fitter.inputProtoTracks = sorterCfg.outputProtoTracks;
  // }
  // fitter.inputInitialTrackParameters =
  //     particleSmearingCfg.outputTrackParameters;
  // fitter.outputTracks = "tracks";
  // fitter.directNavigation = dirNav;
  // fitter.pickTrack = vm["fit-pick-track"].as<int>();
  // fitter.trackingGeometry = trackingGeometry;
  // fitter.fit = makeKalmanFitterFunction(
  //     trackingGeometry, magneticField,
  //     vm["fit-multiple-scattering-correction"].as<bool>(),
  //     vm["fit-energy-loss-correction"].as<bool>(),
  //     reverseFilteringMomThreshold, Acts::FreeToBoundCorrection(
  //         vm["fit-ftob-nonlinear-correction"].as<bool>()));
  // sequencer.addAlgorithm(
  //     std::make_shared<TrackFittingAlgorithm>(fitter, logLevel));

  return 0;
}