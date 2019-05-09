#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：エンディング1
class CObjEnding :public CObj
{
public:
	CObjEnding() {};
	~CObjEnding() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー
private:
	float m_y;
	float m_and;
};