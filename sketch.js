let startTimeSlider; // スライダー
let maxTime = 0; // timeの最大値を格納する変数
let commands = []; // コマンドを格納する配列
let numDrawCommands = 0; // 描画したコマンド数
let lastFile; // 最後に選択されたファイルの内容を保存する変数

function setup() {
    createCanvas(800, 800);
    noLoop(); // 描画ループを無効にする

    // ファイル入力処理
    document.getElementById('fileInput').addEventListener('change', function(e) {
        if (e.target.files.length > 0) {
            // ファイルが選択されたとき、そのファイルを保存
            lastFile = e.target.files[0];
            readFile(lastFile);
        }
    });
    
    document.getElementById('reloadButton').addEventListener('click', function() {
        if (lastFile) {
            // リロードボタンが押されたとき、最後に選択されたファイルを再読み込み
            readFile(lastFile);
        } else {
            alert("ファイルがまだ選択されていません。");
        }
    });
}

function draw() {
    clear();
    background('white');

    // 描画コマンドの実行
    executeCommands();

    // 全描画コマンド数と表示描画コマンド数の表示
    fill(0); // テキストの色を黒に設定
    textSize(12); // テキストサイズの設定
    text(`描画コマンド数: ${numDrawCommands}/${commands.length}`, 10, height - 20);

    if (startTimeSlider) {
        const startTime = startTimeSlider.value();
        text(`時間: ${startTime}/${maxTime}`, 10, height - 40);
    }

}   

function readFile(file) {
    const reader = new FileReader();
    reader.onload = function(event) {
        parseCommands(event.target.result);
        createSliders(); // スライダーを生成
        redraw();
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
}

function createSliders() {
    // 既存のスライダーを削除
    if (startTimeSlider) startTimeSlider.remove();
    
    // 新しいスライダーを生成
    startTimeSlider = createSlider(0, maxTime, 0, 1);
    startTimeSlider.position(100, height);
    startTimeSlider.input(() => redraw()); // スライダーが更新されたときにredrawを呼ぶ
}

function executeCommands() {
    if (!startTimeSlider) {
        console.log("スライダーがまだ存在しません。");
        return; // スライダーがない場合はここで処理を終了
    }

    const startTime = startTimeSlider.value();
    const endTime = startTime;

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
