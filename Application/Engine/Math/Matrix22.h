#pragma once
#include "Vector2.h"

namespace nc
{
	struct Matrix22
	{
		float m[2][2]; // column / row
		// m[0][0] m[1][0]
		// m[0][1] m[1][1]

		Matrix22() = default;
		Matrix22(const Vector2& column1, const Vector2& column2)
		{
			m[0][0] = column1[0]; m[1][0] = column2[0];
			m[0][1] = column1[1]; m[1][1] = column2[1];
		}

		//Uniform Scaling
		void Scale(float s)
		{
			m[0][0] = s; m[1][0] = 0;
			m[0][1] = 0; m[1][1] = s;
		}
		
		//Non-Uniform Scaling
		void Scale(float sx, float sy)
		{
			m[0][0] = sx; m[1][0] = 0;
			m[0][1] = 0; m[1][1] = sy;
		}

		//Vector Based Non-Uniform Scaling
		void Scale(const Vector2& v)
		{
			m[0][0] = v.x; m[1][0] = 0;
			m[0][1] = 0; m[1][1] = v.y;
		}

		void Rotate(float angle)
		{
			m[0][0] = std::cos(angle); m[1][0] = std::sin(angle);
			m[0][1] = -std::sin(angle); m[1][1] = std::cos(angle);
		}

		void SetIdentity()
		{
			m[0][0] = 1; m[1][0] = 0;
			m[0][1] = 0; m[1][1] = 1;
		}

		Matrix22 operator * (const Matrix22& mx)
		{
			Matrix22 result;

			result.m[0][0] = m[0][0] * mx.m[0][0] + m[1][0] * mx.m[0][1];
			result.m[1][0] = m[0][0] * mx.m[1][0] + m[1][0] * mx.m[1][1];
			result.m[0][1] = m[0][1] * mx.m[0][0] + m[1][1] * mx.m[0][1];
			result.m[1][1] = m[0][1] * mx.m[1][0] + m[1][1] * mx.m[1][1];

			return result;
		}

		// p = mx22 * v;
		Vector2 operator * (const Vector2& v)
		{
			Vector2 result;

			result.x = v.x * m[0][0] + v.y * m[0][1];
			result.y = v.x * m[1][0] + v.y * m[1][1];

			return result;
		}
		//p = v * mx22;
		friend Vector2 operator * (const Vector2& v, const Matrix22& mx)
		{
			Vector2 result;

			result.x = v.x * mx.m[0][0] + v.y * mx.m[0][1];
			result.y = v.x * mx.m[1][0] + v.y * mx.m[1][1];

			return result;
		}
	};
}