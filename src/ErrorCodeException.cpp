#include <stdbool.h>
#include <stdint.h>
#include <cstdio>

#include "ErrorCode.h"
#include "ErrorCodeException.hpp"

//Implementing methods
	ErrorCodeException::ErrorCodeException(const ErrorCode code){
    this->code = code;
  }

  bool ErrorCodeException::isSuccess() const{
    return error_isSuccess(code); 
  }

  void ErrorCodeException::printErrorMessage() const{
		cout<<error_getErrorMessage(code)<<endl; 
	}

  void ErrorCodeException::throwErrorIfNeeded(ErrorCode er) throw(ErrorCodeException) {
    //checking success
    ErrorCodeException* exeption = new ErrorCodeException(er);
    if(!exeption->isSuccess()) {
      throw exeption;
    }
  }
  