# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "enpm808x_inspection_robot: 4 messages, 0 services")

set(MSG_I_FLAGS "-Ienpm808x_inspection_robot:/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(enpm808x_inspection_robot_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/flag_array.msg" NAME_WE)
add_custom_target(_enpm808x_inspection_robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "enpm808x_inspection_robot" "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/flag_array.msg" "enpm808x_inspection_robot/flag"
)

get_filename_component(_filename "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/inspect.msg" NAME_WE)
add_custom_target(_enpm808x_inspection_robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "enpm808x_inspection_robot" "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/inspect.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/flag.msg" NAME_WE)
add_custom_target(_enpm808x_inspection_robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "enpm808x_inspection_robot" "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/flag.msg" ""
)

get_filename_component(_filename "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/location.msg" NAME_WE)
add_custom_target(_enpm808x_inspection_robot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "enpm808x_inspection_robot" "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/location.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(enpm808x_inspection_robot
  "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/flag.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/enpm808x_inspection_robot
)
_generate_msg_cpp(enpm808x_inspection_robot
  "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/location.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/enpm808x_inspection_robot
)
_generate_msg_cpp(enpm808x_inspection_robot
  "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/flag_array.msg"
  "${MSG_I_FLAGS}"
  "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/flag.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/enpm808x_inspection_robot
)
_generate_msg_cpp(enpm808x_inspection_robot
  "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/inspect.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/enpm808x_inspection_robot
)

### Generating Services

