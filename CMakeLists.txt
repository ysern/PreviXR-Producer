add_library(previxr-producer SHARED
  src/producer.cpp
)

add_library(PreviXR::Producer
  ALIAS
    previxr-producer
)

target_include_directories(previxr-producer
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_definitions(previxr-producer
  PRIVATE PREVIXR_PRODUCER_BUILD
)

install(TARGETS previxr-producer
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)

install(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
  DESTINATION include
)
