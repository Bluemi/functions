#ifndef __DATE_CLASS__
#define __DATE_CLASS__

union Piece
{
	float f;
	int i;
};

enum Datatype { ERROR, FLOAT, INT };

class Date
{
	public:
		Date(float f);
		Date(int i);
		Date();

		Datatype getType() const;
		bool get(int&) const;
		bool get(float&) const;
	private:
		Piece p;
		Datatype d;
};

#endif
