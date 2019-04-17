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

	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_block_type = false;	//踏んでいるブロックの種類


	//当たり判定HitoBoxを作成
	Hits::SetHitBox(this, g_px, g_py, 32, 32, ELEMENT_BULLET, OBJ_BULLET, 1);



	
}
//アクション
void CObjBullet::Action()
{
	if (m_hit_up == true)	//上
		m_hit = true;
	if (m_hit_down == true)	//下
		m_hit = true;
	if (m_hit_left == true)	//左
		m_hit = true;
	if (m_hit_right == true)//右
		m_hit = true;

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
	
	//METEOに当たっているか
	if (hit->CheckObjNameHit(OBJ_BLOCK) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//METEOに当たっているか
	if (hit->CheckObjNameHit(OBJ_METEOFALL) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//METEOに当たっているか
	if (hit->CheckObjNameHit(OBJ_METEO) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}





	//ブロックとの当たり判定実行
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&*x, &g_py, false,
	&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy, &m_block_type);

	//壁に当たったら消える処理
	if (m_hit == true) {
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