#include "ErrorCode.h"

#include <exception>
#include <iostream>

using std::endl;
using std::cout;

class ErrorCodeException {
//Fields
ErrorCode code;

//methods
public:

	/**
 	* @brief Construct a new ErrorCodeException object.
 	* 
 	* @param code The ErrorCode.
 	*/
	ErrorCodeException(const ErrorCode code);

	/**
	 * @brief Checks if error code indicates a success or not.
	 *
	 * @return whether the error code indicates a success or not.
	 */
	bool isSuccess() const;

	/**
	 * @brief Checks prints error code's error message.
	 */
	void printErrorMessage() const;

	/**
	 * @brief Destroy the ErrorCodeException object.
	 * 
	 */
	~ErrorCodeException() = default;
};
