/**
 * @file main.cpp
 * @author Zeid Kootbally (zeidk@umd.edu)
 * @brief Simple main function showing an example of the micromouse API use
 * @version 1.0
 * @date 2025-08-03
 * 
 * @see https://github.com/mackorone/mms
 * @see https://github.com/mackorone/mms-cpp/tree/master
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "maze_solver/maze_api.hpp"

int main() {
  micro_mouse::MazeControlAPI maze_control_api;

  maze_control_api.log("Running...");
  maze_control_api.log("Setting start color and text");
  maze_control_api.set_color(0, 0, 'B');
  maze_control_api.set_text(0, 0, "start");

  maze_control_api.log("Setting goal colors and text");
  maze_control_api.set_color(8, 7, 'R');
  maze_control_api.set_text(8, 7, "(8,7)");
  maze_control_api.set_color(7, 7, 'C');
  maze_control_api.set_text(7, 7, "(7,7)");
  maze_control_api.set_color(8, 8, 'G');
  maze_control_api.set_text(8, 8, "(8,8)");
  maze_control_api.set_color(7, 8, 'O');
  maze_control_api.set_text(7, 8, "(7,8)");

  // Example of how to set a left wall in the simulator
  maze_control_api.set_wall(0, 0, 'w');
  // Example of how to set a south wall in the simulator
  maze_control_api.set_wall(0, 0, 's');

  // ==================
  // Demonstration: Left wall follower
  // ==================
  // The robot will always try to keep its left "hand" on the wall
  // If it can turn left (no wall), it does so immediately - this ensures it
  // follows the left wall closely If it can't move forward, it turns right
  // until it finds an opening It then moves forward and repeats the process
  // Note: Replace the code below with method calls for BFS
  while (true) {
    if (!maze_control_api.has_wall_left()) {
      maze_control_api.turn_left();
    }

    while (maze_control_api.has_wall_front()) {
      maze_control_api.turn_right();
    }
    maze_control_api.move_forward(1);
  }
}