//STLデバッグ機能をOFFにする
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL/DrawTexture.h"
#include "GameL/Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "SceneOP.h"
#include "GameHead.h"

//コンストラクタ
CSceneOP::CSceneOP()
{

}

//デストラクタ
CSceneOP::~CSceneOP()
{

}

//ゲームOP初期化メソッド
void CSceneOP::InitScene()
{
	/*Audio::LoadAudio(0, L"titleBGM.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(1, L"ChoiceSE.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(2, L"next.wav", SOUND_TYPE::EFFECT);

	Audio::Start(0);
	Draw::LoadImage(L"OPtobira.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"OPteki.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"敵3印.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"扉3印.png", 2, TEX_SIZE_512);*/

	//OPオブジェクト作成
	CObjOP* abc = new CObjOP();
	Objs::InsertObj(abc, OBJ_OP, 10);

	//OPオブジェクト作成
	CObjOP* d = new CObjOP();
	Objs::InsertObj(d, OBJ_OP, 10);
}

//ゲームタイトル実行中メソッド
void CSceneOP::Scene()
{
}
