#include <stdbool.h>
#include <stdint.h>
#include <cstdio>

#include "ErrorCode.h"
#include "ErrorCodeException.hpp"

//Implementing methods
	ErrorCodeException::ErrorCodeException(const ErrorCode er){
    _errorCode = er;
  }

  bool ErrorCodeException::isSuccess() const{
    return error_isSuccess(_errorCode); 
  }

  void ErrorCodeException::printErrorMessage() const{
		cout<<error_getErrorMessage(_errorCode)<<endl; 
	}

  void ErrorCodeException::throwErrorIfNeeded(ErrorCode er) throw(ErrorCodeException) {
    //checking success
    ErrorCodeException* exeption = new ErrorCodeException(er);
    if(!exeption->isSuccess()) {
      throw exeption;
    }
  }
