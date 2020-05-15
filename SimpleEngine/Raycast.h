#pragma once

class Vector2;
class GameObject;

GameObject* RayCastOrNull(const Vector2& origin, const Vector2& direction, int maxDistance);