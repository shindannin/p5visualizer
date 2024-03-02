using namespace std;

//----------- p5visualizerのマクロ Version 1.0（ここから） -------------
#define VISUALIZE // 提出時にはここをコメントアウトすること。そうしないとTLEする。

#ifdef VISUALIZE
std::ofstream sVisStream("VisCommands.txt");

// ビジュアライザ上で表示される時間を指定します
inline void time(int t) {
	sVisStream << "time = " << t << ";" << std::endl;
}

// ビジュアライザ上で常に表示されます
inline void always() {
	time(-1);
}

inline void setSingleColor(int colorOrGray, int alpha = 255) {
	sVisStream << colorOrGray;
	if (alpha < 255) {
		sVisStream << ", " << alpha;
	}
}

inline void setRGBColor(int r, int g, int b, int alpha = 255) {
	sVisStream << r << ", " << g << ", " << b;
	if (alpha < 255) {
		sVisStream << ", " << alpha;
	}
}

// リファレンス https://p5js.org/reference/ 
// Web上のエディタ https://editor.p5js.org/


//---------- Shape : 2D Primitives ----------
inline void arc(float x, float y, float w, float h, float start, float stop) {
	sVisStream << "arc(" << x << ", " << y << ", " << w << ", " << h << ", " << start << ", " << stop << ");" << std::endl;
}

inline void ellipse(float x, float y, float w, float h) {
	sVisStream << "ellipse(" << x << ", " << y << ", " << w << ", " << h << ");" << std::endl;
}

inline void circle(float x, float y, float d) {
	sVisStream << "circle(" << x << ", " << y << ", " << d << ");" << std::endl;
}

inline void line(float x1, float y1, float x2, float y2) {
	sVisStream << "line(" << x1 << ", " << y1 << ", " << x2 << ", " << y2 << ");" << std::endl;
}

inline void point(float x, float y) {
	sVisStream << "point(" << x << ", " << y << ");" << std::endl;
}

inline void quad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
	sVisStream << "quad(" << x1 << ", " << y1 << ", " << x2 << ", " << y2 << ", " << x3 << ", " << y3 << ", " << x4 << ", " << y4 << ");" << std::endl;
}

inline void rect(float x, float y, float w, float h) {
	sVisStream << "rect(" << x << ", " << y << ", " << w << ", " << h << ");" << std::endl;
}

inline void square(float x, float y, float s) {
	sVisStream << "square(" << x << ", " << y << ", " << s << ");" << std::endl;
}

inline void triangle(float x1, float y1, float x2, float y2, float x3, float y3) {
	sVisStream << "triangle(" << x1 << ", " << y1 << ", " << x2 << ", " << y2 << ", " << x3 << ", " << y3 << ");" << std::endl;
}

//---------- Color : Setting ----------
inline void background(int gray, int alpha = 255) {
	sVisStream << "background(";
	setSingleColor(gray, alpha);
	sVisStream << ");" << std::endl;
}

inline void background(int r, int g, int b, int alpha = 255) {
	sVisStream << "background(";
	setRGBColor(r, g, b, alpha);
	sVisStream << ");" << std::endl;
}

inline void background(const std::string& value) {
	sVisStream << "background(\"" << value << "\");" << std::endl;
}

inline void clear() {
	sVisStream << "clear();" << std::endl;
}

inline void colorMode(const std::string& mode, int max1, int max2, int max3, int maxA) {
	sVisStream << "colorMode(" << mode << ", " << max1 << ", " << max2 << ", " << max3 << ", " << maxA << ");" << std::endl;
}

inline void fill(int gray, int alpha = 255) {
	sVisStream << "fill(";
	setSingleColor(gray, alpha);
	sVisStream << ");" << std::endl;
}

inline void fill(int r, int g, int b, int alpha = 255) {
	sVisStream << "fill(";
	setRGBColor(r, g, b, alpha);
	sVisStream << ");" << std::endl;
}

inline void fill(const std::string& value) {
	sVisStream << "fill(\"" << value << "\");" << std::endl;
}

inline void noFill() {
	sVisStream << "noFill();" << std::endl;
}

