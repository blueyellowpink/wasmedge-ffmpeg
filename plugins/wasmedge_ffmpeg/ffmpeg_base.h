// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2019-2023 Second State INC

#pragma once

#include "common/errcode.h"
#include "runtime/hostfunc.h"

#include "ffmpeg_env.h"

namespace WasmEdge {
namespace Host {

template <typename T>
class WasmEdgeFfmpeg : public Runtime::HostFunction<T> {
public:
  WasmEdgeFfmpeg(WasmEdgeFfmpegEnvironment& host_env)
  : Runtime::HostFunction<T>(0), env(host_env) {}

protected:
  WasmEdgeFfmpegEnvironment& env;
};

} // namespace Host
} // namespace WasmEdge
