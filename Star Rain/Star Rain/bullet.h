#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�e��
class Bullet : public CObj
{
	public:
		Bullet() {};
		~Bullet() {};
		void Init();
		void Action();
		void Draw();
	private:
};