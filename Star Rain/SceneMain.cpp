//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include"GameL\DrawFont.h"
#include"GameL\UserData.h"
#include"GameL\Audio.h"


//使用するネームスペース
using namespace GameL;

bool g_f = false;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"

//コンストラクタ
CSceneMain::CSceneMain()
{

}

//デストラクタ
CSceneMain::~CSceneMain()
{

}

//初期化メゾット
void CSceneMain::InitScene()
{
	//Font作成
	Font::SetStrTex(L"0123456789分秒");

	//外部データの読み込み（ステージ情報）
	unique_ptr<wchar_t> p; //ステージ情報ポインター
	int size;              //ステージ情報の大きさ

	if (g_map_chenge == 0)
			p = Save::ExternalDataOpen(L"map1.csv", &size);//外部データ読み込み
		if (g_map_chenge == 1)
			p = Save::ExternalDataOpen(L"map2_1.csv", &size);//外部データ読み込み
		if (g_map_chenge == 2)
			p = Save::ExternalDataOpen(L"map3.csv", &size);//外部データ読み込み

	int map[21][120];
	int count = 1;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 120; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;

			if (w >= 10)
			{
				count += 1;
			}

			count += 2;
		}
	}

	if (g_map_chenge == 0)
	{
		Draw::LoadImage(L"背景1.jpg", 3, TEX_SIZE_1920);
		Draw::LoadImage(L"宇宙の地面.png", 2, TEX_SIZE_768);
	}

	if (g_map_chenge == 1)
	{
		Draw::LoadImage(L"背景2.jpg", 3, TEX_SIZE_1920);
		Draw::LoadImage(L"宇宙の地面.png", 2, TEX_SIZE_768);
	}

	if (g_map_chenge == 2)
	{
		Draw::LoadImage(L"背景2.jpg", 3, TEX_SIZE_1920);
		Draw::LoadImage(L"宇宙の地面.png", 2, TEX_SIZE_768);
	}

	//Font作成
	Font::SetStrTex(L"0123456789分秒");

	//外部グラフィックファイルを読み込み0番に登録(576×384ピクセル)
	Draw::LoadImage(L"主人公.png", 0, TEX_SIZE_576);
	Draw::LoadImage(L"落下隕石.png", 7, TEX_SIZE_768);
	Draw::LoadImage(L"ゴール.png", 5, TEX_SIZE_64);
	//Draw::LoadImage(L"設置型隕石.png", 4, TEX_SIZE_768);
	Draw::LoadImage(L"隕石小.png", 8, TEX_SIZE_64);
	Draw::LoadImage(L"隕石　大.png", 9, TEX_SIZE_64);

	Draw::LoadImage(L"隕石 中.png", 7, TEX_SIZE_768);
	Draw::LoadImage(L"goal.png", 5, TEX_SIZE_64);
	//Draw::LoadImage(L"設置型隕石ー改.png", 4, TEX_SIZE_768);
	Draw::LoadImage(L"設置型隕石２改.png", 6, TEX_SIZE_768);
	Draw::LoadImage(L"隕石小.png", 8, TEX_SIZE_64);
	Draw::LoadImage(L"隕石　大.png", 9, TEX_SIZE_64);
	Draw::LoadImage(L"隕石改改.png", 4, TEX_SIZE_64);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//背景オブジェクト作成
	C0bjBackground * back = new C0bjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 8);

	//blockオブジェクト作成
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//音楽読み込みメゾット
	if (g_map_chenge == 0)
	{
		Audio::LoadAudio(0, L"map1.wav", BACK_MUSIC);		//階層1 音楽読み込み
		float f = Audio::VolumeMaster(1.5);					//BGMの音量変更
	}
	else if (g_map_chenge == 1)
	{
		Audio::LoadAudio(0, L"map2.wav", BACK_MUSIC);		//階層2 音楽読み込み
		float v = Audio::VolumeMaster(1.5);					//BGMの音量変更
	}
	else if (g_map_chenge == 2)
	{
		Audio::LoadAudio(0, L"map3.wav", BACK_MUSIC);		//階層3 音楽読み込み
		float v = Audio::VolumeMaster(1.5);					//BGMの音量変更
	}

	Audio::Start(0);                             //音楽スタート
	////隕石オブジェクト作成
	//ObjMeteo*objm = new ObjMeteo();
	//Objs::InsertObj(objm, OBJ_METEO, 10);

	//タイムオブジェクト作成
	//C0bjTime* objt = new C0bjTime();
	//Objs::InsertObj(objt, OBJ_TIME, 12);


}

//実行中メゾット
void CSceneMain::Scene()
{

}
