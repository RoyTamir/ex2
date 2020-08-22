#include <string>
#include <vector>
using std::string;
using std::vector;

class ColorTableParser {

	string _str;
	vector<vector<int>> colors;

public:
	string getStr() const;
	vector<int> getColor(int n) const;
}
