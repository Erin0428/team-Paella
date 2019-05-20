//STLデバッグ機能をOFFにする
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "../GameL\SceneObjManager.h"
#include "../GameL\DrawFont.h"
#include "../GameL/Audio.h"
//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "../ゲームメイン/SceneMain.h"
#include "SceneED2.h"
#include "../GameHead.h"

//コンストラクタ
CSceneED2::CSceneED2()
{
}

//デストラクタ
CSceneED2::~CSceneED2()
{
}

//ゲームエンディング2初期化メソッド
void CSceneED2::InitScene()
{

	Audio::LoadAudio(0, L"ENDBGM .wav", SOUND_TYPE::BACK_MUSIC);
	Audio::Start(0);

	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"ゲームを始める");

	//エンディング2オブジェクト作成
	CObjED2* obj = new CObjED2();
	Objs::InsertObj(obj, OBJ_ED2, 10);
}

//ゲームエンディング2実行中メソッド
void CSceneED2::Scene()
{
}
