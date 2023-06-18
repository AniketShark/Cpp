#pragma once
#include<iostream>
#include<thread>
#include<queue>
#include <list>
#include <mutex>
#include<semaphore>

enum TaskType
{
	Engine,
	Cleaning
};

class Task
{
public:
	TaskType type;
	long duration;
};



class thread_guard
{
public:
	std::thread& t;
	explicit thread_guard(std::thread& thread) : t(thread) {}
	~thread_guard()
	{
		if (t.joinable())
		{
			t.join();
		}
	}
	thread_guard(thread_guard& const) = delete;
	thread_guard& operator=(thread_guard& const) = delete;
};

extern std::list<int> threadSafeList;
extern std::mutex m;
extern std::condition_variable condition;
extern std::counting_semaphore full;
extern std::counting_semaphore empty;


void FunctionA();
void FunctionB();
void FunctionC();
void ThreadJoinAndDetach();
void ThrowException();

void CleaningThread(long deadline);
void FullSpeedThread(long deadline);
void StopThread(long deadline);

void simple_task_scheduler_using_threads();
void TaskWorker(int& command, std::queue<Task*>& cleaningQueue);
void multithreading_command_ship();
void multithreading_useful_methods();
void multithreading_ship_sailing_example(int & currentCommand,std::queue<Task*>& cleaningQueue, std::queue<Task*>& engineQueue);

void mutex_thread(int x);
void mutex_lock_guard_thread(int x);
void multithreading_mutex_example();

void multithreading_producer_conditional();
void multithreading_consumer_conditional();

//void multithreading_producer_counting_semaphore();
//void multithreading_consumer_counting_semaphore();
