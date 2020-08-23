class Color {

    int _R;
    int _G;
    int _B;

public:
	Color(int R, int G, int B) {
		this._R = R;
		this._G = G;
		this._B = B;
	}

    int getR() const {
		return R;
	}

    int getG() const {
		return G;
	}

    int getB() const {
		return B;
	}
}
