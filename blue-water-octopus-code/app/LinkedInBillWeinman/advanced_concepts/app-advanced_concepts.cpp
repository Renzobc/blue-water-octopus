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
 * AdvancedConcepts.hpp
 */

#include <iostream>

#include "advanced_concepts/advanced_concepts.hpp"
#include "advanced_concepts/initialization_spaceship_chrono_span_filesystem.hpp"
#include "advanced_concepts/iterator.hpp"
#include "advanced_concepts/move_semantics.hpp"
#include "advanced_concepts/rationale.hpp"

int main()[[noexcept]]
{
  std::cout << "LinkedInLearning c++ Bill Weinman" << std::endl;

  //   start_advanced_concepts_bill_weinman();

  rationale_main();

  main_move_semantics();

  //   main_iterator();

  main_initialization_spaceship_chrono_span_filesystem();

  return 0;
}