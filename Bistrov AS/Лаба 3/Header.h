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

	void Output(const Load& load);

	Load()
	{
		value = 0;
	};

	Load(int i) : value(i)
	{};

	~Load();

	//унарные операторы
	const Load& operator+(const Load& i) //унарный плюс
	{
		return i.value;
	}

	const Load operator-(const Load& i)
	{
		return (-i.value);
	};

	//бинарные операторы

	friend const Load& operator++(Load& i) //префиксная версия возвращает значение после инкремента
	{
		i.value++;
		return i;
	};

	friend const Load operator++(Load& i, int) //постфиксная версия возвращает значение до инкремента
	{
		Load preValue(i.value);
		i.value++;
		return i;
	}
	
	friend const Load& operator--(Load& i) //префиксная версия возвращает значение после декремента
	{
		Load preValue(i.value);
		i.value--;
		return i;
	}

	friend const Load& operator--(Load& i, int) //постфиксная версия возвращает значение до декремента
	{
		Load preValue(i.value);
		i.value--;
		return preValue;
	}

	friend const Load operator+(const Load& left, const Load& right) //оператор возвращает значение i
	{
		return Load(left.value + right.value);
	}

	friend bool operator==(const Load& left, const Load& right) //оператор, создающий новое значение
	{
		return left.value == right.value;
	}

	Load operator*(const Load& i) //разыменование указателя
	{
		int* ptr = &value;
	}

	Load& operator=(const Load& right) // оператор присваивания
	{
		if (this == &right)
		{
			return *this;
		}
		value = right.value;
		return *this;
	}

	//операции сравнения

	friend const Load operator>(const Load& left, const Load& right) //оператор сравнения "Больше"
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

	friend const Load operator<(const Load& left, const Load& right) //оператор сравнения "Меньше"
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

	friend const Load operator>=(const Load& left, const Load& right) //оператор сравнения "Больше или равно"
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

	friend const Load operator<=(const Load& left, const Load& right) //оператор сравнения "Меньше или равно"
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

	friend const Load operator!=(const Load& left, const Load& right) //оператор сравнения "Неравенство"
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

	// логические операции

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
		if (left.value==true, right.value==true)
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
		
		if(left.value == false, right.value == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// составное присваивание

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

	//oператоры работы с указателями и членами класса

	friend Load operator *(Load& i)
	{
		return *i;
	}

	friend Load operator &(Load& i)
	{
		return &i;
	}

	//Другие операторы

	friend Load operator,(Load& left, Load& right)
	{
		return left.value, right.value;
	}
};
