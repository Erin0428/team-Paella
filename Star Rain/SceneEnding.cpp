//STLデバッグ機能をOFFにする
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"


//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "ObjEnding.h"
#include "SceneEnding.h"
#include "GameHead.h"

//コンストラクタ
CSceneEnding::CSceneEnding()
{
}

//デストラクタ
CSceneEnding::~CSceneEnding()
{
}

//ゲームエンディング1初期化メソッド
void CSceneEnding::InitScene()
{
	/*Audio::LoadAudio(0, L"titleBGM.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::Start(0);

	//敵１を読み込み1番に登録
	Draw::LoadImage(L"teki1.png", 1, TEX_SIZE_512);
	//敵２を読み込み2番に登録
	Draw::LoadImage(L"teki2.png", 2, TEX_SIZE_512);
	//敵３を読み込み3番に登録
	Draw::LoadImage(L"teki3.png", 3, TEX_SIZE_512);
	//敵４を読み込み4番に登録
	Draw::LoadImage(L"teki4.png", 4, TEX_SIZE_512);
	//敵５を読み込み5番に登録
	Draw::LoadImage(L"teki5.png", 5, TEX_SIZE_512);*/

	//エンディング1オブジェクト作成
	CObjEnding* obj = new CObjEnding();
	Objs::InsertObj(obj, OBJ_ENDING, 10);
}

//ゲームエンディング1実行中メソッド
void CSceneEnding::Scene()
{
}
