<<<<<<< HEAD
<<<<<<< HEAD
1234564513465465123454641

=======
#include <iostream>
class DateTime {
private:
  static int sth;
  int year, month, day;
  int hour, minute, second;
public:
  DateTime();
  DateTime(int y, int m, int d, int hour, int minute, int second); 
  DateTime(const DateTime &dt);
  ~DateTime();
  static void showTime();
  void showMoon();  //×÷Òµ£º½«µ±Ç°¹«Àú×ª»»ÎªÅ©ÀúÏÔÊ¾³öÀ´ 
};

int DateTime::sth = 0;

int main() {
  DateTime dt, dt1(2020, 3, 27, 10, 40, 55);
  DateTime dt2(dt), &dt3 = dt;
  DateTime *dt4 = &dt;
  dt.showTime();
  dt1.showTime();
  dt2.showTime();
  dt3.showTime();
  dt4->showTime();
  return 0;
}
DateTime::DateTime()
{
  year = 2020; month = 3; day = 20;
  hour = 11; minute = 27; second = 55;
  sth = 11;
}
DateTime::DateTime(int y, int m, int d, int hour, int minute, int second)
{
  year = y; month = m; day = d;
  this->hour = hour; this->minute = minute; this->second = second;
}
DateTime::DateTime(const DateTime &dt)
{
  year = dt.year; month = dt.month; day = dt.day;
  hour = dt.hour; minute = dt.minute; second = dt.second;
}
DateTime::~DateTime() 
{
  std::cout << " Go die, Ha~Ha~" << std::endl;
}
void DateTime::showTime()
{
  printf("µ±Ç°Ê±¼ä£º%d/%d/%d %d:%d:%d\n", year, month, day, hour, minute, second);
  std::cout << sth << std::endl;
}
 
>>>>>>> upstream/master
=======
#include <iostream>
int a[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int b[] = {-5, 25, 54, 84, 114, 144, 173, 203, 232, 261, 291, 320, 350};
class DateTime {
	private:
		int year, month, day;
		int month_1, day_1;
  	int hour, minute, second;
  	int n_day;
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
	std::cout << "è¾“å…¥å½“å‰æ—¶é—´(ä»…æ”¯æŒ2020å¹´)ï¼š" << std::endl;
	scanf("%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);
}
DateTime::~DateTime() 
{
  std::cout << "Over" << std::endl;
}
void DateTime::showTime()
{
	printf("å½“å‰æ—¶é—´ï¼š%d/%d/%d %d:%d:%d\n",
	year, month, day, hour, minute, second);
}
void DateTime::showMoon()
{
	n_day = 0;
	for (int i = 1; i < month; i++) {
		n_day += a[i];
	}
	n_day += day;
	for (month_1 = 0; b[month_1] <= n_day; month_1++) ;
	month_1--;
	day_1 = n_day - b[month_1] + 1;
	if (month_1 == 0) {
		printf("å†œåŽ†æ—¶é—´ï¼š2019/12/%d %d:%d:%d\n",
		day_1, hour, minute, second);
		return;
	} else if (month_1 == 5) {
		printf("å†œåŽ†æ—¶é—´ï¼š%d/é—°å››æœˆ/%d %d:%d:%d\n",
		year, day_1, hour, minute, second);
		return;
	}
	if (month_1 > 5) month_1--;
	printf("å†œåŽ†æ—¶é—´ï¼š%d/%d/%d %d:%d:%d\n",
	year, month_1, day_1, hour, minute, second);
}
>>>>>>> 0b61a410afc755018ce517333db9fbe18e7313dd
