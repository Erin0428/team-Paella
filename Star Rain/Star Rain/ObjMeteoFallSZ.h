#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

extern float g_px;
extern float g_py;

//�I�u�W�F�N�g : �S�[���u���b�N
class ObjMeteoFallSZ : public CObj
{
#define ALL_BLOCK_SIZE (32.0f)
public:
	ObjMeteoFallSZ(float x, float y);
	~ObjMeteoFallSZ() {};
	void Init();   //�C��V�����C�Y
	void Action();	//�A�N�V����
	void Draw();    //�h���[
	int m_map[19][120]; //�}�b�v���

	void SetFall(bool t) { Fall_f = t; }

private:

	float m_py;
	float m_px;

	//block�Ƃ̏Փˏ�Ԋm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
	int  d;
	int  m_block_type;

	float m_scroll;     //���E�X�N���[���p
	float m_vx;			//�ړ��x�N�g��
	float m_vy;
	float m_scrollx;     //���E�X�N���[���p
	float m_scrolly;
	float m_speed_power_y;	//�X�s�[�h�p���[
	float m_speed_power_x;
	bool Fall_f;

	bool abc;
	//�ړ��̌�������p
	bool m_move;
}; 
