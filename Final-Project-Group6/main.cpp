#include <iostream>
#include "src/Maze/maze.h"
#include "src/API/api.h"
#include "src/LandBasedWheeled/landbasedwheeled.h"
#include "src/Algorithm/algorithm.h"

int main()
{
    fp::Maze maze;
    // Parameters wheel_number, name, speed, width, length, height, capacity, x, y, direction 
    fp::LandBasedWheeled robot(2, "robot1", 0, 10, 10, 10, 0, 0, 0, 'N');
    
    fp::Algorithm bfs;
    int i = 1;
    while(bfs.CheckGoal(robot.get_x(), robot.get_y()) == false) {
        std::cerr << "BFS Iteration " << i << std::endl;
        bfs.SolveBFS(robot, maze);
        bfs.MoveRobot(robot, maze);
        if(i == 40)
            break;
        i = i + 1;    
    }
    
    return 0;
}
