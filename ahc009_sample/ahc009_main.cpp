// https://atcoder.jp/contests/ahc009

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <time.h>
#include <math.h>
#include <assert.h>
#include <random>
#include <bitset>
#include <thread>
#include <chrono>
#include <vector>
#include <unordered_set>
#include <array>


using namespace std;
using namespace std::chrono;

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

typedef long long ll;
typedef unsigned long long ull;
template<class T> bool INRANGE(T x, T a, T b) { return a <= x && x <= b; }
template<class T> void amin(T& a, T v) { if (a > v) a = v; }
template<class T> void amax(T& a, T v) { if (a < v) a = v; }
template<class T> T CLAMP(T x, T a, T b) { return min(max(x, a), b); }
#define NG (-1)
#define BIG (static_cast<int>(1e9))
#define SZ(a) ((int)a.size()) 
#define SQ(a) ((a)*(a))
#define PI (acos(-1))
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(v) (v).begin(),(v).end()
#define ALL_OF(v, pred) all_of(ALL(v), [&](const auto& x) { return pred; })
#define ANY_OF(v, pred) any_of(ALL(v), [&](const auto& x) { return pred; })
#define NONE_OF(v, pred) none_of(ALL(v), [&](const auto& x) { return pred; })
#define COUNT_IF(v, pred) count_if(ALL(v), [&](const auto& x) { return pred; })
#define BitSet(arg,posn) ((arg) |= (1 << (posn)))
#define BitClr(arg,posn) ((arg) &= ~(1 << (posn)))
#define BitFlp(arg,posn) ((arg) ^= (1 << (posn)))
#define IsBit(arg,posn) static_cast<bool>((arg) & (1 << (posn)))

template<class T>
vector<T> make_vector(int n, T t) {
	return vector<T>(n, t);
}

template<class ...Ts>
auto make_vector(int n, Ts ... ts) {
	return vector<decltype(make_vector(ts...))>(n, make_vector(ts...));
}

inline double RAD2DEG(double rad) { return rad * 180.0 / PI; }

static const double EPS = 1e-9;
inline int ROUND(double x) { return (int)(x + 0.5); }
inline bool ISINT(double x) { return fabs(ROUND(x) - x) <= EPS; }
inline bool ISEQUAL(double x, double y) { return fabs(x - y) <= EPS * max(1.0, max(fabs(x), fabs(y))); }
inline double SQSUM(double x, double y) { return x * x + y * y; }

template<class T>
void wt(const vector <T>& v, bool showNum = false) {
	if (showNum) {
		cout << SZ(v) << endl;
	}
	for (int i = 0; i < SZ(v); ++i) {
		if (i > 0) cout << " ";
		cout << v[i];
	}
	cout << endl;
}

template<class T>
void wt1(const vector <T>& v, bool showNum = false) {
	if (showNum) {
		cout << SZ(v) << endl;
	}
	for (int i = 0; i < SZ(v); ++i) {
		if (i > 0) cout << " ";
		cout << v[i] + 1;
	}
	cout << endl;
}

template<class T>
void wtln(const vector <T>& v, bool showNum = false) {
	if (showNum) {
		cout << SZ(v) << endl;
	}

	for (int i = 0; i < SZ(v); ++i) {
		cout << v[i] << endl;
	}
}

template<class T>
void wtln1(const vector <T>& v, bool showNum = false) {
	if (showNum) {
		cout << SZ(v) << endl;
	}

	for (int i = 0; i < SZ(v); ++i) {
		cout << v[i] + 1 << endl;
	}
}

class RandXor {
public:
	RandXor() {
		init();
	}

	void init() {
		x = 123456789;
		y = 362436069;
		z = 521288629;
		w = 88675123;
	}

	void init(ll seed) {
		x = 123456789;
		y = static_cast<unsigned int>(362436069 + seed * 674890201);
		z = static_cast<unsigned int>(521288629 - seed * seed * 164907679);
		w = static_cast<unsigned int>(88675123 * seed);
	}


