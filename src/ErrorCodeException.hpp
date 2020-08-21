#include "ErrorCode.h"

#include <exception>

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
	bool isSuccess();

	/**
	 * @brief Checks prints error code's error message.
	 */
	void printErrorMessage();
};
