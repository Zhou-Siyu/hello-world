#include <iostream>
class DateTime {
	private:
		int year, month, day;
		int year_1, month_1, day_1;
  	int hour, minute, second;
  public:
  	DateTime();
  	~DateTime();
  	void showTime();
  	void showMoon();
};

int main()
{
	DateTime dt;
	dt.showTime();
	dt.showMoon();
	return 0;
}

DateTime::DateTime()
{
	year = 2020; month = 3; day = 20;
	year_1 = 2020; month_1 = 2; day_1 = day+7;
  hour = 11; minute = 27; second = 55;
}
DateTime::~DateTime() 
{
  std::cout << "Over" << std::endl;
}
void DateTime::showTime()
{
	printf("当前时间：%d/%d/%d %d:%d:%d\n",
	year, month, day, hour, minute, second);
}
void DateTime::showMoon()
{
	printf("农历时间：%d/%d/%d %d:%d:%d\n\n",
	year_1, month_1, day_1, hour, minute, second);
}
