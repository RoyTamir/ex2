#include <stdbool.h>
#include <stdint.h>

#include "ErrorCode.h"

class ErrorCodeException : public std::exception {
private:
	ErrorCode code;

public:
	/**
	 * @brief Checks if error code indicates a success or not.
	 *
	 * @return whether the error code indicates a success or not.
	 */
	bool isSuccess();

	/**
	 * @brief Checks prints error code's error message.
	 */
	void printErrorMessage();
}
