#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�FOP
class CObjOP :public CObj
{
public:
	CObjOP() {};
	~CObjOP() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[
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