// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2019-2023 Second State INC

#include <string>
#include <iostream>

extern "C" {
  #include <libavformat/avformat.h>
  #include <libavformat/avio.h>
  #include <libavutil/mem.h>
}

#include "common/defines.h"

#include "ffmpeg_func.h"

namespace WasmEdge {
namespace Host {

Expect<uint32_t> WasmEdgeFfmpegAdd::body(const Runtime::CallingFrame& frame, uint32_t a, uint32_t b) {
  // Check memory instance from module.
  auto* mem_instance = frame.getMemoryByIndex(0);
  if (mem_instance == nullptr) {
    return Unexpect(ErrCode::Value::HostFuncError);
  }

  return a + b;
}

Expect<uint32_t> WasmEdgeFfmpegSubtract::body(const Runtime::CallingFrame& frame, uint32_t a, uint32_t b) {
  // Check memory instance from module.
  auto* mem_instance = frame.getMemoryByIndex(0);
  if (mem_instance == nullptr) {
    return Unexpect(ErrCode::Value::HostFuncError);
  }

  return a - b;
}

Expect<uint64_t> WasmEdgeFfmpegAvFormatAllocContext::body(const Runtime::CallingFrame& frame) {
  auto* mem_instance = frame.getMemoryByIndex(0);
  if (mem_instance == nullptr) {
    return Unexpect(ErrCode::Value::HostFuncError);
  }

  AVFormatContext* p_format_context = avformat_alloc_context();
  std::cout << p_format_context << std::endl;

  return reinterpret_cast<uintptr_t>(p_format_context);
}

Expect<void> WasmEdgeFfmpegAvFormatFreeContext::body(const Runtime::CallingFrame& frame, uint64_t context) {
  auto* mem_instance = frame.getMemoryByIndex(0);
  if (mem_instance == nullptr) {
    return Unexpect(ErrCode::Value::HostFuncError);
  }

  AVFormatContext* context_ptr = reinterpret_cast<AVFormatContext*>(context);
  avformat_free_context(context_ptr);

  return {};
}

Expect<uint64_t> WasmEdgeFfmpegAvFormatGetContext::body(const Runtime::CallingFrame& frame, uint64_t avformat_context) {
  auto* mem_instance = frame.getMemoryByIndex(0);
  if (mem_instance == nullptr) {
    return Unexpect(ErrCode::Value::HostFuncError);
  }

  AVFormatContext* p_avformat_context = reinterpret_cast<AVFormatContext*>(avformat_context);

  /* AVFormatContext* p_avformat_context = mem_instance->getPointer<AVFormatContext*>(context_ptr); */
  /* std::cout << p_avformat_context << std::endl; */

  return p_avformat_context->event_flags;
}

Expect<uint32_t> WasmEdgeFfmpegAvFormatGetNbStreams::body(const Runtime::CallingFrame& frame, uint64_t avformat_context) {
  auto* mem_instance = frame.getMemoryByIndex(0);
  if (mem_instance == nullptr) {
    return Unexpect(ErrCode::Value::HostFuncError);
  }
  AVFormatContext* p_avformat_context = reinterpret_cast<AVFormatContext*>(avformat_context);
  return p_avformat_context->nb_streams;
}

Expect<uint64_t> WasmEdgeFfmpegAvFormatGetStream::body(const Runtime::CallingFrame& frame, uint64_t avformat_context, uint32_t index) {
  auto* mem_instance = frame.getMemoryByIndex(0);
  if (mem_instance == nullptr) {
    return Unexpect(ErrCode::Value::HostFuncError);
  }
  AVFormatContext* p_avformat_context = reinterpret_cast<AVFormatContext*>(avformat_context);
  AVStream* p_stream = p_avformat_context->streams[index];
  return reinterpret_cast<uintptr_t>(p_stream);
}

Expect<uint32_t> WasmEdgeFfmpegAvFormatOpenInput::body(const Runtime::CallingFrame& frame, uint64_t avformat_context, uint32_t file_name, uint32_t file_name_len) {
  auto* mem_instance = frame.getMemoryByIndex(0);
  if (mem_instance == nullptr) {
    return Unexpect(ErrCode::Value::HostFuncError);
  }

  AVFormatContext* p_avformat_context = reinterpret_cast<AVFormatContext*>(avformat_context);
  char* m_buffer = mem_instance->getPointer<char*>(file_name);
  std::string m_file_name;

  std::copy_n(m_buffer, file_name_len, std::back_inserter(m_file_name));

  if (avformat_open_input(&p_avformat_context, m_file_name.c_str(), NULL, NULL) != 0) {
    return 1;
  }

  return 0;
}

Expect<uint32_t> WasmEdgeFfmpegAvFormatFindStreamInfo::body(const Runtime::CallingFrame& frame, uint64_t avformat_context) {
  auto* mem_instance = frame.getMemoryByIndex(0);
  if (mem_instance == nullptr) {
    return Unexpect(ErrCode::Value::HostFuncError);
  }

  AVFormatContext* p_avformat_context = reinterpret_cast<AVFormatContext*>(avformat_context);

  if (avformat_find_stream_info(p_avformat_context, NULL) < 0) {
    return 1;
  }

  return 0;
}

Expect<uint64_t> WasmEdgeFfmpegAvFormatAllocOutputContext2::body(const Runtime::CallingFrame& frame, uint64_t avformat_context, uint32_t file_name, uint32_t file_name_len) {
  auto* mem_instance = frame.getMemoryByIndex(0);
  if (mem_instance == nullptr) {
    return Unexpect(ErrCode::Value::HostFuncError);
  }

  AVFormatContext* p_avformat_context = reinterpret_cast<AVFormatContext*>(avformat_context);
  char* m_buffer = mem_instance->getPointer<char*>(file_name);
  std::string m_output_file_name;

  std::copy_n(m_buffer, file_name_len, std::back_inserter(m_output_file_name));

  avformat_alloc_output_context2(&p_avformat_context, NULL, NULL, m_output_file_name.c_str());
  if (!p_avformat_context) {
    return 1;
  }

  return reinterpret_cast<uintptr_t>(p_avformat_context);
}

Expect<uint64_t> WasmEdgeFfmpegAvStreamCodecpar::body(const Runtime::CallingFrame& frame, uint64_t avstream) {
  auto* mem_instance = frame.getMemoryByIndex(0);
  if (mem_instance == nullptr) {
    return Unexpect(ErrCode::Value::HostFuncError);
  }

  AVStream* p_stream = reinterpret_cast<AVStream*>(avstream);
  AVCodecParameters* p_codecpar = p_stream->codecpar;

  return reinterpret_cast<uintptr_t>(p_codecpar);
}

Expect<uint32_t> WasmEdgeFfmpegAvCodecParamsCodecType::body(const Runtime::CallingFrame& frame, uint64_t avcodec_params) {
  auto* mem_instance = frame.getMemoryByIndex(0);
  if (mem_instance == nullptr) {
    return Unexpect(ErrCode::Value::HostFuncError);
  }

  AVCodecParameters* p_codecpar = reinterpret_cast<AVCodecParameters*>(avcodec_params);

  int codec_type = p_codecpar->codec_type;

  return static_cast<uint32_t>(codec_type + 1);
}

Expect<uint32_t> WasmEdgeFfmpegAvCodecParamsCopy::body(const Runtime::CallingFrame& frame, uint64_t dst, uint64_t src) {
  auto* mem_instance = frame.getMemoryByIndex(0);
  if (mem_instance == nullptr) {
    return Unexpect(ErrCode::Value::HostFuncError);
  }

  AVCodecParameters* p_src = reinterpret_cast<AVCodecParameters*>(src);
  AVCodecParameters* p_dst = reinterpret_cast<AVCodecParameters*>(dst);
  int ret = avcodec_parameters_copy(p_dst, p_src);
  if (ret < 0) {
    return 1;
  }

  return 0;
}

Expect<uint64_t> WasmEdgeFfmpegAvFormatNewStream::body(const Runtime::CallingFrame& frame, uint64_t avformat_context) {
  auto* mem_instance = frame.getMemoryByIndex(0);
  if (mem_instance == nullptr) {
    return Unexpect(ErrCode::Value::HostFuncError);
  }

  AVFormatContext* p_avformat_context = reinterpret_cast<AVFormatContext*>(avformat_context);
  AVStream* p_stream = avformat_new_stream(p_avformat_context, NULL);
  if (!p_stream) {
    return 0;
  }

  return reinterpret_cast<uintptr_t>(p_stream);
}

Expect<void> WasmEdgeFfmpegAvDumpFormat::body(const Runtime::CallingFrame& frame, uint64_t avformat_context, uint32_t index, uint32_t file_name, uint32_t file_name_len, uint32_t is_output) {
  auto* mem_instance = frame.getMemoryByIndex(0);
  if (mem_instance == nullptr) {
    return Unexpect(ErrCode::Value::HostFuncError);
  }

  AVFormatContext* p_avformat_context = reinterpret_cast<AVFormatContext*>(avformat_context);
  std::cout << p_avformat_context << std::endl;
  std::cout << p_avformat_context->nb_streams << std::endl;
  std::cout << p_avformat_context->oformat->name << std::endl;
  std::cout << p_avformat_context->metadata << std::endl;
  std::cout << p_avformat_context->nb_programs << std::endl;
  std::cout << p_avformat_context->nb_chapters << std::endl;

  char* m_buffer = mem_instance->getPointer<char*>(file_name);
  std::string m_output_file_name;

  std::copy_n(m_buffer, file_name_len, std::back_inserter(m_output_file_name));

  int m_index = static_cast<int>(index);
  int m_is_output = static_cast<int>(is_output);

  std::cout << m_index << std::endl;
  std::cout << m_is_output << std::endl;
  std::cout << m_output_file_name << std::endl;

  /* av_dump_format(p_avformat_context, m_index, m_output_file_name.c_str(), m_is_output); */

  return {};
}

Expect<uint32_t> WasmEdgeFfmpegAvioOpen::body(const Runtime::CallingFrame& frame, uint64_t avformat_context, uint32_t file_name, uint32_t file_name_len) {
  auto* mem_instance = frame.getMemoryByIndex(0);
  if (mem_instance == nullptr) {
    return Unexpect(ErrCode::Value::HostFuncError);
  }

  AVFormatContext* p_avformat_context = reinterpret_cast<AVFormatContext*>(avformat_context);
  char* m_buffer = mem_instance->getPointer<char*>(file_name);
  std::string m_output_file_name;

  std::copy_n(m_buffer, file_name_len, std::back_inserter(m_output_file_name));

  int ret = avio_open(&p_avformat_context->pb, m_output_file_name.c_str(), AVIO_FLAG_WRITE);
  if (ret < 0) {
    return 1;
  }

  return 0;
}

Expect<uint32_t> WasmEdgeFfmpegAvFormatWriteHeader::body(const Runtime::CallingFrame& frame, uint64_t avformat_context) {
  auto* mem_instance = frame.getMemoryByIndex(0);
  if (mem_instance == nullptr) {
    return Unexpect(ErrCode::Value::HostFuncError);
  }

  AVFormatContext* p_avformat_context = reinterpret_cast<AVFormatContext*>(avformat_context);
  int ret = avformat_write_header(p_avformat_context, NULL);
  if (ret < 0) {
    return 1;
  }

  return 0;
}

} // namespace Host
} // namespace WasmEdge