	inline unsigned int rand() {
		unsigned int t;
		t = (x ^ (x << 11)); x = y; y = z; z = w; return(w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
	}

	unsigned int next() {
		return rand();
	}

	int nextInt(int num) {
		return rand() % num;
	}

	// [a,b)
	int next(int a, int b) {
		return a + (rand() % (b - a));
	}

	void next2(int& ret0, int& ret1, const int a) {
		ret0 = nextInt(a);
		ret1 = nextInt(a - 1);
		if (ret1 >= ret0) ret1++;
	}

	// [-d,d]
	int nextDelta(int d) {
		return next(-d, d + 1);
	}

	double nextD(double a, double b) {
		return a + (b - a) * nextDouble();
	}

	double nextDouble() {
		return (rand() + 0.5) * (1.0 / 4294967296.0);
	}

	template <class T>
	void randomShuffle(vector <T>& a) {
		const int n = SZ(a);
		for (int i = n - 1; i > 0; --i) {
			swap(a[i], a[nextInt(i + 1)]);
		}
	}

private:
	unsigned int x;
	unsigned int y;
	unsigned int z;
	unsigned int w;
};

// 秒を返す
inline double getTime() {
	return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count() * 1e-6;
}

using namespace std;

struct Pos {
	int x;
	int y;

	Pos() = default;

	Pos(const Pos& other) {
		this->y = other.y;
		this->x = other.x;
	}

	Pos(int y, int x) {
		this->y = y;
		this->x = x;
	}

	bool operator< (const Pos& other) const {
		if (this->y < other.y) {
			return true;
		} else if (this->y == other.y) {
			if (this->x < other.x) {
				return true;
			}
		}

		return false;
	}

	Pos& operator=(const Pos& other) {
		this->y = other.y;
		this->x = other.x;
		return *this;
	}

	const Pos operator + (const Pos& other) const {
		return Pos(this->y + other.y, this->x + other.x);
	}

	Pos& operator += (const Pos& other) {
		this->y += other.y;
		this->x += other.x;

		return *this;
	}

	const Pos operator - (const Pos& other) const {
		return Pos(this->y - other.y, this->x - other.x);
	}

	Pos& operator -= (const Pos& other) {
		this->y -= other.y;
		this->x -= other.x;

		return *this;
	}

	bool operator== (const Pos& other) const {
		return this->y == other.y && this->x == other.x;
	}

	bool operator!= (const Pos& other) const {
		return !(*this == other);
	}

	bool isZero() const {
		return x == 0 && y == 0;
	}

