#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームエンディング1
class CSceneED_Roll :public CScene
{
public:
	CSceneED_Roll();
	~CSceneED_Roll();
	void InitScene();//ゲームエンディングの初期化メソッド
	void Scene();	 //ゲームエンディングの実行中メソッド
private:
};