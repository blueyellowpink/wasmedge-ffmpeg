// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2019-2023 Second State INC

#include <memory>

#include "ffmpeg_module.h"
#include "ffmpeg_func.h"

namespace WasmEdge {
namespace Host {

WasmEdgeFfmpegModule::WasmEdgeFfmpegModule() : ModuleInstance("wasmedge_ffmpeg") {
  addHostFunc("wasmedge_ffmpeg_avformat_alloc_context", std::make_unique<WasmEdgeFfmpegAvFormatAllocContext>(env));
  addHostFunc("wasmedge_ffmpeg_avformat_free_context", std::make_unique<WasmEdgeFfmpegAvFormatFreeContext>(env));
  addHostFunc("wasmedge_ffmpeg_avformat_get_context", std::make_unique<WasmEdgeFfmpegAvFormatGetContext>(env));
  addHostFunc("wasmedge_ffmpeg_avformat_open_input", std::make_unique<WasmEdgeFfmpegAvFormatOpenInput>(env));
  addHostFunc("wasmedge_ffmpeg_avformat_find_stream_info", std::make_unique<WasmEdgeFfmpegAvFormatFindStreamInfo>(env));
  addHostFunc("wasmedge_ffmpeg_avformat_get_nb_streams", std::make_unique<WasmEdgeFfmpegAvFormatGetNbStreams>(env));
  addHostFunc("wasmedge_ffmpeg_avformat_get_stream", std::make_unique<WasmEdgeFfmpegAvFormatGetStream>(env));
  addHostFunc("wasmedge_ffmpeg_avformat_alloc_output_context2", std::make_unique<WasmEdgeFfmpegAvFormatAllocOutputContext2>(env));
  addHostFunc("wasmedge_ffmpeg_avformat_write_header", std::make_unique<WasmEdgeFfmpegAvFormatWriteHeader>(env));
  addHostFunc("wasmedge_ffmpeg_avformat_new_stream", std::make_unique<WasmEdgeFfmpegAvFormatNewStream>(env));
  addHostFunc("wasmedge_ffmpeg_avformat_close_input", std::make_unique<WasmEdgeFfmpegAvFormatCloseInput>(env));

  addHostFunc("wasmedge_ffmpeg_avcodec_params_codec_type", std::make_unique<WasmEdgeFfmpegAvCodecParamsCodecType>(env));
  addHostFunc("wasmedge_ffmpeg_avcodec_params_copy", std::make_unique<WasmEdgeFfmpegAvCodecParamsCopy>(env));

  addHostFunc("wasmedge_ffmpeg_av_dump_format", std::make_unique<WasmEdgeFfmpegAvDumpFormat>(env));
  addHostFunc("wasmedge_ffmpeg_av_read_frame", std::make_unique<WasmEdgeFfmpegAvReadFrame>(env));
  addHostFunc("wasmedge_ffmpeg_av_packet", std::make_unique<WasmEdgeFfmpegAvPacket>(env));
  addHostFunc("wasmedge_ffmpeg_av_packet_stream_index", std::make_unique<WasmEdgeFfmpegAvPacketStreamIndex>(env));
  addHostFunc("wasmedge_ffmpeg_av_packet_unref", std::make_unique<WasmEdgeFfmpegAvPacketUnref>(env));
  addHostFunc("wasmedge_ffmpeg_av_interleaved_write_frame", std::make_unique<WasmEdgeFfmpegAvInterleavedWriteFrame>(env));
  addHostFunc("wasmedge_ffmpeg_av_write_trailer", std::make_unique<WasmEdgeFfmpegAvWriteTrailer>(env));

  addHostFunc("wasmedge_ffmpeg_copy_packet", std::make_unique<WasmEdgeFfmpegCopyPacket>(env));

  addHostFunc("wasmedge_ffmpeg_avio_open", std::make_unique<WasmEdgeFfmpegAvioOpen>(env));
  addHostFunc("wasmedge_ffmpeg_avio_closep", std::make_unique<WasmEdgeFfmpegAvioClosep>(env));

  addHostFunc("wasmedge_ffmpeg_avstream_codecpar", std::make_unique<WasmEdgeFfmpegAvStreamCodecpar>(env));
}

} // namespace Host
} // namespace WasmEdge
