#include "Debug.hpp"

int Debug::indentCounter;
std::vector<Timer*> Debug::timers;

Timer::Timer(std::string function)
	: function(function)
{
	Debug::timers.push_back(this);
}

Timer::~Timer()
{
	Debug::timers.pop_back();
}

void Timer::clearAndPrint()
{
	float average = 0;
	float max = 0;
	float sum = 0;
	for (unsigned int i = 0; i < times.size(); i++)
	{
		sum += times[i];
		if (times[i] > max)
		{
			max = times[i];
		}
	}
	average = sum/times.size();

	std::cout << "Timer \"" << function << "\": " << sum << " = " << average << " * " << times.size() << " (max=" << max << ")" << std::endl;
	times.clear();
}

TimerInstance::TimerInstance(Timer* t)
	: t(t)
{}

TimerInstance::~TimerInstance()
{
	t->times.push_back(((float) c.restart().asMicroseconds()) / 1000.f);
}

// note

void Debug::note(const std::string& s)
{
	std::cout << NOTE_COLOR << "NOTE: " << s << RESET_COLOR << std::endl;
}

// test

void Debug::test(const std::string& s)
{
	std::cout << TEST_COLOR << "TEST: " << s << RESET_COLOR << std::endl;
}

// warn

void Debug::warn(const std::string& s)
{
	std::cout << WARN_COLOR << "WARN: " << s << RESET_COLOR << std::endl;
}

// error

void Debug::error(const std::string& s)
{
	std::cout << ERROR_COLOR << "ERROR: " << s << RESET_COLOR << std::endl;
}

void Debug::time(const std::string& s)
{
	static sf::Clock c;
	int t = c.restart().asMilliseconds();
	std::cout << TIME_COLOR << "TIME: " << t << ": " << s << std::endl;
}

// func

void Debug::func(const std::string& s)
{
	std::string t = "";
	for (int i = 0; i < indentCounter; i++)
	{
		t += "    ";
	}
	std::cout << FUNC_COLOR << "FUNC:" + t + s << RESET_COLOR << std::endl;
}

void Debug::funcOn(const std::string& s)
{
	std::string t = "";
	for (int i = 0; i < indentCounter; i++)
	{
		t += "    ";
	}
	std::cout << FUNC_COLOR << "FUNC:" + t + s + " {" << RESET_COLOR << std::endl;
	indentCounter++;
}

void Debug::funcOff(const std::string& s)
{
	indentCounter--;
	std::string t = "";
	for (int i = 0; i < indentCounter; i++)
	{
		t += "    ";
	}
	std::cout << FUNC_COLOR << "FUNC:" + t + "}" << RESET_COLOR << std::endl;
}
