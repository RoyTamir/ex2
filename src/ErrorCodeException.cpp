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
    /**
     * @brief Checks if error code indicates a success or not.
     *
     * @return whether the error code indicates a success or not.
     */
    bool isSuccess() {
         return error_isSuccess(code); 
        }

    /**
     * @brief Checks prints error code's error message.
     */
    void printErrorMessage() {
		cout<<error_getErrorMessage(code)<<endl; 
	}
};
