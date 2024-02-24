using namespace std;

//----------- p5visualizerのマクロ（ここから） -------------
#define VISUALIZE // 提出時にはここをコメントアウトすること。そうしないとTLEする。

#ifdef VISUALIZE
std::ofstream sVisStream("VisCommands.txt");

// ビジュアライザ上で表示される時間を指定します
#define time(t) sVisStream << "time = " << (t) << ";" << endl;
// ビジュアライザ上で常に表示されます
#define always(t) time(-1)

// リファレンス https://p5js.org/reference/ 
// Web上のエディタ https://editor.p5js.org/
#define arc(x,y,w,h,start,stop) sVisStream << "arc( " << (x) << ", " << (y) << ", " << (w) << ", " << (h) << ", " << (start) << ", " << (stop) << ");" << endl;
#define ellipse(x,y,w,h) sVisStream << "ellipse( " << (x) << ", " << (y) << ", " << (w) << ", " << (h) << ");" << endl;
#define circle(x,y,d) sVisStream << "circle( " << (x) << ", " << (y) << ", " << (d) << ");" << endl;
#define line(x1,y1,x2,y2) sVisStream << "line( " << (x1) << ", " << (y1) << ", " << (x2) << ", " << (y2) << ");" << endl;
#define point(x,y) sVisStream << "point( " << (x) << ", " << (y) << ");" << endl;
#define quad(x1,y1,x2,y2,x3,y3,x4,y4) sVisStream << "quad( " << (x1) << ", " << (y1) << ", " << (x2) << ", " << (y2) << ", " << (x3) << ", " << (y3) << ", " << (x4) << ", " << (y4) << ");" << endl;
#define rect(x,y,w,h) sVisStream << "rect( " << (x) << ", " << (y) << ", " << (w) << ", " << (h) << ");" << endl;
#define square(x,y,s) sVisStream << "square( " << (x) << ", " << (y) << ", " << (s) << ");" << endl;
#define triangle(x1,y1,x2,y2,x3,y3) sVisStream << "triangle( " << (x1) << ", " << (y1) << ", " << (x2) << ", " << (y2) << ", " << (x3) << ", " << (y3) << ");" << endl;

#define background(r, g, b) sVisStream << "background(" << (r) << ", " << (g) << ", " << (b) << ");" << endl;
#define clear() sVisStream << "clear();" << endl;
#define colorMode(mode, max1, max2, max3, maxA) sVisStream << "colorMode(" << (mode) << ", " << (max1) << ", " << (max2) << ", " << (max3) << ", " << (maxA) << ");" << endl;
#define fill(r, g, b, a) sVisStream << "fill(" << (r) << ", " << (g) << ", " << (b) << ", " << (a) << ");" << endl;
#define noFill() sVisStream << "noFill();" << endl;
#define noStroke() sVisStream << "noStroke();" << endl;
#define stroke(r, g, b, a) sVisStream << "stroke(" << (r) << ", " << (g) << ", " << (b) << ", " << (a) << ");" << endl;
#define erase() sVisStream << "erase();" << endl;
#define noErase() sVisStream << "noErase();" << endl;

#define textAlign(alignX, alignY) sVisStream << "textAlign(" << (alignX) << ", " << (alignY) << ");" << endl;
#define textLeading(leading) sVisStream << "textLeading(" << (leading) << ");" << endl;
#define textSize(size) sVisStream << "textSize(" << (size) << ");" << endl;
#define textStyle(style) sVisStream << "textStyle(" << (style) << ");" << endl;
#define textWidth(text) sVisStream << "textWidth(" << (text) << ");" << endl;
#define textAscent() sVisStream << "textAscent();" << endl;
#define textDescent() sVisStream << "textDescent();" << endl;
#define textWrap(wrap) sVisStream << "textWrap(" << (wrap) << ");" << endl;
#define text(str, x, y) sVisStream << "text(" << "\"" << (str) << "\"" << ", " << (x) << ", " << (y) << ");" << endl;

#else //  VISUALIZE

#define time(t)
#define always(t)

#define arc(x,y,w,h,start,stop)
#define ellipse(x,y,w,h)
#define circle(x,y,d)
#define line(x1,y1,x2,y2)
#define point(x,y)
#define quad(x1,y1,x2,y2,x3,y3,x4,y4)
#define rect(x,y,w,h)
#define square(x,y,s)
#define triangle(x1,y1,x2,y2,x3,y3)

#define background(r, g, b)
#define clear()
#define colorMode(mode, max1, max2, max3, maxA)
#define fill(r, g, b, a)
#define noFill()
#define noStroke()
#define stroke(r, g, b, a)
#define erase()
#define noErase()

#define textAlign(alignX, alignY)
#define textLeading(leading)
#define textSize(size)
#define textStyle(style)
#define textWidth(text)
#define textAscent()
#define textDescent()
#define textWrap(wrap)
#define text(str, x, y)

#endif // VISUALIZE
//----------- p5visualizerのマクロ（ここまで） -------------
