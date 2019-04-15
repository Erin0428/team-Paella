//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "CObjBullet.h"

#include "GameHead.h"
#include "ObjHero.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

float g_px = 64.0f;
float g_py = 450.0f;

//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_pos_x = 0.0f;
	m_pos_y = 0.0f;
	m_vx = 0.0f; //�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 1.0f; //�E����0.0f,������1.0f

	m_ani_time = 0;
	m_ani_frame = 0;  //�Î~�t���[��������������

	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_f = true;

	m_del = false;

	m_key_f == false;

	m_block_type = 0;	//����ł���u���b�N�̎��


	m_speed_power = 0.5f;//�ʏ푬�x
	m_ani_max_time = 4;  //�A�j���[�V�����Ԋu��

	m_time = 31;

	hit_size = 0;
	hit_size_x = 0;
	hit_size_x2 = 0;

	//�����蔻��p��HitBox���쐬				
	Hits::SetHitBox(this, g_px, g_py, 32, 64, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//�A�N�V����
void CObjHero::Action()
{
	hit_size = 0;
	hit_size_x = 0;
	hit_size_x2 = 0;

	//�����ɂ��Q�[���I�[�o�[�����X�^�[�g
	if (g_py > 1000.0f)
	{
		//��O�ɏo���烊�X�^�[�g
		Scene::SetScene(new CSceneOver());
	}

	m_speed_power = 0.5f;


	//��l���@�̒e�۔���
	if (Input::GetVKey('Z') == true)
	{
		if (m_f == true)
		{
			//�e�ۃI�u�W�F�N�g�쐬
			CObjBullet* obj_b = new CObjBullet(g_px + 30.0f, g_py + 15.0f);
			Objs::InsertObj(obj_b, OBJ_BULLET, 14);

			m_f = false;
		}
	}
	else
	{
		m_f = true;
	}

	//�W�����v
	if (Input::GetVKey(VK_SPACE) == true)
	{
		if (m_hit_down == true && m_time == 0)
		{
			m_vy = -9;
			g_py += m_vy;

		}
	}
	//�W�����v
	else if (Input::GetVKey('W') == true)
	{
		if (m_hit_down == true && m_time == 0)
		{
			m_vy = -9;
			g_py += m_vy;

		}
	}
	if (m_time > 0) {
		m_time--;
		if (m_time <= 0) {
			m_time = 0;
		}
	}

	//���g��HitBox�������Ă���
	CHitBox*hit = Hits::GetHitBox(this);

	if (m_ani_frame >= 4)
	{
		m_ani_frame = 0;
		m_ani_time = 0;
	}

	else if (Input::GetVKey('D') == true)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	else if (Input::GetVKey('A') == true)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}

	else
	{
		m_ani_frame = 0;   //�L�[���͂������ꍇ�Î~�t���[���ɂ���
		m_ani_time = 0;
	}
	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}
	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//��l���@���̈�O�s���Ȃ�����
	if (g_px + 64.0f > 800.0f)
	{
		g_px = 800.0f - 64.0f;

	}

	CObjBlock*b = (CObjBlock*)Objs::GetObj(OBJ_HERO);
	//����X�N���[�����C��
	if (g_px < 80)
	{
		g_px = 80;
		b->SetScroll(b->GetScroll());
	}

	//�O���X�N���[�����C��
	if (g_px > 350)
	{
		g_px = 350;
		b->SetScroll(b->GetScroll());
	}



	//���C
	//m_vx += -(m_vx*0.098);

	//���R�����^��
	m_vy += 3.0 / (16.0f);

	//���C
	m_vx += -(m_vx*0.098);

	//�u���b�N�Ƃ̓����蔻����s
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&g_px, &g_py, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type
	);

	//�G�Ɠ������Ă��邩�m�F
	if (hit->CheckObjNameHit(OBJ_METEO) != nullptr)
	{
		//��l�����G�Ƃǂ̊p�x�������Ă��邩���m�F
		HIT_DATA**hit_data;           //�����������ׂ̍��ȏ������邽�߂̍\����
		hit_data = hit->SearchObjNameHit(OBJ_METEO);//hit_data�Ɏ�l���Ɠ������Ă��鑼�S�Ă�HitBox�Ƃ̏�������

		for (int i = 0; i < hit->GetCount(); i++)
		{
			//�G�̍��E�ɓ���������
			float r = 0;
			for (int i = 0; i < 10; i++)
			{
				if (hit_data[i] != nullptr) {
					r = hit_data[i]->r;
				}
			}

			if ((r < 75 && r >= 0) || r > 300)
			{
				if (Input::GetVKey('D') == true || Input::GetVKey(VK_RIGHT) == true)
				{
					m_vx = 0.0f;
				}
			}
			if (r > 120 && r < 235)
			{
				if (Input::GetVKey('A') == true || Input::GetVKey(VK_LEFT) == true)
				{
					m_vx = 0.0f;
				}

			}
			if (r > 60 && r < 120)
			{
				if (Input::GetVKey('S') == true)
				{
					if (r > 0 && r < 180)
						Scene::SetScene(new CSceneOver());
				}
				else
					Scene::SetScene(new CSceneOver());
			}
		}
	}

	//�G�Ɠ������Ă��邩�m�F
	if (hit->CheckObjNameHit(OBJ_METEOFALL) != nullptr)
	{
		//��l�����G�Ƃǂ̊p�x�������Ă��邩���m�F
		HIT_DATA**hit_data;           //�����������ׂ̍��ȏ������邽�߂̍\����
		hit_data = hit->SearchObjNameHit(OBJ_METEOFALL);//hit_data�Ɏ�l���Ɠ������Ă��鑼�S�Ă�HitBox�Ƃ̏�������

		for (int i = 0; i < hit->GetCount(); i++)
		{
			//�G�̍��E�ɓ���������
			float r = 0;
			for (int i = 0; i < 10; i++)
			{
				if (hit_data[i] != nullptr) {
					r = hit_data[i]->r;
				}
			}

			if ((r < 75 && r >= 0) || r > 300)
			{
				if (Input::GetVKey('D') == true || Input::GetVKey(VK_RIGHT) == true)
				{
					m_vx = 0.0f;
				}
			}
			if (r > 120 && r < 235)
			{
				if (Input::GetVKey('A') == true || Input::GetVKey(VK_LEFT) == true)
				{
					m_vx = 0.0f;
				}

			}
			if (r > 60 && r < 120)
			{
				if (Input::GetVKey('S') == true)
				{
					if (r > 0 && r < 180)
						Scene::SetScene(new CSceneOver());
				}
				else
					Scene::SetScene(new CSceneOver());
			}
		}
	}

	//�G�Ɠ������Ă��邩�m�F
	if (hit->CheckObjNameHit(OBJ_METEO) != nullptr)
	{
		//��l�����G�Ƃǂ̊p�x�������Ă��邩���m�F
		HIT_DATA**hit_data;           //�����������ׂ̍��ȏ������邽�߂̍\����
		hit_data = hit->SearchObjNameHit(OBJ_METEO);//hit_data�Ɏ�l���Ɠ������Ă��鑼�S�Ă�HitBox�Ƃ̏�������

		for (int i = 0; i < hit->GetCount(); i++)
		{
			//�G�̍��E�ɓ���������
			float r = 0;
			for (int i = 0; i < 10; i++)
			{
				if (hit_data[i] != nullptr) {
					r = hit_data[i]->r;
				}
			}

			if ((r < 75 && r >= 0) || r >= 290)
			{
				if (m_c == true)
				{
					Scene::SetScene(new CSceneOver());
				}
			}
		}
	}

	//�ʒu�̍X�V
	g_px += m_vx;
	g_py += m_vy;
	m_pos_x += m_vx;
	m_pos_y += m_vy;

	//HitBox�̈ʒu���X�V
	hit->SetPos(g_px + 18 - hit_size_x, g_py + hit_size, 64 - hit_size, 32 + hit_size_x2);

	if (hit->CheckObjNameHit(OBJ_BLOCK) != nullptr)
	{
		Scene::SetScene(new CSceneOver());//��O�ɏo���烊�X�^�[�g
		g_px = 64.0f;
		g_py = 500.0f;
	}
}

//�h���[
void CObjHero::Draw()
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
	dst.m_top = 0.0f + g_py;
	dst.m_left = (64.0f*m_posture) + g_px;
	dst.m_right = (64 - 64.0f*m_posture) + g_px;
	dst.m_bottom = 64.0f + g_py;


	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}