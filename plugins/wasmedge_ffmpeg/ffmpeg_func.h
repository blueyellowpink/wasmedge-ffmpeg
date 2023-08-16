// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2019-2023 Second State INC

#pragma once

#include "runtime/callingframe.h"

#include "ffmpeg_base.h"

namespace WasmEdge {
namespace Host {

class WasmEdgeFfmpegAdd : public WasmEdgeFfmpeg<WasmEdgeFfmpegAdd> {
public:
  WasmEdgeFfmpegAdd(WasmEdgeFfmpegEnvironment& host_env)
  : WasmEdgeFfmpeg(host_env) {}

  Expect<uint32_t> body(const Runtime::CallingFrame& frame, uint32_t a, uint32_t b);
};

class WasmEdgeFfmpegSubtract : public WasmEdgeFfmpeg<WasmEdgeFfmpegSubtract> {
public:
  WasmEdgeFfmpegSubtract(WasmEdgeFfmpegEnvironment& host_env)
  : WasmEdgeFfmpeg(host_env) {}

  Expect<uint32_t> body(const Runtime::CallingFrame& frame, uint32_t a, uint32_t b);
};

class WasmEdgeFfmpegAvFormatAllocContext : public WasmEdgeFfmpeg<WasmEdgeFfmpegAvFormatAllocContext> {
public:
  WasmEdgeFfmpegAvFormatAllocContext(WasmEdgeFfmpegEnvironment& host_env)
  : WasmEdgeFfmpeg(host_env) {}

  Expect<uint64_t> body(const Runtime::CallingFrame& frame);
};

class WasmEdgeFfmpegAvFormatFreeContext : public WasmEdgeFfmpeg<WasmEdgeFfmpegAvFormatFreeContext> {
public:
  WasmEdgeFfmpegAvFormatFreeContext(WasmEdgeFfmpegEnvironment& host_env)
  : WasmEdgeFfmpeg(host_env) {}

  Expect<void> body(const Runtime::CallingFrame& frame, uint64_t avformat_context);
};

class WasmEdgeFfmpegAvFormatGetContext : public WasmEdgeFfmpeg<WasmEdgeFfmpegAvFormatGetContext> {
public:
  WasmEdgeFfmpegAvFormatGetContext(WasmEdgeFfmpegEnvironment& host_env)
  : WasmEdgeFfmpeg(host_env) {}

  Expect<uint64_t> body(const Runtime::CallingFrame& frame, uint64_t avformat_context);
};

class WasmEdgeFfmpegAvFormatGetNbStreams : public WasmEdgeFfmpeg<WasmEdgeFfmpegAvFormatGetNbStreams> {
public:
  WasmEdgeFfmpegAvFormatGetNbStreams(WasmEdgeFfmpegEnvironment& host_env)
  : WasmEdgeFfmpeg(host_env) {}

  Expect<uint32_t> body(const Runtime::CallingFrame& frame, uint64_t avformat_context);
};

class WasmEdgeFfmpegAvFormatGetStream : public WasmEdgeFfmpeg<WasmEdgeFfmpegAvFormatGetStream> {
public:
  WasmEdgeFfmpegAvFormatGetStream(WasmEdgeFfmpegEnvironment& host_env)
  : WasmEdgeFfmpeg(host_env) {}

  Expect<uint64_t> body(const Runtime::CallingFrame& frame, uint64_t avformat_context, uint32_t index);
};

class WasmEdgeFfmpegAvFormatOpenInput : public WasmEdgeFfmpeg<WasmEdgeFfmpegAvFormatOpenInput> {
public:
  WasmEdgeFfmpegAvFormatOpenInput(WasmEdgeFfmpegEnvironment& host_env)
  : WasmEdgeFfmpeg(host_env) {}

  Expect<uint32_t> body(const Runtime::CallingFrame& frame, uint64_t avformat_context, uint32_t file_name, uint32_t file_name_len);
};

class WasmEdgeFfmpegAvFormatFindStreamInfo : public WasmEdgeFfmpeg<WasmEdgeFfmpegAvFormatFindStreamInfo> {
public:
  WasmEdgeFfmpegAvFormatFindStreamInfo(WasmEdgeFfmpegEnvironment& host_env)
  : WasmEdgeFfmpeg(host_env) {}

