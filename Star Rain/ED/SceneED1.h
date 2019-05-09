#pragma once
//使用するヘッダーファイル
#include "../GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームエンディング1
class CSceneED1 :public CScene
{
public:
	CSceneED1();
	~CSceneED1();
	void InitScene();//ゲームエンディングの初期化メソッド
	void Scene();	 //ゲームエンディングの実行中メソッド
private:

};