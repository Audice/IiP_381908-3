#pragma once
class zmei
{
public:
	zmei();
	void set_x(int a);
	void set_y(int a);
	int  get_x();
	int get_y();
	int get_orientation();

private:

	int x;
	int y;
	int  orientation;
};
