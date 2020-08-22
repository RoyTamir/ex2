class BMPParser {

    const char* _BMP;
    BitmapHeaderParser _BHparser;
    DIBHeaderParser _DIBParser;
    ColorTableParser _CTParser;
    BitMapArrayParser _BMAParser;

public:
	BMPParser(char* BMP) {
		this._BMP = BMP;
	}

    char* getBMP() const {
		return _BMP;
	}
}
