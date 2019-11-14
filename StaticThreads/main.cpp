// App.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <thread>

#include "SingletonWithThread.h"


using namespace std;

int main(int /*argc*/, char** /*argv*/)
{
	cout << "Hello CMake." << endl;

    SingletonWithThread::getInstance();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    
    return 0;
}
