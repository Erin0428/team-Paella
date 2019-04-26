//使用するヘッダー
#include "../GameL\DrawTexture.h"
#include "../GameL\WinInputs.h"
#include "../GameL\DrawFont.h"
#include "../GameL\SceneManager.h"

#include "../GameHead.h"
#include "../タイトル/ObjTitle.h"
#include "../ゲームメイン/SceneMain.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjED3::Init()
{

	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
}

//アクション
void CObjED3::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
	//マウスの位置とクリックする場所で当たり判定
	if (m_mou_x > 470 && m_mou_x < 780 && m_mou_y>520 && m_mou_y < 555)
	{
		//マウスのボタンが押されたらメインに遷移
		if (m_mou_r == true || m_mou_l == true)
		{
			Scene::SetScene(new CSceneED_Roll());
		}
	}

}

//ドロー
void CObjED3::Draw()
{
	
	float c[4] = { 1,1,1,1 };

	//ED画像を読み込み0番に登録
	Draw::LoadImage(L"ED3.png", 3, TEX_SIZE_512);

	CObjED3gazou* ED3 = new CObjED3gazou();
	Objs::InsertObj(ED3, OBJ_ED3GAZOU, 20);


	

	float o[4] = { 1.0f,1.0f,0.0f,1.0f };
	Font::StrDraw(L"HAPPY END", 200, 50, 90, o);

	float s[4] = { 0.2f,1.0f,0.9f,1.0f };
	Font::StrDraw(L"やったね！無傷で脱出することができた！", 150, 450, 30, s);

	Font::StrDraw(L"クリックでエンドロールへ", 480, 535, 25, c);

}