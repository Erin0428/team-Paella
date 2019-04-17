//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "CObjBullet.h"
#include "GameL\HitBoxManager.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjBullet::CObjBullet(float x, float y)
{
	g_px = x;
	g_py = y;
}


//�C�j�V�����C�Y
void CObjBullet::Init()
{
	m_vx = 0.0f;
	//�����蔻��HitoBox���쐬
	Hits::SetHitBox(this, g_px, g_py, 32, 32, ELEMENT_BULLET, OBJ_BULLET, 1);
}
//�A�N�V����
void CObjBullet::Action()
{
	m_vx += 1.0f;

	g_px += m_vx;

	//HitBox�̓��e���X�V
	CHitBox * hit = Hits::GetHitBox(this);
	hit->SetPos(g_px, g_py);


	//�o���b�g����ʊO�ō폜
	if (g_px > 800.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		
	}




}

//�h���[
void CObjBullet::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top	 = 0.0f	 + g_py;
	dst.m_left	 = 0.0f  + g_px;
	dst.m_right  = 32.0f + g_px;
	dst.m_bottom = 32.0f + g_py;

	//�`��
	Draw::Draw(7, &src, &dst, c, 0.0f);
}