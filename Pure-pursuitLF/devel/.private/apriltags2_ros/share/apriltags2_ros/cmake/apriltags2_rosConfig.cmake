# generated from catkin/cmake/template/pkgConfig.cmake.in

# append elements to a list and remove existing duplicates from the list
# copied from catkin/cmake/list_append_deduplicate.cmake to keep pkgConfig
# self contained
macro(_list_append_deduplicate listname)
  if(NOT "${ARGN}" STREQUAL "")
    if(${listname})
      list(REMOVE_ITEM ${listname} ${ARGN})
    endif()
    list(APPEND ${listname} ${ARGN})
  endif()
endmacro()

# append elements to a list if they are not already in the list
# copied from catkin/cmake/list_append_unique.cmake to keep pkgConfig
# self contained
macro(_list_append_unique listname)
  foreach(_item ${ARGN})
    list(FIND ${listname} ${_item} _index)
    if(_index EQUAL -1)
      list(APPEND ${listname} ${_item})
    endif()
  endforeach()
endmacro()

# pack a list of libraries with optional build configuration keywords
# copied from catkin/cmake/catkin_libraries.cmake to keep pkgConfig
# self contained
macro(_pack_libraries_with_build_configuration VAR)
  set(${VAR} "")
  set(_argn ${ARGN})
  list(LENGTH _argn _count)
  set(_index 0)
  while(${_index} LESS ${_count})
    list(GET _argn ${_index} lib)
    if("${lib}" MATCHES "^(debug|optimized|general)$")
      math(EXPR _index "${_index} + 1")
      if(${_index} EQUAL ${_count})
        message(FATAL_ERROR "_pack_libraries_with_build_configuration() the list of libraries '${ARGN}' ends with '${lib}' which is a build configuration keyword and must be followed by a library")
      endif()
      list(GET _argn ${_index} library)
      list(APPEND ${VAR} "${lib}${CATKIN_BUILD_CONFIGURATION_KEYWORD_SEPARATOR}${library}")
    else()
      list(APPEND ${VAR} "${lib}")
    endif()
    math(EXPR _index "${_index} + 1")
  endwhile()
endmacro()

# unpack a list of libraries with optional build configuration keyword prefixes
# copied from catkin/cmake/catkin_libraries.cmake to keep pkgConfig
# self contained
macro(_unpack_libraries_with_build_configuration VAR)
  set(${VAR} "")
  foreach(lib ${ARGN})
    string(REGEX REPLACE "^(debug|optimized|general)${CATKIN_BUILD_CONFIGURATION_KEYWORD_SEPARATOR}(.+)$" "\\1;\\2" lib "${lib}")
    list(APPEND ${VAR} "${lib}")
  endforeach()
endmacro()


if(apriltags2_ros_CONFIG_INCLUDED)
  return()
endif()
set(apriltags2_ros_CONFIG_INCLUDED TRUE)

# set variables for source/devel/install prefixes
if("TRUE" STREQUAL "TRUE")
  set(apriltags2_ros_SOURCE_PREFIX /code/catkin_ws/src/dt-core/packages/apriltags2_ros/apriltags2_ros)
  set(apriltags2_ros_DEVEL_PREFIX /code/catkin_ws/devel/.private/apriltags2_ros)
  set(apriltags2_ros_INSTALL_PREFIX "")
  set(apriltags2_ros_PREFIX ${apriltags2_ros_DEVEL_PREFIX})
else()
  set(apriltags2_ros_SOURCE_PREFIX "")
  set(apriltags2_ros_DEVEL_PREFIX "")
  set(apriltags2_ros_INSTALL_PREFIX /code/catkin_ws/install)
  set(apriltags2_ros_PREFIX ${apriltags2_ros_INSTALL_PREFIX})
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "WARNING: package 'apriltags2_ros' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  message("${_msg}")
endif()

