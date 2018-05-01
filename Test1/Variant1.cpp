#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

double stackSum(const stack<double> &st)
{
	stack<double>	copy	= st;

	double	sum = 0;
	while (!copy.empty())
	{
		sum += copy.top();
		copy.pop();
	}

	return sum;
}

bool operator>(const stack<double> &lhs, const stack<double> &rhs)
{
	return stackSum(lhs) > stackSum(rhs);
}

size_t indexHeaviest(const stack<double> *arr, size_t size)
{
	size_t ind = 0;

	for (size_t i = 1; i < size; i++)
	{
		if (arr[i] > arr[ind])
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
			if (arr[j] > arr[iMax])
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

class Ticket
{
public:
	Ticket(const char *name = "", const char *num = "AA0000", const char *seat_ = "01A");
	Ticket(const Ticket &other);
	Ticket& operator=(const Ticket &rhs);
	~Ticket();

	void setPassengerName(const char *name);
	void setFlightNum(const char *num);
	void setSeat(const char *seat_);

	const char *getPassengerName() const;
	const char *getFlightNum() const;
	const char *getSeat() const;

private:
	void copy(const Ticket &other);
	void del();

	char *passengerName;
	char flightNum[7];
	char seat[4];
};

Ticket::Ticket(const char *name, const char *num, const char *seat_) : passengerName(nullptr)
{
	setPassengerName(name);

	setFlightNum(num);

	setSeat(seat_);
}

Ticket::Ticket(const Ticket &other) : passengerName(nullptr)
{
	copy(other);
}

Ticket & Ticket::operator=(const Ticket &rhs)
{
	if (this != &rhs)
	{
		del();
		copy(rhs);
	}

	return *this;
}

Ticket::~Ticket()
{
	del();
}

void Ticket::setPassengerName(const char *name)
{
	delete[] passengerName;
	size_t nameLen = strlen(name) + 1;
	passengerName = new char[nameLen];
	strcpy_s(passengerName, nameLen, name);
}

void Ticket::setFlightNum(const char *num)
{
	assert(strlen(num) == 6);
	for (size_t i = 0; i < 2; i++)
	{
		assert(num[i] >= 'A' && num[i] <= 'Z');
	}
	for (size_t i = 2; i < 6; i++)
	{
		assert(num[i] >= '0' && num[i] <= '9');
	}
	strcpy_s(flightNum, 7, num);
}

void Ticket::setSeat(const char *seat_)
{
	assert(strlen(seat_) == 3);
	for (size_t i = 0; i < 2; i++)
	{
		assert(seat_[i] >= '0' && seat_[i] <= '9');
	}
	size_t row = (seat_[0] - '0') * 10 + seat_[1] - '0';
	assert(row > 0 && row < 26);
	assert(seat_[2] >= 'A' && seat_[2] <= 'Z');
	strcpy_s(seat, 4, seat_);
}

const char *Ticket::getPassengerName() const
{
	return passengerName;
}

const char *Ticket::getFlightNum() const
{
	return flightNum;
}

const char *Ticket::getSeat() const
{
	return seat;
}

void Ticket::copy(const Ticket &other)
{
	size_t nameLen = strlen(other.passengerName) + 1;
	passengerName = new char[nameLen];
	strcpy_s(passengerName, nameLen, other.passengerName);

	strcpy_s(flightNum, 7, other.flightNum);

	strcpy_s(seat, 4, other.seat);
}

void Ticket::del()
{
	delete[] passengerName;
}

class Flight
{
public:
	Flight(const char *num, const char *time);

	const char *getFlightNum() const;
	const char *getDateTime() const;

	bool boarding(const Ticket &ticket);
	int passengersOnBoard() const;

private:
	char flightNum[7];
	char dateTime[15];
	Ticket tickets[150];
	size_t passengerCount;
};

Flight::Flight(const char *num, const char *time) : passengerCount(0)
{
	assert(strlen(num) == 6);
	for (size_t i = 0; i < 2; i++)
	{
		assert(num[i] >= 'A' && num[i] <= 'Z');
	}
	for (size_t i = 2; i < 6; i++)
	{
		assert(num[i] >= '0' && num[i] <= '9');
	}
	strcpy_s(flightNum, 7, num);

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

const char *Flight::getFlightNum() const
{
	return flightNum;
}

const char *Flight::getDateTime() const
{
	return dateTime;
}

bool Flight::boarding(const Ticket &ticket)
{
	if (strcmp(ticket.getFlightNum(), flightNum) == 0)
	{
		const char *seat = ticket.getSeat();
		size_t index = ((seat[0] - '0') * 10 + seat[1] - '1') * 6 + seat[2] - 'A';
		tickets[index] = ticket;
		passengerCount++;
		return true;
	}

	return false;
}

int Flight::passengersOnBoard() const
{
	return passengerCount;
}

int main()
{
	size_t n = 2;
	stack<double>	*arr = new stack<double>[n];

	stack<double> st1;
	st1.push(2);

	stack<double> st2;
	st2.push(3);

	arr[0] = st1;
	arr[1] = st2;

	cout << indexHeaviest(arr, n) << endl;
	sort(arr, n);

	cout << arr[0].top() << " " << arr[1].top() << endl;

	Flight af("AF3295","20180415 06:20");
	Ticket ivan("", "AF3295", "23A");
	Ticket maria("Maria Ivanova", "AF3295", "23B");

	ivan.setPassengerName("Ivan Ivanov");

	af.boarding(ivan);
	af.boarding(maria);

	cout << af.passengersOnBoard() << endl;
	cout << af.getFlightNum() << endl;
	cout << af.getDateTime() << endl;

	cin.get();
	delete[] arr;
	return 0;
}

