//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjMeteo.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

ObjMeteo::ObjMeteo(float x, float y)
{
	m_px = x;		//�ʒu
	m_py = y;
}

//�C�j�V�����C�Y
void ObjMeteo::Init()
{
	m_ani_time = 0;
	m_ani_frame = 0;
	m_ani_max_time = 15;
	m_vx = 0.0f;		//�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 1.0f;	//�E����0.0f ������1.0f

	m_speed_power = 10.0f;	//�ʏ푬�x

	m_move = true;			//true=�E false=��

	//block�Ƃ̏Փˏ�Ԋm�F
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 128, 32, ELEMENT_ENEMY, OBJ_METEO, 1);
}

//�A�N�V����
void ObjMeteo::Action()
{
	//��l���̈ʒu���擾
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	m_ani_time += 1;
	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}
	if (m_ani_frame == 7)
	{
		m_ani_frame = 0;
	}
	//����
	//if (m_py > 1000.0f)
	//{
	//	;
	//}

	////�ʏ푬�x
	//m_speed_power = 10.0f;


	//�u���b�N�Փ˂Ō����ύX
	//if (m_hit_down == true)
	//{
	//	m_move = true;
	//}
	//if (m_hit_up == true)
	//{
	//	m_move = false;
	//}

	////����
	//if (m_move == false)
	//{
	//	m_vy += m_speed_power;
	//}
	//else if (m_move == true)
	//{
	//	m_vy -= m_speed_power;
	//}

	////���C
	//m_vx += -(m_vx * 0.098);
	//m_vy += -(m_vy * 0.098);


	//�u���b�N�^�C�v���m�p�̕ϐ����Ȃ����߂̃_�~�[
	int d;

	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scrollx = block->GetScrollX();
	m_scrolly = block->GetScrollY();
	memcpy(m_map, block->m_map, sizeof(int) * 19 * 65);

	//�ʒu�̍X�V
	/*m_px += m_vx;
	m_py += m_vy;*/

	//HitBox�̈ʒu�̕ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + block->GetScroll(), m_py);

	//�o���b�g�ɓ������Ă��邩
	/*if (hit->CheckObjNameHit(ELEMENT_BULLET) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}*/

}

//�h���[
void ObjMeteo::Draw()
{
	int AniData[7] =
	{
		0,1,2,3,4,5,6
	};

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

				//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f - AniData[m_ani_frame] * 128;
	src.m_right = 130.0f - AniData[m_ani_frame] * 128;
	src.m_bottom = 50.0f;


	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//�\���ʒu�̐ݒ�
	dst.m_top = -15.0f + m_py;						//���`��ɑ΂��ăX�N���[���̉e����������
	dst.m_left = (ALL_BLOCK_SIZE * m_posture) + m_px-35+ block->GetScroll();
	dst.m_right = (ALL_BLOCK_SIZE - ALL_BLOCK_SIZE * m_posture) + m_px+145 + block->GetScroll();
	dst.m_bottom = ALL_BLOCK_SIZE + m_py;

	//�`��
	Draw::Draw(4, &src, &dst, c, 0.0f);
}

//wallHit�֐�
//�����P    float * x           :������s��object��X�ʒu
//�����Q    float * y           :������s��object��Y�ʒu
//�����R    bool     scroll_on  :������s��object�̓X�N���[���̉e���^���邩�ǂ����itrue=�^����@false=�^���Ȃ��j
//�����S    bool *   up         :�㉺���E����̏㕔���ɓ������Ă��邩�ǂ�����Ԃ�
//�����T    bool *   down       :�㉺���E����̉������ɓ������Ă��邩�ǂ�����Ԃ�
//�����U    bool *   left       :�㉺���E����̍������ɓ������Ă��邩�ǂ�����Ԃ�
//�����V    bool *   right      :�㉺���E����̉E�����ɓ������Ă��邩�ǂ�����Ԃ�
//�����W    float * vx          :���E���莞�̔����ɂ��ړ������E�͂̒l�ς��ĕԂ�
//�����X    float * vy          :�㉺���莞�ɂ�鎩�R�����^���̈ړ������E�͂̒l�ς��ĕԂ�
//�����P�O  int * bt            :���������莞�A����ȃu���b�N�̃^�C�v��Ԃ�
//������s��object�ƃu���b�N64�~64����ŁA�����蔻��Ə㉺���E������s��
//���̌��ʂ͈���4�`10�ɕԂ�
void ObjMeteo::MeteoHit(
	float*x, float*y, bool scroll_on,
	bool*up, bool*down, bool*left, bool*right,
	float*vx, float*vy, int*bt
)

{
	//�Փˏ�Ԋm�F�p�t���O�̏�����
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//����ł���block�̎�ނ̏�����
	*bt = 0;

	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 19; i++)
	{

		for (int j = 0; j < 65; j++)
		{
			if (m_map[i][j] > 0 && m_map[i][j] != 30)
			{
				//�v�f�ԍ������W�ɕύX
				float bx = j*32.0f;
				float by = i*32.0f;

				//�X�N���[���̉e��
				float scrollx = scroll_on ? m_scrollx : 0;
				float scrolly = scroll_on ? m_scrolly : 0;

				//�I�u�W�F�N�g�ƃu���b�N�̓����蔻��
				if ((*x + (-scrollx) + 32.0f > bx) && (*x + (-scrollx) < bx + 32.0f) && (*y + (-scrolly) + 32.0f > by) && (*y + (-scrolly)< by + 32.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float rvx = (*x + (-scrollx)) - bx;
					float rvy = (*y + (-scrolly)) - by;

					//���������߂�
					float len = sqrt(rvx*rvx + rvy*rvy);

					//�p�x�����߂�
					float r = atan2(rvy, rvx);
					r = r*180.0f / 3.14f;

					if (r < 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);
					//len��������̒����̂��Z���ꍇ����ɓ���
					if (len < 79.0f)
					{
						//�p�x�ŏ㉺���E�𔻒�
						if ((r < 75 && r>0) || r > 315)
						{
							//�E
							*right = true;//�I�u�W�F�N�g�̍��̕������Փ˂��Ă���
							*x = bx + 32.0f + (scrollx);//�u���b�N�̈ʒu+��l���̕�
							*vx = 0.0f;//-VX*�����W��
						}
						if (r > 75 && r < 128)
						{
							//��
							*down = true;//��l���̉��̕������Փ˂��Ă���
							*y = by - 32.0f + (scrolly);//�u���b�N�̈ʒu-��l���̕�
							*vy = 0.0f;
						}
						if (r > 128 && r < 170)
						{
							//��
							*left = true;//��l���̉E�̕������Փ˂��Ă���
							*x = bx - 32.0f + (scrollx);//�u���b�N�̈ʒu-��l���̕�
							*vx = -(*vx)*0.0f;//-VX*�����W��
						}
						if (r > 190 && r < 315)
						{
							//��
							*up = true;//��l���̏�̕������Փ˂��Ă���
							*y = by + 32.0f + (scrolly);//�u���b�N�̈ʒu+��l���̕�
							if (*vy < 0)
							{
								*vy = 0.0f;
							}
						}

					}
				}
			}
		}
	}
}