#include "ErrorCodeException.hpp"

using namespace MatrixClasses;
using std::endl;
using std::cerr;

//Implementing methods
	ErrorCodeException::ErrorCodeException(const ErrorCode er) : m_errorCode(er){}

  bool ErrorCodeException::isSuccess() const{
    return error_isSuccess(m_errorCode); 
  }

  void ErrorCodeException::printErrorMessage() const{
		cerr<<error_getErrorMessage(m_errorCode)<<endl; 
	}

  void ErrorCodeException::throwErrorIfNeeded(const ErrorCode er){
    //checking success
    ErrorCodeException exeption = ErrorCodeException(er);
    if(!exeption.isSuccess()) {
      throw exeption;
    }
  }
