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
#include "SceneED1.h"
#include "../GameHead.h"

//コンストラクタ
CSceneED1::CSceneED1()
{
}

//デストラクタ
CSceneED1::~CSceneED1()
{
}

//ゲームエンディング1初期化メソッド
void CSceneED1::InitScene()
{
	Audio::LoadAudio(0, L"BADENDBGM .wav", SOUND_TYPE::BACK_MUSIC);
	Audio::Start(0);

	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"ゲームを始める");

	//エンディング1オブジェクト作成
	CObjED1* obj = new CObjED1();
	Objs::InsertObj(obj, OBJ_ED1, 10);
}

//ゲームエンディング1実行中メソッド
void CSceneED1::Scene()
{
}
