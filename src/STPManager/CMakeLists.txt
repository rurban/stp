include_directories(${CMAKE_SOURCE_DIR}/src/AST/)
include_directories(${CMAKE_BINARY_DIR}/src/AST/)

add_library(stpmgr OBJECT
    STP.cpp
    STPManager.cpp
)
