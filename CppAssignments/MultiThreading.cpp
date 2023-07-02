#include "MultiThreading.h"
#include <chrono>
#include <queue>
#include<cstdlib>

void FunctionA()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(8000));
	printf("Hello World from FunctionA! : %d\n", std::this_thread::get_id());
}

void FunctionB()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	std::thread thread2(FunctionC);
	thread2.join();
	printf("Hello World from FunctionB! : %d\n", std::this_thread::get_id());
}

void FunctionC()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	printf("Hello World from FunctionC! : %d\n", std::this_thread::get_id());
}

void ThreadJoinAndDetach()
{
	std::thread thread1(FunctionA);
	std::thread thread2(FunctionB);
	thread1.join();
	thread2.detach();
	printf("Hello World from ThreadJoinAndDetach! : %d\n", std::this_thread::get_id());
}

void ThrowException()
{
	std::runtime_error("Throwing Error\n");
}

void CleaningThread(long time)
{
	printf("Cleaning Ship! : %d\n", std::this_thread::get_id());
	std::this_thread::sleep_for(std::chrono::milliseconds(time));
	printf("Cleaning Ship Complete!\n");
}

void FullSpeedThread(long time)
{
	printf("Full Speed Ahead! : %d\n", std::this_thread::get_id());
	std::this_thread::sleep_for(std::chrono::milliseconds(time));
	printf("Full Speed Complete!\n");
}

void StopThread(long time)
{
	printf("Stop The Ship! : %d\n", std::this_thread::get_id());
	std::this_thread::sleep_for(std::chrono::milliseconds(time));
	printf("Ship came to halt!\n");
}

void multithreading_command_ship()
{
	int command{};
	long deadline{};
	do {

		std::cout << "Give command to crew \nCommands:->\n1= clean\n2=fullspeed\n3=stop\nor 100=exit\nCommand :";
		std::cin >> command;
		std::cout << "\n Deadline : ";
		std::cin >> deadline;

		if (command != 1 && command != 2 && command != 3 && command != 100)
		{
			printf("\n Invalid command : press 1=clean,2=full speed,3=stop or 100=exit \n");
			continue;
		}

		switch (command)
		{
		case 1:
		{
			std::thread clean(CleaningThread, deadline);
			thread_guard tg(clean);
			clean.detach();
			break;
		}
		case 2:
		{
			std::thread fullspeed(FullSpeedThread, deadline);
			fullspeed.join();
			break;
		}
		case 3:
		{
			std::thread stop(StopThread, deadline);
			stop.join();
			break;
		}
		default:
			break;
		}

	} while (command != 100);

}

void multithreading_useful_methods()
{
	/// <summary>
	///  GetId() method demo 
	/// </summary>
	std::thread thread1(FunctionA);
	std::thread thread2(FunctionB);
	std::thread thread3(FunctionC);

	printf("Thread 1 %d\n", thread1.get_id());
	printf("Thread 2 %d\n", thread2.get_id());
	printf("Thread 3 %d\n", thread3.get_id());

	thread1.detach();
	printf("Thread 1 %d\n", thread1.get_id());
	thread2.join();
	thread3.join();

	//once thread is joined that thread does not represent active 
	// thread execution
	printf("Thread 2 %d\n", thread2.get_id());
	printf("Thread 3 %d\n", thread3.get_id());

	printf("Number of threads allowed %d\n", std::thread::hardware_concurrency());


}


// Example of sailing ship using threading
// and task scheduling
void TaskWorker(int& command,std::queue<Task*>& queue)
{
	while (command != 100)
	{
		if (queue.size() > 0)
		{

			while (queue.size()> 0)
			{
				Task* task = queue.front();
				if(task->type == TaskType::Cleaning)
					printf("Performaing Cleaning Task for %d milliseconds \n", task->duration);
				else if(task->type== TaskType::Engine)
					printf("Performaing Engine Task for %d milliseconds \n", task->duration);
				queue.pop();
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				delete task;
			}
		}
		else
		{
			//printf("\nNo Task Available");
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		}
	}
}

void multithreading_ship_sailing_example(int &command,std::queue<Task*>& cleaningQueue, std::queue<Task*>& engineQueue)
{
	std::thread cleaningThread(TaskWorker,std::ref(command), std::ref(cleaningQueue));
	std::thread engineThread(TaskWorker, std::ref(command),std::ref(engineQueue));

	cleaningThread.detach();
	engineThread.detach();
}
// simple task scheduler using threads
void simple_task_scheduler_using_threads()
{
	std::queue<Task*> cleaningQueue;
	std::queue<Task*> engineQueue;
	int command{};

	multithreading_ship_sailing_example(command, cleaningQueue, engineQueue);

	while (command != 100)
	{

		std::cout << "Give command to crew \nCommands:->\n1= clean\n2=fullspeed\n3=stop\nor 100=exit\nCommand :";
		std::cin >> command;

		if (command != 1 && command != 2 && command != 3 && command != 100)
		{
			printf("\n Invalid command : press 1=clean,2=full speed,3=stop or 100=exit \n");
			continue;
		}

		switch (command)
		{
		case 1:
		{
			Task* cleaningTask = new Task();
			cleaningTask->type = TaskType::Cleaning;
			cleaningTask->duration = 1000;
			cleaningQueue.push(cleaningTask);
			break;
		}
		case 2:
		{
			Task* engineTask = new Task();
			engineTask->type = TaskType::Engine;
			engineTask->duration = 1000;
			engineQueue.push(engineTask);
			break;
		}
		case 3:
		{
			Task* engineTask = new Task();
			engineTask->type = TaskType::Engine;
			engineTask->duration = 1000;
			engineQueue.push(engineTask);
			break;
		}
		default:
			break;
		}

	}

}

//Semafores in multithreading
// Mutex utilization with and without lock guard

std::list<int> threadSafeList;
const int maxBufferSize = 15;
std::mutex m;
std::condition_variable condition;

void mutex_thread(int x)
{
	m.lock();
	threadSafeList.push_back(x);
	m.unlock();
	std::cout << "Into mutex lock method \n";
}

void mutex_lock_guard_thread(int x)
{
	std::lock_guard<std::mutex> lg(m);
	threadSafeList.push_back(x);
	std::cout << "Into lockguard method \n";
}

void multithreading_mutex_example()
{
	std::thread thread1(mutex_lock_guard_thread, 11);
	std::thread thread2(mutex_lock_guard_thread, 20);
	thread1.join();
	thread2.join();
}

void multithreading_producer_conditional()
{
	do 
	{
		std::unique_lock<std::mutex> lck(m);
		condition.wait(lck, [] {return threadSafeList.size() < maxBufferSize; });
		int random = std::rand();
		threadSafeList.push_back(random);
		printf("Number Pushed : %d\n", random);
		lck.unlock();
		condition.notify_one();
		
	} while (true);
}

void multithreading_consumer_conditional()
{
	do
	{
		std::unique_lock<std::mutex> lck(m);
		condition.wait(lck, [] {return threadSafeList.size() > 0; });
		int random = threadSafeList.front();
		printf("Number Popped : %d threadId : %d\n", random, std::this_thread::get_id());
		threadSafeList.pop_front();
		lck.unlock();
		condition.notify_one();

	} while (true);
}




