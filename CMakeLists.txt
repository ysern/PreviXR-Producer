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

# The public networking surface, and deliberately not RVR::Networking.
#
# This target is the one third parties build against, so it links what they can
# link. Reaching the device protocol from here would compile perfectly well and
# would be exactly the mistake: the boundary is kept by which target is named,
# and this is the naming that proves the public half is sufficient on its own.
target_link_libraries(rvr-host-api
	PUBLIC
	RVR::Networking::PublicApi
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
