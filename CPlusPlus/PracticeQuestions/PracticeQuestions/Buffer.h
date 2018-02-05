#pragma once
#include <thread>
#include <deque>
#include <mutex>
#include <chrono>
#include <condition_variable>
class Buffer
{
public:
	void add(int num) {
		while (true) {
			std::unique_lock<std::mutex> locker(mu);
			cond.wait(locker, [this]() {return buffer_.size() < size_; });
			buffer_.push_back(num);
			locker.unlock();
			cond.notify_all();
			return;
		}
	}
	int remove() {
		while (true)
		{
			std::unique_lock<std::mutex> locker(mu);
			cond.wait(locker, [this]() {return buffer_.size() > 0; });
			int back = buffer_.back();
			buffer_.pop_back();
			locker.unlock();
			cond.notify_all();
			return back;
		}
	}
	Buffer() {}
private:
	// Add them as member variables here
	std::mutex mu;
	std::condition_variable cond;

	// Your normal variables here
	deque<int> buffer_;
	const unsigned int size_ = 10;
};