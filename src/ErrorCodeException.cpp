#include <stdbool.h>
#include <stdint.h>
#include <cstdio>

#include "ErrorCode.h"
#include "ErrorCodeException.hpp"

class ErrorCodeException : public std::exception {
private:
    ErrorCode code;

public:
    /**
     * @brief Checks if error code indicates a success or not.
     *
     * @return whether the error code indicates a success or not.
     */
    bool isSuccess() { return !code };

    /**
     * @brief Checks prints error code's error message.
     */
    void printErrorMessage() {
		cout << error_getErrorMessage(code) << std::endl; 
	}
}
