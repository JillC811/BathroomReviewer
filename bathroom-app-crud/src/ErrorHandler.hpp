
#ifndef CRUD_ERRORHANDLER_HPP
#define CRUD_ERRORHANDLER_HPP

#include "dto/StatusDto.hpp"

#include "oatpp/web/server/handler/ErrorHandler.hpp"
#include "oatpp/web/protocol/http/outgoing/ResponseFactory.hpp"


/**
 * @brief error handler object class
 * 
 * @authors Justin Tsang, Elizabeth Shiu, Joey Gendy, Colton Undseth, Jill Chong
*/
class ErrorHandler : public oatpp::web::server::handler::ErrorHandler {
private:
  typedef oatpp::web::protocol::http::outgoing::Response OutgoingResponse;
  typedef oatpp::web::protocol::http::Status Status;
  typedef oatpp::web::protocol::http::outgoing::ResponseFactory ResponseFactory;
private:
  std::shared_ptr<oatpp::data::mapping::ObjectMapper> m_objectMapper;
public:

  /** @brief Error catcher for API fetch errors and other application errors
   *
   * @param status: error status text
   * @param code: error code
   * @param message: error message
   * 
   */
  ErrorHandler(const std::shared_ptr<oatpp::data::mapping::ObjectMapper>& objectMapper);

  std::shared_ptr<OutgoingResponse>
  handleError(const Status& status, const oatpp::String& message, const Headers& headers) override;

};


#endif //CRUD_ERRORHANDLER_HPP
