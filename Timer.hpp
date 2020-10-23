#include <chrono>


class Timer{
	public:
		Timer();
		~Timer();
		void Stop();
	private:
		chrono::time_point<chrono::high_resolution_clock> m_Start;
};