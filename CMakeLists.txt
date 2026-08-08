set(RVR_HOST_API_HEADERS
	include/rvr/host_api/host_api.h
	include/rvr/host_api/host_api_export.h
)

set(RVR_HOST_API_SOURCES
	src/host_api.cpp
)

add_library(rvr-host-api SHARED
	${RVR_HOST_API_HEADERS}
	${RVR_HOST_API_SOURCES}
)

add_library(RVR::HostApi
	ALIAS
	rvr-host-api
)

target_include_directories(rvr-host-api
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

target_compile_definitions(rvr-host-api
	PRIVATE RVR_HOST_API_BUILD
)

install(TARGETS rvr-host-api
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)

install(
	DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
	DESTINATION include
)

set_target_properties(rvr-host-api PROPERTIES FOLDER "RVR")
