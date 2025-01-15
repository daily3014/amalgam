#pragma once
#include "../../SDK/SDK.h"

struct Bind_t
{
	std::string Name = "";
	int Type = 0; // Key, Class, Weapon type
	int Info = 0; // Key: Hold, Toggle, Double click, Cycle
	// Class: Scout, Soldier, Pyro, Demoman, Heavy, Engineer, Medic, Sniper, Spy
	// Weapon type: Hitscan, Projectile, Melee
	int Key = 0;
	int Index = 0;
	bool Not = false;
	KeyStorage Storage = {};

	bool Active = false;
	bool Visible = true;

	int Parent = -1;
};

class CBinds
{
public:
	void Run(CTFPlayer* pLocal, CTFWeaponBase* pWeapon);

	bool GetBind(int iID, Bind_t* pBind);

	bool HasChildren(int iBind);
	int GetParent(int iBind);
	void AddBind(int iBind, Bind_t tCond);
	void RemoveBind(int iBind, bool bForce = true);

	template <typename T>
	std::vector<Bind_t*> GetBindForCVar(const ConfigVar<T> &var);

	std::vector<Bind_t> vBinds = {};
};

ADD_FEATURE(CBinds, Binds)