# flag project as catkin-based to distinguish if a find_package()-ed project is a catkin project
set(apriltags2_ros_FOUND_CATKIN_PROJECT TRUE)

if(NOT "/code/catkin_ws/devel/.private/apriltags2_ros/include;/code/catkin_ws/src/dt-core/packages/apriltags2_ros/apriltags2_ros/include;/usr/include/eigen3;/opt/ros/kinetic/include/opencv-3.3.1-dev;/opt/ros/kinetic/include/opencv-3.3.1-dev/opencv " STREQUAL " ")
  set(apriltags2_ros_INCLUDE_DIRS "")
  set(_include_dirs "/code/catkin_ws/devel/.private/apriltags2_ros/include;/code/catkin_ws/src/dt-core/packages/apriltags2_ros/apriltags2_ros/include;/usr/include/eigen3;/opt/ros/kinetic/include/opencv-3.3.1-dev;/opt/ros/kinetic/include/opencv-3.3.1-dev/opencv")
  if(NOT "https://github.com/dmalyuta/apriltags2_ros/issues " STREQUAL " ")
    set(_report "Check the issue tracker 'https://github.com/dmalyuta/apriltags2_ros/issues' and consider creating a ticket if the problem has not been reported yet.")
  elseif(NOT "http://www.ros.org/wiki/apriltags2_ros " STREQUAL " ")
    set(_report "Check the website 'http://www.ros.org/wiki/apriltags2_ros' for information and consider reporting the problem.")
  else()
    set(_report "Report the problem to the maintainer 'Danylo Malyuta <danylo.malyuta@gmail.com>' and request to fix the problem.")
  endif()
  foreach(idir ${_include_dirs})
    if(IS_ABSOLUTE ${idir} AND IS_DIRECTORY ${idir})
      set(include ${idir})
    elseif("${idir} " STREQUAL "include ")
      get_filename_component(include "${apriltags2_ros_DIR}/../../../include" ABSOLUTE)
      if(NOT IS_DIRECTORY ${include})
        message(FATAL_ERROR "Project 'apriltags2_ros' specifies '${idir}' as an include dir, which is not found.  It does not exist in '${include}'.  ${_report}")
      endif()
    else()
      message(FATAL_ERROR "Project 'apriltags2_ros' specifies '${idir}' as an include dir, which is not found.  It does neither exist as an absolute directory nor in '/code/catkin_ws/src/dt-core/packages/apriltags2_ros/apriltags2_ros/${idir}'.  ${_report}")
    endif()
    _list_append_unique(apriltags2_ros_INCLUDE_DIRS ${include})
  endforeach()
endif()

set(libraries "/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_calib3d3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_core3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_dnn3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_features2d3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_flann3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_highgui3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_imgcodecs3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_imgproc3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_ml3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_objdetect3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_photo3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_shape3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_stitching3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_superres3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_video3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_videoio3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_videostab3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_viz3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_aruco3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_bgsegm3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_bioinspired3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_ccalib3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_cvv3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_datasets3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_dpm3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_face3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_fuzzy3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_hdf3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_img_hash3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_line_descriptor3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_optflow3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_phase_unwrapping3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_plot3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_reg3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_rgbd3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_saliency3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_stereo3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_structured_light3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_surface_matching3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_text3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_tracking3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_xfeatures2d3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_ximgproc3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_xobjdetect3.so.3.3.1;/opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_xphoto3.so.3.3.1")
foreach(library ${libraries})
  # keep build configuration keywords, target names and absolute libraries as-is
  if("${library}" MATCHES "^(debug|optimized|general)$")
    list(APPEND apriltags2_ros_LIBRARIES ${library})
  elseif(${library} MATCHES "^-l")
    list(APPEND apriltags2_ros_LIBRARIES ${library})
  elseif(TARGET ${library})
    list(APPEND apriltags2_ros_LIBRARIES ${library})
  elseif(IS_ABSOLUTE ${library})
    list(APPEND apriltags2_ros_LIBRARIES ${library})
  else()
    set(lib_path "")
    set(lib "${library}-NOTFOUND")
    # since the path where the library is found is returned we have to iterate over the paths manually
    foreach(path /code/catkin_ws/devel/.private/apriltags2_ros/lib;/code/catkin_ws/devel/lib;/opt/ros/kinetic/lib)
      find_library(lib ${library}
        PATHS ${path}
        NO_DEFAULT_PATH NO_CMAKE_FIND_ROOT_PATH)
      if(lib)
        set(lib_path ${path})
        break()
      endif()
    endforeach()
    if(lib)
      _list_append_unique(apriltags2_ros_LIBRARY_DIRS ${lib_path})
      list(APPEND apriltags2_ros_LIBRARIES ${lib})
    else()
      # as a fall back for non-catkin libraries try to search globally
      find_library(lib ${library})
      if(NOT lib)
        message(FATAL_ERROR "Project '${PROJECT_NAME}' tried to find library '${library}'.  The library is neither a target nor built/installed properly.  Did you compile project 'apriltags2_ros'?  Did you find_package() it before the subdirectory containing its code is included?")
      endif()
      list(APPEND apriltags2_ros_LIBRARIES ${lib})
    endif()
  endif()
