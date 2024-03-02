let maxTime = 0; // timeの最大値を格納する変数
let commands = []; // コマンドを格納する配列
let numDrawCommands = 0; // 描画したコマンド数
let lastFile; // 最後に選択されたファイルの内容を保存する変数
let playButton, playSpeedInput;
let playing = false; // 再生中かどうかのフラグ
let playSpeed = 1; // 再生速度（スライダーのvalueを進める速度）

// スライダーの最大値を更新するグローバル関数
window.updateMaxTime = function(maxTime) {
    document.getElementById('timeSlider').max = maxTime;
};

// 現在のスライダーの値を更新するグローバル関数
window.updateSliderValue = function(value) {
    document.getElementById('timeSlider').value = value;
};

function setup() {
    createCanvas(800, 800, WEBGL).parent('canvasContainer'); // キャンバスの親要素を設定
    loop();

     // 'フォルダを読み込む' ボタンのクリックイベントを設定
  document.getElementById('loadFolderButton').addEventListener('click', function() {
    document.getElementById('fileInput').click(); // 実際のファイル入力をトリガー
  });
  
  document.getElementById('fileInput').addEventListener('change', handleFileSelect);

/*
    document.getElementById('fileInput').addEventListener('change', function(e) {
        if (e.target.files.length > 0) {
            // ファイルが選択されたとき、そのファイルを保存
            lastFile = e.target.files[0];
            readFile(lastFile);
        }
    });
*/

    document.getElementById('fileInput').addEventListener('click', function(e) {
        this.value = null;
    });

    // スライダーの設定部分
    // スライダーの値が変更されたときにテキストボックスを更新
    let timeSlider = document.getElementById('timeSlider');
    timeSlider.addEventListener('input', function() {
        document.getElementById('currentTimeInput').value = this.value;
        if (!playing) {
            redraw(); // スライダーが手動で操作されたときに描画を更新
        }
    });

    // テキストボックスの値が変更されたときにスライダーの値を更新
    let currentTimeInput = document.getElementById('currentTimeInput');
    currentTimeInput.addEventListener('input', function() {
        let value = parseInt(this.value);
        if (!isNaN(value)) {
            value = Math.min(Math.max(value, 0), maxTime); // 範囲内に収める
            timeSlider.value = value;
            if (!playing) {
                redraw(); // テキストボックスが手動で操作されたときに描画を更新
            }
        }
    });

    // 再生速度の設定（テキストボックスから値を取得）
    document.getElementById('playSpeed').addEventListener('input', function() {
        playSpeed = parseInt(this.value); // 再生速度を更新
    });

    // 再生ボタンのクリックイベントをHTML側で扱う
    document.getElementById('playButton').addEventListener('click', togglePlay);

    // GIF録画ボタンのイベントリスナーを追加
    document.getElementById('recordGifButton').addEventListener('click', recordGif);

    // 再生速度設定のセットアップ
    playSpeedInput = select('#playSpeed');
    playSpeedInput.input(() => {
        playSpeed = float(playSpeedInput.value());
    });
}

function handleFileSelect(event) {
    const files = event.target.files; // 選択されたファイルのリスト
    const fileListContainer = document.getElementById('fileListContainer');
    fileListContainer.innerHTML = ''; // リストをクリア

    // ファイルリストを表示
    for (const file of files) {
        const btn = document.createElement('button');
        btn.textContent = file.name;
        btn.addEventListener('click', () => loadAndDraw(file));
        fileListContainer.appendChild(btn);
    }
}

function loadAndDraw(file) {
    // FileReaderを使用してファイルの内容を読み込み
    const reader = new FileReader();
    reader.onload = function(event) {
        const content = event.target.result;
        // ファイルの内容から描画コマンドを実行する処理をここに記述
        console.log(content); // とりあえずコンテンツをログに出力
    };
    reader.readAsText(file);
}

function draw() {
    clear();
    background('white');
    rotateX(frameCount * 0.01);
    rotateY(frameCount * 0.01);

    if (playing) {
        loop();
        // 描画コマンドの実行とその他の描画処理...
        let timeSlider = document.getElementById('timeSlider');
        const currentTime = parseInt(timeSlider.value);
        let nextTime = currentTime + playSpeed; // 次の時間を計算
        timeSlider.value = nextTime; // スライダーの値を更新
        if (nextTime >= maxTime) {
            nextTime = maxTime;
            playing = false; // 最大値に達したら再生を停止
            noLoop(); // drawループを停止
        }
        timeSlider.value = nextTime; // スライダーの値を更新
        document.getElementById('currentTimeInput').value = nextTime; // テキストボックスも更新
   }

    // 描画コマンドの実行
    executeCommands();

    // 全描画コマンド数と表示描画コマンド数の表示
    /*
    fill(0); // テキストの色を黒に設定
    textSize(12); // テキストサイズの設定
    text(`描画コマンド数: ${numDrawCommands}/${commands.length}`, 10, height - 20);
    */
}   

function readFile(file) {
    const reader = new FileReader();
    reader.onload = function(event) {
        parseCommands(event.target.result);
        // スライダーの最大値と現在値を更新
        let timeSlider = document.getElementById('timeSlider');
        timeSlider.max = maxTime;
        timeSlider.value = 0; // スライダーの値をリセット
        document.getElementById('maxTimeDisplay').innerText = `${maxTime}`; // 最大時間の表示を更新
        redraw(); // キャンバスを更新
    };

    reader.readAsText(file);
}

function parseCommands(fileContent) {
    commands = []; // コマンドリストを初期化
    maxTime = 0; // 最大time値をリセット
    currentTime = 0;
    const commandsArray = fileContent.replace(/\r\n?/g, '\n').split(';');
    commandsArray.forEach(commandString => {
        const trimmedCommand = commandString.trim();
        if (trimmedCommand === '') return;
        const timeMatch = trimmedCommand.match(/^time = (-?\d+)/);
        if (timeMatch) {
            const time = parseInt(timeMatch[1], 10);
            maxTime = max(maxTime, time); // 最大time値を更新
            currentTime = time;
        } else {
            commands.push({ time: currentTime, cmd: trimmedCommand });
        }
    });

    timeSlider.max = maxTime;
    // 最大値を表示
    document.getElementById('maxTimeDisplay').innerText = `${maxTime}`;
}

function executeCommands() {
    let timeSlider = document.getElementById('timeSlider');
    const currentTime = parseInt(timeSlider.value);
    const startTime = currentTime;
    const endTime = currentTime;

    // 時間の条件を満たすコマンド文字列を連結
    let commandsToExecute = '';
    numDrawCommands = 0;
    commands.forEach(({time, cmd}) => {
        if ( (startTime <= time && time <= endTime) || time < 0) { // time = -1は常に描画
            commandsToExecute += cmd + ';';
            numDrawCommands += 1;
        }
    });
    
    if (commandsToExecute) {
        eval(commandsToExecute); // 連結されたコマンドをevalで1回だけ評価
    }
}

// 再生/停止の切り替え関数
function togglePlay() {
    playing = !playing;
    if (playing) {
        loop(); // drawループを有効にして描画を続ける
    } else {
        noLoop(); // drawループを停止
    }
}

// GIF録画関数
function recordGif() {
    saveGif('mySketch', 5);
}
