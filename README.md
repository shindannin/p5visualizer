# p5visualizer
競プロ用。C++コードに描画コマンドを埋め込み、ファイルを出力し、それをブラウザ上で表示させる

# 使用方法
1. 自分のmain.cppに、macro.cppを挿入する。
2. main.cppに描画コマンドを書いていく。
3. 実行時にVisCommands.txtが出力される
4. ビジュアライザindex.htmlをブラウザで開く
5. 「ファイルを選択」で先ほどのVisCommands.txtを開く
6. 表示される。時間のスライダーで表示させたい時間を選べる

# 描画
https://p5js.org/reference/ の一部の描画命令をサポートしている。なお、https://editor.p5js.org/ にウェブ版のエディタがあるので、描画コマンドがおかしいときはここでも確認できる。

* 特殊命令
** time(t)
** always(t)
* 基本図形
** arc(x,y,w,h,start,stop)
** ellipse(x,y,w,h)
** circle(x,y,d)
** line(x1,y1,x2,y2)
** point(x,y)
** quad(x1,y1,x2,y2,x3,y3,x4,y4)
** rect(x,y,w,h)
** square(x,y,s)
** triangle(x1,y1,x2,y2,x3,y3)
* スタイル指定
** background(r, g, b)
** clear()
** colorMode(mode, max1, max2, max3, maxA)
** fill(r, g, b, a)
** noFill()
** noStroke()
** stroke(r, g, b, a)
** erase()
** noErase()
* テキスト描画
** textAlign(alignX, alignY)
** textLeading(leading)
** textSize(size)
** textStyle(style)
** textWidth(text)
** textAscent()
** textDescent()
** textWrap(wrap)
** text(str, x, y)

# サンプル
AHC009 ( https://atcoder.jp/contests/ahc009 ) に
* ahc009_sample.cpp 提出コード
* ahc009_VisCommands.txt 出力された描画コマンド

# TODO
* 再生ボタン
* 時間をテキストボックスで指定するボタン
* 入力・出力などテキストを表示させるためのテキストボックス
* 3D描画
