/**
 * @brief The main method and the run configurations are set in this section 
 * 
 * This is where the app is run from and where the environment gets created
 * 
 * @authors Justin Tsang, Elizabeth Shiu, Joey Gendy, Colton Undseth, Jill Chong
 * 
*/

#include "AppComponent.hpp"
#include "Bathroom.hpp"
#include "Building.hpp"


#include "controller/UserController.hpp"
#include "controller/BathroomController.hpp"
#include "controller/BuildingController.hpp"
#include "controller/RatingController.hpp"

#include "oatpp-swagger/Controller.hpp"

#include "oatpp/network/Server.hpp"

#include <iostream>


/**
 * @brief Gets endpoints and sets run configurations
 * 
*/
void run() {
  
  AppComponent components; // Create scope Environment components
  
  /* Get router component */
  OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);

  oatpp::web::server::api::Endpoints docEndpoints;

  docEndpoints.append(router->addController(UserController::createShared())->getEndpoints());
  docEndpoints.append(router->addController(BathroomController::createShared())->getEndpoints());
  docEndpoints.append(router->addController(BuildingController::createShared())->getEndpoints());
  docEndpoints.append(router->addController(RatingController::createShared())->getEndpoints());


  router->addController(oatpp::swagger::Controller::createShared(docEndpoints));

  /* Get connection handler component */
  OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, connectionHandler);

  /* Get connection provider component */
  OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, connectionProvider);

  /* create server */
  oatpp::network::Server server(connectionProvider,
                                connectionHandler);
  
  OATPP_LOGD("Server", "Running on port %s...", connectionProvider->getProperty("port").toString()->c_str());
  
  server.run();

  /* stop db connection pool */
  OATPP_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, dbConnectionProvider);
  dbConnectionProvider->stop();
  
}

/**
 * @brief main method that runs app and distroys app when terminated
 */
int main(int argc, const char * argv[]) {

  oatpp::base::Environment::init();

  run();
  
  /* Print how many objects were created during app running, and what have left-probably leaked */
  /* Disable object counting for release builds using '-D OATPP_DISABLE_ENV_OBJECT_COUNTERS' flag for better performance */
  std::cout << "\nEnvironment:\n";
  std::cout << "objectsCount = " << oatpp::base::Environment::getObjectsCount() << "\n";
  std::cout << "objectsCreated = " << oatpp::base::Environment::getObjectsCreated() << "\n\n";
  
  oatpp::base::Environment::destroy();
  
  return 0;
}