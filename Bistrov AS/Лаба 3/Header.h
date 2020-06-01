#pragma once

class Load
{
private:
	int value;

	int CompA;

	int CompB;

public:

	int GetCompA();

	void SetCompA(int a);

	int GetCompB();

	void SetCompB(int a);

	void output();

	Load(int i) : value(i)

	{};

	Load();

	~Load();


	const Load& operator+(const Load& i)
	{
		return i.value;
	}

	const Load operator-(const Load& i)
	{
		return (-i.value);
	};

	friend const Load& operator++(Load& i)
	{
		i.value++;
		return i;
	};

	friend const Load operator++(Load& i, int)
	{
		Load preValue(i.value);
		i.value++;
		return i;
	}

	friend const Load& operator--(Load& i)
	{
		Load preValue(i.value);
		i.value--;
		return i;
	}

	friend const Load& operator--(Load& i, int)
	{
		Load preValue(i.value);
		i.value--;
		return preValue;
	}

	friend const Load operator+(const Load& left, const Load& right)
	{
		return Load(left.value + right.value);
	}

	friend bool operator==(const Load& left, const Load& right)
	{
		return left.value == right.value;
	}

	Load operator*(const Load& i)
	{
		int* ptr = &value;
	}

	Load& operator=(const Load& right)
	{
		if (this == &right)
		{
			return *this;
		}
		value = right.value;
		return *this;
	}



	friend const Load operator>(const Load& left, const Load& right)
	{
		if (left.value > right.value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend const Load operator<(const Load& left, const Load& right)
	{
		if (left.value < right.value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend const Load operator>=(const Load& left, const Load& right)
	{
		if (left.value >= right.value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend const Load operator<=(const Load& left, const Load& right)
	{
		if (left.value <= right.value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend const Load operator!=(const Load& left, const Load& right)
	{
		if (left.value != right.value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}



	friend const Load operator!(const Load& i)
	{
		if (i.value == 0)
		{
			return true;
		}
		else if (i.value == 1)
		{
			return false;
		}
	}

	friend const Load operator&&(const Load& left, const Load& right)
	{
		if (left.value == true, right.value == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend const Load operator||(const Load& left, const Load& right)
	{
		if (left.value == true, right.value == false)
		{
			return true;
		}

		if (left.value == false, right.value == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	friend Load operator+=(Load& left, const Load& right)
	{
		left.value += right.value;
		return left;
	}

	friend Load operator-=(Load& left, const Load& right)
	{
		left.value -= right.value;
		return left;
	}

	friend Load operator*=(Load& left, const Load& right)
	{
		left.value *= right.value;
		return left;
	}

	friend Load operator/=(Load& left, const Load& right)
	{
		left.value /= right.value;
		return left;
	}


	friend Load operator *(Load& i)
	{
		return *i;
	}

	friend Load operator &(Load& i)
	{
		return &i;
	}


	friend Load operator,(Load& left, Load& right)
	{
		return left.value, right.value;
	}
};