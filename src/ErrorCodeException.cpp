#include "ErrorCodeException.hpp"

using namespace MatrixClasses;
using std::endl;
using std::cerr;

//Implementing methods
	ErrorCodeException::ErrorCodeException(const ErrorCode er) : m_errorCode(er){}

  bool ErrorCodeException::isSuccess() const{
    return error_isSuccess(m_errorCode); 
  }

  const char* ErrorCodeException::what() const noexcept{
		return error_getErrorMessage(m_errorCode); 
	}

  void ErrorCodeException::throwErrorIfNeeded(const ErrorCode er){
    //checking success
    ErrorCodeException exeption = ErrorCodeException(er);
    if(!exeption.isSuccess()) {
      throw exeption;
    }
  }
