#pragma once
#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;


extern float g_px;
extern float g_py;

//オブジェクト : ゴールブロック
class ObjMeteo : public CObj
{
#define ALL_BLOCK_SIZE (32.0f)

public:
	ObjMeteo(float x, float y);
	~ObjMeteo() {};
	void Init();   //イ二シャライズ
	void Action();	//アクション
	void Draw();    //ドロー
	int m_map[19][65]; //マップ情報

	//ブロックの当たり判定
	void MeteoHit(
		float*x, float*y, bool scroll_on,
		bool*up, bool*down, bool*left, bool*right,
		float*vx, float*vy, int*bt
	);
private:
	float m_px;			//位置
	float m_py;
	float m_vx;			//移動ベクトル
	float m_vy;
	float m_posture;	//姿勢

	int des = 0;

	float m_speed_power;	//スピードパワー

	float m_scrollx;     //左右スクロール用
	float m_scrolly;
	float m_scroll_map;

	//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
	int  d;
	int  m_block_type;
	//移動の向き制御用
	bool m_move;
};