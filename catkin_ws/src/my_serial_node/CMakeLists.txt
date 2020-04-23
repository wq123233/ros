cmake_minimum_required(VERSION 2.8.3)
project( my_serial_node )

find_package(catkin REQUIRED COMPONENTS
  roscpp
  serial
  std_msgs
  tf
  nav_msgs
)

catkin_package(
  CATKIN_DEPENDS
    serial
    std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)


add_executable( my_serial_send_node src/my_serial_send_node.cpp)
target_link_libraries( my_serial_send_node
  ${catkin_LIBRARIES}
)



add_executable( my_serial_receive_node src/my_serial_receive_node.cpp)
#add_dependencies( my_serial_receive_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries( my_serial_receive_node
  ${catkin_LIBRARIES}
)