	int dist(const Pos& other) const {
		return abs(x - other.x) + abs(y - other.y);
	}
};

const double TL = 1.9;

constexpr int N = 20;
double P;
int SI, SJ, TI, TJ; char H[20][22], V[20][22];

int numBest = 0;
string res; double res_score;
string tmp; double tmp_score;
double score_history[200];


double score_calc(const string &s, bool visualize = false){
  int i, j, k, t, ni, nj;
  double score = 0;
  static double dp[20][20], nx[20][20];

  if(s.size() > 200) return 0;

  REP(i,N) REP(j,N) dp[i][j] = 0;
  dp[SI][SJ] = 1;

  const int sz = 20;


  textFont("Georgia"); // フォントの指定

  if (visualize) {
	always(); // 迷路は常に描画する
	noStroke();

	// 背景を白で描画
	fill("white");
	rect(0, 0, sz * N, sz * N);

	noFill();
	stroke("green");
	REP(y, N) {
		REP(x, N - 1) {
			if (H[y][x]) {
				line(x * sz, y * sz, (x + 1) * sz, y * sz);	// 横方向の壁を線で描画
			}
		}
	}

	REP(y, N - 1) {
		REP(x, N) {
			if (V[y][x]) {
				line(x * sz, y * sz, x * sz, (y + 1) * sz);	// 縦方向の壁を線で描画
			}
		}
	}

	noStroke();
  }

  textAlign("LEFT", "TOP");	// テキスト表示のときは左上を基準にする
  REP(t,s.size()){
	if (visualize) {
		// 密度の描画
		time(t);	// 時間に応じて表示するものを替えたいので、時間を指定する。
		REP(y, N) {
			REP(x, N) {
				int white = 255 - static_cast<int>(255 * dp[y][x]);
				fill(255, white, white, 255);		// 密度が高いと赤色を表示する。密度が低いと白色
				square(x * sz + 1, y * sz + 1, sz - 2);	// 正方形を描画

				fill("black");
				int value = static_cast<int>(dp[y][x] * 1000);
				if (value >= 1) {
					text(to_string(value), x * sz, y * sz);	// 密度の値を最大1000で描画
				}
			}
		}

		// スコアの描画
		fill("blue");
		text("score = " + to_string(score * 250000), sz * N + 10, 10);
	}
	  
	// DP本体の部分
	REP(i,N) REP(j,N) nx[i][j] = dp[i][j] * P;
	REP(i,N) REP(j,N){
	  ni = i;
	  nj = j;
      if(s[t] == 'U' && i-1 >= 0 && V[i-1][j] == 0) ni--;
      if(s[t] == 'D' && i+1 <  N && V[i  ][j] == 0) ni++;
      if(s[t] == 'L' && j-1 >= 0 && H[i][j-1] == 0) nj--;
      if(s[t] == 'R' && j+1 <  N && H[i][j  ] == 0) nj++;
      nx[ni][nj] += dp[i][j] * (1 - P);
    }
	REP(i,N) REP(j,N) dp[i][j] = nx[i][j];
    score += (400 - t) * dp[TI][TJ];

    dp[TI][TJ] = 0;

  }

  // スタートゴール
  if (visualize) {
	  always();	// 常に描画する
	  stroke("black");	// 縁取りは黒色
	  fill("red");	// スタートは赤色
	  circle((SJ + 0.5f)* sz, (SI + 0.5f)* sz, 5);	// 小さい円を描画
	  fill("blue");	// ゴールは赤色
	  circle((TJ + 0.5f)* sz, (TI + 0.5f)* sz, 5);	// 小さい円を描画
  }


  score *= 250000;
  if(score > res_score){
    res_score = score;
    res = s;
	numBest++;
//	cerr << " numBest=" << numBest << " res_score=" << res_score << endl;
  }

  return score;
}

void solve() {
  int i, j, k;
  double t;
  string nx; double nx_score;
  RandXor randXor;
 
  int num_break = 0;

  tmp = "";
  REP(i, 200) {
	  tmp += randXor.nextDouble() < 0.5 ? 'R' : 'D';
  }
  tmp_score = score_calc(tmp);

  const auto startTime = getTime();

  ll numLoops = 0;

  for(;;){
	numLoops++;
	t = (TL - (getTime()-startTime)) / TL;
//	cerr << " t=" << t << endl;

    if(t <= 0) break;

	const int neighbor_type = randXor.nextInt(3);

	if (neighbor_type == 0) {
		i = randXor.nextInt((int)tmp.size());
		nx = tmp;
		nx[i] = "UDLR"[randXor.nextInt(4)];
	} else if (neighbor_type == 1) {
		i = randXor.nextInt(((int)tmp.size()-1));
		nx = tmp;
		swap(nx[i], nx[i + 1]);
	} else {
		i = randXor.nextInt(((int)tmp.size() - 1));
		nx = tmp;
		nx[i+1] = nx[i];
	}

    nx_score = score_calc(nx);

    if(nx_score >= tmp_score || randXor.nextDouble() < exp( (nx_score - tmp_score) * 0.01 / t )){
      // if(tmp_score != nx_score) fprintf(stderr, "%f: %f -> %f\n", t, tmp_score, nx_score);
      tmp_score = nx_score;
      tmp = nx;
    }
  }

  score_calc(tmp, true);
}

int main() 
{
	cin >> SI >> SJ >> TI >> TJ >> P;
	REP(y, N) {
		string s;
		cin >> s;
		REP(x, N - 1) {
			H[y][x] = s[x];
			H[y][x] -= '0';
		}
	}

	REP(y, N - 1) {
		string s;
		cin >> s;
		REP(x, N) {
			V[y][x] = s[x];
			V[y][x] -= '0';
		}
	}

	solve();
	cout << res << endl;

	cerr << " numBest=" << numBest << endl;
	fprintf(stderr, "%f\n", res_score);

	return 0;
}
