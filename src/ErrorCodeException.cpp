#include <stdbool.h>
#include <stdint.h>
#include <cstdio>

#include "ErrorCode.h"
#include "ErrorCodeException.hpp"

class ErrorCodeException {
//Fields
ErrorCode code;

//methods
public:

	ErrorCodeException(const ErrorCode code){
        this->code = code;
    }

    bool isSuccess() {
         return error_isSuccess(code); 
        }

    void printErrorMessage() {
		cout<<error_getErrorMessage(code)<<endl; 
	}
};
