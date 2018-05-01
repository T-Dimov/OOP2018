#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

double stackSum(const stack<double> &st)
{
	stack<double>	copy = st;

	double	sum = 0;
	while (!copy.empty())
	{
		sum += copy.top();
		copy.pop();
	}

	return sum;
}

bool operator<(const stack<double> &lhs, const stack<double> &rhs)
{
	return stackSum(lhs) < stackSum(rhs);
}

size_t indexLightest(const stack<double> *arr, size_t size)
{
	size_t ind = 0;

	for (size_t i = 1; i < size; i++)
	{
		if (arr[i] < arr[ind])
		{
			ind = i;
		}
	}

	return ind;
}

void sort(stack<double> *arr, size_t size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		int iMax = i;

		for (size_t j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[iMax])
			{
				iMax = j;
			}
		}

		if (iMax != i)
		{
			swap(arr[i], arr[iMax]);
		}
	}
}

class Report
{
public:
	Report(const char *name = "", const char *num = "AAA1", const char *title_ = "", const char *time = "19000101 00:00");
	Report(const Report &other);
	Report& operator=(const Report &rhs);
	~Report();

	void setReporter(const char *name);
	void setSessionName(const char *num);
	void setTitle(const char *title_);
	void setDateTime(const char *time);

	const char *setReporter() const;
	const char *getReportNum() const;
	const char *setTitle() const;
	const char *getDateTime() const;

private:
	void copy(const Report &other);
	void del();

	char *reporter;
	char reportNum[5];
	char *title;
	char dateTime[15];
};

Report::Report(const char *name, const char *num, const char *title_, const char *time) : reporter(nullptr), title(nullptr)
{
	setReporter(name);

	setSessionName(num);

	setTitle(title_);

	setDateTime(time);
}

Report::Report(const Report &other) : reporter(nullptr), title(nullptr)
{
	copy(other);
}

Report &Report::operator=(const Report &rhs)
{
	if (this != &rhs)
	{
		del();
		copy(rhs);
	}

	return *this;
}

Report::~Report()
{
	del();
}

void Report::setReporter(const char *name)
{
	delete[] reporter;
	size_t nameLen = strlen(name) + 1;
	reporter = new char[nameLen];
	strcpy_s(reporter, nameLen, name);
}

void Report::setSessionName(const char *num)
{
	assert(strlen(num) == 4);
	for (size_t i = 0; i < 3; i++)
	{
		assert(num[i] >= 'A' && num[i] <= 'Z');
	}
	assert(num[3] >= '1' && num[3] <= '9');
	strcpy_s(reportNum, 5, num);
}

void Report::setTitle(const char *title_)
{
	delete[] title;
	size_t titleLen = strlen(title_) + 1;
	title = new char[titleLen];
	strcpy_s(title, titleLen, title_);
}

void Report::setDateTime(const char *time)
{
	assert(strlen(time) == 14);
	for (size_t i = 0; i < 8; i++)
	{
		assert(time[i] >= '0' && time[i] <= '9');
	}
	assert(time[8] == ' ');
	for (size_t i = 9; i < 11; i++)
	{
		assert(time[i] >= '0' && time[i] <= '9');
	}
	assert(time[11] == ':');
	for (size_t i = 12; i < 14; i++)
	{
		assert(time[i] >= '0' && time[i] <= '9');
	}
	strcpy_s(dateTime, 15, time);
}

const char *Report::setReporter() const
{
	return reportNum;
}

const char *Report::getReportNum() const
{
	return reportNum;
}

const char *Report::setTitle() const
{
	return title;
}

const char *Report::getDateTime() const
{
	return dateTime;
}

void Report::copy(const Report &other)
{
	size_t nameLen = strlen(other.reporter) + 1;
	reporter = new char[nameLen];
	strcpy_s(reporter, nameLen, other.reporter);

	strcpy_s(reportNum, 5, other.reportNum);

	size_t titleLen = strlen(other.title) + 1;
	title = new char[titleLen];
	strcpy_s(title, titleLen, other.title);

	strcpy_s(dateTime, 15, other.dateTime);
}

void Report::del()
{
	delete[] reporter;
}

class ConferenceSession
{
public:
	ConferenceSession(const char *name, const char *time);

	const char *getSessionName() const;
	const char *getDate() const;

	bool presentReport(const Report &ticket);
	int countOfPresentedReports() const;

private:
	char sessionName[4];
	char date[9];
	Report reports[9];
	size_t reportCount;
};

ConferenceSession::ConferenceSession(const char *name, const char *date_) : reportCount(0)
{
	assert(strlen(name) == 3);
	for (size_t i = 0; i < 3; i++)
	{
		assert(name[i] >= 'A' && name[i] <= 'Z');
	}
	strcpy_s(sessionName, 4, name);

	assert(strlen(date_) == 8);
	for (size_t i = 0; i < 8; i++)
	{
		assert(date_[i] >= '0' && date_[i] <= '9');
	}
	strcpy_s(date, 9, date_);
}

const char *ConferenceSession::getSessionName() const
{
	return sessionName;
}

const char *ConferenceSession::getDate() const
{
	return date;
}

bool ConferenceSession::presentReport(const Report &report)
{
	const char *reportNum = report.getReportNum();
	const char *reportTime = report.getDateTime();

	if (strncmp(reportNum, sessionName, 3) == 0 && strncmp(reportTime, date, 8) == 0)
	{
		size_t index = reportNum[3] - '1';
		reports[index] = report;
		reportCount++;
		return true;
	}

	return false;
}

int ConferenceSession::countOfPresentedReports() const
{
	return reportCount;
}

int main()
{
	size_t n = 2;
	stack<double>	*arr = new stack<double>[n];

	stack<double> st1;
	st1.push(2);

	stack<double> st2;
	st2.push(1);

	arr[0] = st1;
	arr[1] = st2;

	cout << indexLightest(arr, n) << endl;
	sort(arr, n);

	cout << arr[0].top() << " " << arr[1].top() << endl;

	ConferenceSession ifs("IFS", "20180411");
	Report gc("GC", "IFS7", "", "20180411 09:00");

	gc.setTitle("IF Modal Operators");

	ifs.presentReport(gc);

	size_t reportCount = ifs.countOfPresentedReports();
	cout << reportCount << endl << reportCount * 30 << endl;
	cout << ifs.getSessionName() << endl;
	cout << ifs.getDate() << endl;

	cin.get();
	delete[] arr;
	return 0;
}

