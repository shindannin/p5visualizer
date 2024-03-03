using namespace std;

//----------- p5visualizerのマクロ Version 1.1（ここから） -------------
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

//---------- Shape : Attributes ----------
inline void ellipseMode(const std::string& mode) {
	sVisStream << "ellipseMode(" << mode << ");" << std::endl;
}

inline void noSmooth() {
	sVisStream << "noSmooth();" << std::endl;
}

inline void rectMode(const std::string& mode) {
	sVisStream << "rectMode(" << mode << ");" << std::endl;
}

inline void smooth() {
	sVisStream << "smooth();" << std::endl;
}

inline void strokeCap(const std::string& cap) {
	sVisStream << "strokeCap(" << cap << ");" << std::endl;
}

inline void strokeJoin(const std::string& join) {
	sVisStream << "strokeJoin(" << join << ");" << std::endl;
}

inline void strokeWeight(float weight) {
	sVisStream << "strokeWeight(" << weight << ");" << std::endl;
}

//---------- Shape : Curves ----------
inline void bezier(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
	sVisStream << "bezier(" << x1 << ", " << y1 << ", " << x2 << ", " << y2 << ", "
		<< x3 << ", " << y3 << ", " << x4 << ", " << y4 << ");" << std::endl;
}

inline void bezierDetail(int detail) {
	sVisStream << "bezierDetail(" << detail << ");" << std::endl;
}

inline void bezierPoint(float a, float b, float c, float d, float t) {
	sVisStream << "bezierPoint(" << a << ", " << b << ", " << c << ", " << d << ", " << t << ");" << std::endl;
}

inline void bezierTangent(float a, float b, float c, float d, float t) {
	sVisStream << "bezierTangent(" << a << ", " << b << ", " << c << ", " << d << ", " << t << ");" << std::endl;
}

inline void curve(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
	sVisStream << "curve(" << x1 << ", " << y1 << ", " << x2 << ", " << y2 << ", "
		<< x3 << ", " << y3 << ", " << x4 << ", " << y4 << ");" << std::endl;
}

inline void curveDetail(int detail) {
	sVisStream << "curveDetail(" << detail << ");" << std::endl;
}

inline void curveTightness(float tightness) {
	sVisStream << "curveTightness(" << tightness << ");" << std::endl;
}

inline void curvePoint(float a, float b, float c, float d, float t) {
	sVisStream << "curvePoint(" << a << ", " << b << ", " << c << ", " << d << ", " << t << ");" << std::endl;
}

inline void curveTangent(float a, float b, float c, float d, float t) {
	sVisStream << "curveTangent(" << a << ", " << b << ", " << c << ", " << d << ", " << t << ");" << std::endl;
}

//---------- Shape : Vertex ----------
inline void beginContour() {
	sVisStream << "beginContour();" << std::endl;
}

inline void beginShape(const std::string& mode = "") {
	if (!mode.empty()) {
		sVisStream << "beginShape(\"" << mode << "\");" << std::endl;
	} else {
		sVisStream << "beginShape();" << std::endl;
	}
}

inline void bezierVertex(float x1, float y1, float x2, float y2, float x3, float y3) {
	sVisStream << "bezierVertex(" << x1 << ", " << y1 << ", " << x2 << ", " << y2 << ", " << x3 << ", " << y3 << ");" << std::endl;
}

inline void curveVertex(float x, float y) {
	sVisStream << "curveVertex(" << x << ", " << y << ");" << std::endl;
}

inline void endContour() {
	sVisStream << "endContour();" << std::endl;
}

inline void endShape(const std::string& mode = "") {
	if (!mode.empty()) {
		sVisStream << "endShape(\"" << mode << "\");" << std::endl;
	} else {
		sVisStream << "endShape();" << std::endl;
	}
}

inline void quadraticVertex(float cx, float cy, float x, float y) {
	sVisStream << "quadraticVertex(" << cx << ", " << cy << ", " << x << ", " << y << ");" << std::endl;
}

inline void vertex(float x, float y) {
	sVisStream << "vertex(" << x << ", " << y << ");" << std::endl;
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

//---------- Structure ----------
inline void push() {
	sVisStream << "push();" << std::endl;
}

inline void pop() {
	sVisStream << "pop();" << std::endl;
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

inline void textAscent() {
	sVisStream << "textAscent();" << std::endl;
}

inline void textDescent() {
	sVisStream << "textDescent();" << std::endl;
}

inline void textWrap(const std::string& wrap) {
	sVisStream << "textWrap(\"" << wrap << "\");" << std::endl;
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
inline void setSingleColor(int, int = 255) {}
inline void setRGBColor(int, int, int, int = 255) {}

//---------- Shape : 2D Primitives ----------
inline void arc(float, float, float, float, float, float) {}
inline void ellipse(float, float, float, float) {}
inline void circle(float, float, float) {}
inline void line(float, float, float, float) {}
inline void point(float, float) {}
inline void quad(float, float, float, float, float, float, float, float) {}
inline void rect(float, float, float, float) {}
inline void square(float, float, float) {}
inline void triangle(float, float, float, float, float, float) {}

//---------- Shape : Attributes ----------
inline void ellipseMode(const std::string&) {}
inline void noSmooth() {}
inline void rectMode(const std::string&) {}
inline void smooth() {}
inline void strokeCap(const std::string&) {}
inline void strokeJoin(const std::string&) {}
inline void strokeWeight(float) {}

//---------- Shape : Curves ----------
inline void bezier(float, float, float, float, float, float, float, float) {}
inline void bezierDetail(int) {}
inline void bezierPoint(float, float, float, float, float) {}
inline void bezierTangent(float, float, float, float, float) {}
inline void curve(float, float, float, float, float, float, float, float) {}
inline void curveDetail(int) {}
inline void curveTightness(float) {}
inline void curvePoint(float, float, float, float, float) {}
inline void curveTangent(float, float, float, float, float) {}

//---------- Shape : Vertex ----------
inline void beginContour() {}
inline void beginShape(const std::string & = "") {}
inline void bezierVertex(float, float, float, float, float, float) {}
inline void curveVertex(float, float) {}
inline void endContour() {}
inline void endShape(const std::string & = "") {}
inline void quadraticVertex(float, float, float, float) {}
inline void vertex(float, float) {}

//---------- Color : Setting ----------
inline void background(int, int = 255) {}
inline void background(int, int, int, int = 255) {}
inline void background(const std::string&) {}
inline void clear() {}
inline void colorMode(const std::string&, int, int, int, int = 0) {}
inline void fill(int, int = 255) {}
inline void fill(int, int, int, int = 255) {}
inline void fill(const std::string&) {}
inline void noFill() {}
inline void noStroke() {}
inline void stroke(int, int = 255) {}
inline void stroke(int, int, int, int = 255) {}
inline void stroke(const std::string&) {}
inline void erase() {}
inline void noErase() {}

//---------- Structure ----------
inline void push() {}
inline void pop() {}

//---------- Typography ----------
inline void textAlign(const std::string&, const std::string & = "") {}
inline void textLeading(float) {}
inline void textSize(float) {}
inline void textStyle(const std::string&) {}
inline void textAscent() {}
inline void textDescent() {}
inline void textWrap(const std::string&) {}
inline void text(const std::string&, float, float) {}
inline void textFont(const std::string&) {}
#endif // VISUALIZE

//----------- p5visualizerのマクロ（ここまで） -------------
