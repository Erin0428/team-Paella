#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：メイン
class CSceneMain :public CScene
{
	public:
		CSceneMain();
		~CSceneMain();
		void InitScene();//初期化メゾッド
		void Scene();//実行中メゾッド
	private:
};