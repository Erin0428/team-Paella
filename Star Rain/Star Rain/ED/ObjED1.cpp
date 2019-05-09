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
void CObjED1::Init()
{

	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
}

//アクション
void CObjED1::Action()
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
void CObjED1::Draw()
{
	float c[4] = { 1,1,1,1 };
	
	//ED画像を読み込み0番に登録
	Draw::LoadImage(L"ED1.png", 3, TEX_SIZE_512);

	CObjED1gazou* ED1 = new CObjED1gazou();
	Objs::InsertObj(ED1, OBJ_ED1GAZOU, 20);

	float o[4] = { 0.5f,0.0f,1.0f,1.0f };
	Font::StrDraw(L"BAD END", 250, 50, 90, o);

	float a[4] = { 0.5f,0.5f,0.5f,1.0f };
	Font::StrDraw(L"敵と戦っていたらたくさんの敵が集まってきて捕らえられた", 70, 450, 25, a);
	Font::StrDraw(L"ノーダメージでクリアすると・・？", 70, 480, 25, a);

	float s[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"クリックでエンドロールへ", 460, 535, 25, s);
}