  Expect<uint32_t> body(const Runtime::CallingFrame& frame, uint64_t avformat_context);
};

class WasmEdgeFfmpegAvFormatAllocOutputContext2 : public WasmEdgeFfmpeg<WasmEdgeFfmpegAvFormatAllocOutputContext2> {
public:
  WasmEdgeFfmpegAvFormatAllocOutputContext2(WasmEdgeFfmpegEnvironment& host_env)
  : WasmEdgeFfmpeg(host_env) {}

  Expect<uint64_t> body(const Runtime::CallingFrame& frame, uint64_t avformat_context, uint32_t file_name, uint32_t file_name_len);
};

class WasmEdgeFfmpegAvStreamCodecpar : public WasmEdgeFfmpeg<WasmEdgeFfmpegAvStreamCodecpar> {
public:
  WasmEdgeFfmpegAvStreamCodecpar(WasmEdgeFfmpegEnvironment& host_env)
  : WasmEdgeFfmpeg(host_env) {}

  Expect<uint64_t> body(const Runtime::CallingFrame& frame, uint64_t avstream);
};

class WasmEdgeFfmpegAvCodecParamsCodecType : public WasmEdgeFfmpeg<WasmEdgeFfmpegAvCodecParamsCodecType> {
public:
  WasmEdgeFfmpegAvCodecParamsCodecType(WasmEdgeFfmpegEnvironment& host_env)
  : WasmEdgeFfmpeg(host_env) {}

  Expect<uint32_t> body(const Runtime::CallingFrame& frame, uint64_t avcodec_params);
};

class WasmEdgeFfmpegAvFormatNewStream : public WasmEdgeFfmpeg<WasmEdgeFfmpegAvFormatNewStream> {
public:
  WasmEdgeFfmpegAvFormatNewStream(WasmEdgeFfmpegEnvironment& host_env)
  : WasmEdgeFfmpeg(host_env) {}

  Expect<uint64_t> body(const Runtime::CallingFrame& frame, uint64_t avformat_context);
};

class WasmEdgeFfmpegAvCodecParamsCopy : public WasmEdgeFfmpeg<WasmEdgeFfmpegAvCodecParamsCopy> {
public:
  WasmEdgeFfmpegAvCodecParamsCopy(WasmEdgeFfmpegEnvironment& host_env)
  : WasmEdgeFfmpeg(host_env) {}

  Expect<uint32_t> body(const Runtime::CallingFrame& frame, uint64_t dst, uint64_t src);
};

class WasmEdgeFfmpegAvDumpFormat : public WasmEdgeFfmpeg<WasmEdgeFfmpegAvDumpFormat> {
public:
  WasmEdgeFfmpegAvDumpFormat(WasmEdgeFfmpegEnvironment& host_env)
  : WasmEdgeFfmpeg(host_env) {}

  Expect<void> body(const Runtime::CallingFrame& frame, uint64_t avformat_context, uint32_t index, uint32_t file_name, uint32_t file_name_len, uint32_t is_output);
};

class WasmEdgeFfmpegAvioOpen : public WasmEdgeFfmpeg<WasmEdgeFfmpegAvioOpen> {
public:
  WasmEdgeFfmpegAvioOpen(WasmEdgeFfmpegEnvironment& host_env)
  : WasmEdgeFfmpeg(host_env) {}

  Expect<uint32_t> body(const Runtime::CallingFrame& frame, uint64_t avformat_context, uint32_t file_name, uint32_t file_name_len);
};

class WasmEdgeFfmpegAvFormatWriteHeader : public WasmEdgeFfmpeg<WasmEdgeFfmpegAvFormatWriteHeader> {
public:
  WasmEdgeFfmpegAvFormatWriteHeader(WasmEdgeFfmpegEnvironment& host_env)
  : WasmEdgeFfmpeg(host_env) {}

  Expect<uint32_t> body(const Runtime::CallingFrame& frame, uint64_t avformat_context);
};

} // namespace Host
} // namespace WasmEdge
