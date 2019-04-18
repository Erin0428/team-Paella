//使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "CObjBullet.h"
#include "GameL\HitBoxManager.h"


//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjBullet::CObjBullet(float x, float y)
{
	g_px = x;
	g_py = y;
}


//イニシャライズ
void CObjBullet::Init()
{
	m_vx = 0.0f;
	//当たり判定HitoBoxを作成
	Hits::SetHitBox(this, g_px, g_py, 32, 32, ELEMENT_BULLET, OBJ_BULLET, 1);
}
//アクション
void CObjBullet::Action()
{
	m_vx += 1.0f;

	g_px += m_vx;

	//HitBoxの内容を更新
	CHitBox * hit = Hits::GetHitBox(this);
	hit->SetPos(g_px, g_py);


	//バレットが画面外で削除
	if (g_px > 800.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		
	}




}

//ドロー
void CObjBullet::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	//表示位置の設定
	dst.m_top	 = 0.0f	 + g_py;
	dst.m_left	 = 0.0f  + g_px;
	dst.m_right  = 32.0f + g_px;
	dst.m_bottom = 32.0f + g_py;

	//描画
	Draw::Draw(7, &src, &dst, c, 0.0f);
}