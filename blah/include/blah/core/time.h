#pragma once
#include <blah/core/common.h>

namespace Blah
{
	struct Time
	{
		// ticks per second (microseconds, in this case)
		static constexpr u64 ticks_per_second = 1000000;

		// uptime, in ticks
		static u64 ticks;

		// uptime, in seconds
		static double seconds;

		// previous frame uptime, in ticks
		static u64 previous_ticks;

		// previous frame uptime, in seconds
		static double previous_seconds;

		// delta time from last frame
		static float delta;

		// time the application should pause for
		static float pause_timer;

		// pauses the entire application for the given time
		static void pause_for(float duration);

		// returns true on the given time interval
		static bool on_interval(double time, float delta, float interval, float offset);

		// returns true on the given time interval
		static bool on_interval(float delta, float interval, float offset);

		// returns true on the given time interval
		static bool on_interval(float interval, float offset = 0);

		// returns true when the given timestamp is passed
		static bool on_time(double time, double timestamp);

		// returns true between time intervals
		static bool between_interval(double time, float interval, float offset);
		
		// returns true between time intervals
		static bool between_interval(float interval, float offset = 0);
	};
}