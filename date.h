#ifndef DATE_H
#define DATE_H
#include <iostream>

class Date
{
public:

	Date();
	Date(int _year, int _month, int _day);
	Date(const char* _yyyyMMDD, char _sep = '/');
	void Print(char _sep = '/');
	bool IsLeapYear() const;

	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;

	/* Lection 3 */
	//	Declaration of Copy Constructor
	Date(const Date & _d);
	/* End of lection 3 */

	/* Lection 4 */
	bool operator == (const Date & d) const;
	bool operator != (const Date & d) const;
	bool operator < (const Date & d) const;
	bool operator <= (const Date & d) const;
	bool operator > (const Date & d) const;
	bool operator >= (const Date & d) const;

	/* End of lection 4 */

private:

	bool IsValid() const;

	int m_Year, m_Month, m_Day;
};

inline int Date::GetYear() const
{
	return m_Year;
}

inline int Date::GetMonth() const
{
	return m_Month;
}

inline int Date::GetDay() const
{
	return m_Day;
}

inline bool Date::operator == (const Date & d) const
{
	return !(d < *this) && !(*this < d);
}

inline bool Date::operator != (const Date & d) const
{
	return (d < *this) || (*this < d);
}

std::ostream & operator << (std::ostream & o, const Date & d);
std::istream & operator >> (std::istream & i, Date & d);

#endif