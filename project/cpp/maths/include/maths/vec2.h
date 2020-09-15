struct vec2
{
	union
	{
		struct
		{
			float x;
			float y;
		};
	};
	vec2(float x, float y);
	vec2 operator=(const vec2& a);
	vec2 operator+(const vec2& a);
	vec2 operator-(const vec2& a);
	vec2 operator*(const float scalar);
	vec2 operator*(const vec2& a);

};