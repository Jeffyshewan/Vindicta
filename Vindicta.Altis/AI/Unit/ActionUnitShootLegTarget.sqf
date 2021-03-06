
#define OOP_INFO
#define OOP_ERROR
#define OOP_WARNING
#define OOP_DEBUG
#include "common.hpp"
#define IS_TARGET_ARRESTED_UNCONSCIOUS_DEAD !(alive _target) || (animationState _target == "unconsciousoutprone") || (animationState _target == "unconsciousfacedown") || (animationState _target == "unconsciousfaceup") || (animationState _target == "unconsciousrevivedefault") || (animationState _target == "acts_aidlpsitmstpssurwnondnon_loop") || (animationState _target == "acts_aidlpsitmstpssurwnondnon01")

/*
Class: Action.ActionUnitShootLegTarget
Makes a single unit shoot near a target like a warning shot with a chance of hitting leg

Parameters:
"target" - object handle of the target to shoot near
*/
#define pr private

CLASS("ActionUnitShootLegTarget", "ActionUnit")

	VARIABLE("target");
	VARIABLE("objectHandle");
	VARIABLE("countAmmo");
	VARIABLE("spawnHandle");
	VARIABLE("isHandleSpawned");
	VARIABLE("startSpawnedTime");

	METHOD("new") {
		params [["_thisObject", "", [""]], ["_AI", "", [""]], ["_target", objNull, [objNull]] ];

		pr _a = GETV(_AI, "agent");
		pr _oh = CALLM0(_a, "getObjectHandle");
		pr _count = _oh ammo primaryWeapon _oh;

		T_SETV("isHandleSpawned", 0);
		T_SETV("spawnHandle", scriptNull);
		T_SETV("objectHandle", _oh);
		T_SETV("countAmmo", _count);
		T_SETV("target", _target);
	} ENDMETHOD;

	METHOD("activate") {
		params [["_thisObject", "", [""]]];
		
		pr _oh = T_GETV("objectHandle");
		pr _target = T_GETV("target");
		pr _posUnit = getPos _oh;

		_oh reveal _target;
		_oh setSpeedMode "FULL";
		_oh setBehaviour "CARELESS";
		
		T_SETV("state", ACTION_STATE_ACTIVE);
		ACTION_STATE_ACTIVE
	} ENDMETHOD;
	
	// logic to run each update-step
	METHOD("process") {
		params [["_thisObject", "", [""]]];

		CALLM0(_thisObject, "activateIfInactive");

		pr _state = T_GETV("state");
		if (_state != ACTION_STATE_ACTIVE) exitWith {_state};

		pr _oh = T_GETV("objectHandle");
		pr _oldCount = T_GETV("countAmmo");
		pr _count = _oh ammo primaryWeapon _oh;

		if (_count < _oldCount - 1) exitWith {
			T_SETV("state", ACTION_STATE_COMPLETED);
			ACTION_STATE_COMPLETED
		};

		pr _target = T_GETV("target");
		pr _posUnit = getPos _oh;
		pr _posTarget = getPos _target;

		if (IS_TARGET_ARRESTED_UNCONSCIOUS_DEAD) exitWith {
			T_SETV("state", ACTION_STATE_COMPLETED);
			ACTION_STATE_COMPLETED
		};

		if ((_posUnit distance2D _posTarget) < 40 ) then {
			if (T_GETV("isHandleSpawned") != 1) then {
				T_SETV("startSpawnedTime", time);
				pr _spawnedTime = T_GETV("startSpawnedTime");

				pr _handle = [_target, _oh, _oldCount, _posUnit, _posTarget, _spawnedTime] spawn {
					params ["_target", "_oh", "_oldCount", "_posUnit", "_posTarget", "_spawnedTime"];

					pr _fakeTarget = "FireSectorTarget" createVehicle (getpos _target);
					_fakeTarget attachto [_target, [0, 0, 0], "leftleg"];
					_fakeTarget hideObject true;
					doStop _oh;
					_oh disableAI "autotarget";
					_oh disableAI "target";
					_oh setBehaviour "combat";
					_oh reveal [_fakeTarget, 1];

					// add check to not fire GL or anything other than bullets
					_oh selectWeapon (primaryWeapon _oh);
					sleep 1;
					_oh doTarget _fakeTarget;
					sleep 0.5;
					_oh forceWeaponFire [weaponState _oh select 1, weaponState _oh select 2];

					waitUntil {
						_oldCount - 1 >= (_oh ammo primaryWeapon _oh) ||
						(_posUnit distance2D _posTarget) > 100 ||
						IS_TARGET_ARRESTED_UNCONSCIOUS_DEAD ||
						time > (20 + _spawnedTime)
					};

					deleteVehicle _fakeTarget;
					_oh enableAI "target";
					_oh enableAI "autotarget";
					_oh setBehaviour "SAFE";
				};

				T_SETV("spawnHandle", _handle);
				T_SETV("isHandleSpawned", 1);
				ACTION_STATE_ACTIVE
			} else {				
				if (scriptDone T_GETV("spawnHandle")) then {
					ACTION_STATE_COMPLETED
				} else {
					ACTION_STATE_ACTIVE
				};
			};
		} else {
			_oh doMove _posTarget;
			ACTION_STATE_ACTIVE
		};
	} ENDMETHOD;
ENDCLASS;
