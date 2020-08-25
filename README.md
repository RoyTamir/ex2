# ex2

## part 1 - wrapper of ex1:

We made an ErrorCodeException exception class that has an ErrorCode field.
The exception gets thrown whenever the returned ErrorCode of a function from ex1 isn't 0 (success).

We made a MatrixClass class with a PMatrix field.
We used delegation to get all of the original functionality of ex1.
All of MatrixClass's functions are operators except for constructors, destructors, getHeight,
getHeight, and setValue.

## part 2 - BMP file parsing:

We created a BMPParser class.
BMPParser's fields are a string (the text in the BMP file) and parsers for each of the BMP's parts.

BMP files have 4 parts and we created a parser for each one of them:

DIB header: We created a DIBHeaderParser class to read and store all of the DIB header's
important information.

Bitmap array header: We created a BitmapHeaderParser class to read and store all of the 
bitmap header's important information.

ColorTableParser: We created a ColorTableparser class to read and store all of the 
color table header's important information. This part is only needed if the bit map has 8 bits per pixel.

Bitmap array: We created a bitmap array class to read and store all of the 
bitmap array's important information for 2 different formats: 8 bits per pixel and 24 bits per pixel.

These parsers let us interpret the BMP file and we can the information to write new BMP files as such:

To turn a picture clockwise:
> 1. We change the header parts of the string to accomodate for the rotated
>    matrix's new dimensions and make sure that it is a 24 bit per pixel BMP.
> 2. We then make a new bitmap array parser with a bitmap array parser method that
>    return a new bit map array parser with a rotated bitmap array.
> 3. We then concatenate the string from step 1 with the bitmap array parser from step 2's
>    str field to get the new BMP text of the rotated picture.

To turn a picture gray we follow the same steps except we use a different method in step 2.
