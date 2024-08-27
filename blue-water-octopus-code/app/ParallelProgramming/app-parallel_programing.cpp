// Copyright 2024 Capra Robotics ApS
// __________________
// All Rights Reserved.
// NOTICE: All information contained herein is, and remains the property
// of Capra Robotics ApS. The intellectual and technical concepts contained
// herein are proprietary to Capra Robotics ApS and may be covered by U.S.
// and Foreign Patents, patents in process, and are protected by trade secret
// or copyright law. Dissemination of this information or reproduction of this
// material is strictly forbidden unless prior written permission is obtained
// from Capra Robotics ApS.
//
// ParallelPrograming
#include "parallel_programing.hpp"

/*
Proceses vs threads.
Proceses exists in its own separate address space. Variables and data are isolated to a particular address space. 
It requires ipc (inter process communication), sockers and pipes / shared memory / remote procedure calls. 
Threads live in a single process.
Threads are more lightweight and it is easier to "switch" between thread than to "switch" between processes. 
Threads live within a single process. Thats means a single address space.
*/

/*
Concurrency
Is about how a program is structured. If the HW resources are limited concurrent programm might not execute parallel but "switch" between threads. 
Parallel execution
Is a simultanious execution between two programs. Is for computationally instensive tasks.
*/

/*
Execution scheduling
Os scheduler task. It assignes a process to the processing cores. 
The process sits waiting in the IO queue.
When a process is taken out of the core by the scheduler and another is triggered then it is called a "Context Switch".
Context Switch.
Save a state a of a process and load the state of the incomming process.
Algorithms for a scheduler: First come, first served, Shortest job next, Prioritym Shortest remaining time, round robin, multiple level queues.
*/

/*
Dettached thread / daemon thred
Is a thread that will not prevent the main program from exiting.
Threads by default are not dettached thread.
Thread that are dettached will not gracefully shutdown but be terminated. Termination is abrupt for dettached threads.
The dettached thread is NON Joinable. The main thread will indicated when the dettahced thread will abruptly finish.
*/

/*
Synchronization techniques.
Accessing and modifying a shared data resources.
Process of sharing a data resource: Read, Modify, write.
*/

/*
Atomic types 
If the mutex is need only for a single operation on primitive data to be safe then is better to use an atomic type. example coulbe a counter value between threads.
*/

/*
Recursive/Reentrant mutex.
It happens when a thread tries to lock a mutex while having locked it before. A normal mutex would lead to a deadlock since the second locking will block execution
Reeentrant mutex keeps track how may times the mutex have been locked by the owning thread. ONLY the locking thread.
One use case is a recursive function using shared data between threads
*/

/*
Non blocking lock
try lock return true false
*/

/*
Shared mutex. Read/Write mode.
Keep track the number of readers and prioritize writers.
Its make sense to use it when: Threads ONLY reading are >> (much more in number) threads writing.
If all thread are only reading
If a thread is write excusive.

*/

int main()
{
  spawn_threads();
  return 0;
}