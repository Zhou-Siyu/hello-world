#include "time.h"
#include "stdio.h"
#include "stdlib.h"
#include <iostream>
using namespace std;
int a[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//ũ��ÿ�³�һ��Ӧ��2020��ĵ�x��
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
	cout << "��֧�ֵ�2020��ĩ" << endl;
	//�ó�ϵͳ��ǰʱ�� 
	time_t now;
	struct tm *timenow;
	time(&now);
	timenow = localtime(&now);
	year = timenow->tm_year+1900; month = timenow->tm_mon+1; day = timenow->tm_mday;
	hour = timenow->tm_hour; minute = timenow->tm_min; second = timenow->tm_sec; 
}
DateTime::~DateTime() 
{
  cout << "Over" << endl;
}
void DateTime::showTime()
{
	printf("��ǰʱ�䣺%d/%d/%d %d:%d:%d\n",
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
		printf("ũ��ʱ�䣺2019/12/%d %d:%d:%d\n",
		day_1, hour, minute, second);
		return;
	} else if (month_1 == 5) {
		printf("ũ��ʱ�䣺%d/������/%d %d:%d:%d\n",
		year, day_1, hour, minute, second);
		return;
	}
	if (month_1 > 5) month_1--;
	printf("ũ��ʱ�䣺%d/%d/%d %d:%d:%d\n",
	year, month_1, day_1, hour, minute, second);
}
