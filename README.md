# 工学研究部部報65号のおまけ

## はじめに
このリポジトリは工学研究部部報65号でHatgamoが執筆した記事の付録~~的な何か~~です。

## 注意
1. 掲載されているソースコードのライセンスはMITです。
2. 掲載されているソースコードには不備が見受けられます。
3. 掲載されているソースコードの使用は自己責任です。
   使用したことで何か問題が生じても作者は一切の責任を負いません。

## プログラムの概要
第一引数のパスで指定されたwavファイルを1回再生して終了します。
音量はOS側から調整可能です。

## コンパイル環境
作者が使用したコンパイル環境は下記のとおりです。

- 環境: CYGWIN_NT-10.0
- 環境のバージョン: 3.1.7
- CPUのアーキテクチャ: x86_64

ビルドに使用したツールはg++です。

## プログラムの実行方法
生成されるプログラムは以下の様に実行することができます。

```Bash
(program name) path/to/wav_file.wav
```