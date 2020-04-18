# 3Dセルオートマトンの実装

これは、セルオートマトンの一種であるConwayの[ライフゲーム](https://ja.wikipedia.org/wiki/%E3%83%A9%E3%82%A4%E3%83%95%E3%82%B2%E3%83%BC%E3%83%A0)を拡張したものである。
3次元空間への拡張や、状態数の変更、寿命の概念の追加などを行い、従来のライフゲームとは異なるものを実装することで、見栄えを良くした。
また、キーボード入力によって、セルの編集やセルの更新速度の変更を行えるようにした。

動画は[こちら](https://www.youtube.com/playlist?list=PL0oc7AkB1TQK4kQ9fDaY6qSUhQsMoNwQf)

![movie](./Sample_movie/4-6-7-12-13.gif)

# On Linux 
install OpenMP
```
$ sudo ap install libomp-dev
```

install OpenCL
```
$ sudo apt install clinfo
$ sudo apt install ocl-icd-libopencl1
$ sudo apt install opencl-headers
$ sudo apt install ocl-icd-opencl-dev
```


## 起動方法
Normal 
```
$ make Compile_Gnugcc
$ ./3D_LifeGame
```
Use OpenMP
```
$ make Compile_Gnugcc_MP
$ ./3D_LifeGame
```
Use OpenCL
```
$ make Compile_Gnugcc_CL
$ ./3D_LifeGame
```

によって起動する。

初期値の操作は20~25行目で行う。
セルの更新設定(survive, birth配列)によってかなり変わるので、
変えてみると面白い。


## 操作方法

動作画面の左上に従う。

### 通常時
|キー入力|動作内容|
| :--: | :--:|
|v | 自動移動モードへの移行/通常モードへの復帰|
|s | 一時停止/再開|
|r | セルの初期化|
|f | セル更新を早める|
|d | セル更新を遅くする|
|l | カメラ位置をリセットする|
|c | セル初期化時の状態の変更|
|n | 色の変更|
|e | 編集モードへの移行|
|q | 終了|

### 編集モード時

|キー入力|動作内容|
| :--: | :--:|
|i/o |z方向の移動|
|上下左右 | x,yの移動|
|p| セルの状態の変更|
