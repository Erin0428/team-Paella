#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：OP
class CObjOP :public CObj
{
public:
	CObjOP() {};
	~CObjOP() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー
private:
	float m_mou_x;
	float m_mou_y;
	bool m_mou_r;
	bool m_mou_l;
	int m_cnt;
	float m_and;
	bool m_f;
	bool m_flag;
	bool m_andf;
	bool m_gazo;
	bool m_kesu;
	int m_time;
};