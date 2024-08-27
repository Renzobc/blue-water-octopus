/**
 * Copyright 2024 Capra Robotics ApS
 * __________________
 * All Rights Reserved.
 * NOTICE: All information contained herein is, and remains the property
 * of Capra Robotics ApS. The intellectual and technical concepts contained
 * herein are proprietary to Capra Robotics ApS and may be covered by U.S.
 * and Foreign Patents, patents in process, and are protected by trade secret
 * or copyright law. Dissemination of this information or reproduction of this
 * material is strictly forbidden unless prior written permission is obtained
 * from Capra Robotics ApS.
 * 
 * parallel_programing.hpp
 */

#pragma once

#include <array>
#include <atomic>
#include <chrono>
#include <iostream>
#include <memory>
#include <shared_mutex>
#include <thread>

/*Shared mutex*/

char WEEKDAYS[7][10] = {"MONDAY", "TUESDAY",  "WEDNESDAY", "THRUSDAY",
                        "FRIDAY", "SATURDAY", "SUNDAY"};

int today = 0;
std::shared_mutex marker;

void calendar_reader(const int id)
{
  for (int i = 0; i < 7; ++i) {
    marker.lock_shared();
    std::cout << "Reader : " << id << ", sees today as : " << WEEKDAYS[today] << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    marker.unlock_shared();
  }
}

void calendar_writer(const int id)
{
  for (int i = 0; i < 7; ++i) {
    marker.lock();
    today = (today + 1) % 7;
    std::cout << "Writer : " << id << ", updated today as : " << WEEKDAYS[today] << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    marker.unlock();
  }
}

int spawn_threads()
{
  // create ten reader threads ...but only two writer threads
  std::array<std::thread, 10> readers;
  for (int i = 0; i < readers.size(); ++i) {
    readers[i] = std::thread(calendar_reader, i);
  }

  std::array<std::thread, 2> writers;
  for (int i = 0; i < writers.size(); ++i) {
    writers[i] = std::thread(calendar_writer, i);
  }

  // Join the threads

  for (auto & thread : readers) {
    thread.join();
  }

  for (auto & thread : writers) {
    thread.join();
  }
}
