# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TeamTextEditor_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TeamTextEditor_autogen.dir\\ParseCache.txt"
  "TeamTextEditor_autogen"
  )
endif()