### Generating Module File
_generate_module_cpp(enpm808x_inspection_robot
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/enpm808x_inspection_robot
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(enpm808x_inspection_robot_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(enpm808x_inspection_robot_generate_messages enpm808x_inspection_robot_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/flag_array.msg" NAME_WE)
add_dependencies(enpm808x_inspection_robot_generate_messages_cpp _enpm808x_inspection_robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/inspect.msg" NAME_WE)
add_dependencies(enpm808x_inspection_robot_generate_messages_cpp _enpm808x_inspection_robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/flag.msg" NAME_WE)
add_dependencies(enpm808x_inspection_robot_generate_messages_cpp _enpm808x_inspection_robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/location.msg" NAME_WE)
add_dependencies(enpm808x_inspection_robot_generate_messages_cpp _enpm808x_inspection_robot_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(enpm808x_inspection_robot_gencpp)
add_dependencies(enpm808x_inspection_robot_gencpp enpm808x_inspection_robot_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS enpm808x_inspection_robot_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(enpm808x_inspection_robot
  "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/flag.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/enpm808x_inspection_robot
)
_generate_msg_eus(enpm808x_inspection_robot
  "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/location.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/enpm808x_inspection_robot
)
_generate_msg_eus(enpm808x_inspection_robot
  "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/flag_array.msg"
  "${MSG_I_FLAGS}"
  "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/flag.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/enpm808x_inspection_robot
)
_generate_msg_eus(enpm808x_inspection_robot
  "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/inspect.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/enpm808x_inspection_robot
)

### Generating Services

### Generating Module File
_generate_module_eus(enpm808x_inspection_robot
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/enpm808x_inspection_robot
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(enpm808x_inspection_robot_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(enpm808x_inspection_robot_generate_messages enpm808x_inspection_robot_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/flag_array.msg" NAME_WE)
add_dependencies(enpm808x_inspection_robot_generate_messages_eus _enpm808x_inspection_robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/inspect.msg" NAME_WE)
add_dependencies(enpm808x_inspection_robot_generate_messages_eus _enpm808x_inspection_robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/flag.msg" NAME_WE)
add_dependencies(enpm808x_inspection_robot_generate_messages_eus _enpm808x_inspection_robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/location.msg" NAME_WE)
add_dependencies(enpm808x_inspection_robot_generate_messages_eus _enpm808x_inspection_robot_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(enpm808x_inspection_robot_geneus)
add_dependencies(enpm808x_inspection_robot_geneus enpm808x_inspection_robot_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS enpm808x_inspection_robot_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(enpm808x_inspection_robot
  "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/flag.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/enpm808x_inspection_robot
)
_generate_msg_lisp(enpm808x_inspection_robot
  "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/location.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/enpm808x_inspection_robot
)
_generate_msg_lisp(enpm808x_inspection_robot
  "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/flag_array.msg"
  "${MSG_I_FLAGS}"
  "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/flag.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/enpm808x_inspection_robot
)
_generate_msg_lisp(enpm808x_inspection_robot
  "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/inspect.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/enpm808x_inspection_robot
)

### Generating Services

### Generating Module File
_generate_module_lisp(enpm808x_inspection_robot
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/enpm808x_inspection_robot
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(enpm808x_inspection_robot_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(enpm808x_inspection_robot_generate_messages enpm808x_inspection_robot_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/flag_array.msg" NAME_WE)
add_dependencies(enpm808x_inspection_robot_generate_messages_lisp _enpm808x_inspection_robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/inspect.msg" NAME_WE)
add_dependencies(enpm808x_inspection_robot_generate_messages_lisp _enpm808x_inspection_robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/flag.msg" NAME_WE)
add_dependencies(enpm808x_inspection_robot_generate_messages_lisp _enpm808x_inspection_robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/location.msg" NAME_WE)
add_dependencies(enpm808x_inspection_robot_generate_messages_lisp _enpm808x_inspection_robot_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(enpm808x_inspection_robot_genlisp)
add_dependencies(enpm808x_inspection_robot_genlisp enpm808x_inspection_robot_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS enpm808x_inspection_robot_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(enpm808x_inspection_robot
  "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/flag.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/enpm808x_inspection_robot
)
_generate_msg_nodejs(enpm808x_inspection_robot
  "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/location.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/enpm808x_inspection_robot
)
_generate_msg_nodejs(enpm808x_inspection_robot
  "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/flag_array.msg"
  "${MSG_I_FLAGS}"
  "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/flag.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/enpm808x_inspection_robot
)
_generate_msg_nodejs(enpm808x_inspection_robot
  "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/inspect.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/enpm808x_inspection_robot
)

### Generating Services

### Generating Module File
_generate_module_nodejs(enpm808x_inspection_robot
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/enpm808x_inspection_robot
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(enpm808x_inspection_robot_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(enpm808x_inspection_robot_generate_messages enpm808x_inspection_robot_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/flag_array.msg" NAME_WE)
add_dependencies(enpm808x_inspection_robot_generate_messages_nodejs _enpm808x_inspection_robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/inspect.msg" NAME_WE)
add_dependencies(enpm808x_inspection_robot_generate_messages_nodejs _enpm808x_inspection_robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/flag.msg" NAME_WE)
add_dependencies(enpm808x_inspection_robot_generate_messages_nodejs _enpm808x_inspection_robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/location.msg" NAME_WE)
add_dependencies(enpm808x_inspection_robot_generate_messages_nodejs _enpm808x_inspection_robot_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(enpm808x_inspection_robot_gennodejs)
add_dependencies(enpm808x_inspection_robot_gennodejs enpm808x_inspection_robot_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS enpm808x_inspection_robot_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(enpm808x_inspection_robot
  "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/flag.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/enpm808x_inspection_robot
)
_generate_msg_py(enpm808x_inspection_robot
  "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/location.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/enpm808x_inspection_robot
)
_generate_msg_py(enpm808x_inspection_robot
  "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/flag_array.msg"
  "${MSG_I_FLAGS}"
  "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/flag.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/enpm808x_inspection_robot
)
_generate_msg_py(enpm808x_inspection_robot
  "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/inspect.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/enpm808x_inspection_robot
)

### Generating Services

### Generating Module File
_generate_module_py(enpm808x_inspection_robot
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/enpm808x_inspection_robot
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(enpm808x_inspection_robot_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(enpm808x_inspection_robot_generate_messages enpm808x_inspection_robot_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/flag_array.msg" NAME_WE)
add_dependencies(enpm808x_inspection_robot_generate_messages_py _enpm808x_inspection_robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/inspect.msg" NAME_WE)
add_dependencies(enpm808x_inspection_robot_generate_messages_py _enpm808x_inspection_robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/flag.msg" NAME_WE)
add_dependencies(enpm808x_inspection_robot_generate_messages_py _enpm808x_inspection_robot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/charu/catkin_ws/src/enpm808x_inspection_robot/msg/location.msg" NAME_WE)
add_dependencies(enpm808x_inspection_robot_generate_messages_py _enpm808x_inspection_robot_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(enpm808x_inspection_robot_genpy)
add_dependencies(enpm808x_inspection_robot_genpy enpm808x_inspection_robot_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS enpm808x_inspection_robot_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/enpm808x_inspection_robot)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/enpm808x_inspection_robot
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(enpm808x_inspection_robot_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/enpm808x_inspection_robot)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/enpm808x_inspection_robot
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(enpm808x_inspection_robot_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/enpm808x_inspection_robot)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/enpm808x_inspection_robot
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(enpm808x_inspection_robot_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/enpm808x_inspection_robot)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/enpm808x_inspection_robot
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(enpm808x_inspection_robot_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/enpm808x_inspection_robot)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/enpm808x_inspection_robot\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/enpm808x_inspection_robot
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(enpm808x_inspection_robot_generate_messages_py std_msgs_generate_messages_py)
endif()
