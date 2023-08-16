# SPDX-License-Identifier: Apache-2.0
# SPDX-FileCopyrightText: 2019-2023 Second State INC

wasmedge_add_library(wasmedgePluginWasmEdgeFfmpeg
  SHARED
  ffmpeg_env.cpp
  ffmpeg_func.cpp
  ffmpeg_module.cpp
)

target_link_directories(wasmedgePluginWasmEdgeFfmpeg PUBLIC ${FFMPEG_LIB_DIR})

target_compile_options(wasmedgePluginWasmEdgeFfmpeg
  PUBLIC
  -DWASMEDGE_PLUGIN
)

if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
  target_link_options(wasmedgePluginWasmEdgeFfmpeg
    PUBLIC
    -Wl,-U,__ZN8WasmEdge6Plugin14PluginRegisterC1EPKNS0_6Plugin16PluginDescriptorE
    -Wl,-U,__ZN8WasmEdge6Plugin14PluginRegisterD1Ev
    -Wl,-U,__ZN8WasmEdge9Allocator7releaseEPhj
  )
endif()

target_include_directories(wasmedgePluginWasmEdgeFfmpeg
  PUBLIC
  $<TARGET_PROPERTY:wasmedgePlugin,INCLUDE_DIRECTORIES>
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${FFMPEG_INCLUDE_DIR}
)

target_link_libraries(wasmedgePluginWasmEdgeFfmpeg
  PRIVATE
  wasmedge_shared
  avformat
  avutil
)

install(TARGETS wasmedgePluginWasmEdgeFfmpeg DESTINATION ${CMAKE_INSTALL_LIBDIR}/wasmedge)
