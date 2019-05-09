//使用するヘッダー
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"

#include "../GameHead.h"
#include "ObjED2.h"
#include "../ゲームメイン/SceneMain.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjED2::Init()
{

	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
}

//アクション
void CObjED2::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
	//マウスの位置とクリックする場所で当たり判定
	if (m_mou_x > 450 && m_mou_x < 755 && m_mou_y>525 && m_mou_y < 560)
	{
		//マウスのボタンが押されたらメインに遷移
		if (m_mou_r == true || m_mou_l == true)
		{
			Scene::SetScene(new CSceneED_Roll());
		}
	}

}

//ドロー
void CObjED2::Draw()
{
	float c[4] = { 1,1,1,1 };

	//ED画像を読み込み0番に登録
	Draw::LoadImage(L"ED2.png", 3, TEX_SIZE_512);

	CObjED2gazou* ED2 = new CObjED2gazou();
	Objs::InsertObj(ED2, OBJ_ED2GAZOU, 20);

	
	Font::StrDraw(L"NORMAL END", 180, 50, 90, c);
	Font::StrDraw(L"無事に脱出することができた!",200, 435, 30, c);
	Font::StrDraw(L"クリックでエンドロールへ", 460, 535, 25, c);
}
