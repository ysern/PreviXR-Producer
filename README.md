# rvr-host-api

The integration library for host applications.

A game engine, DCC tool or other host application links against `rvr-host-api` to talk to an RVR
service running on the same machine.

## Status

Early. The API surface is still being worked out and nothing here is stable yet — the library
currently builds and exports nothing useful. It is published at this stage so that integrators
can follow its shape as it settles.

## Building

CMake, producing a shared library:

```
add_subdirectory(host_api)
target_link_libraries(your_target PRIVATE RVR::HostApi)
```

Include as:

```cpp
#include "rvr/host_api/host_api.h"
```