inline void noStroke() {
	sVisStream << "noStroke();" << std::endl;
}

inline void stroke(int gray, int alpha = 255) {
	sVisStream << "stroke(";
	setSingleColor(gray, alpha);
	sVisStream << ");" << std::endl;
}

inline void stroke(int r, int g, int b, int alpha = 255) {
	sVisStream << "stroke(";
	setRGBColor(r, g, b, alpha);
	sVisStream << ");" << std::endl;
}

inline void stroke(const std::string& value) {
	sVisStream << "stroke(\"" << value << "\");" << std::endl;
}

inline void erase() {
	sVisStream << "erase();" << std::endl;
}

inline void noErase() {
	sVisStream << "noErase();" << std::endl;
}

//---------- Typography ----------
inline void textAlign(const std::string& alignX, const std::string& alignY = "") {
	if (alignY.empty()) {
		sVisStream << "textAlign(" << alignX << ");" << std::endl;
	} else {
		sVisStream << "textAlign(" << alignX << ", " << alignY << ");" << std::endl;
	}
}

inline void textLeading(float leading) {
	sVisStream << "textLeading(" << leading << ");" << std::endl;
}

inline void textSize(float size) {
	sVisStream << "textSize(" << size << ");" << std::endl;
}

inline void textStyle(const std::string& style) {
	sVisStream << "textStyle(" << style << ");" << std::endl;
}

inline void textWidth(const std::string& text) {
	sVisStream << "textWidth(" << text << ");" << std::endl;
}

inline void textAscent() {
	sVisStream << "textAscent();" << std::endl;
}

inline void textDescent() {
	sVisStream << "textDescent();" << std::endl;
}

inline void textWrap(const std::string& wrap) {
	sVisStream << "textWrap(" << wrap << ");" << std::endl;
}

inline void text(const std::string& str, float x, float y) {
	sVisStream << "text(\"" << str << "\", " << x << ", " << y << ");" << std::endl;
}

inline void textFont(const std::string& fontName) {
	sVisStream << "textFont(\"" << fontName << "\");" << std::endl;
}

#else //  VISUALIZE

inline void time(int t) {}
inline void always() {}
inline void setSingleColor(int colorOrGray, int alpha = 255) {}
inline void setRGBColor(int r, int g, int b, int alpha = 255) {}

//---------- Shape : 2D Primitives ----------
inline void arc(float x, float y, float w, float h, float start, float stop) {}
inline void ellipse(float x, float y, float w, float h) {}
inline void circle(float x, float y, float d) {}
inline void line(float x1, float y1, float x2, float y2) {}
inline void point(float x, float y) {}
inline void quad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {}
inline void rect(float x, float y, float w, float h) {}
inline void square(float x, float y, float s) {}
inline void triangle(float x1, float y1, float x2, float y2, float x3, float y3) {}

//---------- Color : Setting ----------
inline void background(int gray, int alpha = 255) {}
inline void background(int r, int g, int b, int alpha = 255) {}
inline void background(const std::string& value) {}
inline void clear() {}
inline void colorMode(const std::string& mode, int max1, int max2, int max3, int maxA) {}
inline void fill(int gray, int alpha = 255) {}
inline void fill(int r, int g, int b, int alpha = 255) {}
inline void fill(const std::string& value) {}
inline void noFill() {}
inline void noStroke() {}
inline void stroke(int gray, int alpha = 255) {}
inline void stroke(int r, int g, int b, int alpha = 255) {}
inline void stroke(const std::string& value) {}
inline void erase() {}
inline void noErase() {}

//---------- Typography ----------
inline void textAlign(const std::string& alignX, const std::string& alignY = "") {}
inline void textLeading(float leading) {}
inline void textSize(float size) {}
inline void textStyle(const std::string& style) {}
inline void textWidth(const std::string& text) {}
inline void textAscent() {}
inline void textDescent() {}
inline void textWrap(const std::string& wrap) {}
inline void text(const std::string& str, float x, float y) {}
inline void textFont(const std::string& fontName) {}

#endif // VISUALIZE
//----------- p5visualizerのマクロ（ここまで） -------------
