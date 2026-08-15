// Copyright 2026, Iurii Sernivka.

#pragma once

#include "rvr/host_api/host_api_export.h"

// The public networking surface, and the only one reachable from here: this
// target links RVR::Networking::PublicApi rather than RVR::Networking, so the
// device protocol has no include path that resolves it. See the file comment in
// rvr/networking/public/session.h for why that boundary exists.
#include "rvr/networking/public/session.h"

namespace rvr {
namespace host_api {

class RVR_HOST_API HostApi
{
// TODO: Declare RVR::HostApi::HostApi
};

//! Proof the public headers are reachable and sufficient on their own.
inline constexpr std::uint32_t SupportedNetworkingApiVersion()
{
    return rvr::network::pub::kPublicApiVersion;
}

} // namespace host_api
} // namespace rvr
