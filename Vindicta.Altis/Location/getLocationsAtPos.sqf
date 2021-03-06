#include "..\OOP_Light\OOP_Light.h"

// Class: Location
/*
Method: (static)getLocationsAtPos
Returns an array of locations that have the provided position/object within its border. 
Same as getLocationAtPos, but returns all locations

Parameters: _pos, _locations

_pos - position or object
_locations - optional, array of locations to search through. If omitted, all locations are checked.

Returns: <Location> or "" if there is no such location

Author: Sparker 08 June 2019
*/

#define pr private

params [ ["_thisClass", "", [""]], ["_pos", [], [objNull, []]], ["_locations", []]];

pr _locsToCheck = if (count _locations > 0) then {_locations} else {GETSV("Location", "all")};

_locsToCheck select {
	_pos inArea GETV(_x, "border")
}