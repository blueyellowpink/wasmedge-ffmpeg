// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2019-2023 Second State INC

#pragma once

#include <cstdint>

#include "plugin/plugin.h"

namespace WasmEdge {
namespace Host {

class WasmEdgeFfmpegEnvironment {
public:
  WasmEdgeFfmpegEnvironment() noexcept = default;

  static Plugin::PluginRegister Register;

  /* Expect<uint32_t> subtract(uint32_t a, uint32_t b) { */
  /*   return a - b; */
  /* } */
  /**/
  /* Expect<uint32_t> add(uint32_t a, uint32_t b) { */
  /*   return a + b; */
  /* } */
};

} // namespace Host
} // namespace WasmEdge
