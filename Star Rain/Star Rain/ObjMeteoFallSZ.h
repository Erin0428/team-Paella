#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

extern float g_px;
extern float g_py;

//オブジェクト : ゴールブロック
class ObjMeteoFallSZ : public CObj
{
#define ALL_BLOCK_SIZE (32.0f)
public:
	ObjMeteoFallSZ(float x, float y);
	~ObjMeteoFallSZ() {};
	void Init();   //イ二シャライズ
	void Action();	//アクション
	void Draw();    //ドロー
	int m_map[19][120]; //マップ情報

	void SetFall(bool t) { Fall_f = t; }

private:

	float m_py;
	float m_px;

	//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
	int  d;
	int  m_block_type;

	float m_scroll;     //左右スクロール用
	float m_vx;			//移動ベクトル
	float m_vy;
	float m_scrollx;     //左右スクロール用
	float m_scrolly;
	float m_speed_power_y;	//スピードパワー
	float m_speed_power_x;
	bool Fall_f;

	bool abc;
	//移動の向き制御用
	bool m_move;
}; 
