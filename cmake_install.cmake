# Install script for directory: /Users/ssmilkshake/Documents/MUSIC-8903-2016

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/ssmilkshake/Documents/MUSIC-8903-2016-Assignment1/MUSI8903Exec/cmake_install.cmake")
  include("/Users/ssmilkshake/Documents/MUSIC-8903-2016-Assignment1/AudioFileIO/cmake_install.cmake")
  include("/Users/ssmilkshake/Documents/MUSIC-8903-2016-Assignment1/CombFilter/cmake_install.cmake")
  include("/Users/ssmilkshake/Documents/MUSIC-8903-2016-Assignment1/Dtw/cmake_install.cmake")
  include("/Users/ssmilkshake/Documents/MUSIC-8903-2016-Assignment1/Vibrato/cmake_install.cmake")
  include("/Users/ssmilkshake/Documents/MUSIC-8903-2016-Assignment1/TestExec/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/ssmilkshake/Documents/MUSIC-8903-2016-Assignment1/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
