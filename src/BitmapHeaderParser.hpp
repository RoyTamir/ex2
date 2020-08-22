class BitmapHeaderParser {

	const char* _str;
	const int _size;
	const int _offset;

private:
	char* getStr() const;
	int getSize() const;
	int getOffset() const;
}
