class BMPParser {
	const char* BMP;
	BitmapHeaderParser _BHparser;
	DIBHeaderParser _DIBParser;
	ColorTableParser _CTParser;
	BitMapArrayParser _BMAParser;
public:
	char* getBMP() const;
}