endforeach()

set(apriltags2_ros_EXPORTED_TARGETS "apriltags2_ros_generate_messages_cpp;apriltags2_ros_generate_messages_py")
# create dummy targets for exported code generation targets to make life of users easier
foreach(t ${apriltags2_ros_EXPORTED_TARGETS})
  if(NOT TARGET ${t})
    add_custom_target(${t})
  endif()
endforeach()

set(depends "apriltags2;geometry_msgs;duckietown_msgs;image_transport;roscpp;sensor_msgs;std_msgs;message_runtime;cv_bridge;tf")
foreach(depend ${depends})
  string(REPLACE " " ";" depend_list ${depend})
  # the package name of the dependency must be kept in a unique variable so that it is not overwritten in recursive calls
  list(GET depend_list 0 apriltags2_ros_dep)
  list(LENGTH depend_list count)
  if(${count} EQUAL 1)
    # simple dependencies must only be find_package()-ed once
    if(NOT ${apriltags2_ros_dep}_FOUND)
      find_package(${apriltags2_ros_dep} REQUIRED NO_MODULE)
    endif()
  else()
    # dependencies with components must be find_package()-ed again
    list(REMOVE_AT depend_list 0)
    find_package(${apriltags2_ros_dep} REQUIRED NO_MODULE ${depend_list})
  endif()
  _list_append_unique(apriltags2_ros_INCLUDE_DIRS ${${apriltags2_ros_dep}_INCLUDE_DIRS})

  # merge build configuration keywords with library names to correctly deduplicate
  _pack_libraries_with_build_configuration(apriltags2_ros_LIBRARIES ${apriltags2_ros_LIBRARIES})
  _pack_libraries_with_build_configuration(_libraries ${${apriltags2_ros_dep}_LIBRARIES})
  _list_append_deduplicate(apriltags2_ros_LIBRARIES ${_libraries})
  # undo build configuration keyword merging after deduplication
  _unpack_libraries_with_build_configuration(apriltags2_ros_LIBRARIES ${apriltags2_ros_LIBRARIES})

  _list_append_unique(apriltags2_ros_LIBRARY_DIRS ${${apriltags2_ros_dep}_LIBRARY_DIRS})
  list(APPEND apriltags2_ros_EXPORTED_TARGETS ${${apriltags2_ros_dep}_EXPORTED_TARGETS})
endforeach()

set(pkg_cfg_extras "apriltags2_ros-msg-extras.cmake")
foreach(extra ${pkg_cfg_extras})
  if(NOT IS_ABSOLUTE ${extra})
    set(extra ${apriltags2_ros_DIR}/${extra})
  endif()
  include(${extra})
endforeach()
