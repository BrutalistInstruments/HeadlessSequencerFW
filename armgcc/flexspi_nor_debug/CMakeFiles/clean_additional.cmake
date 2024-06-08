# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "flexspi_nor_debug")
  file(REMOVE_RECURSE
  "output.map"
  )
endif()
