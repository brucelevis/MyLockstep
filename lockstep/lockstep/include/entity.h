#ifndef LOCKSTEP_ENTITY_H
#define LOCKSTEP_ENTITY_H
#include "lockstep.h"
#include <map>
using namespace std;
namespace lockstep
{
	class World;
	class Component;
	class Entity
	{
	public:
	
		Entity(World* pWorld, unsigned long long id, int type);
		virtual ~Entity();

		Entity(Entity&) = delete;
		Entity& operator=(const Entity&) = delete;
	public:

		inline unsigned long long GetId() { return mId; }
		inline Vector2 GetPos() { return mPos; }
	
		inline void SetPos(Vector2 pos) { mPos = pos; }

		inline int GetD() { return mD; }
		inline void SetD(int d) { mD = d; }
		inline int GetVisual() { return mVisual; }
		inline void SetVisual(int visual) { mVisual = visual; }
		inline int GetCamp() { return mCamp; }
		inline void SetCamp(int camp) { mCamp = camp; }
		inline void SetFrozen(int frozen) { mFrozen = frozen; }
		inline int GetFrozen() { return mFrozen; }
		inline int GetXMove() { return mXMove; }
		inline void SetXMove(int x_move) { mXMove = x_move; }
		inline int GetNextXMove() { return mNextXMove; }
		inline void SetNextXMove(int x_move) { mNextXMove = x_move; }
	public:
		bool GetIsSkill();
		void SetIsSkill(bool is_skill);
		bool GetIsCmdCtr();
		void SetIsCmdCtr(bool is_cmd_ctr);
		void Add(string name, Component* pCompoent);
		void Remove(string name);
		Component* Get(string type);
		int GetType() { return mType; }
	private:

		map<string, Component*> mComponent;
		World* mWrold;
		unsigned long long mId;
		int mType;
		Vector2 mPos; //λ��
		int mD;//����
		int mVisual; //Ԥ��Id;
		int mCamp;//��Ӫ
		int mFrozen;//��ֱ֡��
		int mXMove;//��ǰ�ƶ�����
		int mNextXMove;//��һ���ƶ��ı���
		unsigned int mState;

	};
}


#endif // !_ENTITY_H


