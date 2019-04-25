#ifndef LOCKSTEP_WORLD_H
#define LOCKSTEP_WORLD_H
#include <vector>
#include <string>
#include "data.h"
#include<map>
using namespace std;
namespace lockstep
{
	class Entity;
	class GSystem;
	class CmdAdapter;
	class Controller;
	class Component;
	class CRandom;
	class Physix;
	class World
	{
		friend class  Entity;
		friend class CmdAdapter;
		friend class Controller;
		friend class SystemFactory;
	public:
		World();
		~World();

		World(World&) = delete;
		World& operator=(const World&) = delete;
		
	public:
		//��������
		void DoCmd(command_data* cmd, int size);
		//ѭ��֡
		void Tick();
		//���ص�ͼ����
		bool Load(const level_data map);
		//���ص�ͼ�г�ʼ����ʵ��
		bool LoadEntitys(const entity_data* data, int num);

	public:
		GSystem* GetSystem(string name);
	public:
		Entity* FindEntity(unsigned long long id);
		inline int GetMinX() { return mMinX;  }
		inline int GetMaX() { return mMaxX; }
		inline int GetMaxY() { return mMaxY; }

		inline CRandom* GetRand() { return mRand; }
		inline Physix* GetPhysix() { return mPPhysx; }
	private:
		
		void set_enable(string name, Component* pComponent);
		void set_disable(string name, Component* pComponent);
		Entity* create_entity(int type);
		Entity* create_entity_with_id(unsigned long long id, int type);
		void delete_entity(Entity* pEnity);
		
		bool load_entity(entity_data& data);
		

	private:
		std::map<unsigned long long, Entity*> mEntitys; //��ͼ�����е�ʵ�嶼Ҫ�洢������
		std::map<string, GSystem*> mSystem; //���������ϵͳ
		int mSeed; //�������
		unsigned long long mEnityId; //���������Ϊû��Id��ʵ�����Id��


	private:
		int mMinX; //��ͼ��߽�
		int mMaxX; //��ͼ�ұ߽�
		int mMaxY; //��ͼ�����
		CRandom* mRand;
		Physix* mPPhysx;
	};

}
#endif // !_WORLD_H

