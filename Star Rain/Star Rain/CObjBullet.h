#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�e��
class CObjBullet : public CObj
{
public:
		CObjBullet(float x,float y) ;//�R���X�g���N�^
		~CObjBullet() {};
		void Init();
		void Action();
		void Draw();
private:
	float g_px;
	float g_py;
	float m_vx;
	float m_vy;


	//block�Ƃ̏Փˏ�Ԋm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	bool m_hit;	//�Փ˔���

	int m_block_type;

	//�u���b�N�̓����蔻��
	void BlockHit(
		float*x, float*y, bool scroll_on,
		bool*up, bool*down, bool*left, bool*right,
		float*vx, float*vy, int*bt
	);

};